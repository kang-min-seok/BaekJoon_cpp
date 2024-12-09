#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits.h>

using namespace std;

int height, width;
vector<vector<pair<int,int>>>parent;
vector<vector<int>>ranking;
vector<vector<char>> board;
vector<pair<int,int>> swan_position;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void basic_input(){
    cin >> height >> width;
    parent.resize(height, vector<pair<int,int>>(width));
    ranking.resize(height, vector<int>(width, 0));
    board.resize(height, vector<char>(width));

    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            cin >> board[i][j];
            parent[i][j] = make_pair(j,i);
            if(board[i][j] == 'L'){
                swan_position.push_back(make_pair(j,i));
            }
        }
    }

}

pair<int,int> find(pair<int,int>xy){
    int x = xy.first;
    int y = xy.second;
    if(parent[y][x] == make_pair(x,y)) return make_pair(x,y);
    
    return parent[y][x] = find(parent[y][x]);
}

void connect_swan(pair<int,int>xy1, pair<int,int>xy2){
    xy1 = find(xy1);
    xy2 = find(xy2);

    if(xy1 != xy2){
        if(ranking[xy1.second][xy1.first] > ranking[xy2.second][xy2.first]){
            parent[xy2.second][xy2.first] = xy1;
        } else {
            parent[xy1.second][xy1.first] = xy2;
            if(ranking[xy1.second][xy1.first] == ranking[xy2.second][xy2.first]){
                ranking[xy2.second][xy2.first]++;
            }
        }
    }
}

void bfs(){
    vector<vector<bool>>visited(height, vector<bool>(width, false));
    queue<pair<int,int>> connect_q;
    queue<pair<int,int>> next_q;
    int result = 0;

    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            if((board[i][j] == '.' || board[i][j] == 'L') && !visited[i][j]) {
                connect_q.push(make_pair(j,i));
                visited[i][j] = true;
                while(!connect_q.empty()){
                    int cx = connect_q.front().first;
                    int cy = connect_q.front().second;
                    connect_q.pop();
                    for(int p=0; p<4; p++){
                        int nx = cx + dx[p];
                        int ny = cy + dy[p];
                        if(nx < 0 || ny < 0 || nx >= width || ny >= height || visited[ny][nx])
                            continue;
                        if(board[ny][nx] == '.' || board[ny][nx] == 'L'){
                            visited[ny][nx] = true;
                            connect_swan(make_pair(nx,ny), make_pair(cx, cy));
                            connect_q.push(make_pair(nx,ny));
                        } else if(board[ny][nx] == 'X'){
                            next_q.push(make_pair(nx,ny));
                        }
                    }
                }
            }
        }
    }

    while(1){
        if(find(swan_position[0]) == find(swan_position[1])){
            cout << result << "\n";
            return;
        }
        result++;

        while(!next_q.empty()){
            connect_q.push(next_q.front());
            board[next_q.front().second][next_q.front().first] = '.';
            for(int p=0; p<4; p++){
                int nx = next_q.front().first + dx[p];
                int ny = next_q.front().second + dy[p];
                if(nx < 0 || ny < 0 || nx >= width || ny >= height)
                    continue;
                if(board[ny][nx] == '.' || board[ny][nx] == 'L'){
                    connect_swan(make_pair(nx,ny), make_pair(next_q.front().first, next_q.front().second));
                }
            }
            next_q.pop();
        }

        while(!connect_q.empty()){
            int cx = connect_q.front().first;
            int cy = connect_q.front().second;
            connect_q.pop();
            for(int p=0; p<4; p++){
                int nx = cx + dx[p];
                int ny = cy + dy[p];
                if(nx < 0 || ny < 0 || nx >= width || ny >= height || visited[ny][nx])
                    continue;
                
                if(board[ny][nx] == 'X' && !visited[ny][nx]){
                    next_q.push(make_pair(nx,ny));
                    visited[ny][nx] = true;
                }
            }
        }
    }

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    basic_input();

    bfs();

    return 0;
}