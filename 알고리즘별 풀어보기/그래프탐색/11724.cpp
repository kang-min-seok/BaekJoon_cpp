#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int point, line;

vector<vector<bool>>connect_vec;
vector<bool>visited_vec;

void dfs(int now_point){
    visited_vec[now_point] = true;
    for(int i=1; i<=point; i++){
        if(connect_vec[now_point][i] && !visited_vec[i]){
            dfs(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> point >> line;

    connect_vec.resize(point+1, vector<bool>(point+1));
    visited_vec.resize(point+1, false);

    for(int i=0; i<line; i++){
        int one, two;
        cin >> one >> two;
        connect_vec[one][two] = true;
        connect_vec[two][one] = true;
    }
    int result = 0;
    for(int i=1; i<=point; i++){
        if(!visited_vec[i]){
            dfs(i);
            result += 1;
        }
    }
    cout << result << "\n";
    return 0;
}
