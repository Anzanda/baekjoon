#include <bits/stdc++.h>

#define MAXN 50
using namespace std;

int n;
int sr,sc;
int low, high;
int height[MAXN][MAXN];
int dx[] = {1,-1,1, -1, 1, 0, -1, 0};
int dy[] = {1, 1, -1, -1, 0, 1, 0, -1};
vector<pair<int, int>> house;
vector<int> tired;
bool vst[MAXN][MAXN];
bool IsOutSegment(int x, int y){
    if(x<0 || x>=n || y<0 || y>=n){
        return true;
    }
    return false;
}
bool IsInRange(int x, int y){
    if(height[x][y] < tired[low] || height[x][y] > tired[high]){
        return false;
    }
    return true;
}
void dfs(int x, int y){
    if(IsOutSegment(x,y) || !IsInRange(x,y)){
        return;
    }
    if(vst[x][y])
        return;
    
    vst[x][y]=true;
    for(int i=0; i<8; i++){
        
        int nx = x + dx[i];
        int ny = y + dy[i];
        dfs(nx, ny);
    }
}
bool checkIsValid(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            vst[i][j] = false;
        }
    }
    dfs(sr, sc);
    for(auto it=house.begin(); it!=house.end(); it++){
        if(!vst[it->first][it->second]){
            //printf("when [%d][%d]\n", it->first, it->second);
            return false;
        }
    }
    return true;
}
int main(void){
    cin >> n;
    for(int i=0; i<n; i++){
        char c[MAXN]; cin >> c;
        for(int j=0; j<n; j++){
            if(c[j] == 'P'){
                sr = i;
                sc = j;
            }
            if(c[j] == 'K'){
                house.push_back({i, j});
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
    
    low=0, high=tired.size()-1;    
    int l=0;
    int r=tired.size()-1;
    int min = INT_MAX;
    while(l<=r){
        int mid = (l+r)/2;
        high = mid;
        if(checkIsValid()){
            int right = mid;
            while(right>=0){
                low = right;
                if(checkIsValid()){
                    break;
                }
                else{
                    right--;
                }
            }
            //printf("high: %d || low: %d\n", tired[high], tired[low]);
            min = min > (tired[high]-tired[low]) ? (tired[high]-tired[low]) : min;
            low = 0;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    //printf("high: %d || low: %d\n", tired[high], tired[low]);
    cout << min;
    return 0;
}