#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> v;
int main(void){
    cin >> n >> k;
    v.resize(n);
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        v[i] = num;
    }

    int ans=0;
    for(auto riter(v.rbegin()); riter !=v.rend(); riter++){
        if(*riter > k){
            continue;
        }
        ans += k / (*riter);
        k %= *riter;
    }
    cout << ans;
    return 0;
}