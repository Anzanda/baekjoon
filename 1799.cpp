#include <bits/stdc++.h>
#define MAXN 10
using namespace std;

int n;
int field[MAXN][MAXN];
int tmpField[MAXN][MAXN];
vector<pair<int,int>> bishop;
vector<pair<int,int>> done;

void bishopWorking(int x, int y){
    tmpField[x][y] = 0;

    int tmpX = x;
    int tmpY = y;
    while(tmpX>=0&&tmpX<=n-1&&tmpY>=0&&tmpY<=n-1){
        if(tmpField[tmpX][tmpY]){
            tmpField[tmpX][tmpY]=0;
        }
        tmpX+=1;
        tmpY+=1;
    }
    
    tmpX = x;
    tmpY = y;
    while(tmpX>=0&&tmpX<=n-1&&tmpY>=0&&tmpY<=n-1){
        if(tmpField[tmpX][tmpY]){
            tmpField[tmpX][tmpY]=0;
        }
        tmpX+=-1;
        tmpY+=1;
    }

    tmpX = x;
    tmpY = y;
    while(tmpX>=0&&tmpX<=n-1&&tmpY>=0&&tmpY<=n-1){
        if(tmpField[tmpX][tmpY]){
            tmpField[tmpX][tmpY]=0;
        }
        tmpX+=1;
        tmpY+=-1;
    }

    tmpX = x;
    tmpY = y;
    while(tmpX>=0&&tmpX<=n-1&&tmpY>=0&&tmpY<=n-1){
        if(tmpField[tmpX][tmpY]){
            tmpField[tmpX][tmpY]=0;
        }
        tmpX+=-1;
        tmpY+=-1;
    }
}
int main(void){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> field[i][j];
            if(field[i][j]){
                bishop.push_back({i,j});
            }
        }
    }
    
    int ans = 0;
    int idx = 0;
    while(idx != bishop.size()){
        memcpy(tmpField, field, sizeof field);
        bishopWorking(bishop[idx].first, bishop[idx].second);

        int count = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(tmpField[i][j]){
                    bishopWorking(i,j);
                    count++;
                }
            }
        }
        
        
        ans = ans > count ? ans : count;
        idx++;
    }
    
    cout << ans << "\n";
    return 0;
}
