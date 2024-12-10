#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int node_num, line_num;

vector<pair<pair<int,int>, int>> line_vec;
vector<long long> point_vec;

void basic_input(){
    cin >> node_num >> line_num;
    point_vec.resize(node_num+1, INT_MAX);

    for(int i=0; i<line_num; i++){
        int start, end, cost;
        cin >> start >> end >> cost;
        line_vec.push_back(make_pair(make_pair(start, end), cost));
    }

    
}

bool bellman(){
    point_vec[1] = 0;
    for(int i=0; i<node_num-1; i++){

        for(auto &edge: line_vec){
            int start = edge.first.first;
            int end = edge.first.second;
            int cost = edge.second;

            if(point_vec[start] != INT_MAX && point_vec[end] > point_vec[start] + cost){
                point_vec[end] = point_vec[start] + cost;
            }
        }
    }

    for(auto &edge: line_vec){
        int start = edge.first.first;
        int end = edge.first.second;
        int cost = edge.second;

        if(point_vec[start] != INT_MAX && point_vec[end] > point_vec[start] + cost){
            return true;
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    basic_input();

    if(bellman()){
        cout << "-1" << "\n";
    } else {
        for(int i=2; i<=node_num; i++){
            if(point_vec[i] != INT_MAX){
                cout << point_vec[i] << "\n";
            } else {
                cout << "-1" << "\n";
            }
        }
    }

    return 0;
}