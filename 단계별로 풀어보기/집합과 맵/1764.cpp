#include <iostream>
#include<string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int A_num, B_num;
    cin >> A_num >> B_num;
    int cnt=0;

    map<string, string> A_group;
    map<string, string> B_group;
    vector<string> result_group;

    for(int i=0;i<A_num;i++){
        string temp;
        cin >> temp;
        A_group.insert({temp,temp});
    }


    for(int i=0;i<B_num;i++){
        string temp;
        cin >> temp;
        if(A_group.find(temp) != A_group.end()){
            result_group.push_back(temp);
            cnt += 1;
        }
    }
    sort(result_group.begin(), result_group.end());
    cout << cnt << endl;
    for (int i=0; i<result_group.size();i++) {
        cout << result_group[i] << endl;
    }
    return 0;
}




// endl은 효율이 쓰레기 -> '\n'을 쓰는게 훨 좋음
// B_group선언해놓고 안씀 -> 난 ㅄ
// cnt변수 필요없음 -> result_group.size()사용하면 됨


// GPT피드백 + 인터넷 코드
// #include <iostream>
// #include <map>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main(void) {
//     int A_num, B_num;
//     cin >> A_num >> B_num;

//     map<string, bool> A_group;
//     vector<string> result_group;

//     string temp;

//     for(int i = 0; i < A_num; i++) {
//         cin >> temp;
//         A_group.insert(make_pair(temp, true)); 
//     }

//     for(int i = 0; i < B_num; i++) {
//         cin >> temp;
//         if(A_group[temp]) {
//             result_group.push_back(temp);
//         }
//     }

//     sort(result_group.begin(), result_group.end());
//     cout << result_group.size() << '\n';
//     for(int i=0; i< result_group.size(); i++) {
//         cout << result_group[i] << '\n';
//     }

//     return 0;
// }