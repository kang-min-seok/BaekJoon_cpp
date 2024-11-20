#include <iostream>
#include <queue>
using namespace std;

int height, width;
vector<vector<char>> board;

// dx, dy값에 맞춰 구슬을 움직일 수 있는만큼 움직여주는 함수
// 해당 방향으로 움직일수 있는지 여부, 움직인 뒤에 구슬 위치 반환
pair<pair<bool,pair<bool,bool>>, pair<pair<int,int>, pair<int,int>>> move_ball(pair<int,int>red, pair<int,int>blue, int dx, int dy){
    bool is_move = false;
    bool is_red = false;
    bool is_blue = false;
    queue<pair<pair<int,int>, pair<int,int>>> q;
    q.push(make_pair(red, blue));

    while(!q.empty()){
        bool is_temp_move = false;
        int red_nx = q.front().first.first;
        int red_ny = q.front().first.second;
        int blue_nx = q.front().second.first;
        int blue_ny = q.front().second.second;

        

        int next_red_nx = q.front().first.first;
        int next_red_ny = q.front().first.second;
        int next_blue_nx = q.front().second.first;
        int next_blue_ny = q.front().second.second;
        q.pop();

        // 빨간색이 한칸 움직일 수 있다면
        if(board[red_ny + dy][red_nx + dx] == '.' && !is_red){
            is_temp_move = true;
            is_move = true;
            next_red_nx = red_nx+dx;
            next_red_ny = red_ny+dy;
        }
        // 파란색이 한칸 움직일 수 있다면
        if(board[blue_ny + dy][blue_nx + dx] == '.' && !is_blue){
            is_temp_move = true;
            is_move = true;
            next_blue_nx = blue_nx+dx;
            next_blue_ny = blue_ny+dy;
        }
        // 파란색이 구멍에 들어가면
        if(board[blue_ny + dy][blue_nx + dx] == 'O'){
            next_blue_nx = blue_nx+dx;
            next_blue_ny = blue_ny+dy;
            is_move = true;
            is_blue = true;
            break;
        }
        // 빨간색이 구멍에 들어가면
        if(board[red_ny + dy][red_nx + dx] == 'O'){
            next_red_nx = red_nx+dx;
            next_red_ny = red_ny+dy;
            is_move = true;
            is_red = true;
        }
        // 만약 두 구슬이 겹친다면 이동취소
        if(next_red_nx == next_blue_nx && next_red_ny == next_blue_ny){
            break;
        }
        // 둘 중 하나라도 일단 움직였다면
        if(is_temp_move){
            red.first = next_red_nx;
            red.second = next_red_ny;
            blue.first = next_blue_nx;
            blue.second = next_blue_ny;
            q.push(make_pair(make_pair(next_red_nx, next_red_ny), make_pair(next_blue_nx, next_blue_ny)));
        }
    }
    return make_pair(make_pair(is_move, make_pair(is_red, is_blue)), make_pair(red,blue));
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width;
    board.resize(height, vector<char>(width));
    pair<int,int> now_red, now_blue, finish_hole; // 구슬 x,y
    
    // 보드판 입력
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            char temp;
            cin >> temp;
            if(temp == 'R'){
                now_red = make_pair(j,i);
                board[i][j] = '.';
            } else if(temp == 'B'){
                now_blue = make_pair(j,i);
                board[i][j] = '.';
            } else if(temp == 'O'){
                finish_hole = make_pair(j,i);
                board[i][j] = temp;
            } else {
                board[i][j] = temp;
            }
        }
    }

    // 보드판을 왼쪽, 오른쪽, 아래, 왼쪽으로 기울여보고 r과b의 움직임이 있다면 q.push
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    vector<pair<int,int>> visited_red;
    vector<pair<int,int>> visited_blue;

    visited_red.push_back(now_red);
    visited_blue.push_back(now_blue);
    // 빨강위치, 파랑위치, 몇번했는지
    queue<pair<pair<pair<int,int>,pair<int,int>>,int>> q;
    q.push(make_pair(make_pair(now_red, now_blue),0));
    bool is_finish = false;
    while(!q.empty()){
        pair<int,int> nr = q.front().first.first;
        pair<int,int> nb = q.front().first.second;
        int now_cost = q.front().second;
        
        q.pop();
        if(now_cost >= 10){
            continue;
        }
        for(int i=0; i<4; i++){
            //  make_pair(make_pair(is_move, make_pair(is_red, is_blue)), make_pair(red,blue));
            pair<pair<bool,pair<bool,bool>>, pair<pair<int,int>, pair<int,int>>> next_ball = move_ball(nr,nb,dx[i], dy[i]);
            // 파란 구슬이 구멍에 들어간다면
            if(next_ball.first.second.second){
                continue;
            }
            // 파란구슬은 구멍에 안들어가면서 빨간구슬이 구멍에 들어간다면 종료
            if(next_ball.first.second.first){
                cout << now_cost + 1 << "\n";
                is_finish = true;
                break;
            }

            // 방문한적 있는 경우인지 체크
            bool is_visited = false;
            for(int j=0; j<visited_red.size(); j++){
                if(visited_red[j] == next_ball.second.first && visited_blue[j] == next_ball.second.second){
                    is_visited = true;
                    break;
                }
            }
            // 방문한적이 있으면
            if(is_visited){
                continue;
            }
            // 두 구슬 중에 하나라도 움직일 수 있다면
            if(next_ball.first.first){
                visited_red.push_back(next_ball.second.first);
                visited_blue.push_back(next_ball.second.second);
                q.push(make_pair(make_pair(next_ball.second.first, next_ball.second.second),now_cost+1));
            }
        }

        if(is_finish){
            break;
        }
    }

    if(!is_finish){
        cout << "-1" << "\n";
    }
    

    return 0;
}