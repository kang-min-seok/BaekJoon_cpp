#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

string word_goal;
vector<string>word_vector;
map<int,int>cost_map; // 단어 길이, 비용
set<int>result_set;

map<char, int> getCharFrequency(const string& str) {
    map<char, int> freqMap;
    for (char ch : str) {
        freqMap[ch]++;
    }
    return freqMap;
}

void dp(int now_index, int cost){
    if(now_index == word_goal.size()){
        result_set.insert(cost);
    }
    // 벡터안 단어들 다 집어넣어봄
    for(int i=0; i<word_vector.size(); i++){ // 단어 갯수만큼 반복
        string now_word = word_vector[i]; 
        int word_size = now_word.size();

        
        // 검사할 부분 문자열
        string subA = word_goal.substr(now_index, word_size);

        map<char, int> freqA = getCharFrequency(subA);
        map<char, int> freqB = getCharFrequency(now_word);

        // 단어가 들어갈 수 있는지 없는지 검사
        if(freqA == freqB){ // 단어가 들어갈 수 있는경우
            // 비용이 얼마인지 계산하는 코드
            int plus_cost=0;
            for(int j=0; j<word_size; j++){
                if(word_goal[now_index+j] != now_word[j]){
                    plus_cost += 1;
                }
            }
            // 단어 길이가 존재하는지 확인
            if (cost_map.find(now_index+word_size) != cost_map.end()) {
                // 만약 길이대비 비용이 기존꺼보다 높거나 같다면 리턴
                if(cost+plus_cost >= cost_map[now_index+word_size]){
                    continue;
                } else {
                    cost_map[now_index+word_size] = cost + plus_cost;
                    dp(now_index+word_size, cost+plus_cost);
                }
            } else { // 단어길이가 존재하지 않다면 추가하고 재귀호출
                cost_map[now_index + word_size] = cost + plus_cost;
                dp(now_index+word_size, cost+plus_cost);
            }
            
            
        }

      
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> word_goal;

    int word_num;
    cin >> word_num;

    for(int i=0; i<word_num; i++){
        string word;
        cin >> word;
        word_vector.push_back(word);
    }

    dp(0, 0);

    if(result_set.empty()){
        cout << "-1" << "\n";
    } else {
        cout << *result_set.begin() << "\n";
    }
    return 0;
}