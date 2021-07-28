#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define f first
#define s second

typedef long long int ll;

int ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    ll eq = a.f * b.s + b.f * c.s + c.f * a.s;
    eq = eq - a.s * b.f - b.s * c.f - c.s * a.f;
    if(eq > 0) return 1;
    else if(eq == 0) return 0;
    else return -1;
}
bool solve(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c, pair<ll, ll> d) {
    int abc = ccw(a, b, c);
    int abd = ccw(a, b, d);
    int cda = ccw(c, d, a);
    int cdb = ccw(c, d, b);
    if(abc * abd == 0 && cda * cdb == 0) {
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        return a <= d && c <= b;
    }
    return abc * abd <= 0 && cda * cdb <= 0;
}
int main(void) {
    FastIO;
    ll x1, y1, x2, y2;
    pair<ll, ll> p1;
    pair<ll, ll> p2;
    pair<ll, ll> p3;
    pair<ll, ll> p4;
    cin >> x1 >> y1 >> x2 >> y2;
    p1 = {x1, y1};
    p2 = {x2, y2};
    cin >> x1 >> y1 >> x2 >> y2;
    p3 = {x1, y1};
    p4 = {x2, y2};

    cout << solve(p1,p2,p3,p4) << endl;
    return 0;
}