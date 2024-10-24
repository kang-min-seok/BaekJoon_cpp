#include <iostream>
#include<string>
#include <vector>
#include <map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, bool>oper_map;

    for(int i=1; i<=20; i++){
        oper_map[i] = false;
    }

    int oper_num;
    cin >> oper_num;

    for(int i=0; i<oper_num; i++){
        string oper;
        cin >> oper;

        if(oper == "add"){
            int temp;
            cin >> temp;
            oper_map[temp] = true;
        } else if(oper == "remove") {
            int temp;
            cin >> temp;
            oper_map[temp] = false;
        } else if(oper == "check") {
            int temp;
            cin >> temp;
            if(oper_map[temp] == true){
                cout << "1" << "\n";
            } else {
                cout << "0" << "\n";
            }
        } else if(oper == "toggle") {
            int temp;
            cin >> temp;
            if(oper_map[temp] == true){
                oper_map[temp] = false;
            } else {
                oper_map[temp] = true;
            }
        } else if(oper == "all") {
            for(int i=1; i<=20; i++){
                oper_map[i] = true;
            }
        } else if(oper == "empty") {
            for(int i=1; i<=20; i++){
                oper_map[i] = false;
            }
        }
    }
    
    return 0;
}
