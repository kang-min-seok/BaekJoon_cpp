// map은 확인, 삽입, 삭제에서 평균적으로 log N의 시간복잡도가 발생해서 비효율적임
// 이런경우에는 그냥 배열 쓰는게 속도가 훨 빠름
#include <iostream>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;

vector<vector<char>>board_vec;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int width, height;
bool visit_vec[26] = {false,};
int result = 0;

void dfs(int x, int y, int cost){

    if(cost > result){
        result = cost;
    }

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= width || ny >= height)
            continue;
        // 만약 다음 방문할 곳의 값이 여지껏 없던 값이라면
        if(!visit_vec[(int)board_vec[ny][nx] - 65]){
            visit_vec[(int)board_vec[ny][nx] - 65] = true;
            dfs(nx,ny,cost+1);
            visit_vec[(int)board_vec[ny][nx] - 65] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width;

    board_vec.resize(height, vector<char>(width));
    
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            cin >> board_vec[i][j];
        }
    }

    visit_vec[(int)board_vec[0][0] - 65] = true;
    dfs(0,0,1);

    cout << result << "\n";

    return 0;
}


// #include <iostream>
// #include <stack>
// #include <tuple>
// #include <vector>
// #include <map>
// using namespace std;

// vector<vector<char>>board_vec;

// int dx[4] = {1,-1,0,0};
// int dy[4] = {0,0,1,-1};

// int width, height;

// map<char, bool>visit_map;
// int result = 0;

// void dfs(int x, int y, int cost){

//     if(cost > result){
//         result = cost;
//     }

//     for(int i=0; i<4; i++){
//         int nx = x + dx[i];
//         int ny = y + dy[i];
//         if(nx < 0 || ny < 0 || nx >= width || ny >= height)
//             continue;
//         // 만약 다음 방문할 곳의 값이 여지껏 없던 값이라면
//         if(!visit_map[board_vec[ny][nx]]){
//             visit_map[board_vec[ny][nx]] = true;
//             dfs(nx,ny,cost+1);
//             visit_map[board_vec[ny][nx]] = false;
//         }
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     cin >> height >> width;

//     board_vec.resize(height, vector<char>(width));
    
//     for(int i=0; i<height; i++){
//         for(int j=0; j<width; j++){
//             cin >> board_vec[i][j];
//         }
//     }

//     for(int i=65; i<=90; i++){
//         visit_map[char(i)] = false;
//     }


//     visit_map[board_vec[0][0]] = true;
//     dfs(0,0,1);

//     cout << result << "\n";

//     return 0;
// }