#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, string>parent; // 키 -> 본인 이름이 뭐냐 / 밸류 -> 상단 부모 이름이 뭐냐
unordered_map<string, int>ranked;
unordered_map<string, int>sizeed;

string find(string x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void connect_add(string a, string b){
    a = find(a);
    b = find(b);

    if(a != b){
        sizeed[a] += sizeed[b];
        sizeed[b] = sizeed[a];
        if(ranked[a] < ranked[b]){
            parent[a] = b;
        } else if(ranked[b] < ranked[a]){
            parent[b] = a;
        } else {
            parent[b] = a;
            ranked[a]++;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int test_case;
    cin >> test_case;

    for(int i=0; i<test_case; i++){
        int F;
        cin >> F;
        parent.clear();
        ranked.clear();
        sizeed.clear();

        for(int j=0; j<F; j++){
            string f1, f2;
            cin >> f1 >> f2;

            if(parent.find(f1) == parent.end()){
                parent[f1] = f1;
                ranked[f1] = 0;
                sizeed[f1] = 1;
            }
            if(parent.find(f2) == parent.end()){
                parent[f2] = f2;
                ranked[f2] = 0;
                sizeed[f2] = 1;
            }

            connect_add(f1,f2);


            cout << sizeed[find(f1)] << "\n";

        }
    }


    return 0;
}