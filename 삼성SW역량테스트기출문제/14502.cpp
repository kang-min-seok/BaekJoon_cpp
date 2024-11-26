#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int height, width;
vector<vector<int>> board;
int blank_num = 0;
vector<pair<int,int>> blank_vec;
vector<pair<int,int>> virus_vec;

void basic_input(){
    cin >> height >> width;
    board.resize(height, vector<int>(width));
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            int t;
            cin >> t;
            board[i][j] = t;
            if(t == 0){
                blank_num++;
                blank_vec.push_back(make_pair(j,i));
            } else if(t == 2){
                virus_vec.push_back(make_pair(j,i));
            }
        }
    }
}



int result = 70;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void bfs(){
    queue<pair<int, int>> q;
    int spread_num = 0;
    
    vector<vector<int>> copy_board = board;
    for(int i=0; i<virus_vec.size(); i++){
        q.push(virus_vec[i]);
    }
    while(!q.empty()){
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int next_x = nx + dx[i];
            int next_y = ny + dy[i];
            if(next_x < 0 || next_y < 0 || next_x >= width || next_y >= height)
                continue;
            if(copy_board[next_y][next_x] == 0){
                copy_board[next_y][next_x] = 2;
                q.push(make_pair(next_x, next_y));
                spread_num++;
            }
        }
    }

    if(result > spread_num){
        result = spread_num;
    }
}

int len = 0;

void backtracking(int start){
    if(len == 3){
        bfs();
        return;
    }
    for(int i=start+1; i<blank_num; i++){
        len++;
        board[blank_vec[i].second][blank_vec[i].first] = 1;
        backtracking(i);
        board[blank_vec[i].second][blank_vec[i].first] = 0;
        len--;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    basic_input();

    for(int i=0; i<blank_num-2; i++){
        len++;
        board[blank_vec[i].second][blank_vec[i].first] = 1;
        backtracking(i);
        board[blank_vec[i].second][blank_vec[i].first] = 0;
        len--;
    }

    cout << blank_num - result - 3 << "\n";


    return 0;
}