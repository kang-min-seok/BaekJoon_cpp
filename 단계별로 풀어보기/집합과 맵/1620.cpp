#include <iostream>
#include<string>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Dic_num, Q_num;
    cin >> Dic_num >> Q_num;

    unordered_map<string, string> name_Dic;
    unordered_map<string, string> num_Dic;
    string pocketmon, temp;

    vector<string>result;

    for(int i=1; i<=Dic_num; i++){
        cin >> pocketmon;
        name_Dic.insert(make_pair(pocketmon, to_string(i)));
        num_Dic.insert(make_pair(to_string(i),pocketmon));
    }

    for(int i=0; i<Q_num; i++){
        cin >> temp;
        if(name_Dic.find(temp) != name_Dic.end()){
            result.push_back(name_Dic[temp]);
        } else {
            result.push_back(num_Dic[temp]);
        }
    }

    for(int i=0; i<Q_num; i++){
        cout << result[i] << '\n';
    }

    return 0;
}



// GPT피드백 받고 리팩토링한 코드
// 원래는 값을 받으면 키값이 숫자인 해시맵과 포켓몬 이름인 해시맵을 두개 만들어서
// 원하는 결과 입력시에 숫자로 들어오면 숫자가 키인 해시맵에서 찾고 아니면 포켓몬 이름인 해시맵으로 찾았는데
// 그 대신에 숫자가 키값이 해시맵을 그냥 벡터로 바꾸고
// 결과 입력시 숫자인지 아닌지 판단한 뒤에 숫자라면 벡터에서 인덱스 값으로 찾고 아니면 원래대로 찾고

// cin.tie(NULL); 이걸 넣으면 입력 출력을 동시에 해도 서로 떨어짐
// 즉 반복문안에 입력 출력을 동시에 넣었을때
// 입력 > 출력 > 입력 > 출력이
// 입력 > 입력 > 출력 > 출력으로 바뀜

// #include <iostream>
// #include<string>
// #include <vector>
// #include <unordered_map>

// using namespace std;

// bool isNumber(const string& s) {
//     for (char c : s) {
//         if (!isdigit(c)) return false;
//     }
//     return true;
// }


// int main(void) {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int Dic_num, Q_num;
//     cin >> Dic_num >> Q_num;

//     unordered_map<string, string> name_Dic;
//     vector<string> num_Dic(Dic_num+1);
//     string pocketmon, temp;


//     for(int i=1; i<=Dic_num; i++){
//         cin >> pocketmon;
//         name_Dic.insert(make_pair(pocketmon, to_string(i)));
//         num_Dic[i] = pocketmon;
//     }

//     for(int i=0; i<Q_num; i++){
//         cin >> temp;
//         if(isNumber(temp)) {
//             cout << num_Dic[stoi(temp)] << '\n';
//         } else {
//             cout << name_Dic[temp] << '\n';
//         }
//     }

//     return 0;
// }