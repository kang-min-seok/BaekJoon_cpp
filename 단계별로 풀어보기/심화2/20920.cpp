// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cmath>
// #include <map>
// #include <set>

// using namespace std;

// bool compareByCountLengthAlphabet(const pair<string, pair<int, int>>& a, const pair<string, pair<int, int>>& b) {
//     if (a.second.first != b.second.first) {
//         // 단어 횟수 (second.first) 기준으로 내림차순 정렬
//         return a.second.first > b.second.first;
//     }
//     if (a.second.second != b.second.second) {
//         // 단어 길이 (second.second) 기준으로 내림차순 정렬
//         return a.second.second > b.second.second;
//     }
//     // 횟수와 길이가 같을 때는 사전순 정렬 (오름차순)
//     return a.first < b.first;
// }

// int main(void) {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int word_num, word_len;
//     string temp;
//     cin >> word_num >> word_len;

//     map<string, pair<int, int>>memory_words;
//     vector<pair<string,pair<int,int>>>ordered_memory;

//     // (단어, 단어 갯수)로 map에 저장 / 단어 사전순으로 정렬
//     for(int i=0; i<word_num; i++){
//         cin >> temp;
//         if (temp.length() >= word_len) {
//             // 단어가 이미 존재하는 경우, 첫 번째 값(횟수)을 증가시키고, 길이는 업데이트하지 않음
//             if (memory_words.find(temp) != memory_words.end()) {
//                 memory_words[temp].first++; // 횟수 증가
//             } 
//             // 단어가 처음 등장한 경우, pair 초기화
//             else {
//                 memory_words[temp] = make_pair(1, temp.length()); // (횟수 1, 길이)
//             }
//         }
//     }
//     // (key: append, value: (1,6)), (key: appendd, value: (4,7)),
//     // (key: apple, value: (2,5)), (key: sand, value: (3,4)) 이렇게 됨
//     // 횟수 많은게 앞으로 적은게 뒤로 정렬 사전순 정렬은 유지
//     // memory_words.first = 단어
//     // memory_words.second.first = 단어 갯수
//     // memory_words.second.second = 단어 길이
//     for (const auto& entry : memory_words) {
//         ordered_memory.push_back(make_pair(entry.first, make_pair(entry.second.first, entry.second.second)));
//     }
//     sort(ordered_memory.begin(), ordered_memory.end(), compareByCountLengthAlphabet);

//     // 정렬된 결과 출력
//     for (const auto& entry : ordered_memory) {
//         cout << entry.first << '\n';
//     }

//     return 0;
// }



#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compareByCountLengthAlphabet(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second != b.second) {
        // 단어 횟수 (second.first) 기준으로 내림차순 정렬
        return a.second > b.second;
    }
    if (a.first.length() != b.first.length()) {
        // 단어 길이 (second.second) 기준으로 내림차순 정렬
        return a.first.length() > b.first.length();
    }
    // 횟수와 길이가 같을 때는 사전순 정렬 (오름차순)
    return a.first < b.first;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int word_num, word_len;
    string temp;
    cin >> word_num >> word_len;

    map<string, int>memory_words;
    vector<pair<string,int>>ordered_memory;

    // (단어, 단어 갯수)로 map에 저장 / 단어 사전순으로 정렬
    for(int i=0; i<word_num; i++){
        cin >> temp;
        if (temp.length() >= word_len) {
            memory_words[temp]++;
        }
    }

    for (const auto& entry : memory_words) {
        ordered_memory.push_back(make_pair(entry.first, entry.second));
    }
    sort(ordered_memory.begin(), ordered_memory.end(), compareByCountLengthAlphabet);

    // 정렬된 결과 출력
    for (const auto& entry : ordered_memory) {
        cout << entry.first << '\n';
    }

    return 0;
}