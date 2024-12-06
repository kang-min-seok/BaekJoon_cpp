#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits.h>

using namespace std;

int board_size, guest_num, fuel;
vector<vector<int>> board;

int taxi_y, taxi_x;

vector<vector<int>> start_point;
vector<pair<int,int>> end_point;

void basic_input(){
    cin >> board_size >> guest_num >> fuel;
    board.resize(board_size, vector<int>(board_size));
    start_point.resize(board_size, vector<int>(board_size,0));

    for(int i=0; i<board_size; i++){
        for(int j=0; j<board_size; j++){
            cin >> board[i][j];
        }
    }
    cin >> taxi_y >> taxi_x;
    taxi_x--;
    taxi_y--;
    end_point.push_back(make_pair(0, 0));
    for(int i=1; i<=guest_num; i++){
        int st_y, st_x, en_y, en_x;
        cin >> st_y >> st_x >> en_y >> en_x;
        start_point[st_y-1][st_x-1] = i;
        end_point.push_back(make_pair(en_x-1, en_y-1));
    }
}

int dx[4] = {0,-1,1,0};
int dy[4] = {-1,0,0,1};



bool find_end_bfs(int guest_num){
    int end_x = end_point[guest_num].first;
    int end_y = end_point[guest_num].second;

    queue<tuple<int,int,int>> q; // x,y,이동거리
    q.push(make_tuple(taxi_x, taxi_y, 0));
    vector<vector<bool>> visited(board_size, vector<bool>(board_size, false));
    visited[taxi_y][taxi_x] = true;

    while(!q.empty()){
        int now_x = get<0>(q.front());
        int now_y = get<1>(q.front());
        int move_value = get<2>(q.front());
        q.pop();

        // 만약 도착지에 왔다면
        if(end_x == now_x && end_y == now_y){
            if(fuel >= move_value){
                fuel += move_value;
                taxi_x = now_x;
                taxi_y = now_y;
                return true;
            } else {
                return false;
            }
        }

        for(int i=0; i<4; i++){
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if(next_x < 0 || next_y < 0 || next_x >= board_size || next_y >= board_size || visited[next_y][next_x])
                continue;
            
            if(board[next_y][next_x] == 0){
                q.push(make_tuple(next_x, next_y, move_value+1));
                visited[next_y][next_x] = true;
            }
        }
    }
    return false;
}


bool find_guest_bfs(){
    queue<tuple<int,int,int>> q; // x,y,이동거리
    q.push(make_tuple(taxi_x, taxi_y, 0));
    vector<vector<bool>> visited(board_size, vector<bool>(board_size, false));
    visited[taxi_y][taxi_x] = true;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>min_guest;
    int min_dis = INT_MAX;

    while(!q.empty()){
        int now_x = get<0>(q.front());
        int now_y = get<1>(q.front());
        int move_value = get<2>(q.front());
        q.pop();
        // 만약 남은 연료보다 먼곳이라면
        if(move_value > fuel || move_value > min_dis)
            continue;
        
        // 만약 손님을 만났다면
        if(start_point[now_y][now_x] != 0){
            min_dis = move_value;
            min_guest.push(make_pair(now_y, now_x));
            continue;
        }

        for(int i=0; i<4; i++){
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if(next_x < 0 || next_y < 0 || next_x >= board_size || next_y >= board_size || visited[next_y][next_x])
                continue;
            
            if(board[next_y][next_x] == 0){
                q.push(make_tuple(next_x, next_y, move_value+1));
                visited[next_y][next_x] = true;
            }
        }
    }

    // 손님을 만날 연료가 충분하다면
    if(fuel > min_dis){
        fuel -= min_dis;
        taxi_y = min_guest.top().first;
        taxi_x = min_guest.top().second;
        int guest_index = start_point[taxi_y][taxi_x];
        start_point[taxi_y][taxi_x] = 0;
        if(!find_end_bfs(guest_index)){
            cout << "-1" << "\n";
            return false;
        }
        return true;
    } else {
        cout << "-1" << "\n";
        return false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    basic_input();
    bool is_pass = true;
    for(int i=0; i<guest_num; i++){
        if(!find_guest_bfs()){
            is_pass = false;
            break;
        }
    }

    if(is_pass){
        cout << fuel << "\n";
    }
    
    return 0;
}