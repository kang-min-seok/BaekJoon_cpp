#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int height, width;

// 카메라 정보 (x,y,종류)
vector<tuple<int,int,int>> camera;
int camera_num = 0;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int max_search = 0;
int blank_num = 0;
vector<vector<int>> board;
int search_area(int now_x, int now_y, int direction, int search_value){
    direction = direction % 4;
    while(true){
        now_x += dx[direction];
        now_y += dy[direction];

        if(now_x < 0 || now_y < 0 || now_x >= width || now_y >= height)
            break;

        // 다음칸이 빈칸이라면
        if(board[now_y][now_x] == 0){
            board[now_y][now_x] = -1;
            search_value++;
        } 
        // 다음칸이 벽이라면
        else if(board[now_y][now_x] == 6){
            break;
        }
    }
    return search_value;
}

void backtracking(int search_value, int camera_index){
    // 종료조건
    if(camera_index >= camera_num){
        if(max_search < search_value){
            max_search = search_value;
        }
        return;
    }

    int now_x = get<0>(camera[camera_index]);
    int now_y = get<1>(camera[camera_index]);
    int now_type = get<2>(camera[camera_index]);
    vector<vector<int>> temp_board = board;

    if(now_type == 5){
        int searh_result = search_area(now_x, now_y, 0, search_value);
        searh_result = search_area(now_x, now_y, 1, searh_result);
        searh_result = search_area(now_x, now_y, 2, searh_result);
        searh_result = search_area(now_x, now_y, 3, searh_result);
        backtracking(searh_result, camera_index+1);
        board = temp_board;
    } else if(now_type == 2){
        for(int i=0; i<2; i++){
            int searh_result = search_area(now_x, now_y, i, search_value);
            searh_result = search_area(now_x, now_y, i+2, searh_result);
            backtracking(searh_result, camera_index+1);
            board = temp_board;
        }
    } else if(now_type == 1){
        for(int i=0; i<4; i++){
            int searh_result = search_area(now_x, now_y, i, search_value);
            backtracking(searh_result, camera_index+1);
            board = temp_board;
        }
    } else if(now_type == 3){
        for(int i=0; i<4; i++){
            int searh_result = search_area(now_x, now_y, i, search_value);
            searh_result = search_area(now_x, now_y, i+1, searh_result);
            backtracking(searh_result, camera_index+1);
            board = temp_board;
        }
    } else if(now_type == 4){
        for(int i=0; i<4; i++){
            int searh_result = search_area(now_x, now_y, i, search_value);
            searh_result = search_area(now_x, now_y, i+1, searh_result);
            searh_result = search_area(now_x, now_y, i+3, searh_result);
            backtracking(searh_result, camera_index+1);
            board = temp_board;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width;
    board.resize(height, vector<int>(width));
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            int t;
            cin >> t;
            board[i][j] = t;
            // 입력값이 카메라라면
            if(t != 0 && t != 6){
                camera_num++;
                camera.push_back(make_tuple(j,i,t));
            } else if(t == 0){
                blank_num++;
            }
        }
    }

    backtracking(0, 0);

    cout << blank_num - max_search << "\n";
    return 0;
}