#include <iostream>
#include <vector>
#include <sstream>
#include <deque>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    cin >> testCase;

    for(int i=0; i<testCase; i++){
        string command;
        cin >> command;

        int array_num;
        cin >> array_num;

        string array_str;
        cin >> array_str;

        string s = "";
        deque<int> array_deque;

        for (int i = 0; i<array_str.length();i++) {

            if (isdigit(array_str[i])) {
                s += array_str[i];

            }
            else {
                if (!s.empty()) {
                    array_deque.push_back(stoi(s));
                    s = "";
                }
            }
        }



        bool isLeft = true;
        bool isError = false;
        for(int j=0; j<command.length(); j++){
            if(command[j] == 'R'){
                isLeft = !isLeft;
            } else { // 'D'가 들어왔을때
                if(array_deque.empty()){ // 덱 비어있으면 에러 출력
                    cout << "error" << "\n";
                    isError = true;
                    break;
                } else { // 덱 비어있지 않다면 isLeft값에 따라 값 빼기
                    if(isLeft){
                        array_deque.pop_front();
                    } else {
                        array_deque.pop_back();
                    }
                }
            }
        }

        int array_size = array_deque.size();

        if(!isError){// 에러가 아닌 경우에 배열 출력
            cout << "[";
            if(isLeft){ // isLeft가 true라면 왼쪽에서부터 출력
                for(int j=0; j<array_size-1;j++){
                    cout << array_deque.front() << ",";
                    array_deque.pop_front();
                }
                if(array_size > 0) {
                    cout << array_deque.front();
                }
            } else { // isLeft가 false라면 오른쪽에서부터 출력
                for(int j=0; j<array_size-1;j++){
                    cout << array_deque.back() << ",";
                    array_deque.pop_back();
                }
                if(array_size > 0){
                    cout << array_deque.back();
                }
                

            }
            cout << "]" << "\n";
        }
    }


    return 0;
}