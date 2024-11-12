#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int node_num;
    cin >> node_num;
    int edge_num;
    cin >> edge_num;

    vector<vector<pair<int,int>>>edges(node_num+1); // edges[start] = {end, cost}

    for(int i=0; i<edge_num; i++){
        int start, end, cost;
        cin >> start >> end >> cost;

        edges[start].push_back(make_pair(end, cost));
    }

    int goal_start, goal_end;
    cin >> goal_start >> goal_end;

    // 비용, 위치
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue_min;
    
    // 각 노드별 비용
    vector<int>node_cost(node_num+1, INT_MAX);
    node_cost[goal_start] = 0;

    queue_min.push(make_pair(0, goal_start));

    while(!queue_min.empty()){
        int now_cost = queue_min.top().first;
        int now_node = queue_min.top().second;
        queue_min.pop();
        if(now_node == goal_end){
            cout << now_cost << "\n";
            break;
        }

        for(auto &edge : edges[now_node]){
            int next_node = edge.first;
            int next_cost = edge.second;


            if(node_cost[next_node] > node_cost[now_node] + next_cost){
                node_cost[next_node] = node_cost[now_node] + next_cost;
                queue_min.push(make_pair(node_cost[now_node] + next_cost, next_node));
            }
        }
    }
    
    return 0;
}