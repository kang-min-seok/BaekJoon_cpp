#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>>queue_min; // 큐(최소힙)

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        if(temp == 0){
            if(queue_min.empty()){
                cout << "0" << "\n";
            } else {
                cout << queue_min.top() << "\n";
                queue_min.pop();
            }
        } else {
            queue_min.push(temp);
        }
    }

    return 0;
}