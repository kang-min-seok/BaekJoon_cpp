#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N;
    int a, cnt=0, v;

    cin >> N;

    // --------------------------------------------
    int array[N];
    for(int i = 0; i < N ; i++){
        cin >> a;
        array[i] = a;
    }

    // 이게 더 좋은 방법임
    // vector<int> array(N);  
    // for (int i = 0; i < N; i++) {
    //     cin >> array[i];  
    // }
    // --------------------------------------------


    cin >> v;

    for(int i = 0; i < N ; i++){
        if(array[i] == v){
            cnt += 1;
        }
    }
    cout << cnt;
}