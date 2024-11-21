// 다이나믹 프로그래밍
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 각 층별로 방문했을때 다음층에 최댓값을 계속 갱신해나가는 방식

    int n;
    cin >> n;

    // 상담 걸리는 시간 벡터
    vector<int> time_vec(n);
    // 상담 시 받을 수 있는 돈 벡터
    vector<int> money_vec(n);
    // 각 층별로 방문했을때 돈 최댓값 저장하는 벡터
    vector<int> max_money(n+1, 0);

    for(int i=0; i<n; i++){
        int time, money;
        cin >> time >> money;
        time_vec[i] = time;
        money_vec[i] = money;
    }

    for(int i=0; i<n; i++){
        if(time_vec[i] == 1){
            max_money[i] += money_vec[i];
            for(int j = i+1; j<=n; j++){
                if(max_money[i]>max_money[j]){
                    max_money[j] = max_money[i];
                }
            } 
        }
        else if(i + time_vec[i] <= n){
            int next_money = max_money[i] + money_vec[i];
            for(int j=i + time_vec[i]; j<=n; j++){
                if(next_money > max_money[j]){
                    max_money[j] = next_money;
                }
            }
        }


    }

    int result = 0;
    for(int i=0; i<=n; i++){
        if(max_money[i] > result){
            result = max_money[i];
        }
    }
    cout << result << "\n";


    return 0;
}