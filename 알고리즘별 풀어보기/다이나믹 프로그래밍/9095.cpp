#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int dp[12];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    // f(n)=f(n−1)+f(n−2)+f(n−3) 왜 이런식이 나오냐
    // 마지막에 1을 더한 경우라면 그 앞의 값은 f(n−1)임
    // 마지막에 2을 더한 경우라면 그 앞의 값은 f(n−2)임
    // 마지막에 3을 더한 경우라면 그 앞의 값은 f(n−3)임
    // 그래서 이런 점화식이 나옴
    for(int i=4; i<=11; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    int temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        
        cout << dp[temp] << '\n';
    }
    return 0;
}