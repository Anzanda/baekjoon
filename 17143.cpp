#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 10007

int R,C,M;
int ans;
typedef struct shark{
    int r,c,v,d,w;
    bool isAlive;
    shark()
        :r(0), c(c), v(v), d(d), w(w), isAlive(false) {}
    shark(int r, int c, int v, int d, int w, bool isAlive)
        :r(r), c(c), v(v), d(d), w(w), isAlive(isAlive) {}
}shark;
shark arr[MAX];
void move() {
    for(int i=0; i<M; i++) {
        if(!arr[i].isAlive) continue;
        int v = arr[i].v;
        while(v > 0) {
            switch(arr[i].d) {
                case 1:
                    if(arr[i].r - v <= 0) {
                        v -= arr[i].r;
                        arr[i].r = 0;
                        arr[i].d = 2;
                    } else {
                        arr[i].r -= v;
                        v = 0;
                    }
                    break;
                case 2:
                    if(arr[i].r + v >= R-1) {
                        v -= (R-1-arr[i].r);
                        arr[i].d = 1;
                        arr[i].r = R-1;
                    } else {
                        arr[i].r += v;
                        v = 0;
                    }
                    break;
                case 3:
                    if(arr[i].c + v >= C-1) {
                        v -= (C-1-arr[i].c);
                        arr[i].c= C-1;
                        arr[i].d = 4;
                    } else {
                        arr[i].c += v;
                        v = 0;
                    }
                    break;
                case 4:
                    if(arr[i].c - v <= 0) {
                        v -= arr[i].c;
                        arr[i].c = 0;
                        arr[i].d = 3;
                    } else {
                        arr[i].c -= v;
                        v = 0;
                    }
            }
        }
    }
}
void deleteShark(int now) {
    vector<vector<int>> tmp(R, vector<int>(C, -1));
    for(int i=0; i<M; i++) {
        if(!arr[i].isAlive) continue;
        int idx = tmp[arr[i].r][arr[i].c];
        if(idx != -1) {
            if(arr[i].w > arr[idx].w) {
                arr[idx].isAlive = false;
                tmp[arr[i].r][arr[i].c] = i;
            }  else {
                arr[i].isAlive = false;
                tmp[arr[i].r][arr[i].c] = idx;
            }
        } else {
            tmp[arr[i].r][arr[i].c] = i;
        }
    }
    // for(int i=0; i<R; i++) {
    //     for(int j=0; j<C; j++) {
    //         cout << tmp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}
void fishing(int now) {
    vector<vector<int>> tmp(R, vector<int>(C, -1));
    for(int i=0; i<M; i++) {
        if(!arr[i].isAlive) continue;
        tmp[arr[i].r][arr[i].c] = i;
    }
    for(int i=0; i<R; i++) {
        if(tmp[i][now] != -1) {
            int idx = tmp[i][now];
            ans += arr[idx].w;
            arr[idx].isAlive = false;
            break;
        }    
    }
}
int main(void) {
    FastIO;
    cin >> R >> C >> M;
    for(int i=0; i<M; i++) {
        int r, c, v, d, w;
        cin >> r >> c >> v >> d >> w;
        arr[i] = shark(r-1,c-1,v,d,w, true); 
    }
    fishing(0);
    for(int i=0; i<C-1; i++) {
        move();
        deleteShark(i);
        fishing(i+1);
    }
    cout << ans << endl;
    return 0;
}