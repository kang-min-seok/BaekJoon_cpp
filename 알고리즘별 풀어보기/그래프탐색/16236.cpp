#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <map>
using namespace std;

int shark_size = 2;
int eat_size = 0;
int n;
vector<vector<int>>space;

pair<pair<int,int>,int> bfs(int start_x, int start_y){
    queue<pair<pair<int,int>, int>> q; // x,y
    q.push(make_pair(make_pair(start_x, start_y), 0));
    vector<vector<bool>>visited(n, vector<bool>(n, false));
    visited[start_y][start_x] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int dx[4] = {0,-1,1,0};
    int dy[4] = {-1,0,0,1};

    int sec_min = INT_MAX;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int sec = q.front().second;
        q.pop();
        if(sec >= sec_min){
            continue;
        }
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >=n || ny >= n)
                continue;
            
            // 만약 상어가 움직일 수 있다면 
            if(shark_size >= space[ny][nx] && !visited[ny][nx]){
                visited[ny][nx] = true;
                // 만약 상어가 먹을 수 있다면
                if(shark_size > space[ny][nx] &&  space[ny][nx] != 0){
                    pq.push(make_pair(ny,nx)); // 최솟값 좌표 저장
                    sec_min = sec + 1; // 최솟값 저장
                    
                } else {
                    q.push(make_pair(make_pair(nx, ny),sec+1));
                }
            }
        }
    }

    if(sec_min == INT_MAX){
        return make_pair(make_pair(0, 0),0);
    } else {
        space[pq.top().first][pq.top().second] = 0; // 물고기 0으로 치환
        eat_size += 1; // 먹은 물고기 수 저장
        if(eat_size == shark_size){ // 만약 상어 크기만큼 물고기 먹었으면 레벨업
            shark_size += 1;
            eat_size = 0;
        }
        return make_pair(make_pair(pq.top().second, pq.top().first), sec_min);
    }
}
    



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    space.resize(n, vector<int>(n));
    pair<int,int> first_shark; // x,y

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp;
            cin >> temp;
            space[i][j] = temp;
            if(temp == 9){
                first_shark = make_pair(j,i);
                space[i][j] = 0;
            }
        }
    }

    int cal_x = first_shark.first;
    int cal_y = first_shark.second;
    int result_sec = 0;
    

    while(1){
        pair<pair<int,int>,int> next_eat = bfs(cal_x, cal_y);
        cal_x = next_eat.first.first;
        cal_y = next_eat.first.second;
        int next_sec = next_eat.second;

        if(next_sec == 0){
            break;
        }
        result_sec += next_sec;
    }

    
    cout << result_sec << "\n";
    
    
    return 0;
}