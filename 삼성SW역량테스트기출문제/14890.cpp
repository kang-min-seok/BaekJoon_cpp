#include <iostream>
#include <vector>
using namespace std;

int n, slope_len;
vector<vector<int>> board_vec;

void basic_input(){
    cin >> n >> slope_len;
    board_vec.resize(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board_vec[i][j];
        }
    }
}
int result = 0;
void check_width_pass(){
    for(int i=0; i<n; i++){
        int up_slope = 1;
        int down_slope = slope_len;
        bool is_pass = true;
        for(int j=0; j<n-1; j++){
            // 경사가 똑같다면
            if(board_vec[i][j] == board_vec[i][j+1]){
                up_slope++;
                // 내리막 경사로를 사용 중이라면
                if(down_slope != slope_len){
                    down_slope--;
                    if(down_slope == 0){
                        down_slope = slope_len;
                    }
                }
            } 
            // 한칸 줄어들고 아직 내리막 경사로를 사용 안한 상태라면
            else if(board_vec[i][j] - 1 == board_vec[i][j+1] && down_slope == slope_len){
                down_slope--;
                up_slope = -slope_len+1;
                if(down_slope == 0){
                    down_slope = slope_len;
                }
            }
            // 한칸 늘어나고 오르막 경사로 스택을 모두 쌓은 상태이고 내리막을 사용 안하는 중이라면
            else if(board_vec[i][j] + 1 == board_vec[i][j+1] && up_slope >= slope_len && down_slope == slope_len){
                up_slope = 1;
            } 
            else {
                is_pass = false;
                break;
            }
        }
        if(is_pass && down_slope == slope_len){
            result++;
        }
    }
}

void check_height_pass(){
    for(int i=0; i<n; i++){
        int up_slope = 1;
        int down_slope = slope_len;
        bool is_pass = true;
        for(int j=0; j<n-1; j++){
            // 경사가 똑같다면
            if(board_vec[j][i] == board_vec[j+1][i]){
                up_slope++;
                // 내리막 경사로를 사용 중이라면
                if(down_slope != slope_len){
                    down_slope--;
                    if(down_slope == 0){
                        down_slope = slope_len;
                    }
                }
            } 
            // 한칸 줄어들고 아직 내리막 경사로를 사용 안한 상태라면
            else if(board_vec[j][i] - 1 == board_vec[j+1][i] && down_slope == slope_len){
                down_slope--;
                up_slope = -slope_len+1;
                if(down_slope == 0){
                    down_slope = slope_len;
                }
            }
            // 한칸 늘어나고 오르막 경사로 스택을 모두 쌓은 상태이고 내리막을 사용 안하는 중이라면
            else if(board_vec[j][i] + 1 == board_vec[j+1][i] && up_slope >= slope_len && down_slope == slope_len){
                up_slope = 1;
            } 
            else {
                is_pass = false;
                break;
            }
        }
        if(is_pass && down_slope == slope_len){
            result++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    basic_input();

    check_width_pass();
    check_height_pass();

    cout << result << "\n";

    return 0;
}