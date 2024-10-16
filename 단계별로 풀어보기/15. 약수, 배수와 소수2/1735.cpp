#include <iostream>

using namespace std;


int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(void) {
    int A_numerator, A_denominator;
    int B_numerator, B_denominator;
    int result_numerator, result_denominator;

    
    cin >> A_numerator >> A_denominator;
    cin >> B_numerator >> B_denominator;

    result_numerator = (A_numerator * B_denominator) + (A_denominator * B_numerator);
    result_denominator = A_denominator * B_denominator;
    
    int highest_common = gcd(result_numerator, result_denominator);

    result_numerator /= highest_common;
    result_denominator /= highest_common;

    cout << result_numerator << " " << result_denominator << endl;
    
    return 0;
}

// 인터넷 코드랑 똑같아서 그냥 안들고옴