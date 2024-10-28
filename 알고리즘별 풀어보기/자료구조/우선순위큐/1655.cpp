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
    int now_length = 0;
    // 우선순위 큐 선언
    priority_queue<int>queue_left; // 왼쪽 큐(최대힙)
    priority_queue<int, vector<int>, greater<int>>queue_right; // 오른쪽 큐(최소힙)

    // 왼쪽큐가 무조건 하나 더 많거나 서로 같아야함.
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        now_length += 1;

        // 맨처음에는 왼쪽 큐에 집어넣음
        if(now_length == 1){ 
            queue_left.push(temp);
        }
        // 왼쪽큐가 1개 더 많으면 오른쪽 큐에 넣어야함 
        else if(queue_left.size() > queue_right.size()){
            // 넣는 값이 왼쪽큐의 가장 큰값보다 작거나 같다면
            // 넣는 값을 왼쪽에 넣어야 하기떄문에 기존 왼쪽에서 가장 큰값을 오른쪽으로 넣은뒤에
            // 왼쪽으로 넣는 값을 넣음
            if(queue_left.top() >= temp){
                queue_right.push(queue_left.top());
                queue_left.pop();
                queue_left.push(temp);
            } else { // 위 경우가 아니라면 그냥 오른쪽 큐에 넣으면 됨
                queue_right.push(temp);
            }
        } 
        // 위 상황이랑 반대인 경우. 
        // 즉, 왼쪽 큐와 오른쪽 큐의 크기가 같다면 무조건 왼쪽에 넣어야함.
        else if(queue_left.size() <= queue_right.size()){
            if(queue_right.top() <= temp){
                queue_left.push(queue_right.top());
                queue_right.pop();
                queue_right.push(temp);
            } else {
                queue_left.push(temp);
            }
        } 
        if ((now_length & 1) == 0) {
            // 현재 길이가 짝수일 때는 왼, 오 비교해서 작은값 출력
            if(queue_left.top() > queue_right.top()){
                cout << queue_right.top() << "\n";
            } else {
                cout << queue_left.top() << "\n";
            }
        } else {
            // 현재 길이가 홀수일 때는 왼쪽 큐에서 가장 큰값이 중앙값
            cout << queue_left.top() << "\n";
        }
    }    
    return 0;
}