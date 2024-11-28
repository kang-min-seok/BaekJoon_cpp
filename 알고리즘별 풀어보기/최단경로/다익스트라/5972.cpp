#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int n,m;
vector<vector<pair<int,int>>> line_vec;
vector<int>point_vec;


void basic_input(){
    cin >> n >> m;
    line_vec.resize(n+1);
    point_vec.resize(n+1, INT_MAX);
    for(int i=0; i<m; i++){
        int start, end, cost;
        cin >> start >> end >> cost;

        line_vec[start].push_back(make_pair(end, cost));
        line_vec[end].push_back(make_pair(start, cost));
    }
    point_vec[1] = 0;
}

void daikstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, 1));

    while(!pq.empty()){
        int now_cost = pq.top().first;
        int now_point = pq.top().second;
        pq.pop();

        for(auto & edge: line_vec[now_point]){
            int next_point = edge.first;
            int next_cost = edge.second;

            if(point_vec[next_point] > now_cost + next_cost){
                point_vec[next_point] = now_cost + next_cost;
                pq.push(make_pair(now_cost+next_cost, next_point));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    basic_input();

    daikstra();

    cout << point_vec[n] << "\n";

    return 0;
}