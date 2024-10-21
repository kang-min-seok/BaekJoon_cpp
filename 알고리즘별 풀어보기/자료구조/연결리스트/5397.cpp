#include <iostream>
#include <list>  // list를 사용하기 위한 헤더 파일

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string temp;
    for(int i=0; i<n;i++){
        cin >> temp;
    
        list<char> password_list;
        auto it = password_list.begin();
        for(int j=0; j<temp.length(); j++){
            if(!password_list.empty()){
                // 왼쪽이동 로직
                if(temp[j] == '<' && it != password_list.begin()){
                    --it;
                }
                // 오른쪽 이동 로직
                else if(temp[j] == '>' && it != password_list.end()){
                    it++;
                }
                // 삭제 로직
                else if(temp[j] == '-' && it != password_list.begin()){
                    // it--; 
                    // password_list.erase(it);
                    it = password_list.erase(--it); 
                }
                // 추가 로직
                else if(temp[j] != '<' && temp[j] != '>' && temp[j] != '-'){
                    password_list.insert(it, temp[j]);
                }

            } else { // 리스트가 비어있다면 추가로직만 허용
                if(temp[j] != '<' && temp[j] != '>' && temp[j] != '-'){
                    password_list.insert(it, temp[j]);
                }
            }
        }


        for (char value : password_list) {
            cout << value;  
        }
        cout << "\n";
    }

    return 0;
}

// 30~31번째줄처럼 짜면 무한반복이 돔.
// erase는 삭제된 요소의 다음 요소를 가리키는 반복자를 반환합니다. 
// 현재 코드에서는 it--로 이미 이전 요소로 이동한 상태에서 삭제를 수행하기 때문에 
// 반복자가 불일치하게 되어 무한 루프나 정의되지 않은 동작이 발생할 수 있습니다.

// 삭제 로직에서는 it--로 반복자를 먼저 감소시키지 않고, erase() 함수가 
// 반환하는 반복자를 사용해야 합니다. erase() 함수는 삭제된 요소의 다음 반복자를 반환하므로, 
// 이를 올바르게 처리해야 합니다.
// it = password_list.erase(--it);  // 삭제 후 다음 요소를 가리킴