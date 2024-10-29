#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<char>>RGB_field(n, vector<char>(n, ' '));
    vector<vector<char>>RB_field(n, vector<char>(n, ' '));

    vector<vector<bool>>RGB_visited(n, vector<bool>(n, false));
    vector<vector<bool>>RB_visited(n, vector<bool>(n, false));

    // 값 입력
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char temp;
            cin >> temp;
            RGB_field[i][j] = temp;
            if(temp == 'G'){
                RB_field[i][j] = 'R';
            } else {
                RB_field[i][j] = temp;
            }
        }
    }
    pair<int,int> move_list[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}}; 
    int RGB_result = 0;
    int RB_result = 0;
    // 메인 로직
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            queue<pair<int,int>>visit_queue;
            // 적록색약 아닌 경우 로직
            if(!RGB_visited[i][j]){
                RGB_result += 1;
                visit_queue.push(make_pair(i,j));
                while(!visit_queue.empty()){
                    int y = visit_queue.front().first;
                    int x = visit_queue.front().second;
                    visit_queue.pop();
                    for(int z=0; z<4; z++){
                        int next_x = x + move_list[z].first;
                        int next_y = y + move_list[z].second;
                        if(next_x < 0 || next_y < 0 || next_x >= n || next_y >= n)
                            continue;
                        if(RGB_field[i][j] == RGB_field[next_y][next_x] && !RGB_visited[next_y][next_x]){
                            visit_queue.push(make_pair(next_y, next_x));
                            RGB_visited[next_y][next_x] = true;
                        }
                    }
                }
            }

            // 적록색약인 경우 로직
            if(!RB_visited[i][j]){
                RB_result += 1;
                visit_queue.push(make_pair(i,j));
                while(!visit_queue.empty()){
                    int y = visit_queue.front().first;
                    int x = visit_queue.front().second;
                    visit_queue.pop();
                    for(int z=0; z<4; z++){
                        int next_x = x + move_list[z].first;
                        int next_y = y + move_list[z].second;
                        if(next_x < 0 || next_y < 0 || next_x >= n || next_y >= n)
                            continue;
                        if(RB_field[i][j] == RB_field[next_y][next_x] && !RB_visited[next_y][next_x]){
                            visit_queue.push(make_pair(next_y, next_x));
                            RB_visited[next_y][next_x] = true;
                        }
                    }
                }
            }
        }
    }
    

    cout << RGB_result << " " << RB_result << "\n";    

    return 0;
}
    



// 내가 푼 코드 리팩토링 한건데 12ms 느려짐
// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;


// pair<int,int> move_list[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}}; 

// vector<vector<bool>>bfs(int x_first, int y_first, int max, vector<vector<bool>>visited, vector<vector<char>>field){
//     queue<pair<int,int>>visit_queue;
//     visit_queue.push(make_pair(y_first,x_first));
//     while(!visit_queue.empty()){
//         int y = visit_queue.front().first;
//         int x = visit_queue.front().second;
//         visit_queue.pop();
//         for(int z=0; z<4; z++){
//             int next_x = x + move_list[z].first;
//             int next_y = y + move_list[z].second;
//             if(next_x < 0 || next_y < 0 || next_x >= max || next_y >= max)
//                 continue;
//             if(field[y_first][x_first] == field[next_y][next_x] && !visited[next_y][next_x]){
//                 visit_queue.push(make_pair(next_y, next_x));
//                 visited[next_y][next_x] = true;
//             }
//         }
//     }
//     return visited;
// }


// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     cin >> n;

//     vector<vector<char>>RGB_field(n, vector<char>(n, ' '));
//     vector<vector<char>>RB_field(n, vector<char>(n, ' '));

//     vector<vector<bool>>RGB_visited(n, vector<bool>(n, false));
//     vector<vector<bool>>RB_visited(n, vector<bool>(n, false));

//     // 값 입력
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             char temp;
//             cin >> temp;
//             RGB_field[i][j] = temp;
//             if(temp == 'G'){
//                 RB_field[i][j] = 'R';
//             } else {
//                 RB_field[i][j] = temp;
//             }
//         }
//     }

//     int RGB_result = 0;
//     int RB_result = 0;

//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             queue<pair<int,int>>visit_queue;
//             // 적록색약 아닌 경우
//             if(!RGB_visited[i][j]){
//                 RGB_result += 1;
//                 RGB_visited = bfs(j,i,n,RGB_visited,RGB_field);
//             }
//             // 적록색약인 경우
//             if(!RB_visited[i][j]){
//                 RB_result += 1;
//                 RB_visited = bfs(j,i,n,RB_visited,RB_field);
//             }
//         }
//     }
    
//     cout << RGB_result << " " << RB_result << "\n";    

//     return 0;
// }
    
