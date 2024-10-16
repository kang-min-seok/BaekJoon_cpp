#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    int N, result=0;
    bool flag = false;
    cin >> N;
    vector<string>words(N);
    vector<int>temp;

    for(int i = 0; i < N; i++){
        cin >> words[i]; 
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < words[i].length(); j++){
            auto it = find(temp.begin(), temp.end(), words[i][j]);
            if (it != temp.end()) {
                flag = true;
                break;
            } else if(j == words[i].length()-1){
                break;
            }
            else if(words[i][j] != words[i][j+1]){
                temp.push_back(words[i][j]);
            }
        }
        temp.clear();
        if(!flag){
            result += 1;
        }
        flag = false;
    }
    cout << result;
}

// GPT풀이
// 딱봐도 훨씬 간결하고 ㅈㄴ 잘짬..
// 나는 temp벡터를 만들고 알파벳을 벡터에 push하고 다음값이 벡터안에 존재하는지 
// 검사하고 단어 하나 끝나면 temp를 비우고 다시 시작하는 방식으로 했는데
// 이 방식은 모든 알파벳을 다 미리 초기화해놓고 방문처리하는 방식으로 함
// 그리고 값을 입력할때마다 새롭게 visited배열을 초기화하는 방식임

// int main() {
//     int N, result = 0;
//     cin >> N;

//     for(int i = 0; i < N; i++){
//         string word;
//         cin >> word;

//         bool visited[26] = {false};
//         bool isGroupWord = true;

//         for(int j = 0; j < word.length(); j++){
//             if(j > 0 && word[j] != word[j - 1]) {
//                 if(visited[word[j] - 'a']) {
//                     isGroupWord = false;
//                     break;
//                 }
//             }
//             visited[word[j] - 'a'] = true;
//         }

//         if(isGroupWord) {
//             result++;
//         }
//     }

//     cout << result;
//     return 0;
// }