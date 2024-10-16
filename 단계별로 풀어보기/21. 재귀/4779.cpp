#include <iostream>

using namespace std;

void line_draw(int now, int end, string line){
    int blank_num = 1;
    for(int i=0 ; i< now-1; i++){
        blank_num *= 3;
    }
    string blank(blank_num, ' ');
    line = line + blank + line;
    if(now == end){
        cout << line;
        return;
    }
    now += 1;
    return line_draw(now, end, line);
}


int main() {
    int num;

    // EOF까지 입력을 받으며 처리
    while (cin >> num) {
        if(num == 0){
            cout << "-";
        } else {
            line_draw(1, num, "-");
        }
		cout << "\n";
	}

    return 0;
}


// #include <iostream>
// #include <cmath>
// using namespace std;

// void cantor(int n) {
// 	int size = pow(3, n - 1);

// 	// N = 0 인 경우 "-" 출력
// 	if (n == 0) {
// 		cout << "-";
// 		return;
// 	}

// 	// N번째 칸토어 집합 = N -1 번째 칸토어 집합을 2개 이은 것
// 	// 사이에 공백이 N - 1번째 칸토어 집합의 사이즈만큼 있어야 함
// 	cantor(n - 1);
// 	for (int i = 0; i < size; i++) {
// 		cout << " ";
// 	}
// 	cantor(n - 1);

// }

// int main() {
// 	int N;

// 	while (cin >> N) {
// 		cantor(N);
// 		cout << "\n";
// 	}

// 	return 0;
// }