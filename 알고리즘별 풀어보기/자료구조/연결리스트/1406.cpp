#include <iostream>
#include <list>  // list를 사용하기 위한 헤더 파일

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // 초기 문자열
    string code;
    cin >> code;

    // 명령어 갯수
    int command_num;
    cin >> command_num;

    // 초기 문자열 리스트에 입력
    list<char> command_list;
    for(int i=0; i< code.length(); i++){
        command_list.push_back(code[i]);
    }

    // 커서는 마지막에서 시작
    auto it = command_list.end();

    for(int i=0; i<command_num; i++){
        char command;
        cin >> command;
        if(command == 'L' && it != command_list.begin()){
            it--;
        } else if(command == 'D' && it != command_list.end()){
            it++;
        } else if(command == 'B' && it != command_list.begin()){
            it = command_list.erase(--it);
        } else if(command == 'P'){
            char add_char;
            cin >> add_char;
            command_list.insert(it, add_char);
        } 
    }

    for (char value : command_list) {
        cout << value;  
    }
    cout << "\n";

    return 0;
}
