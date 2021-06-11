#include <bits/stdc++.h>
#define MAXN (int)1e+6
using namespace std;

int arr[MAXN];
vector<int> seg;
int init(int node, int start, int end){
    if (start == end){
        return seg[node] = arr[start];
    }
    
    int mid = (start+end) >> 1;
    seg[node] = max(init(node*2, start, mid),init(node*2+1, mid+1, end));
    
    return seg[node];    
}void update(int node, int start, int end, int changed_index, int diff){
    if(changed_index < start || changed_index > end){
        return;
    }
    seg[node] += diff;
    if(start != end){
        int mid = (start + end) >> 1;
        update(node*2, start, mid, changed_index, diff);
        update(node*2+1, mid+1, end, changed_index, diff);
    }
}
int main(void){iostream::sync_with_stdio(false);cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int h = (int)ceil(log2(n));
    int tree_size = (1<<(h+1));
    seg.resize(tree_size);


}