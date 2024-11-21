// dfs, 백트래킹
// 해당 코드에서 문제점
// 숫자 움직일때 큐 필요없는데 써서 낭비됨
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> board;
int n, result = 0;

char direction_list[4] = {'L', 'R', 'U', 'D'};

void move_left(){
    vector<vector<bool>> is_merge(n,vector<bool>(n, false));
    for(int i=0; i<n; i++){
        for(int j=1; j<n; j++){
            queue<int>q;
            q.push(j);
            while(!q.empty()){
                int now = q.front();
                q.pop();
                // 왼쪽이 빈칸이라면
                if(now-1 >= 0 && board[i][now-1] == 0){
                    board[i][now-1] = board[i][now];
                    board[i][now] = 0;
                    q.push(now-1);
                } 
                // 왼쪽이랑 합쳐진다면
                else if(now-1 >= 0 && board[i][now-1] == board[i][now] && !is_merge[i][now-1]){
                    board[i][now-1] *= 2;
                    is_merge[i][now-1] = true;
                    if(board[i][now-1] > result){
                        result = board[i][now-1];
                    }
                    board[i][now] = 0;
                }
            }
        }
    }
}


void move_right(){
    vector<vector<bool>> is_merge(n,vector<bool>(n, false));
    for(int i=0; i<n; i++){
        for(int j=n-2; j>=0; j--){
            queue<int>q;
            q.push(j);
            while(!q.empty()){
                int now = q.front();
                q.pop();
                // 오른쪽이 빈칸이라면
                if(now+1 < n && board[i][now+1] == 0){
                    board[i][now+1] = board[i][now];
                    board[i][now] = 0;
                    q.push(now+1);
                } 
                // 오른쪽이랑 합쳐진다면
                else if(now+1 < n && board[i][now+1] == board[i][now] && !is_merge[i][now+1]){
                    board[i][now+1] *= 2;
                    is_merge[i][now+1] = true;
                    if(board[i][now+1] > result){
                        result = board[i][now+1];
                    }
                    board[i][now] = 0;
                }
            }
        }
    }
}


void move_up(){
    vector<vector<bool>> is_merge(n,vector<bool>(n, false));
    for(int i=0; i<n; i++){ // x
        for(int j=1; j<n; j++){ // y
            queue<int>q;
            q.push(j);
            while(!q.empty()){
                int now = q.front();
                q.pop();
                // 위쪽이 빈칸이라면
                if(now-1 >= 0 && board[now-1][i] == 0){
                    board[now-1][i] = board[now][i];
                    board[now][i] = 0;
                    q.push(now-1);
                } 
                // 위쪽이랑 합쳐진다면
                else if(now-1 >= 0 && board[now-1][i] == board[now][i] && !is_merge[now-1][i]){
                    board[now-1][i] *= 2;
                    is_merge[now-1][i] = true;
                    if(board[now-1][i] > result){
                        result = board[now-1][i];
                    }
                    board[now][i] = 0;
                }
            }
        }
    }
}



void move_down(){
    vector<vector<bool>> is_merge(n,vector<bool>(n, false));
    for(int i=0; i<n; i++){ // x
        for(int j=n-2; j>=0; j--){ // y
            queue<int>q;
            q.push(j);
            while(!q.empty()){
                int now = q.front();
                q.pop();
                // 위쪽이 빈칸이라면
                if(now+1 < n && board[now+1][i] == 0){
                    board[now+1][i] = board[now][i];
                    board[now][i] = 0;
                    q.push(now+1);
                } 
                // 위쪽이랑 합쳐진다면
                else if(now+1 < n && board[now+1][i] == board[now][i] && !is_merge[now+1][i]){
                    board[now+1][i] *= 2;
                    is_merge[now+1][i] = true;
                    if(board[now+1][i] > result){
                        result = board[now+1][i];
                    }
                    board[now][i] = 0;
                }
            }
        }
    }
}


void move_board(char direction){
    if(direction == 'L'){
        move_left();
    } else if(direction == 'R'){
        move_right();
    } else if(direction == 'U'){
        move_up();
    } else if(direction == 'D'){
        move_down();
    }
}

void dfs(int cnt){
    if(cnt > 5){
        return;
    }
    for(int i=0; i<4; i++){
        vector<vector<int>> temp_board = board;
        move_board(direction_list[i]);
        dfs(cnt+1);
        board = temp_board;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    board.resize(n, vector<int>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int t;
            cin >> t;
            board[i][j] = t;
            if(t > result) {
                result = t;
            }
        }
    }

    dfs(1);

    cout << result << "\n";

    return 0;
}