// 단순구현
#include <iostream>
#include <vector>
using namespace std;

int n,k;
vector<int>belt;
vector<bool>robot_exist;
vector<int>robot_location;
int broken = 0;
int in_l, out_l;

void basic_input(){
    cin >> n >> k;
    belt.resize(2*n);
    robot_exist.resize(2*n, false);
    in_l = 0;
    out_l = n-1;
    for(int i=0; i< 2*n; i++){
        int temp;
        cin >> temp;
        belt[i] = temp;
        if(temp == 0){
            broken += 1;
        }
    }
}

void spin_belt(){
    in_l -= 1;
    out_l -= 1;
    if(in_l < 0){
        in_l = (2*n) - 1;
    }
    if(out_l < 0){
        out_l = (2*n) - 1;
    }

    if(robot_exist[out_l]){
        robot_exist[out_l] = false;
        robot_location.erase(robot_location.begin());
    }
}

void move_robot(){
    for(int i=0; i<robot_location.size(); i++){
        int next_robot = robot_location[i]+1;
        if(next_robot >= 2*n){
            next_robot = 0;
        }
        if(!robot_exist[next_robot] && belt[next_robot] > 0){
            robot_exist[robot_location[i]] = false;
            robot_exist[next_robot] = true;
            belt[next_robot] -= 1;
            robot_location[i] = next_robot;
            if(belt[next_robot] == 0){
                broken++;
            }

            if(robot_location[i] == out_l){
                robot_exist[robot_location[i]] = false;
                robot_location.erase(robot_location.begin());
                i--;
            }
        }
    }

}

void add_robot(){
    if(belt[in_l] != 0){
        robot_location.push_back(in_l);
        robot_exist[in_l] = true;
        belt[in_l] -= 1;
        
        if(belt[in_l] == 0){
            broken++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    basic_input();
    int result = 0;
    while(broken < k){
        spin_belt();
        move_robot();
        add_robot();
        
        result += 1;
    }

    cout << result << "\n";
    return 0;
}