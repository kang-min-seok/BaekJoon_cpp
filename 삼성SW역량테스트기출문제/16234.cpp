#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>
using namespace std;

int N,L,R;

int world[54][54] = {0};
bool visited[54][54] = {false};

void basic_input(){
    cin >> N >> L >> R;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> world[i][j];
        }
    }
}

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int union_add=0;
int union_num = 1;
vector<pair<int,int>> union_vec;


bool bfs(int start_x, int start_y){
    queue<pair<int,int>> q;
    q.push(make_pair(start_x, start_y));
    visited[start_y][start_x] = true;

    union_add=0;
    union_num = 1;
    union_vec.clear();
    

    union_add += world[start_y][start_x];
    union_vec.push_back(make_pair(start_x, start_y));


    while(!q.empty()){
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= N)
                continue;
            int diff = abs(world[now_y][now_x] - world[next_y][next_x]);
            if(L <= diff && diff <= R && !visited[next_y][next_x]){
                visited[next_y][next_x] = true;
                q.push(make_pair(next_x, next_y));
                union_add += world[next_y][next_x];
                union_num++;
                union_vec.push_back(make_pair(next_x, next_y));
            }
        }
    }
    union_add /= union_num;
    for(auto &u : union_vec){
        world[u.second][u.first] = union_add;
    }
    return !(union_num == 1);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    basic_input();

    int result = 0;
    while(true){
        bool is_finish = true;
		memset(visited, false, sizeof(visited));
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(!visited[i][j]){
                    if(bfs(j,i)){
                        is_finish = false;
                    }
                }
            }
        }
        if(is_finish){
            break;
        }
        result++;
    }
    
    cout << result << "\n";

    return 0;
}