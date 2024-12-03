#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// 위 아래 오른쪽 왼쪽
int dx[5] = {0,0,0,1,-1};
int dy[5] = {0,-1,1,0,0};

int height, width, shark_num;
vector<vector<vector<tuple<int,int,int>>>> shark_info; // [y][x] = (속력, 이동방향, 크기)

void basic_input(){
    cin >> height >> width >> shark_num;
    
    shark_info.resize(height+1, vector<vector<tuple<int,int,int>>>(width+1));
    
    for(int i=0; i<shark_num; i++){
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        shark_info[r-1][c-1].push_back(make_tuple(s,d,z));
    }
}

void move_shark(){
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            for (auto it = shark_info[i][j].begin(); it != shark_info[i][j].end(); ) {
                int speed = get<0>(*it);
                int direction = get<1>(*it);
                int shark_size = get<2>(*it);

                if (speed == 0 || shark_size == 0) {
                    ++it; // 삭제 없이 다음 요소로 진행
                    continue;
                }
                
                if (direction == 1) {
                    int divid = (speed - j) / (height - 1);
                    int rest = (speed - j) % (height - 1);

                    if (divid % 2 == 0) {
                        int next_y = rest;
                        int next_direc = 2;
                        it = shark_info[i][j].erase(it);

                        shark_info[next_y][j].push_back(make_tuple(speed, next_direc, shark_size));
                    } else {
                        int next_y = height -1 - rest;
                        it = shark_info[i][j].erase(it);

                        shark_info[next_y][j].push_back(make_tuple(speed, direction, shark_size));
                    }
                }
                // 상어의 방향이 아래라면
                else if (direction == 2) {
                    int divid = (speed - height + 1 + i) / (height - 1);
                    int rest = (speed - height + 1 + i) % (height - 1);

                    if (divid % 2 == 0) {
                        int next_y = height - 1 - rest;
                        int next_direc = 1;
                        it = shark_info[i][j].erase(it);

                        shark_info[next_y][j].push_back(make_tuple(speed, next_direc, shark_size));

                    } else {
                        int next_y = rest;
                        it = shark_info[i][j].erase(it);

                        shark_info[next_y][j].push_back(make_tuple(speed, direction, shark_size));
                    }
                } 
                // 상어의 방향이 오른쪽이었다면
                else if (direction == 3) {
                    int divid = (speed - width + 1 + j) / (width - 1);
                    int rest = (speed - width + 1 + j) % (width - 1);

                    if (divid % 2 == 0) {
                        int next_x = width - 1 - rest;
                        int next_direc = 4;
                        it = shark_info[i][j].erase(it);

                        shark_info[i][next_x].push_back(make_tuple(speed, next_direc, shark_size));
                    } else {
                        int next_x = rest;
                        it = shark_info[i][j].erase(it);

                        shark_info[i][next_x].push_back(make_tuple(speed, direction, shark_size));
                    }
                } 
                // 상어의 방향이 왼쪽이었다면
                else if (direction == 4) {
                    int divid = (speed - j) / (width - 1);
                    int rest = (speed - j) % (width - 1);

                    if (divid % 2 == 0) {
                        int next_x = rest;
                        int next_direc = 3;
                        it = shark_info[i][j].erase(it);

                        shark_info[i][next_x].push_back(make_tuple(speed, next_direc, shark_size));
                    } else {
                        int next_x = width -1 - rest;
                        it = shark_info[i][j].erase(it);

                        shark_info[i][next_x].push_back(make_tuple(speed, direction, shark_size));
                    }
                }
            }
        }
    }


    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            int max_size=0;
            int max_speed;
            int max_direction;
            for (auto it = shark_info[i][j].begin(); it != shark_info[i][j].end(); ) {
                int speed = get<0>(*it);
                int direction = get<1>(*it);
                int shark_size = get<2>(*it);
                if(shark_size > max_size){
                    max_size = shark_size;
                    max_direction = direction;
                    max_speed = speed;
                }
            }
            shark_info[i][j].clear();
            shark_info[i][j].push_back(make_tuple(max_speed, max_direction, max_size));
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    basic_input();

    int result = 0;
    for(int i=1; i<=width; i++){
        for(int j=0; j<height; j++){
            if(shark_info[j][i].empty()) continue;

            result += get<2>(shark_info[j][i][0]);
            shark_info[j][i].clear();
        }
        move_shark();
    }

    cout << result << "\n";

    return 0;
}