#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <iterator>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<int, int>num_map; // 입력값, 출력순서
    unordered_map<int, int>num_change; // 입력값, 몇번째로 큰지
    int n;
    cin >> n;
    vector<int>num_vec(n);
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        num_map[temp] = i;
        num_vec[i] = temp;
    }
    int result = 0;
    for(const auto& pair : num_map) {
        num_change[pair.first] = result;
        result++;
    }
    for(int i=0; i<n; i++){
        cout << num_change[num_vec[i]] << " ";
    }
    
    cout << "\n";
    return 0;
}

// TODO: 풀긴 풀었는데 문제의 의도대로 푼거 같지는 않음. 다음에 다시 풀어봐