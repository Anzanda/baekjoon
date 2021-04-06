#include <iostream>
#include <vector>
using namespace std;

int n, input_num;
long long ans;
void merge(vector<int>& v, int start, int end){
    int mid = (start+end)/2;
    int left = start;
    int right = mid+1;
    if(start == end){
        return;
    }

    merge(v,start, mid);
    merge(v,mid+1, end);

    vector<int> tmp;
    while(left <= mid && right <= end){
        if(v[left] <= v[right]){
            tmp.push_back(v[left++]);
        }
        else{
            ans += (mid+1 - left);
            tmp.push_back(v[right++]);
        }
    }
    while(left <= mid){
        tmp.push_back(v[left++]);
    }
    while(right <= end){
        tmp.push_back(v[right++]);
    }
    for(int i=start, j=0; i<=end; i++, j++){
        v[i] = tmp[j];
    }
}
int main(void){
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> input_num;
        v[i] = input_num;
    }

    ans = 0;
    merge(v, 0, n-1);
    // for(int i=0; i<n; i++){
    //     cout << v[i] << ' ';
    // }
    cout << ans;
    return 0;
}