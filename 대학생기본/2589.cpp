#include <iostream>
#include <queue>

using namespace std;

int height, width;

vector<vector<int>> board;

void basic_input(){
    cin >> height >> width;
    board.resize(height, vector<int>(width, 0));
    for(int i=0; i<height; i++){
        string temp;
        cin >> temp;
        for(size_t j=0; j<temp.size(); j++) {
            if(temp[j] == 'W'){
                board[i][j] = -1;
            } else {
                board[i][j] = 0;
            }
        }
    }
}

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int bfs(int start_x, int start_y){
    vector<vector<bool>> visited(height, vector<bool>(width, false));
    vector<vector<int>>copy_board = board;

    queue<pair<int,int>>q;
    q.push(make_pair(start_x, start_y));
    visited[start_y][start_x] = true;
    int max_distance = 0;
    while(!q.empty()){
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int next_x = nx + dx[i];
            int next_y = ny + dy[i];
            
            if(next_x < 0 || next_y < 0 || next_x >= width || next_y >= height)
                continue;
            
            if(copy_board[next_y][next_x] == 0 && !visited[next_y][next_x]){
                copy_board[next_y][next_x] = copy_board[ny][nx] + 1;
                if(copy_board[ny][nx] + 1 > max_distance){
                    max_distance = copy_board[ny][nx] + 1;
                }
                q.push(make_pair(next_x, next_y));
                visited[next_y][next_x] = true;
            }
            
        }
    }

    
    return max_distance;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    basic_input();
    int max = 0;

    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            if(board[i][j] == 0){
                int far_value = bfs(j, i);
                if(far_value > max){
                    max = far_value;
                }
            }
        }
    }

    cout << max << "\n";
    return 0;
}