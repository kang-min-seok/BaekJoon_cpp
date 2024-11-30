// 백트래킹
// 이거 좀 많이 어려웠음
// 로직 자체는 어렵지않게 만들었는데 시간초과 자꾸나서 질문이랑 힌트 많이 찾아봄
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int stick_num, bridge_num, height_num;

// [시작라인].first = 도착라인 [시작라인].second = 높이
vector<vector<pair<int,int>>> bridge_connect; 
// [시작라인][높이] =연결여부
// 만약 시작라인이 2이고 높이가 1인곳에 다리를 놨다면
// 시작라인이 1 또는 3이고 높이가 1인 다리는 못놓아야 함
vector<vector<bool>> is_connect;

void basic_input(){
    cin >> stick_num >> bridge_num >> height_num;

    bridge_connect.resize(stick_num+1);
    is_connect.resize(stick_num+1, vector<bool>(height_num+1, false));
    for(int i=0; i<bridge_num; i++){
        int height, start;
        cin >> height >> start;
        is_connect[start][height] = true;
        bridge_connect[start].push_back(make_pair(start+1, height));
        bridge_connect[start+1].push_back(make_pair(start, height));
    }
}

bool arrive_chk(int point){
    int temp_point = point;
    for(int i=1; i<=height_num; i++){
        // 연결된 가로선 없으면 안돌음
        for(auto &edge: bridge_connect[point]){
            if(edge.second == i){
                point = edge.first;
            }
        }
    }
    return temp_point == point;
}


// 한개씩 가로선을 가능한만큼 다 놔봐.
// 그럼에도 종료가 안된다면 두개씩 가로선을 가능한만큼 다 놔바.
// 그럼에도 종료가 안된다면 세개씩 가로선을 가능한만큼 다 놔바.
// 그래도 안되면 -1출력

int result = INT_MAX;
void backtracking(int max_line_num, int now_line_num, int now_line){
    if(max_line_num == now_line_num){
        bool is_pass = true;
        for(int i=1; i<= stick_num; i++){
            if(!arrive_chk(i)){
                is_pass = false;
                break;
            }
        }
        if(is_pass){
            result = max_line_num;
        }
        return;
    }
    
    
    for(int i=now_line; i<stick_num; i++){ // 여기서 시간초과 판가름남
        for(int j=1; j<=height_num; j++){
            if(!is_connect[i-1][j] && !is_connect[i+1][j] && !is_connect[i][j]){
                is_connect[i][j] = true;
                bridge_connect[i].push_back(make_pair(i+1, j));
                bridge_connect[i+1].push_back(make_pair(i, j));
                backtracking(max_line_num, now_line_num+1,i);
                is_connect[i][j] = false;
                bridge_connect[i].pop_back();
                bridge_connect[i+1].pop_back();
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

    bool is_fail = true;
    for(int i=0; i<=3; i++){
        backtracking(i,0,1);
        if(result != INT_MAX){
            cout << result << "\n";
            is_fail = false;
            break;
        }
    }
    if(is_fail){
        cout << "-1" << "\n";
    }

    return 0;
}