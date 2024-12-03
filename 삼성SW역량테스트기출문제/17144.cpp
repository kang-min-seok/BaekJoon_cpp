#include <iostream>
#include <vector>

using namespace std;

int height, width, finish_sec;
int air_up, air_down;

vector<vector<int>> board;

void basic_input(){
    cin >> height >> width >> finish_sec;
    board.resize(height, vector<int>(width));
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            cin >> board[i][j];
        }
    }

    for(int i=2; i<height; i++){
        if(board[i][0] == -1){
            air_up = i;
            air_down = i+1;
            break;
        }
    }
}

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void spread_dust(){
    vector<vector<pair<int,int>>> plus_dust(height); // [x] = (y,먼지값)
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            // 확산 가능하다면
            if(board[i][j] >= 5){
                int plus_value = board[i][j] / 5;
                for(int p=0; p<4; p++){
                    int next_x = j + dx[p];
                    int next_y = i + dy[p];
                    if(next_x < 0 || next_y < 0 || next_x >= width || next_y >= height || board[next_y][next_x] == -1)
                        continue;
                    plus_dust[next_y].push_back(make_pair(next_x, plus_value));
                    board[i][j] -= plus_value;
                }
            }
        }
    }

    for(int i=0; i<height; i++){
        for(auto &wid: plus_dust[i]){
            board[i][wid.first] += wid.second;
        }
    }
}

void clean_up(){
    int now_x = 0;
    int now_y = air_up-1;
    // 위쪽 이동
    while(now_y > 0){
        board[now_y][now_x] = board[now_y-1][now_x];
        now_y--;
    }
    // 최상단 오른쪽 이동
    while(now_x < width-1){
        board[now_y][now_x] = board[now_y][now_x+1];
        now_x++;
    }
    // 오른쪽 아래 이동
    while(now_y < air_up){
        board[now_y][now_x] = board[now_y+1][now_x];
        now_y++;
    }
    // 하단 왼쪽 이동
    while(now_x > 1){
        board[now_y][now_x] = board[now_y][now_x-1];
        now_x--;
    }
    board[air_up][1] = 0;

}


void clean_down(){
    int now_x = 0;
    int now_y = air_down+1;
    // 왼쪽라인 위쪽 이동
    while(now_y < height-1){
        board[now_y][now_x] = board[now_y+1][now_x];
        now_y++;
    }
    // 하단라인 왼쪽 이동
    while(now_x < width-1){
        board[now_y][now_x] = board[now_y][now_x+1];
        now_x++;
    }
    // 오른쪽라인 아래 이동
    while(now_y > air_down){
        board[now_y][now_x] = board[now_y-1][now_x];
        now_y--;
    }
    // 상단라인 왼쪽이동
    while(now_x > 1){
        board[now_y][now_x] = board[now_y][now_x-1];
        now_x--;
    }
    board[air_down][1] = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    basic_input();  


    for(int i=0; i<finish_sec; i++){
        spread_dust();
        clean_up();
        clean_down();
    }
    
    int result = 0;
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            result += board[i][j];
        }
    }
    
    cout << result + 2 << "\n";

    return 0;
}

// void clean_up(){
//     int now_x = 0;
//     int now_y = air_up-1;
//     // 위쪽 이동
//     for(int i=0; i<air_up-1; i++){
//         board[now_y][now_x] = board[now_y-1][now_x];
//         now_y--;
//     }
//     // 최상단 오른쪽 이동
//     for(int i=0; i<width-1; i++){
//         board[now_y][now_x] = board[now_y][now_x+1];
//         now_x++;
//     }
//     // 오른쪽 아래 이동
//     for(int i=0; i<air_up; i++){
//         board[now_y][now_x] = board[now_y+1][now_x];
//         now_y++;
//     }
//     // 하단 왼쪽 이동
//     for(int i=0; i<width-2; i++){
//         board[now_y][now_x] = board[now_y][now_x-1];
//         now_x--;
//     }
//     board[air_up][1] = 0;

// }


// void clean_down(){
//     int now_x = 0;
//     int now_y = air_down+1;
//     // 왼쪽라인 위쪽 이동
//     for(int i=0; i<height-air_down-2; i++){
//         board[now_y][now_x] = board[now_y+1][now_x];
//         now_y++;
//     }
//     // 하단라인 왼쪽 이동
//     for(int i=0; i<width-1; i++){
//         board[now_y][now_x] = board[now_y][now_x+1];
//         now_x++;
//     }
//     // 오른쪽라인 아래 이동
//     for(int i=0; i<height-air_down-1; i++){
//         board[now_y][now_x] = board[now_y-1][now_x];
//         now_y--;
//     }
//     // 상단라인 왼쪽이동
//     for(int i=0; i<width-2; i++){
//         board[now_y][now_x] = board[now_y][now_x-1];
//         now_x--;
//     }
//     board[air_down][1] = 0;
// }