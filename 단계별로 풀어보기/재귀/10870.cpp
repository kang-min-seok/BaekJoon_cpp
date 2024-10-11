#include <iostream>

using namespace std;

int fibo(int a, int b, int c, int finish){
    int sum = a + b;
    if(finish == c){
        return a;
    } else {
        c += 1;
        return fibo(b, sum, c, finish);
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << fibo(0,1,0,n) << '\n';
    return 0;
}