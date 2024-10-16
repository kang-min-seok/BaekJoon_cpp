#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    // 2차원 배열 생성
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    int temp;
    // 높이 만큼 반복하고 
    // 2중으로 꼭대기에서는 한번 한칸씩 내려갈 수록 한번씩 더해서 반복
    // 칸에 입력값 더하고 그 아랫칸 두개에 입력값 삽입
    // 단, 이미 더큰 값이 있다면 삽입 안함
    for(int i=0; i<n; i++){ 
        for(int j=0; j<i+1; j++){
            cin >> temp;
            dp[i][j] += temp;
            if(dp[i][j] > dp[i+1][j]){
                dp[i+1][j] = dp[i][j];
            }
            if(dp[i][j] > dp[i+1][j+1]){
                dp[i+1][j+1] = dp[i][j];
            }
        }

    }
    // 위 과정 다 거치고 맨 아랫줄에서 최댓값 찾으면 정답
    int max = 0;
    for (int i = 0; i < n; i++) {
        if(dp[n][i] > max){
            max= dp[n][i];
        }
    }
    cout << max << '\n';
    return 0;
}