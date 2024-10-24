#include <iostream>
#include <map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;
    cin >> test_case;

    for(int i=0; i<test_case; i++){
        map<string, int> cloth_map;

        int cloth_num;
        cin >> cloth_num;

        if(cloth_num == 0){
            cout << "0" << "\n";
        } else {
            string a, cloth;
            // 옷 입력
            for(int j=0; j<cloth_num; j++){
                cin >> a >> cloth;    
                cloth_map[cloth] += 1; 
            }

            int result = 1;
            for(auto it = cloth_map.begin(); it != cloth_map.end(); it++){
                result = result * (it -> second + 1);
            }
            cout << result-1 << "\n";
        }
        

    }
    return 0;
}
