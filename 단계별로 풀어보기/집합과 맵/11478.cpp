#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main(void) {
    string S;
    cin >> S;

    unordered_set<string> substring;
    string temp;

    int repeat = S.length();
    int part_num;

    while(repeat > 0){
        part_num = S.length() - repeat + 1;

        for(int i=0; i<repeat; i++){ 
            temp = S.substr(i, part_num);

            if(substring.find(temp) == substring.end()){
                substring.insert(temp);
            }

        }
        repeat -= 1;
    }


    cout << substring.size() << '\n';

    return 0;
}



// GPT가 짠 코드
// 변경점: substr함수를 쓰지 않고도 부분 문자열을 다 구하는 알고리즘 사용함
//        unordered_set는 중복된 값을 허용하지 않으므로 중복체크 할 필요가 없으니 if문 뺌
//        시간복잡도 o^3 -> o^2로 줄어듬
// #include <iostream>
// #include <string>
// #include <unordered_set>

// using namespace std;

// int main(void) {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     string S;
//     cin >> S;

//     unordered_set<string> substring;
//     int N = S.length();

//     for (int i = 0; i < N; i++) {
//         string temp = "";
//         for (int j = i; j < N; j++) {
//             temp += S[j]; // 한 글자씩 추가하여 부분 문자열 생성
//             substring.insert(temp); // set에 바로 삽입
//         }
//     }

//     cout << substring.size() << '\n';

//     return 0;
// }