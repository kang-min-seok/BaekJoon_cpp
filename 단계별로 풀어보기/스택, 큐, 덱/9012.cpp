#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // 인풋 갯수
    cin >>  n;
    stack<string>bracket_stack; // 괄호 스택
    string temp;
    bool isVPS = true;

    // 인풋 갯수만큼 반복
    for(int i=0; i<n; i++){
        cin >> temp;
        // 입력한 문자열 갯수만큼 반복
        // (가 들어오면 push, )가 들어오면 pop
        // pop해야 하는데 문자열 비어있으면 NO출력
        for(int j=0; j< temp.length(); j++){
            if(temp[j] == '('){
                bracket_stack.push("(");
            } else {
                if(bracket_stack.empty()){
                    cout << "NO" << '\n';
                    isVPS = false;
                    break;
                } else {
                    bracket_stack.pop();
                }
            }
        }
        // 로직 모두 수행했는데 스택에 값이 남아있으면 NO출력
        // 아니라면 YES 출력
        if(isVPS && bracket_stack.empty()){
            cout << "YES" << '\n';
        } else if(isVPS && !bracket_stack.empty()){
            cout << "NO" << '\n';
        }
        // 스택 비우기
        while(!bracket_stack.empty()){
            bracket_stack.pop();
        }
        // flag값 초기화
        isVPS = true;

    }
    return 0;
}
