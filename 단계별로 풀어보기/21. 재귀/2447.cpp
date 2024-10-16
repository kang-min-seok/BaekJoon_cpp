#include <iostream>
#include <vector>
using namespace std;

string expandStar(string star) {
    string result;
    for(int i=0;i<3;i++){
        result += star;
    }
    return result;
}

string expandStar_withBlank(string star){
    int star_size = star.length()/3;
    for(int i=star_size; i<star_size+star_size; i++){
        star[i] = ' ';
    }
    // cout << star << '\n';
    return star;
}


void star_draw(int goal, int now, vector<string> star){
    // 윗부분 출력(공백없이 3번출력)
    // 중앙부분 출력(출력, 공백, 출력)
    // 아랫부분 출력(공백없이 3번 출력)
    for(int i=0; i<star.size();i++){
        star[i] = expandStar(star[i]);
    }
    int expandSize = star.size();
    for(int i=0; i<expandSize;i++){
        star.push_back(expandStar_withBlank(star[i]));
    }
    for(int i=0; i<expandSize;i++){
        star.push_back(star[i]);
    }
    if(goal == now){
        for(int i=0; i<star.size();i++){
            cout << star[i] << '\n';
        }
    } else {
        now *= 3;
        star_draw(goal, now, star);
        return;
    }
    return;
}


int main() {
    int num;
    vector<string>star_field = {"***",
                                "* *",
                                "***"};
    cin >> num;
    if(num == 3){
        for(int i=0; i<star_field.size();i++){
            cout << star_field[i] << "\n";
        }
    } else {
        star_draw(num, 9, star_field);
    }

    return 0;
}