#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;


int point, line;

// 목표지점, 시작지점, 간선벡터
int daikstra(int v, int start_point, vector<vector<pair<int,int>>> &line_vec){
    // 다익스트라를 실행시킬 최소힙 우선순위 큐 (거리, 위치)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue_min;

    vector<int>point_vec(point+1, INT_MAX);

    queue_min.push(make_pair(0, start_point));
    point_vec[start_point] = 0;

    while(!queue_min.empty()){
        int now_cost = queue_min.top().first;
        int now_point = queue_min.top().second;
        queue_min.pop();

        if(now_point == v){
            return now_cost;
        }
        for(auto &edge : line_vec[now_point]){
            int next_point = edge.first;
            int next_cost = edge.second;

            if(point_vec[next_point] > point_vec[now_point] + next_cost){
                point_vec[next_point] = point_vec[now_point] + next_cost;
                queue_min.push(make_pair(point_vec[now_point] + next_cost, next_point));
            }
        }
    }

    return -1;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    cin >> point >> line;

    vector<vector<pair<int,int>>> line_vec(point+1);

    for(int i=0; i<line; i++){
        int start, end, cost;
        cin >> start >> end >> cost;
        line_vec[start].push_back(make_pair(end, cost));
        line_vec[end].push_back(make_pair(start, cost));
    }

    // 중간에 경유 해야할 포인트
    int v1, v2;
    cin >> v1 >> v2;

    int v1_cost1 = daikstra(v1, 1, line_vec);
    int v2_cost1 = daikstra(v2, 1, line_vec);
    
    int v1_cost2 = daikstra(v2, v1, line_vec);
    int v2_cost2 = daikstra(v1, v2, line_vec);

    int v1_cost3 = daikstra(point, v2, line_vec);
    int v2_cost3 = daikstra(point, v1, line_vec);

    int v1_result = v1_cost1 + v1_cost2 + v1_cost3;
    int v2_result = v2_cost1 + v2_cost2 + v2_cost3;


    bool v1_fail = v1_cost1 == -1 || v1_cost2 == -1 || v1_cost3 == -1;
    bool v2_fail = v2_cost1 == -1 || v2_cost2 == -1 || v2_cost3 == -1;

    if(v1_fail && v2_fail) {
        cout << "-1" << "\n";
    } else if(v1_fail && !v2_fail) {
        cout << v2_result << "\n";
    } else if(!v1_fail && v2_fail) {
        cout << v1_result << "\n";
    } else {
        if(v1_result > v2_result){
            cout << v2_result << "\n";
        } else {
            cout << v1_result << "\n";
        }
    }
    
    return 0;
}


// 인터넷 정답보고 내가 다시 짠 코드인데 위에 코드보다 효율 떨어짐
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <limits.h>
// using namespace std;


// int point, line;

// // 목표지점, 시작지점, 간선벡터
// int goal_daikstra(int v, int start_point, vector<vector<pair<int,int>>> &line_vec){
//     // 다익스트라를 실행시킬 최소힙 우선순위 큐 (거리, 위치)
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue_min;

//     vector<int>point_vec(point+1, INT_MAX);

//     queue_min.push(make_pair(0, start_point));
//     point_vec[start_point] = 0;

//     while(!queue_min.empty()){
//         int now_cost = queue_min.top().first;
//         int now_point = queue_min.top().second;
//         queue_min.pop();

//         if(now_point == v){
//             return now_cost;
//         }
//         for(auto &edge : line_vec[now_point]){
//             int next_point = edge.first;
//             int next_cost = edge.second;

//             if(point_vec[next_point] > point_vec[now_point] + next_cost){
//                 point_vec[next_point] = point_vec[now_point] + next_cost;
//                 queue_min.push(make_pair(point_vec[now_point] + next_cost, next_point));
//             }
//         }
//     }

//     return -1;

// }

// // 목표지점, 시작지점, 간선벡터
// vector<int> daikstra(int v, int start_point, vector<vector<pair<int,int>>> &line_vec){
//     // 다익스트라를 실행시킬 최소힙 우선순위 큐 (거리, 위치)
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue_min;

//     vector<int>point_vec(point+1, INT_MAX);

//     queue_min.push(make_pair(0, start_point));
//     point_vec[start_point] = 0;

//     while(!queue_min.empty()){
//         int now_cost = queue_min.top().first;
//         int now_point = queue_min.top().second;
//         queue_min.pop();

//         for(auto &edge : line_vec[now_point]){
//             int next_point = edge.first;
//             int next_cost = edge.second;

//             if(point_vec[next_point] > point_vec[now_point] + next_cost){
//                 point_vec[next_point] = point_vec[now_point] + next_cost;
//                 queue_min.push(make_pair(point_vec[now_point] + next_cost, next_point));
//             }
//         }
//     }

//     return point_vec;

// }


// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(0);

//     cin >> point >> line;

//     vector<vector<pair<int,int>>> line_vec(point+1);

//     for(int i=0; i<line; i++){
//         int start, end, cost;
//         cin >> start >> end >> cost;
//         line_vec[start].push_back(make_pair(end, cost));
//         line_vec[end].push_back(make_pair(start, cost));
//     }

//     // 중간에 경유 해야할 포인트
//     int v1, v2;
//     cin >> v1 >> v2;

//     vector<int>point_vec = daikstra(point, 1, line_vec);
    
//     int v1_first = point_vec[v1];
//     int v2_first = point_vec[v2];
//     int between = goal_daikstra(v1, v2, line_vec);
//     int v1_second = goal_daikstra(point, v1, line_vec);
//     int v2_second = goal_daikstra(point, v2, line_vec);




//     bool v1_fail = (v1_first == INT_MAX || v2_second == -1);
//     bool v2_fail = (v2_first == INT_MAX || v1_second == -1);
//     bool between_fail = (between == -1);

//     if((v1_fail && v2_fail) || between_fail) {
//         cout << "-1" << "\n";
//     } else if(v1_fail && !v2_fail) {
//         cout << v2_first + v1_second + between << "\n";
//     } else if(!v1_fail && v2_fail) {
//         cout << v1_first + v2_second + between << "\n";
//     } else {
//         if(v1_first + v2_second > v2_first + v1_second){
//             cout << v2_first + v1_second + between << "\n";
//         } else {
//             cout << v1_first + v2_second + between << "\n";
//         }
//     }
    
//     return 0;
// }
