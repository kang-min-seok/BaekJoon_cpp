#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, order, temp, value;
    cin >> N;
    stack<int>S;

    for(int i=0; i<N; i++){
        cin >> order;
        switch (order)
        {
        case 1:
            cin >> temp;
            S.push(temp);
            break;
        case 2:
            if(S.empty()){
                cout << "-1" << '\n';
            } else {
                value = S.top();
                cout << value << '\n';
                S.pop();
            }
            break;
        case 3:
            cout << S.size() << '\n';
            break;
        case 4:
            if(S.empty()){
                cout << "1" << '\n';
            } else {
                cout << "0" << '\n';
            }
            break;
        case 5:
            if(S.empty()){
                cout << "-1" << '\n';
            } else {
                value = S.top();
                cout << value << '\n';
            }
            break;
        
        default:
            break;
        }
    }

    return 0;
}


// 인터넷 풀이랑 거의 똑같음