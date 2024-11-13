#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int point, line, goal_point;
    cin >> point >> line >> goal_point;

    // 다익스트라를 실행시킬 최소힙 우선순위 큐 (거리, 위치)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue_min;

    vector<vector<pair<int,int>>> road_vec(point+1);
    vector<int>return_point_vec(point+1, INT_MAX);

    for(int i=0; i<line; i++){
        int start, end, cost;
        cin >> start >> end >> cost;
        road_vec[start].push_back(make_pair(end, cost));
    }

    return_point_vec[goal_point] = 0;
    queue_min.push(make_pair(0, goal_point));

    // 파티지점으로 부터 각 지점으로 되돌아가는 최소거리 
    while(!queue_min.empty()){
        int now_cost = queue_min.top().first;
        int now_point = queue_min.top().second;
        queue_min.pop();
        for(auto &edge : road_vec[now_point]){
            int next_point = edge.first;
            int next_cost = edge.second;
            if(return_point_vec[next_point] > return_point_vec[now_point] + next_cost){
                return_point_vec[next_point] = return_point_vec[now_point] + next_cost;
                queue_min.push(make_pair(return_point_vec[now_point] + next_cost, next_point));
            }
        }
    }

    

    vector<int>party_point_vec(point+1, INT_MAX); // 각 지점마다 최솟값을 저장할 벡터

    
    // 각 지점으로 부텀 파티지점으로 가는 최소거리
    for(int i=1; i<=point; i++){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue_party;
        vector<int>point_vec(point+1, INT_MAX); // 다익스트라를 실행할 벡터
        point_vec[i] = 0;
        queue_party.push(make_pair(0, i));
        while(!queue_party.empty()){
            int now_cost = queue_party.top().first;
            int now_point = queue_party.top().second;
            if(now_point == goal_point){
                party_point_vec[i] = point_vec[now_point];
                break;
            }
            queue_party.pop();
            for(auto &edge : road_vec[now_point]){
                int next_point = edge.first;
                int next_cost = edge.second;
                if(point_vec[next_point] > point_vec[now_point] + next_cost){
                    point_vec[next_point] = point_vec[now_point] + next_cost;
                    queue_party.push(make_pair(point_vec[now_point] + next_cost, next_point));
                }
            }
        }  
    }
    
    int result = 0;

    for(int i=1; i<=point; i++){
        if(return_point_vec[i] + party_point_vec[i] > result){
            result = return_point_vec[i] + party_point_vec[i];
        }
    }
    cout << result << "\n";

    return 0;
}



// 정답 코드보고 영감을 받은 뒤 내가 짠 코드
// 다익스트라를 역방향으로 진행하는 기가막힌 방법
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <limits.h>
// using namespace std;

// vector<int> daikstra(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q, vector<vector<pair<int,int>>> road, vector<int>p_vec){
//     while(!q.empty()){
//         int now_cost = q.top().first;
//         int now_point = q.top().second;
//         q.pop();
//         for(auto &edge : road[now_point]){
//             int next_point = edge.first;
//             int next_cost = edge.second;
//             if(p_vec[next_point] > p_vec[now_point] + next_cost){
//                 p_vec[next_point] = p_vec[now_point] + next_cost;
//                 q.push(make_pair(p_vec[now_point] + next_cost, next_point));
//             }
//         }
//     }
//     return p_vec;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(0);

//     int point, line, goal_point;
//     cin >> point >> line >> goal_point;

//     // 다익스트라를 실행시킬 최소힙 우선순위 큐 (거리, 위치)
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue_party;
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue_min;

//     vector<vector<pair<int,int>>> road_vec(point+1);
//     vector<vector<pair<int,int>>> return_road_vec(point+1);

//     vector<int>point_vec(point+1, INT_MAX);
//     vector<int>return_point_vec(point+1, INT_MAX);

//     for(int i=0; i<line; i++){
//         int start, end, cost;
//         cin >> start >> end >> cost;
//         road_vec[start].push_back(make_pair(end, cost));
//         return_road_vec[end].push_back(make_pair(start, cost));
//     }
    
//     point_vec[goal_point] = 0;
//     return_point_vec[goal_point] = 0;

//     queue_min.push(make_pair(0, goal_point));
//     queue_party.push(make_pair(0, goal_point));

//     // 파티지점으로 부터 각 지점으로 되돌아가는 최소거리 
    
    
//     point_vec = daikstra(queue_min, road_vec, point_vec);
//     return_point_vec = daikstra(queue_party, return_road_vec, return_point_vec);
    
    
//     int result = 0;

//     for(int i=1; i<=point; i++){
//         if(point_vec[i] + return_point_vec[i] > result){
//             result = point_vec[i] + return_point_vec[i];
//         }
//     }
//     cout << result << "\n";

//     return 0;
// }