#include <iostream>
using namespace std;

int main(void){
    int n;
    cin >> n;

    int half = 1 << (n-1);
    int quater = 1 << (2*n-2);

    cout << half << endl;
    cout << quater << endl;
    return 0;
}