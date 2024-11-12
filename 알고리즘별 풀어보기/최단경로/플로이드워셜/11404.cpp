#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int node_num;
    cin >> node_num;

    int edge_num;
    cin >> edge_num;

    vector<vector<int>>edges(node_num+1, vector<int>(node_num+1, INT_MAX));

    for(int i=1; i<=node_num; i++){
        edges[i][i] = 0;
    }

    for(int i=0; i<edge_num; i++){
        int start, end, cost;
        cin >> start >> end >> cost;
        if(edges[start][end] > cost){
            edges[start][end] = cost;
        }
    }

    for(int k=1; k<=node_num; k++){
        for(int i=1; i<=node_num; i++){
            for(int j=1; j<=node_num; j++){
                if(edges[i][k] != INT_MAX && edges[k][j] != INT_MAX)
                edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);                
            }
        }
    }

    for(int i=1; i<=node_num; i++){
        for(int j=1; j<=node_num; j++){
            if(edges[i][j] == INT_MAX){
                cout << "0 ";
            } else {
                cout << edges[i][j] << " ";
            }
        }
        cout << "\n";
    }


    return 0;
}