#include <bits/stdc++.h>

#define MAXN 50
using namespace std;

int n;
int sr, sc;
vector<pair<int,int>> house;
int height[MAXN][MAXN];
vector<int> tired;
int high, low;
bool vst[MAXN][MAXN];
void dfs(int x, int y){
    if(x<0 || x >=n || y<0 || y>=n || height[x][y] < tired[low] || height[x][y] > tired[high]){
        return;
    }
    if(vst[x][y])   return;
    vst[x][y] = true;
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i==0 && j==0)    continue;
            int nx = x + i;
            int ny = y + j;
            dfs(nx, ny);
        }
    }
}
bool checkIsValid(){
    memset(vst, false, sizeof vst);
    dfs(sr,sc);
    for(auto it=house.begin(); it != house.end(); it++){
        if(!vst[it->first][it->second])
            return false;
    }
    return true;
}
int main(void){
    cin >> n;
    for(int i=0; i<n; i++){
        char c[MAXN];
        cin >> c;
        for(int j=0; j<n; j++){
            if(c[j] == 'K'){
                house.push_back({i,j});
            }
            if(c[j] == 'P'){
                sr = i;
                sc = j;
            }
        }   
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> height[i][j];
            tired.push_back(height[i][j]);
        }
    }
    sort(tired.begin(), tired.end());
    tired.erase(unique(tired.begin(), tired.end()), tired.end());

    int min=INT_MAX;
    high = 0; low=0;
    while(high < tired.size()){
        int l,r,mid;
        l = 0;
        r = high;
        while(l<r){
            mid = (l+r+1)/2;
            low=mid;
            if(checkIsValid()){
                l = mid;
                min = min > (tired[high]-tired[low]) ? (tired[high]-tired[low]) : min;
            }
            else{
                r = mid-1;
            }
        }
        low = l;
        if(checkIsValid()){
            min = min > (tired[high]-tired[low]) ? (tired[high]-tired[low]) : min;
        }
        high++;
    }
    cout << min;
    return 0;
}