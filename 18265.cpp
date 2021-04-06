#include <iostream>
using namespace std;
//1 <= N <= 10^9

int main(void){
    int n;
    cin >> n;
    int idx3=1, idx5=1;
    int cnt=0;
    int nCnt=0;
    int tmp=0;
    while(nCnt<n){
        if(idx3*3 < idx5*5){
            cnt+=1;
            tmp=idx3*3;
            nCnt = (idx3++)*3 - cnt;
        }
        else if(idx3*3 > idx5*5){
            cnt+=1;
            tmp=idx5*5;
            nCnt = (idx5++)*5 - cnt;
        }
        else{
            cnt+=1;
            tmp=idx5*5;
            nCnt = idx5*5 - cnt;
            idx5++, idx3++;
        }
    }
    // printf("cnt: %d\n", cnt);
    // printf("nCnt: %d\n", nCnt);
    // printf("tmp: %d\n", tmp);
    while(true){
        if(tmp%3==0 || tmp%5==0){
            tmp--;
        }
        else{//3의 배수도 아니고 5의배수도 아님.
            if(nCnt == n){
                printf("%d\n", tmp);
                break;
            }
            nCnt--;
            tmp--;
        }
    }
    return 0;
}