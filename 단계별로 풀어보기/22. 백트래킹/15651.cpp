#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtracking(vector<int> sequence, int num_goal, int value){
    // 종료조건
    if(sequence.size() >= num_goal){
        for(int i=0; i<num_goal; i++){
            cout << sequence[i] << " ";
        }
        cout << "\n";
        return;
    } else {
        for(int i=1; i<=value; i++){
            sequence.push_back(i);
            backtracking(sequence, num_goal, value);
            sequence.pop_back();
        }
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        vector<int>sequence_first;
        sequence_first.push_back(i);
        backtracking(sequence_first,M,N);
    }
    

    return 0;
}
