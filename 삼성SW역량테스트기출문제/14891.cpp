#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> wheel;

bool is_spin[4] = {false,};

void spin_wheel(int wheel_index, int direction){
    int next_direction;
    if(direction == 1){
        next_direction = -1;
    } else {
        next_direction = 1;
    }
    if(wheel_index-1 >= 0 && wheel[wheel_index-1][2] != wheel[wheel_index][6] && !is_spin[wheel_index-1]){
        is_spin[wheel_index-1] = true;
        spin_wheel(wheel_index-1, next_direction);
        is_spin[wheel_index-1] = false;
    }
    if(wheel_index+1 < 4 && wheel[wheel_index][2] != wheel[wheel_index+1][6] && !is_spin[wheel_index+1]){
        is_spin[wheel_index+1] = true;
        spin_wheel(wheel_index+1, next_direction);
        is_spin[wheel_index+1] = false;
    }


    vector<int> temp_wheel = wheel[wheel_index];
    for(int i=0; i<8; i++){
        int next_index = i-direction;
        if(next_index < 0){
            next_index = 7;
        } if(next_index > 7){
            next_index = 0;
        }
        wheel[wheel_index][i] = temp_wheel[next_index];
    }
    
}

void basic_input(){
    wheel.resize(4, vector<int>(8));
    for(int i=0; i<4; i++){
        string temp;
        cin >> temp;
        for(int j=0; j<8; j++){
            wheel[i][j] = (int)temp[j] - 48;
        }
    }
    int spin_num;
    cin >> spin_num;
    for(int i=0; i<spin_num; i++){
        int wheel_index, direction;
        cin >> wheel_index >> direction;

        is_spin[wheel_index-1] = true;
        spin_wheel(wheel_index-1, direction);
        is_spin[wheel_index-1] = false;
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    basic_input();
    int result = 0;
    
    result += wheel[0][0];
    result += wheel[1][0] * 2;
    result += wheel[2][0] * 4;
    result += wheel[3][0] * 8;

    cout << result << "\n";
    return 0;
}