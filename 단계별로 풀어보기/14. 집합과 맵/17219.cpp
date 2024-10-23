#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int site_num, search_num;
    cin >> site_num >> search_num;

    unordered_map<string, string>site_password_map;

    for(int i=0; i<site_num; i++){
        string site, password;
        cin >> site >> password;

        site_password_map[site] = password;
    }

    for(int i=0; i<search_num; i++){
        string search_query;
        cin >> search_query;
        cout << site_password_map[search_query] << "\n";
    }
    return 0;
}