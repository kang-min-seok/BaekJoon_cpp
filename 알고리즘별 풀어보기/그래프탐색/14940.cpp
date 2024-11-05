#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int width, height;

vector<vector<int>>real_map; // 입력받을 지도
vector<vector<int>>copy_map; // 결과를 출력할 지도
vector<vector<bool>>visited_map; // 결과를 출력할 지도
queue<pair<int,int>>bfs_queue; // x,y

int nx[4] = {1,-1,0,0};
int ny[4] = {0,0,1,-1};
void bfs(){
    while(!bfs_queue.empty()){
        int x = bfs_queue.front().first;
        int y = bfs_queue.front().second;
        bfs_queue.pop();
        visited_map[y][x] = true;
        for(int i=0; i<4;i++){
            int next_x = x + nx[i];
            int next_y = y + ny[i];
            // 움직일 곳이 범위 밖이 라면 컨티뉴
            if(next_x < 0 || next_y < 0 || next_x >= width || next_y >= height)
                continue;
            // 움직일 곳이 움직일 수 있는 곳이라면
            if(real_map[next_y][next_x] == 1 && !visited_map[next_y][next_x]){
                copy_map[next_y][next_x] = copy_map[y][x] + 1;
                visited_map[next_y][next_x] = true;
                bfs_queue.push(make_pair(next_x, next_y));
            }
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width;

    real_map.resize(height,vector<int>(width)); // 입력받을 지도
    copy_map.resize(height,vector<int>(width, -1)); // 결과를 출력할 지도
    visited_map.resize(height,vector<bool>(width, false)); // 입력받을 지도
    int goal_x, goal_y;
    // 좌표 입력
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            int temp;
            cin >> temp;
            real_map[i][j] = temp;
            if(temp == 2){
                goal_x = j;
                goal_y = i;
                copy_map[i][j] = 0;
            } else if(temp == 0){
                copy_map[i][j] = 0;
            }
        }
    }

    // bfs 실행
    bfs_queue.push(make_pair(goal_x,goal_y));
    bfs();

    // 결과 출력
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            cout << copy_map[i][j] << " ";
        }
        cout << "\n";
    }

    

    return 0;
}
