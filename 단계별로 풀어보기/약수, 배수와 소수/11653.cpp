#include <iostream>
using namespace std;
int main(void) {
    int N;
    cin >> N;
    if(N != 1){
        int i=2;
        while(N != 1){
            if(N % 2 == 0){
                N /= 2;
                cout << 2 << endl;
                continue;
            }
            i += 1;
            while(1){
                if(N % i == 0){
                    N /= i;
                    cout << i << endl;
                    i = 2;
                    break;
                } else {
                    i += 2;
                }
            }
        }
    }
    return 0;
}