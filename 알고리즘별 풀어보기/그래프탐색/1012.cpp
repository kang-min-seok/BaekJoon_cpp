#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;
    cin >> test_case;

    for(int i=0; i<test_case; i++){
        int width, height, cabbage_num;
        cin >> width >> height >> cabbage_num;

        vector<vector<int>> cabbage_vec(height, vector<int>(width, 0));
        vector<vector<bool>> cabbage_visited(height, vector<bool>(width, false));

        queue<pair<int,int>> cabbage_queue;

        // 배추 위치 입력
        for(int j=0; j<cabbage_num; j++){
            int x,y;
            cin >> x >> y;
            cabbage_vec[y][x] = 1;
        }

        int result = 0;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if(cabbage_vec[i][j] == 1 && cabbage_visited[i][j] == false){
                    result += 1;
                    cabbage_queue.push(make_pair(j,i));
                    while(!cabbage_queue.empty()){
                        int x = cabbage_queue.front().first;
                        int y = cabbage_queue.front().second;
                        cabbage_visited[y][x] = true;
                        cabbage_queue.pop();

                        pair<int,int> move_list[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
                        for(int i=0; i<4; i++){
                            int move_x = x + move_list[i].first;
                            int move_y = y + move_list[i].second;
                            if(move_x < 0 || move_y < 0 || move_x >= width || move_y >= height){
                                continue;
                            }
                            if(cabbage_vec[move_y][move_x] == 1 && cabbage_visited[move_y][move_x] == false) {
                                cabbage_visited[move_y][move_x] = true;
                                cabbage_queue.push(make_pair(move_x, move_y));
                            }
                        }
                    }

                }
            }
        }
        cout << result << "\n";
    }
    return 0;
}


// 난 queue로 구현했는데 이건
// 재귀로 bfs만들어서 푼 풀이
// #include <iostream>
// #include <string.h>
// using namespace std;
 
// int dy[4]={1,-1,0,0};
// int dx[4]={0,0,1,-1};
// int M,N,K;
// int arr[50][50]={0};
// int visited[50][50]={0};
 
// void dfs(int y,int x){
//     for(int i=0; i<4; i++){
//         int ny=y+dy[i];
//         int nx=x+dx[i];
//         //배열의 인덱스를 넘지 않도록
//         if(ny<0 || ny>=N || nx<0 || nx>=M)
//             continue;
//         //방문 x이고 배추 있다면 탐색 계속
//         if(arr[ny][nx] && !visited[ny][nx]){
//             visited[ny][nx]++;
//             dfs(ny,nx);
//         }
//     }
// }
 
// int main(){
//     int T,x,y;
//     scanf("%d", &T);
    
//     for(int testCase=0; testCase<T; testCase++){
//         scanf("%d %d %d", &M,&N,&K);
        
//         //초기화
//         memset(arr, 0, sizeof(arr));
//         memset(visited, 0, sizeof(visited));
        
//         int ans=0; //지렁이 개수
        
//         for(int i=0; i<K; i++){
//             scanf("%d %d", &x,&y);
//             arr[y][x]=1;
//         }
        
//         for(int i=0; i<N; i++)
//             for(int j=0; j<M; j++)
//                 if(arr[i][j] && !visited[i][j]){
//                     ans++;
//                     visited[i][j]++;
//                     dfs(i,j);
//                 }
//         printf("%d\n", ans);
//     }
// }