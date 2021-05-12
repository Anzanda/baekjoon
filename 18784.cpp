#include <bits/stdc++.h>
using namespace std;
#define MAXN int(1e5)
#define MAX int(1e4) * 2 + 1
#define f first
#define s second
const int MOD = 1e9+7;


int n;
vector<pair<int, int>> point;
vector<pair<int, int>> xpos[MAX];
vector<pair<int, int>> ypos[MAX];
int ysum[MAXN];
int xsum[MAXN];
int ans;
int main(void){
    cin >> n;
    point.resize(n);
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        point[i] = {x,y};
    }

    for(int i=0; i<n; i++){
        xpos[point[i].f + 10000].push_back({point[i].s + 10000, i});
        ypos[point[i].s + 10000].push_back({point[i].f + 10000, i});
    }

    for(int i=0; i<MAX; i++){
        if(xpos[i].size()){
            int sz = xpos[i].size();
            sort(xpos[i].begin(), xpos[i].end());
            int tmp = 0;
            for(int j=0; j<sz; j++){
                tmp = (tmp + xpos[i][j].f - xpos[i][0].f)%MOD;
            }
            for(int j=0; j<sz; j++){
                if(j)   tmp = (tmp + (2*j - sz) * (xpos[i][j].f - xpos[i][j-1].f))%MOD;
                xsum[xpos[i][j].s] = tmp;
            }
        }
    }

    for(int i=0; i<MAX; i++){
        if(ypos[i].size()){
            int sz = ypos[i].size();
            sort(ypos[i].begin(), ypos[i].end());
            int tmp = 0;
            for(int j=0; j<sz; j++){
                tmp = (tmp + ypos[i][j].f - ypos[i][0].f)%MOD;
            }
            for(int j=0; j<sz; j++){
                if(j)   tmp = (tmp + (2*j - sz) * (ypos[i][j].f - ypos[i][j-1].f))%MOD;
                ysum[ypos[i][j].s] = tmp;
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(ysum[i]<0 || xsum[i]<0){
            printf("hello!!!!\n");
        }
        ans = (ans + ((long long int)ysum[i] * xsum[i])%MOD)%MOD;
    }
    cout << ans;
    return 0;
}