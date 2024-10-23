#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <deque>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int meeting_num;
    cin >> meeting_num;

    vector<pair<int,int>> meeting_vector;
    for(int i=0; i<meeting_num; i++){
        int start_time, end_time;
        cin >> start_time >> end_time;
        meeting_vector.push_back(make_pair(start_time,end_time));
    }

    // 끝나는 순서가 작은 순서대로 정렬
     sort(meeting_vector.begin(), meeting_vector.end(), 
              [](const pair<int, int>& a, const pair<int, int>& b) {
                  if (a.second == b.second) {
                      return a.first < b.first;  // 두 번째 인자가 같으면 첫 번째 인자 비교
                  }
                  return a.second < b.second;   // 두 번째 인자를 우선적으로 비교
              });
              
    // 초기값으로 마감시간, 총갯수 저장
    int finish_time=0, total_meeting=1;
    finish_time = meeting_vector[0].second;
    // 끝나는 순서가 작은거 부터 반복
    for(int i=1; i<meeting_vector.size(); i++){
        // 그 뒤로 쭉 검사하면서 선택 회의의 시작시간이 저장된 마감시간보다 크거나 같다면
        // 선택 회의의 시작시간을 마감시간으로 저장하고 총갯수 +1
        if(meeting_vector[i].first >= finish_time){
            total_meeting += 1;
            finish_time = meeting_vector[i].second;
        }
    }
    
    cout << total_meeting << "\n";
    // 이대로 쭉 가서 회의 끝까지 가면 정답

    return 0;
}


// 내 기존 코드랑 똑같지만 정렬코드가 다름
// GPT가 알려준 복잡한 코드 쓰다가 간단한 코드 발견해서 바꿈
// #include <iostream>
// #include <vector>
// #include <stack>
// #include <algorithm>
// #include <deque>
// using namespace std;


// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int meeting_num;
//     cin >> meeting_num;

//     vector<pair<int,int>> meeting_vector;
//     for(int i=0; i<meeting_num; i++){
//         int start_time, end_time;
//         cin >> start_time >> end_time;
//         meeting_vector.push_back(make_pair(end_time,start_time));
//     }

//     // 끝나는 순서가 작은 순서대로 정렬
//     // 이렇게 sort하면 우선 first를 기준으로 오름차순 정렬하고
//     // first가 같은게 있으면 second를 오름차순 정렬함
//      sort(meeting_vector.begin(), meeting_vector.end());
              
//     // 초기값으로 마감시간, 총갯수 저장
//     int finish_time=0, total_meeting=1;
//     finish_time = meeting_vector[0].first;
//     // 끝나는 순서가 작은거 부터 반복
//     for(int i=1; i<meeting_vector.size(); i++){
//         // 그 뒤로 쭉 검사하면서 선택 회의의 시작시간이 저장된 마감시간보다 크거나 같다면
//         // 선택 회의의 시작시간을 마감시간으로 저장하고 총갯수 +1
//         if(meeting_vector[i].second >= finish_time){
//             total_meeting += 1;
//             finish_time = meeting_vector[i].first;
//         }
//     }
    
//     cout << total_meeting << "\n";
//     // 이대로 쭉 가서 회의 끝까지 가면 정답

//     return 0;
// }
