#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

long long A, B;
int result = -1;

unordered_set<long long>visited;
void bfs(){
    queue<pair<long long,int>>pq; // 현재위치, 연산수
    pq.push(make_pair(A,1));
    while(!pq.empty()){
        long long now = pq.front().first;
        int cal_num = pq.front().second;
        visited.insert(now);
        pq.pop();
        if(now > B){
            continue;
        }
        if(now == B){
            result = cal_num;
            break;
        }
        if(visited.find(now*2) == visited.end()){
            pq.push(make_pair(now*2, cal_num+1));
        }
        long long p_int = (now * 10) + 1;
        if(visited.find(p_int) == visited.end()){
            pq.push(make_pair(p_int, cal_num+1));
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;


    bfs();

    cout << result << "\n";
    return 0;
}



// 정답풀이 보고 수정한 코드
// 방문처리가 필요없는 문제였음
// #include <iostream>
// #include <queue>
// #include <vector>
// #include <string>
// using namespace std;

// long long A, B;
// int result = -1;

// void bfs(){
//     queue<pair<long long,int>>pq; // 현재위치, 연산수
//     pq.push(make_pair(A,1));
//     while(!pq.empty()){
//         long long now = pq.front().first;
//         int cal_num = pq.front().second;
//         pq.pop();
//         if(now == B){
//             result = cal_num;
//             break;
//         }
//         if(now*2 <= B){
//             pq.push(make_pair(now*2, cal_num+1));
//         }
//         long long p_int = (now * 10) + 1;
//         if(p_int <= B){
//             pq.push(make_pair(p_int, cal_num+1));
//         }

//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     cin >> A >> B;


//     bfs();

//     cout << result << "\n";
//     return 0;
// }
