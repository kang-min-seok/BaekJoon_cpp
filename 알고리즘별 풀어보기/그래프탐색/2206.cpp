#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int height, width;
    cin >> height >> width;

    vector<vector<int>>move_field(height, vector<int>(width, 0));
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            char temp;
            cin >> temp;
            int temp_int = temp - '0';
            move_field[i][j] = temp_int;
        }
    }



    vector<vector<bool>>move_visited(height, vector<bool>(width, false));
    vector<vector<bool>>break_visited(height, vector<bool>(width, false));

    queue<pair<pair<int,int>,pair<int,bool>>>map_queue; // ( (x,y), (이동값,벽뚫여부) )
    map_queue.push(make_pair(make_pair(0,0), make_pair(1,false)));
    
    move_visited[0][0] = true;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    int result = 0;
    while(!map_queue.empty()){
        int x = map_queue.front().first.first;
        int y = map_queue.front().first.second;
        int move_value = map_queue.front().second.first;
        bool isBreak = map_queue.front().second.second;
        map_queue.pop();
        
   
        if(x == width - 1 && y == height - 1){
            if(result == 0){
                result = move_value;
            }
            else if(move_value < result){
                result = move_value;
            }
            continue;
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= width || ny >= height)
                continue;
        
            // 벽 한번도 안뚫은 상태에서 내가 움직일 곳의 위치값이 0이라면 움직이기
            if(!isBreak && !move_visited[ny][nx] && move_field[ny][nx] == 0){
                move_visited[ny][nx] = true;
                
                map_queue.push(make_pair(make_pair(nx,ny), make_pair(move_value + 1, isBreak)));
            }
            // 벽 한번 뚫은 상태에서 내가 움직일 곳의 위치값이 0이라면 움직이기
            else if(isBreak && !break_visited[ny][nx] && move_field[ny][nx] == 0){
                break_visited[ny][nx] = true;
                
                map_queue.push(make_pair(make_pair(nx,ny), make_pair(move_value + 1, isBreak)));
            }
            // 내가 움직일 곳이 벽이고 벽을 한번도 뚫은적 없는 큐라면 움직이기
            else if(!break_visited[ny][nx] && move_field[ny][nx] == 1 && !isBreak){
                if(isBreak){
                    break_visited[ny][nx] = true;
                }
                map_queue.push(make_pair(make_pair(nx,ny), make_pair(move_value + 1, true)));
            }
        }
    }


    if(result == 0){
        cout << "-1" << "\n";
    } else {
        cout << result << "\n";
    }
    return 0;
}
    
