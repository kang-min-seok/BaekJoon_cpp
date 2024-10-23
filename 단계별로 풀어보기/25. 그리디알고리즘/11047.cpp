#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <deque>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int coin_num, money_total;
    cin >> coin_num >> money_total;

    stack<int>coin_kind;
    for(int i=0; i<coin_num; i++){
        int temp;
        cin >> temp;
        coin_kind.push(temp);
    }

    int result=0;
    while(money_total != 0){
        int minus_value = coin_kind.top();
        if(money_total - minus_value >= 0){
            money_total -= minus_value;
            result += 1;
        } else {
            coin_kind.pop();
        }
        
    }

    cout << result << "\n";
    return 0;
}


// 내가 푼거는 60ms걸리고 0ms걸리는거 있길래 코드보고나서 영감을 얻고 내가 짠 풀이
// #include <iostream>
// #include <vector>
// #include <stack>
// #include <algorithm>
// #include <deque>
// using namespace std;


// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int coin_num, money_total;
//     cin >> coin_num >> money_total;

//     stack<int>coin_kind;
//     for(int i=0; i<coin_num; i++){
//         int temp;
//         cin >> temp;
//         if(temp <= money_total)
//             coin_kind.push(temp);
//     }

//     int result=0;
//     while(money_total != 0){
//         int minus_value = coin_kind.top();
        
//         int amount;
//         amount = money_total / minus_value;
//         money_total -= amount * minus_value;
//         result += amount;
        
//         coin_kind.pop(); 
//     }

//     cout << result << "\n";
//     return 0;
// }