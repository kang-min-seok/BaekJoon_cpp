#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int height, width;
int robot_x, robot_y, direction; // 0 = 북, 1 = 동, 2 = 남, 3 = 서
int result = 0;
vector<vector<int>> board;

void basic_input(){
    cin >> height >> width;
    cin >> robot_y >> robot_x >> direction;
    board.resize(height, vector<int>(width, 0));
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            cin >> board[i][j];
        }
    }
}

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

int rx[4] = {0,-1,0,1};
int ry[4] = {1,0,-1,0};

void bfs(){
    queue<pair<pair<int,int>, int>> q;
    q.push(make_pair(make_pair(robot_x, robot_y), direction));

    while(!q.empty()){
        int nx = q.front().first.first;
        int ny = q.front().first.second;
        int nd = q.front().second;
        q.pop();
        // 현재 칸이 청소되지 않은 빈칸인 경우
        if(board[ny][nx] == 0){
            board[ny][nx] = 2;
            result++;
        }

        bool is_exist = false;
        for(int i=0; i<4; i++){
            if(board[ny+dy[i]][nx+dx[i]] == 0){
                is_exist = true;
                break;
            }
        }
        // 현재 칸의 주변 4칸 중 청소되지 않은 빈칸이 없는 경우
        if(!is_exist){
            // 후진 할 곳이 벽이 아니라면
            if(board[ny+ry[nd]][nx+rx[nd]] != 1){
                q.push(make_pair(make_pair(nx+rx[nd], ny+ry[nd]), nd));
            }
        }
        // 현재 칸의 주변 4칸 중 청소되지 않은 빈칸이 있는 경우
        else {
            // 반시계방향 회전
            int next_d = nd;
            for(int i=0; i<4; i++){
                next_d -= 1;
                if(next_d < 0){
                    next_d = 3;
                }

                if(board[ny+dy[next_d]][nx+dx[next_d]] == 0){
                    q.push(make_pair(make_pair(nx+dx[next_d], ny+dy[next_d]), next_d));
                    break;
                }
            }
            
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    basic_input();

    bfs();

    cout << result << "\n";

    return 0;
}