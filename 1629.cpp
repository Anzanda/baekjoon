#include <iostream>
using namespace std;

long long int A, B, C;
long long int pow(long long int a, long long int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    if(b%2){
        return (pow(a, b-1) * a)%C;
    }
    long long int half = (pow(a, b/2))%C;
    return (half*half)%C;
}
int main(void){
    cin >> A >> B >> C;
    cout << pow(A,B)%C;
    return 0;
}