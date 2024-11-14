#include <iostream>
#include <stack>
#include <tuple>
#include <vector>
#include <unordered_set>
using namespace std;

vector<vector<char>>board_vec;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int width, height;

unordered_set<char>visit_set;
int result = 0;

void dfs(int x, int y, int cost){

    if(cost > result){
        result = cost;
    }

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= width || ny >= height)
            continue;
        // 만약 다음 방문할 곳의 값이 여지껏 없던 값이라면
        if(visit_set.find(board_vec[ny][nx]) == visit_set.end()){
            visit_set.insert(board_vec[ny][nx]);
            dfs(nx,ny,cost+1);
            visit_set.erase(board_vec[ny][nx]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width;

    board_vec.resize(height, vector<char>(width));
    
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            cin >> board_vec[i][j];
        }
    }

    visit_set.insert(board_vec[0][0]);
    dfs(0,0,1);

    cout << result << "\n";

    return 0;
}