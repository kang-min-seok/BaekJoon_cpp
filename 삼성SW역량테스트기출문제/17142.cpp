#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int board_size, active_num;
vector<pair<int,int>> virus_vec;
vector<pair<int,int>> active_vec;
vector<vector<int>> board;
int blank_num = 0;

void basic_input(){
    cin >> board_size >> active_num;
    board.resize(board_size, vector<int>(board_size));
    for(int i=0; i<board_size; i++){
        for(int j=0; j<board_size; j++){
            int temp;
            cin >> temp;
            if(temp == 2){
                board[i][j] = -2;
                virus_vec.push_back(make_pair(j,i));
            } else if(temp == 0){
                board[i][j] = 0;
                blank_num++;
            } else if(temp == 1){
                board[i][j] = -1;
            }
        }
    }
}

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int result = INT_MAX;

void bfs(){
    vector<vector<int>> temp_board = board;
    queue<pair<int,int>> q;
    vector<vector<bool>> first_visit(board_size, vector<bool>(board_size, false));
    int spread_num = 0;
    for(int i=0; i<active_num; i++){
        q.push(active_vec[i]);
        first_visit[active_vec[i].second][active_vec[i].first] = true;
        temp_board[active_vec[i].second][active_vec[i].first] = 0;
    }

    while(!q.empty()){
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();
        

        for(int i=0; i<4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if(nx < 0 || ny < 0 || nx >= board_size || ny >= board_size)
                continue;
            if(temp_board[ny][nx] == -2){
                temp_board[ny][nx] = temp_board[now_y][now_x] + 1;
                q.push(make_pair(nx,ny));
            }
            else if(temp_board[ny][nx] == 0 && !first_visit[ny][nx]){
                temp_board[ny][nx] = temp_board[now_y][now_x]+1;
                q.push(make_pair(nx,ny));
                spread_num++;

                if(spread_num == blank_num){
                    if(temp_board[ny][nx] < result){
                        result = temp_board[ny][nx];
                    }
                    return;
                }
            }
        }

    }
    return;
}

void backtracking(int start){
    if(active_vec.size() == active_num){
        bfs();
        return;
    }

    for(int i=start+1; i<virus_vec.size(); i++){
        active_vec.push_back(virus_vec[i]);
        backtracking(i);
        active_vec.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    basic_input();

    for(int i=0; i<virus_vec.size(); i++){
        active_vec.push_back(virus_vec[i]);
        backtracking(i);
        active_vec.pop_back();
    }

    if(blank_num == 0){
        cout << "0" << "\n";
    }
    else if(result == INT_MAX){
        cout << "-1" << "\n";
    } else {
        cout << result << "\n";
    }

    return 0;
}