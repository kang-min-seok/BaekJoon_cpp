#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int dp[1001];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i=4; i<=1000; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }

    int temp;
    cin >> temp;
    
    cout << dp[temp] << '\n';
    
    return 0;
}