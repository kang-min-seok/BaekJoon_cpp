#include <iostream>
#include <vector>
#include <tuple> 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int stair_num;
    cin >> stair_num;

    vector<int>stair;
    for(int i=0; i<stair_num; i++){
        int temp;
        cin >> temp;
        stair.push_back(temp);
    }

    if(stair_num == 1){
        cout << stair[0] << "\n";
    } else if(stair_num == 2){
        cout << stair[0] + stair[1] << "\n";
    } else {
        vector<tuple<int,int,int>>result;
        // 초기값 설정
        result.push_back(make_tuple(stair[0], 0, stair[0])); // 첫번쨰 계단 올라갔을때
        result.push_back(make_tuple(stair[1], stair[0] + stair[1], stair[0] + stair[1])); // 두번쨰 계단 올라갔을때
    
        for(int i=2; i<stair_num; i++){
            int one_stack =  get<2>(result[i-2]) + stair[i];
            int two_stack = get<0>(result[i-1]) + stair[i];
            result.push_back(make_tuple(one_stack, two_stack, max(one_stack, two_stack)));
        }
        cout << get<2>(result.back()) << "\n";

    }
    
    return 0;
}