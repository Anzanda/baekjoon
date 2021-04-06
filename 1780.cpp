#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<vector<int>> v;
int minus1Count;
int zeroCount;
int oneCount;
int cnt;
void solve(int x, int y, int size){
    cnt++;
    bool flag = false;

    int tmp = v[x][y];
    for(int i=x; i<x+size; i++){
        for(int j=y; j<y+size; j++){
            if(v[i][j] != tmp){
                flag = true;
                break;
            }
        }
        if(flag)    break;
    }

    if(!flag){
        if(tmp == -1){
            minus1Count++;
        }
        else if(tmp == 0){
            zeroCount++;
        }
        else{
            oneCount++;
        }
        return;
    }

    int third = size/3;
    for(int i=x; i<x+size; i+=third){
        for(int j=y; j<y+size; j+=third){
            solve(i,j, third);
        }
    }
        
}

int main(void){
    int n;
    cin>>n;

    v.resize(n);
    for(auto& each: v){
        each.resize(n);
    }

    int num;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> num;
            v[i][j] = num;
        }   
    }
    minus1Count = 0;
    zeroCount = 0;
    oneCount =0;
    solve(0,0,n);
    cout << minus1Count << endl;
    cout << zeroCount << endl;
    cout << oneCount << endl;
    return 0;
}