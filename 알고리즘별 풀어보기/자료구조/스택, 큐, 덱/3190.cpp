#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

pair<int,int> change_direction(pair<int,int> now_direction, char change_char){
    // 기존 방향이 왼쪽이라면
    if(now_direction == make_pair(0,-1)){
        if(change_char == 'D'){
            return make_pair(-1,0);
        } else {
            return make_pair(1,0);
        }
    }

    // 기존 방향이 오른쪽이라면
    else if(now_direction == make_pair(0,1)){
        if(change_char == 'D'){
            return make_pair(1,0);
        } else {
            return make_pair(-1,0);
        }
    }
    // 기존 방향이 윗쪽이라면
    else if(now_direction == make_pair(-1,0)){
        if(change_char == 'D'){
            return make_pair(0,1);
        } else {
            return make_pair(0,-1);
        }
    }
    // 기존 방향이 아랫쪽이라면
    else if(now_direction == make_pair(1,0)){
        if(change_char == 'D'){
            return make_pair(0,-1);
        } else {
            return make_pair(0,1);
        }
    }    
    cout << "error" << '\n';
    return make_pair(0,0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 보드판 크기
    int board_size;
    cin >> board_size;

    // 사과 갯수
    int apple_num;
    cin >> apple_num;

    // 보드판 2차원 배열, (사과 여부)
    vector<vector<bool>> board(board_size+1, vector<bool>(board_size+1, false));
    
    // 보드판 배열에 사과 입력
    for(int i=0; i<apple_num; i++){
        int column, row;
        cin >> column >> row;
        board[column][row] = true;
    }

    // 방향 바뀌는 횟수
    int change_num;
    cin >> change_num;

    // 방향 바뀌는 목록 queue
    // input에서 항상 시간이 작은거부터 입력되기 때문에 queue사용함
    int sec;
    char dic;
    queue<pair<int, char>> change;
    for(int i=0; i<change_num; i++){
        cin >> sec >> dic;
        change.push(make_pair(sec, dic));
    }

    //  왼쪽  = (0, -1)
    // 오른쪽 = (0, +1)
    //  위쪽  = (-1, 0)
    // 아랫쪽 = (+1, 0)
    pair<int,int> direction_now = make_pair(0,1);

    // 뱀의 좌표를 저장하는 deque
    deque<pair<int,int>> snake;
    // 뱀의 좌표를 저장하는 배열, 이걸로 몸통에 부딪혔는지 여부를 검사할꺼임
    vector<vector<bool>> snake_position(board_size+1, vector<bool>(board_size+1, false));

    // 뱀은 1,1 부터 시작
    snake.push_front(make_pair(1,1));
    snake_position[1][1] = true;

    int now_second = 0;

    int change_sec = change.front().first; // 몇초에 뱀을 움직일꺼냐
    char snake_next_dic = change.front().second; // 다음에 어느 방향으로 갈꺼냐
    
    change.pop();

    while(1){
        now_second += 1;
        int next_row, next_column;
        next_row = snake.front().first + direction_now.first;
        next_column = snake.front().second + direction_now.second;

        // 벽에 부딪혔다면 종료
        if(next_row > board_size || next_column > board_size || next_row <= 0 || next_column <= 0){
            cout << now_second << '\n';
            break;
        }
        // 뱀 몸통에 부딪혔다면 종료
        if(snake_position[next_row][next_column]){
            cout << now_second << '\n';
            break;
        }

        // 뱀의 머리를 한칸 앞으로 전진
        snake.push_front(make_pair(next_row, next_column));
        snake_position[next_row][next_column] = true;

        // 전진한 곳에 사과가 없다면 꼬리 없애기
        if(!board[next_row][next_column]){
            snake_position[snake.back().first][snake.back().second] = false;
            snake.pop_back();
        } else { // 전진한 곳에 사과가 있다면 사과 없애기
            board[next_row][next_column] = false;
        }

        // 방향 바꾸기
        if(change_sec == now_second){
            direction_now = change_direction(direction_now,snake_next_dic);
            if(!change.empty()){
                change_sec = change.front().first;
                snake_next_dic = change.front().second;
                change.pop();
            }
        }
    }

    return 0;
}