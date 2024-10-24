#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    map<int, int>num_dp; // 숫자, 스택

    // 초기값 세팅
    int temp;
    cin >> temp;
    num_dp[temp] = 1;

    for(int i=1; i<n; i++){
        cin >> temp;
        int max_stack=0;
        for(auto it = num_dp.begin(); it != num_dp.end(); ++it){
            if(temp > it->first && it->second > max_stack ){
                max_stack = it->second;
            }
        }
        max_stack += 1;
        num_dp[temp] = max_stack;
        
    }

    int result=0;
    for(auto it = num_dp.begin(); it != num_dp.end(); ++it){
        if(it->second >result){
            result = it->second;
        }
    }
    
    cout << result << "\n";

    return 0;
}