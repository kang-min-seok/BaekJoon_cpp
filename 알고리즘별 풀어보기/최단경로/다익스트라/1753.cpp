#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int point, line;
    cin >> point >> line;
    int start;
    cin >> start;

    // 간선 연결 여부 벡터
    vector<vector<pair<int, int>>> line_vec(point + 1);
    // 시작점부터의 거리 저장하는 벡터 (-1 이라면 무제한 즉 INF)
    vector<int>point_vec(point+1, -1);
    // 다익스트라를 실행시킬 최소힙 우선순위 큐 (거리, 위치)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue_min;

    // 간선정보 입력
    for (int i = 0; i < line; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;

        // 간선의 최솟값만을 저장하기 위해 중복 간선을 확인
        bool found = false;
        for (auto &edge : line_vec[start]) {
            if (edge.first == end) { // 이미 간선이 있는 경우
                if (edge.second > cost) {
                    edge.second = cost; // 최소 비용으로 업데이트
                }
                found = true;
                break;
            }
        }
        if (!found) {
            // 중복 간선이 없으면 새 간선 추가
            line_vec[start].push_back({end, cost});
        }
    }

    // 초기값 세팅
    point_vec[start] = 0;
    queue_min.push(make_pair(point_vec[start],start));

    while(!queue_min.empty()){
        // 현재 거리
        int now_distance = queue_min.top().first;
        // 현재위치
        int now = queue_min.top().second;
        queue_min.pop();

        if (now_distance > point_vec[now]) continue;

        // 현재위치로 부터 연결된 간선을 전부 방문하고 최솟값이 되는 값만 저장
        for (auto &edge : line_vec[now]) {
            int next = edge.first;
            int cost = edge.second;

            // 만약 거리가 무한이거나 더 짧은 거리로 업데이트 가능하면 업데이트
            if (point_vec[next] == -1 || point_vec[next] > point_vec[now] + cost) {
                point_vec[next] = point_vec[now] + cost;
                
                queue_min.push(make_pair(point_vec[next], next));
                
            }
        }
    }

    for(int i=1; i<=point; i++){
        if(point_vec[i] == -1){
            cout << "INF" << "\n";
        } else {
            cout << point_vec[i] << "\n";
        }
        
    }

    return 0;
}


// #include <iostream>
// #include <vector>
// #include <queue>
// #include <limits.h> // INT_MAX 사용을 위해 추가
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(0);

//     int point, line;
//     cin >> point >> line;
//     int start;
//     cin >> start;

//     vector<vector<pair<int, int>>> line_vec(point + 1);
//     vector<int> point_vec(point + 1, INT_MAX); // 초기 무한대 값 설정

//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue_min;

//     // 간선정보 입력
//     for (int i = 0; i < line; i++) {
//         int start, end, cost;
//         cin >> start >> end >> cost;
//         line_vec[start].push_back({end, cost});
//     }

//     // 초기값 세팅
//     point_vec[start] = 0;
//     queue_min.push(make_pair(0, start));

//     while (!queue_min.empty()) {
//         int now_distance = queue_min.top().first;
//         int now = queue_min.top().second;
//         queue_min.pop();

//         for (auto &edge : line_vec[now]) {
//             int next = edge.first;
//             int cost = edge.second;

//             if (point_vec[next] > point_vec[now] + cost) {
//                 point_vec[next] = point_vec[now] + cost;
//                 queue_min.push(make_pair(point_vec[next], next));
//             }
//         }
//     }

//     for (int i = 1; i <= point; i++) {
//         if (point_vec[i] == INT_MAX) {
//             cout << "INF" << "\n";
//         } else {
//             cout << point_vec[i] << "\n";
//         }
//     }

//     return 0;
// }