#include <iostream>
#include <cmath>


using namespace std;

int main(void) {
    int N;
    bool isFitted = true;
    cin >> N;

    double X;

    X = (-1 + sqrt(1+(8*N))) / 2;


    if(X != floor(X)){
        X = ceil(X);
        isFitted = false;
    }

    if(static_cast<int>(X) % 2 == 0) {
        if(isFitted){
            cout << X << "/1" << endl;
        } else {
            int temp = ((X*(X+1))/2) - N;

            cout << X-temp << "/" << 1+temp << endl;
        }
    } else{
        if(isFitted){
            cout << "1/" << X << endl;
        } else {
            int temp = ((X*(X+1))/2) - N;

            cout << 1+temp << "/" << X-temp << endl;
        }
    }

    return 0;
}



// GPT비교 평가
// 효율성 면에서는 당신의 코드가 더 나은 성능을 제공합니다. 
// 대각선을 찾는 과정이 상수 시간에 이루어지기 때문에, 
// 매우 큰 N 값에서는 더 빠르게 결과를 도출할 수 있습니다.

// 그러나 직관성과 가독성 측면에서는 인터넷 코드가 더 낫습니다. 
// 특히 작은 N에서는 두 코드 간의 성능 차이가 거의 없으므로 단순한 구조가 더 매력적일 수 있습니다.


// 인터넷 코드
// #include <iostream>
// using namespace std;

// int main() {
// 	int N;
// 	cin >> N;

// 	int i = 1;
// 	while (N > i) {
// 		N -= i;
// 		i++;
// 	}

// 	if (i % 2 == 1)
// 		cout << i + 1 - N << '/' << N << endl;
// 	else
// 		cout << N << '/' << i + 1 - N << endl;
// }