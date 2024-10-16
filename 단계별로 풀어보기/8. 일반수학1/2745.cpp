#include <iostream>
#include <string>
#include <cctype>
#include<math.h>

using namespace std;

int main(void) {
    string N;
    int B, result=0;

    cin >> N >> B;

    for(int i=0; i< N.size();i++){
        int num = N[i] - '0';
        if(isdigit(N[i])){
            result += num * pow(B, N.size()-i-1);
        } else {
            result += (N[i] - 55) * pow(B, N.size()-i-1);
        }
    }

    cout << result << endl;

    return 0;
}


// 인터넷 풀이
// 나랑 사실상 똑같음
// #include <iostream>
// #include <cmath>
// using namespace std;

// int main()
// {
//     string b_num;
//     int n;
//     cin >> b_num >> n;

//     int sum(0);
//     for (int i = 0; i < b_num.length(); i++)
//     {
//         int tmp = b_num[b_num.length() - (i + 1)];
//         if ('0' <= tmp && tmp <= '9')
//         {
//             tmp = tmp - '0';
//         }
//         else
//         {
//             tmp = tmp + 10 - 'A';
//         }
//         sum += (tmp * (int)pow(n, i));
//     }
//     cout << sum << '\n';

//     return 0;
// }