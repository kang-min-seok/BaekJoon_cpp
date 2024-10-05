#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
    int x,y,w,h;
    cin >> x >> y >> w >> h;
    cout << min({x, y, w-x, h-y}) << endl;
    return 0;
}