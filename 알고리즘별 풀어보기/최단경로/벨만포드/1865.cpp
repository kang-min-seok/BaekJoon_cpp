#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

bool bellman(int start_point, vector<pair<pair<int, int>, int>> edges, vector<int> point_vec){
    point_vec[start_point] = 0;
    for(int i=0; i<point_vec.size()-2; i++){
        
        for(auto &edge : edges){
            int now = edge.first.first;
            int next = edge.first.second;
            int cost = edge.second;
            if(point_vec[now] != INT_MAX && point_vec[next] > point_vec[now] + cost){
                point_vec[next] = point_vec[now] + cost;
            }
        }

        
    }

    for(auto &edge : edges){
        int now = edge.first.first;
        int next = edge.first.second;
        int cost = edge.second;
        if(point_vec[now] != INT_MAX && point_vec[next] > point_vec[now] + cost){
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;

    for(int i=0; i<test_case; i++){
        int point_num, road_num, hole_num;
        cin >> point_num >> road_num >> hole_num;

        vector<pair<pair<int, int>, int>> edges; // edges[0] = {{start, end}, cost}
        vector<int>point_vec(point_num+1, INT_MAX);
        vector<vector<int>> adj(point_num + 1); // 노드끼리 연결여부 확인용 벡터

        // 도로 생성
        for(int j=0; j<road_num; j++){
            int start, end, cost;
            cin >>  start >> end >> cost;

            edges.push_back(make_pair(make_pair(start, end), cost));
            edges.push_back(make_pair(make_pair(end, start), cost));
            adj[start].push_back(end);
            adj[end].push_back(start);
        }

        // 웜홀 생성
        for(int j=0; j<hole_num; j++){
            int start, end, cost;
            cin >>  start >> end >> cost;

            edges.push_back(make_pair(make_pair(start, end), -cost));
            adj[start].push_back(end);
        }


        vector<bool>visited_vec(point_num + 1, false);
        queue<int>visited_queue;

        bool is_minus = false;
        
        for(int j=1; j<=point_num; j++){
            // 만약 방문하지 않은 포인트라면 벨만포드 실행
            if(!visited_vec[j]){
                visited_queue.push(j);
                visited_vec[j] = true;
                if(bellman(j, edges, point_vec)){
                    cout << "YES" << "\n";
                    is_minus = true;
                    break;
                }
            }
            // bfs 실행
            while(!visited_queue.empty()){
                int now = visited_queue.front();
                visited_queue.pop();
                for (int neighbor : adj[now]) {
                    if (!visited_vec[neighbor]) {
                        visited_vec[neighbor] = true;
                        visited_queue.push(neighbor);
                    }
                }
            }

            
        }

        if(!is_minus){
            cout << "NO" << "\n";
        }

    }

    return 0;
}