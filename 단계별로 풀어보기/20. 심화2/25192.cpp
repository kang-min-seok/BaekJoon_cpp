#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int chat_num, result=0;
    cin >> chat_num;

    set<string>member;
    string user;
    
    for(int i=0; i<chat_num; i++){
        cin >> user;
        if(user == "ENTER"){
            member.clear();
        } else {
            if (member.find(user) == member.end()) {
                result += 1;
                member.insert(user);
            }
        }
    }
    cout << result << '\n';

    return 0;
}



// 인터넷 코드
// 거의 똑같지만 디테일이 살짝 내가 모잘랐음
// set는 중복을 허용하지 않기 때문에 중복 확인을 할 필요가 없었음
// #include <iostream>
// #include <set>
// using namespace std;

// int main()
// {
// 	int N, count = 0;
// 	cin >> N;
// 	set<string> m;
// 	string str;

// 	while (N--)
// 	{
// 		cin >> str;

// 		if (str == "ENTER")
// 		{
// 			count += m.size();
// 			m.clear();
// 			continue;
// 		}
		
// 		m.insert(str);
// 	}

// 	count += m.size();

// 	cout << count;
// }



// 정답코드 살짝보고 내가 수정한 코드
// #include <iostream>
// #include <set>

// using namespace std;

// int main(void) {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int chat_num, result=0;
//     cin >> chat_num;

//     set<string>member;
//     string user;
    
//     for(int i=0; i<chat_num; i++){
//         cin >> user;
//         if(user == "ENTER"){
//             result += member.size();
//             member.clear();
//         } else {
//             member.insert(user);
//         }
//     }
//     result += member.size();

//     cout << result << '\n';

//     return 0;
// }