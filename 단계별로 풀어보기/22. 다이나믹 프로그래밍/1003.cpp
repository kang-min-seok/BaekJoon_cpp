#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    pair<int, int> dp[41];
    dp[0] = {1,0};
    dp[1] = {0,1};
    dp[2] = {1,1};
    int temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        for(int j=3; j<=temp; j++){
            dp[j].first = dp[j-1].first + dp[j-2].first;
            dp[j].second = dp[j-1].second + dp[j-2].second;
        }
        cout << dp[temp].first << " " << dp[temp].second << '\n';
    }
    return 0;
}



// 인터넷 정답 보고 영감을 얻어서 내가 다시 수정한 풀이
// dp값을 미리 40까지 다 구해놓고 그냥 꺼내서 출력하기만 하면 되는 코드
// 기존 코드는 값을 입력할때마다 dp[temp]의 값을 계속 구하는 바텀업 알고리즘이 돌았음
// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n;
//     cin >> n;
//     pair<int, int> dp[41];
//     dp[0] = {1,0};
//     dp[1] = {0,1};
//     dp[2] = {1,1};
//     for(int j=3; j<=40; j++){
//         dp[j].first = dp[j-1].first + dp[j-2].first;
//         dp[j].second = dp[j-1].second + dp[j-2].second;
//     }
//     int temp;
//     for(int i=0; i<n; i++){
//         cin >> temp;
//         cout << dp[temp].first << " " << dp[temp].second << '\n';
//     }
//     return 0;
// }