#include <iostream>
#include <vector>
using namespace std;

int n,m,k;
vector<int> know_people;
vector<int> party[50];
int disjoint[51];
int Find(int x){
    if(disjoint[x] == x){
        return x;
    }
    return disjoint[x] = Find(disjoint[x]);
}
void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    disjoint[x] = y;
}
int main(void){
    cin >> n >> m;
    cin >> k;
    for(int i=0; i<k; i++){
        int know;
        cin >> know;
        know_people.push_back(know);
    }
    for(int i=1; i<=n; i++){
        disjoint[i] = i;
    }

    for(int i=0; i<m; i++){
        int p;
        cin >> p;
        int topTmp;
        for(int j=0; j<p; j++){
            int num;
             cin >> num;
            if(j>=1){
                Union(num, topTmp);
            }
            else{
                topTmp = num;
            }
            party[i].push_back(num);
        }
    }

    int ans = m;
    for(int i=0; i<m; i++){
        bool flag = false;
        for(auto& people: party[i]){
            for(auto& knowPeople: know_people){
                if(Find(people) == Find(knowPeople)){
                    flag = true;
                    break;
                }
            }
            if(flag){
                ans--;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}