#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int T;

vector<vector<pair<int,int>>> line_vec;
vector<int> point_vec;

void daikstra(int start){
    point_vec[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, start });

    while(!pq.empty()){
        int now_cost = pq.top().first;
        int now_node = pq.top().second;
        pq.pop();

        for(auto &edge: line_vec[now_node]){
            int next_point = edge.first;
            int next_cost = edge.second;

            if(point_vec[next_point] > point_vec[now_node] + next_cost){
                point_vec[next_point] = point_vec[now_node] + next_cost;
                pq.push({ now_cost+next_cost, next_point });
            }
        }
    }
    int count = 0;
    int last_time = 0;
    for (int i = 1; i < point_vec.size(); i++) {
        if (point_vec[i] != INT_MAX) {
            count++;
            if (point_vec[i] > last_time) last_time = point_vec[i];
        }
    }

    cout << count << " " << last_time << "\n";
}



void basic_input(){
    cin >> T;
    for(int i=0; i<T; i++){
        int node_num, line_num, start_point;
        cin >> node_num >> line_num >> start_point;

        line_vec = vector<vector<pair<int,int>>>(node_num+1);
        point_vec = vector<int>(node_num+1, INT_MAX);

        for(int j=0; j<line_num; j++){
            int end, start, cost;
            cin >> end >> start >> cost;
            line_vec[start].push_back({ end, cost });
        }

        daikstra(start_point);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    basic_input();

    return 0;
}