#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int meet_num, result=0;
    string user_a, user_b;
    cin >> meet_num;

    unordered_map<string, bool>dancing_user;

    for(int i=0; i<meet_num; i++){
        cin >> user_a >> user_b;
        if(user_a == "ChongChong" || user_b == "ChongChong"){
            dancing_user[user_a] = true;
            dancing_user[user_b] = true;
        } else if(dancing_user[user_a] || dancing_user[user_b]){
            dancing_user[user_a] = true;
            dancing_user[user_b] = true;
        }
        if(dancing_user.find(user_a) == dancing_user.end())
            dancing_user[user_a] = false;
        if(dancing_user.find(user_b) == dancing_user.end())
            dancing_user[user_b] = false;
    }

    for (const auto& pair : dancing_user) {
        if (pair.second) {
            result+=1;
        }
    }
    cout << result << '\n';
    return 0;
}



// 인터넷 코드 대충 보고 내가 생각해낸 새로운 코드
// 이게 좀 더 메모리적으로 효율적임
// #include <iostream>
// #include <algorithm>
// #include <unordered_set>

// using namespace std;

// int main(void) {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int meet_num;
//     string user_a, user_b;
//     cin >> meet_num;

//     unordered_set<string>dancing_user;

//     for(int i=0; i<meet_num; i++){
//         cin >> user_a >> user_b;
//         if(user_a == "ChongChong" || user_b == "ChongChong"){
//             dancing_user.insert(user_a);
//             dancing_user.insert(user_b);
//         } else if(dancing_user.find(user_a) != dancing_user.end() && dancing_user.find(user_b) == dancing_user.end()){
//             dancing_user.insert(user_b);
//         } else if(dancing_user.find(user_b) != dancing_user.end() && dancing_user.find(user_a) == dancing_user.end()){
//             dancing_user.insert(user_a);
//         }
//     }

    
//     cout << dancing_user.size() << '\n';
//     return 0;
// }