#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int days_total, days_group;
    cin >> days_total >> days_group;

    vector<int>days;
    for(int i=0; i<days_total; i++){
        int temp;
        cin >> temp;
        days.push_back(temp);
    }

    deque<int>result_days;
    vector<int>result;
    // 초기값 세팅
    int add_temp=0;
    for(int i=0; i<days_group; i++){
        add_temp += days[i];
        result_days.push_back(days[i]);
    }
    result.push_back(add_temp);

    for(int i=days_group; i<days_total; i++){
        add_temp -= result_days.front();
        result_days.pop_front(); // 가장 앞값을 뺴고
        result_days.push_back(days[i]); // 가장 뒷값을 추가
        add_temp += result_days.back();
        
        result.push_back(add_temp);
    }

    auto max_iter = max_element(result.begin(), result.end());
    cout << *max_iter << "\n";

    return 0;
}