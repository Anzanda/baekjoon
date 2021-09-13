#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)

const int MAX = 100;

struct Point {
    int x, y;
    Point() 
        :x(0),y(0){}
};
int n;
Point arr[MAX];
void input() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }
}
int getTriangle(Point pivot, Point equalX, Point equalY) {
    return abs(pivot.x-equalY.x)*abs(pivot.y-equalX.y);
}
void solve() {
    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==j)    continue;
            for(int k=0; k<n; k++) {
                if(j==k)    continue;
                if(i==k)    continue;
                if(arr[i].x == arr[j].x) {
                    if(arr[i].y == arr[k].y) {
                        ans = max(ans, getTriangle(arr[i], arr[j], arr[k]));
                    }  
                } else if(arr[i].y == arr[j].y) {
                    if(arr[i].x == arr[k].x) {
                        ans = max(ans, getTriangle(arr[i], arr[k], arr[j]));
                    }
                }
            }
        }
    } 
    cout << ans << endl;
}
int main(void) {
    FastIO;
    input();
    solve();
    return 0;
}