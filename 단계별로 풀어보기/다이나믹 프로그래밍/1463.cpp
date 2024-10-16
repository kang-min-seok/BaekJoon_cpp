#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    // 인풋 최댓값만큼 배열 생성
    vector<int>dp(1000001);

    // 기본값은 미리 넣어놓기
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;

    // dp[n]안의 값은 1부터 시작해서 +1, *2, *3을 해나갔을때
    // n이 될 수 있는 최솟값이 들어감
    // 예를 들어 5 -> 6으로 갈때 +1을 하면 기본적으로 갈 수 있음
    // 그런데 6이 2로 나누어지거나 3으로 나누어지면 나눠서 최솟값 계산
    for(int i=4; i<=n;i++){
        dp[i] = dp[i-1] +1;
        if(i%2==0) dp[i] = min(dp[i],dp[i/2]+1);
        if(i%3==0) dp[i] = min(dp[i],dp[i/3]+1);
    }
    cout << dp[n] << '\n';
    return 0;
}