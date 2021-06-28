#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000
#define lld long long int
#define endl "\n"
#define x first
#define y second

typedef pair<lld, lld> pi;
int n;
pi p[MAXN];
double ccw(pi p1, pi p2, pi p3){
    pi grad = {p2.x-p1.x, p2.y-p1.y};
    return (grad.first*(p3.y-p1.y)-grad.second*(p3.x-p1.x))/2.0;
}
int main(void){
    cin >> n;
    for(int i=0; i<n; i++){
        scanf("%lld %lld", &p[i].x, &p[i].y);
    }
    double ans = 0;
    for(int i=1; i<n; i++){
        ans += ccw(p[i-1], p[i], p[0]);
    }
    printf("%.1lf", abs(ans));
    return 0;
}
