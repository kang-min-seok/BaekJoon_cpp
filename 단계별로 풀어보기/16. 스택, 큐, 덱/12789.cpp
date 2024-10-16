#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(void) {

    int N, temp, line_num = 1;
    bool isComplete = true;
    cin >> N;

    stack<int>line_Stack;
    queue<int>line_Queue;

    for(int i=0; i<N; i++){
        cin >> temp;
        line_Queue.push(temp);
    }


    // queue에서 먼저 들어간 값이 front, 나중이 back
    while(1){
        // queue안 값 들어갈 수 있으면 바로 들어가고
        if(!line_Queue.empty() && line_Queue.front() == line_num) {
            line_Queue.pop();
            line_num += 1;
        }
        // stack 맨위 값이 들어갈 수 있으면 바로 들어가고
        else if(!line_Stack.empty() && line_Stack.top() == line_num){
            line_Stack.pop();
            line_num += 1;
        } 
        // 다 못들어가면 queue맨앞값 스택에 넣기
        else {
            line_Stack.push(line_Queue.front());
            line_Queue.pop();
        } 

        // 반복 종료 조건
        if(line_num >= N){
            break;
        }
        // 위 작업 다 반복하고 큐가 비어있고 스택 맨위값 못넣으면 sad출력
        if(!line_Stack.empty()){
            if(line_Stack.top() != line_num && line_Queue.empty()){
                cout << "Sad" << '\n';
                isComplete = false;
                break;
            }
        }
        
    }

    if(isComplete){
        cout << "Nice" << '\n';
    }


    return 0;
}
