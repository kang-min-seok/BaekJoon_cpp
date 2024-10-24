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
            if(find(sequence.begin(), sequence.end(), i) == sequence.end()) { 
                sequence.push_back(i);
                backtracking(sequence, num_goal, value);
                sequence.pop_back();
            }
        }
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

// #include <iostream>
// #define MAX 9
// using namespace std;

// int n,m;
// int arr[MAX] = {0,};
// bool visited[MAX] = {0,};

// void dfs(int cnt)
// {
//     if(cnt == m)
//     {
//         for(int i = 0; i < m; i++)
//             cout << arr[i] << ' ';
//         cout << '\n';
//         return;
//     }
//     for(int i = 1; i <= n; i++)
//     {
//         if(!visited[i])
//         {
//             visited[i] = true;
//             arr[cnt] = i;
//             dfs(cnt+1);
//             visited[i] = false;
//         }
//     }
// }

// int main() {
//     cin >> n >> m;
//     dfs(0);
// }