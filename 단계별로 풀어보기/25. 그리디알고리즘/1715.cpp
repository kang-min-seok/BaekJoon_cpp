#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> numbers(n);
    for(int i=0; i<n; i++){
        cin >> numbers[i];
    }

    
    
    return 0;
}