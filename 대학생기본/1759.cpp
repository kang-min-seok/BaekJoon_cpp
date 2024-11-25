// 백트래킹
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int l,c;
vector<char> v;

bool bit_masking[35] = {false,};

void basic_input(){

    cin >> l >> c;
    v.resize(c);
    for(int i=0; i<c; i++){
        cin >> v[i];
    }
    // 97~122
    // 97, 101, 105, 111, 117
    bit_masking[0] = true;
    bit_masking[4] = true;
    bit_masking[8] = true;
    bit_masking[14] = true;
    bit_masking[20] = true;

}

int jaum =0;
int moum = 0;
string print_word = "";
int len = 1;

void backtracking(int now){
    if(len == l && moum > 0 && jaum > 1){
        cout << print_word << "\n";
    }
    for(int i = now+1; i<c; i++){
        len++;
        print_word += v[i];
        // 다음 문자가 모음이라면
        if(bit_masking[(int)v[i] - 97]){
            moum++;
            backtracking(i);
            moum--;
        } else {
            jaum++;
            backtracking(i);
            jaum--;
        }
        print_word.pop_back();
        len--;
    }
        
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    basic_input();

    sort(v.begin(), v.end());

    for(int i=0; i<c-l+1; i++){
        char now_c = v[i];
        int bit_i = (int)now_c - 97;
        print_word += now_c;
        if(bit_masking[bit_i]){
            moum++;
            backtracking(i);
            moum--;
        } else {
            jaum++;
            backtracking(i);
            jaum--;
        }
        print_word.pop_back();
    }
    
    return 0;
}