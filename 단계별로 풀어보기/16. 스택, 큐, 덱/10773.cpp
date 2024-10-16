#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K, temp;
    cin >> K;
    stack<int>S;

    for(int i=0; i<K; i++){
        cin >> temp;
        if(temp == 0){
            S.pop();
        } else {
            S.push(temp);
        }
    }

    int result = 0;
    while(!S.empty()){
        result += S.top();
        S.pop();
    }

    cout << result << '\n';

    return 0;
}
