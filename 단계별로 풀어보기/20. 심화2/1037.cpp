#include <iostream>
#include<string>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N_num, small = 1000001, big = 1, temp;
    cin >> N_num;
    for(int i=0; i< N_num; i++){
        cin >> temp;
        
        if(temp <= small){
            small = temp;
        }
        if(temp >= big){
            big = temp;
        }
    }

    cout << small * big << '\n';
    return 0;
}