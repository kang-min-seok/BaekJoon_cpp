// 열심히 풀다가 완벽한거 같은데 계속 시간초과 나길래 뭐지 싶었는데
// bfs로 풀면 안되고 벨만포드 알고리즘이란걸 써야했음
// 삽질만 했음
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


bool bfs(int start, int point_num, vector<vector<int>>road_vec, vector<vector<int>>hole_vec){
    vector<int>point_vec(point_num+1, 0);
    vector<bool>visited_vec(point_num+1, false);
    queue<int>point_queue;
    point_queue.push(start);
    while(!point_queue.empty()){
        int now = point_queue.front();
        int now_time = point_vec[now];
        if(now == start && now_time < 0){
            return false;
        }
        point_queue.pop();
        for(int i=1; i<=point_num; i++){
            // 웜홀이 이어져있고 && 웜홀을 이동했을때 기존값보다 작아짐 || 방문안함
            if((point_vec[i] > now_time - hole_vec[now][i] || !visited_vec[i]) && hole_vec[now][i] != -1){
                point_vec[i] = point_vec[now] - hole_vec[now][i];
                visited_vec[i] = true;
                point_queue.push(i);
            }
            // 도로가 이어져있고 && 도로를 이동했을때 기존값보다 작아짐 || 방문안함
            if((point_vec[i] > now_time + road_vec[now][i] || !visited_vec[i]) && road_vec[now][i] != -1){
                point_vec[i] = point_vec[now] + road_vec[now][i];
                visited_vec[i] = true;
                point_queue.push(i);
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test_case;
    cin >> test_case;

    for(int i=0; i<test_case; i++){
        int point_num, road_num, hole_num;
        cin >> point_num >> road_num >> hole_num;
        // 도로 연결 여부 벡터
        vector<vector<int>>road_vec(point_num+1, vector<int>(point_num+1, -1));
        // 웜홀 연결 여부 벡터 (웜홀은 상관없이 그냥 통과 계속 해야함)
        vector<vector<int>>hole_vec(point_num+1, vector<int>(point_num+1, -1));

        // 도로 연결하기
        for(int j=0; j<road_num; j++){
            int start, end, time;
            cin >> start >> end >> time;
            // 도로는 짧을 수록 이득
            if(road_vec[start][end] == -1 || road_vec[start][end] > time){
                road_vec[start][end] = time;
                road_vec[end][start] = time;
            }
            
        }
        // 웜홀 연결하기
        for(int j=0; j<hole_num; j++){
            int start, end, time;
            cin >> start >> end >> time;
            // 웜홀은 길수록 이득
            if(hole_vec[start][end] == -1 || hole_vec[start][end] < time){
                hole_vec[start][end] = time;
            }
        }
        bool is_yes = false;
        for(int j=1; j<=point_num; j++){

            if(!bfs(j, point_num, road_vec, hole_vec)){
                cout << "YES" << "\n";
                is_yes = true;
                break;
            }
        }
        if(!is_yes){
            cout << "NO" << "\n";
        }


    }
    return 0;
}