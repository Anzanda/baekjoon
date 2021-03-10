#include <iostream>
using namespace std;

int main(void){
    int n, r, c;
    cin >> n >> r >> c;

    int curCount=0;
    while(n){
        bool row = false;
        bool col = false;

        int half = 1 << (n-1);
        if(r >= half)
            row = true;
        if(c >= half)
            col = true;
        
        int quarter = 1 << (2*n-2);
        if(row && col){//1 1
            curCount += quarter*3;
            r -= half;
            c -= half;
        }
        else if(row){//1 0
            curCount += quarter*2;
            r -= half;
        }
        else if(col){//0 1
            curCount += quarter*1;
            c -= half;
        }
        else{//0 0
            curCount += quarter*0;
        }
        n--;
    }
    cout << curCount;
    return 0;
}