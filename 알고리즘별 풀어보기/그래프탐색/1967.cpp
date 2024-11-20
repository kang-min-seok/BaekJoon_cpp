#include <iostream>
#include <queue>
using namespace std;

vector<vector<pair<int,int>>> first_line;
vector<vector<pair<int,int>>> second_line;

int n;

// 끝점, 그 비용 반환
pair<int,int> bfs(int start, vector<int> &v, vector<vector<pair<int,int>>> &line){
    queue<int>q;
    q.push(start);
    int result_cost = 0;
    int result_node = start;
    vector<bool> visited(n+1, false);
    visited[start] = true;
    while(!q.empty()){
        int now = q.front();
        if(v[now] > result_cost){
            result_cost = v[now];
            result_node = now;
        }
        q.pop();

        for(auto &edge: line[now]){
            int next_node = edge.first;
            int next_cost = edge.second;
            if(!visited[next_node]){
                v[next_node] = v[now] + next_cost;
                visited[next_node] = true;
                q.push(next_node);
            }
        }
    }
    return make_pair(result_node, result_cost);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<int>first_vec(n+1, 0);
    vector<int>second_vec(n+1, 0);

    first_line.resize(n+1);
    second_line.resize(n+1);

    for(int i=0; i<n-1; i++){
        int parent, child, cost;
        cin >> parent >> child >> cost;
        first_line[parent].push_back(make_pair(child, cost));

        second_line[parent].push_back(make_pair(child, cost));
        second_line[child].push_back(make_pair(parent, cost));
    }

    pair<int,int> first_result = bfs(1, first_vec, first_line);
    pair<int,int> second_result = bfs(first_result.first, second_vec, second_line);

    cout << second_result.second << "\n";

    return 0;
}