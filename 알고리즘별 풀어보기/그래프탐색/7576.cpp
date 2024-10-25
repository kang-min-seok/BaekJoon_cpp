#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int width, height;
    cin >> width >> height;

    vector<vector<int>> tomato_vec(height, vector<int>(width));
    vector<vector<bool>> tomato_visited(height, vector<bool>(width, false));
    queue<pair<int,int>> tomato_que; // x,y

    pair<int,int> move_list[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}}; // 상하 우좌

    int zero_cnt = 0;

    // 토마토 저장
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            int is_tomato;
            cin >> is_tomato;
            if(is_tomato == 0){
                zero_cnt += 1;
            } 
            tomato_vec[i][j] = is_tomato;
        }
    }

    if(zero_cnt == 0){
        cout << "0" << "\n";
    } 
    else {
        int tomato_num = 0;
        // 1차적으로 토마토 상자에서 모든 토마토 큐에 넣고
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                if(tomato_vec[i][j] == 1){
                    tomato_que.push(make_pair(j,i));
                }
            }
        }
        int result;
        // 큐에 들어간 토마토를 상하좌우 전염 + 큐에 넣고 pop
        while(!tomato_que.empty()){
            int x = tomato_que.front().first;
            int y = tomato_que.front().second;
            tomato_que.pop();
            for(int i=0; i<4; i++){
                int x_move = x + move_list[i].first;
                int y_move = y + move_list[i].second;
                if(x_move < 0 || y_move < 0 || x_move >= width || y_move >= height)
                    continue;

                if(tomato_vec[y_move][x_move] == 0) {
                    tomato_vec[y_move][x_move] = tomato_vec[y][x] + 1;
                    result = tomato_vec[y][x] + 1;
                    tomato_num += 1;
                    tomato_que.push(make_pair(x_move, y_move));
                }
            }
        }

        // 맨처음 입력시 샜던 0갯수와 전염시킨 토마토 갯수 비교해서 같으면 
        // 다 전염한거니까 결과 출력하고 아니면 0이 남았다는 것이니 -1 출력
        // result에 - 1 한 이유는 1부터 시작했기 때문
        if(zero_cnt == tomato_num) {
            cout << result - 1 << "\n";
        } else {
            cout << "-1" << "\n";
        }
    }

    return 0;
}
    
