#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    string S;
    vector<int> result(26, -1);
    char character;
    bool flag = false;
    cin >> S;
    
    // 소문자 아스키 97~122
    for(int i = 0; i< 26; i++){
        character = static_cast<char>(i+97); 
        for(int j = 0; j < S.length(); j++){
            if(character == S[j]){
                result[i] = j;
                flag = true;
            }
            if(flag){
                flag = false;
                break;
            }
        }
    }

    for(int i = 0; i< 26; i++){
       cout << result[i];
        if (i != result.size() - 1) {  // 마지막 원소가 아닌 경우에만 공백 출력
            cout << " ";
        }
    }

}