#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 산술평균
    // 중앙값
    // 최빈값
    // 범위
    int N_num, temp;

    map<int, int> statistics;
    vector<int> middle_vector;
    set<int> many_set;
    int many=0;
    double total=0;

    cin >> N_num;
    for(int i=0; i< N_num; i++){
        cin >> temp;
        statistics[temp]++;
        middle_vector.push_back(temp);
        total += temp;
    }
    sort(middle_vector.begin(), middle_vector.end());

    // 평균
    double average = round(total / N_num);
    // 중앙값

    int middle_value = middle_vector[N_num/2];

    // 최빈값
    for(auto it = statistics.begin(); it != statistics.end(); it++){
        if(many <= it->second){
            many = it->second;
        }
    }
    for(auto it = statistics.begin(); it != statistics.end(); it++){
        if(many == it->second){
            many_set.insert(it->first);
        }
    }
    auto many_it = many_set.begin();
    if(many_set.size()>=2){
        ++many_it;
    }
    // 범위
    int first_key = statistics.begin()->first;
    int last_key = statistics.rbegin()->first;
    int difference = last_key - first_key;
    if(average == -0){
        average = 0;
    }

    cout << average << '\n'; // 평균
    cout << middle_value << '\n'; // 중앙값
    cout << *many_it << '\n';
    cout << difference << '\n'; // 범위


    return 0;
}



// #include <iostream>
// #include <cmath>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {
//     int N, temp;
//     cin >> N;

//     int cnt[8001] = {0}; // -4000 ~ 4000을 인덱스로 사용
//     int sum = 0;
//     int maxFreq = 0;
//     int minValue = 4001, maxValue = -4001;
//     vector<int> modeCandidates;

//     for (int i = 0; i < N; i++) {
//         cin >> temp;
//         sum += temp;
//         cnt[temp + 4000]++;
//         if (cnt[temp + 4000] > maxFreq) {
//             maxFreq = cnt[temp + 4000];
//             modeCandidates.clear();
//             modeCandidates.push_back(temp);
//         } else if (cnt[temp + 4000] == maxFreq) {
//             modeCandidates.push_back(temp);
//         }
//         if (temp < minValue) minValue = temp;
//         if (temp > maxValue) maxValue = temp;
//     }

//     // 평균
//     cout << (int)round((double)sum / N) << '\n';

//     // 중앙값 찾기
//     int count = 0;
//     int median;
//     for (int i = 0; i <= 8000; i++) {
//         count += cnt[i];
//         if (count >= (N + 1) / 2) {
//             median = i - 4000;
//             break;
//         }
//     }
//     cout << median << '\n';

//     // 최빈값 찾기
//     sort(modeCandidates.begin(), modeCandidates.end());
//     int mode;
//     if (modeCandidates.size() > 1) {
//         mode = modeCandidates[1]; // 두 번째로 작은 수 출력
//     } else {
//         mode = modeCandidates[0]; // 하나만 있으면 그 값을 출력
//     }
//     cout << mode << '\n';

//     // 범위
//     cout << maxValue - minValue << '\n';

//     return 0;
// }