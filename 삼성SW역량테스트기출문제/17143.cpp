#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int height, width, shark_num;
vector<vector<tuple<int,int,int>>> shark_info; // [y][x] = (속력, 이동방향, 크기)

void basic_input(){
    cin >> height >> width >> shark_num;
    
    shark_info.resize(height, vector<tuple<int,int,int>>(width, make_tuple(0,0,0)));
    
    for(int i=0; i<shark_num; i++){
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        shark_info[r-1][c-1] = make_tuple(s,d,z);
    }
}


void move_shark(){
    vector<vector<tuple<int,int,int>>> new_shark(height, vector<tuple<int,int,int>>(width, make_tuple(0,0,0)));
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            int speed = get<0>(shark_info[i][j]);
            int direction = get<1>(shark_info[i][j]);
            int shark_size = get<2>(shark_info[i][j]);
            if(shark_size == 0) continue;

            if(direction == 1){
                int move_value = speed % ((height-1)*2);
                int next_y = i - move_value;
                int next_direction = direction;

                
                if(next_y <= -(height-1)){
                    next_y = abs(next_y);
                    next_y = height - 1 - (next_y % (height-1));
                }
                else if(next_y <= 0 && next_y > -(height-1)){
                    next_y = abs(next_y);
                    next_direction = 2;
                }

                if(shark_size > get<2>(new_shark[next_y][j])){
                    new_shark[next_y][j] = make_tuple(speed, next_direction, shark_size);
                }
            }
            else if(direction == 2){
                int move_value = speed % ((height-1)*2);
                int next_y = i + move_value;
                int next_direction = direction;
                

                if(next_y >= 2 * (height-1)){
                    next_y = next_y - (2 * (height-1));
                }
                else if(next_y >= height-1 && next_y < (height-1) * 2){
                    next_y = height - 1 - (next_y % (height-1));
                    next_direction = 1;
                }

                if(shark_size > get<2>(new_shark[next_y][j])){
                    new_shark[next_y][j] = make_tuple(speed, next_direction, shark_size);
                }
            }
            else if(direction == 3){
                int move_value = speed % ((width-1)*2);
                int next_x = j + move_value;
                int next_direction = direction;
                
                if(next_x >= 2 * (width-1)){
                    next_x = next_x - (2 * (width-1));
                }
                else if(next_x >= width-1 && next_x < (width-1) * 2){
                    next_x = width - 1 - (next_x % (width-1));
                    next_direction = 4;
                }

                if(shark_size > get<2>(new_shark[i][next_x])){
                    new_shark[i][next_x] = make_tuple(speed, next_direction, shark_size);
                }
            }
            else if(direction == 4){
                int move_value = speed % ((width-1)*2);
                int next_x = j - move_value;
                int next_direction = direction;
                
                if(next_x <= -(width-1)){
                    next_x = abs(next_x);
                    next_x = width - 1 - (next_x % (width-1));
                }
                else if(next_x <= 0 && next_x > -(width-1)){
                    next_x = abs(next_x);
                    next_direction = 3;
                }

                if(shark_size > get<2>(new_shark[i][next_x])){
                    new_shark[i][next_x] = make_tuple(speed, next_direction, shark_size);
                }
            }

        }
    }

    shark_info = new_shark;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    basic_input();

    int result = 0;
    for(int i=0; i<width; i++){
        for(int j=0; j<height; j++){
            if(get<2>(shark_info[j][i]) == 0) continue;

            result += get<2>(shark_info[j][i]);
            shark_info[j][i] = make_tuple(0,0,0);
            break;
        }
        move_shark();
    }

    cout << result << "\n";

    return 0;
}