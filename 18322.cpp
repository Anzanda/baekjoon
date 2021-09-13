#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"

const int MAX = 100;

int n, k;
string arr[MAX];
string ans[MAX];
void input() {
	cin >> n >> k;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
}
void solve() {
	int currCnt = 0;
	vector<string> v;
	for(int i=0; i<n; i++) {
		if(currCnt + (int)arr[i].size() > k) {
			for(int j=0; j<(int)v.size(); j++) {
				if(j+1 == (int)v.size()) {
					cout << v[j] << endl;
				} else {
					cout << v[j] << " ";
				}
			}
			vector<string>().swap(v);
			v.push_back(arr[i]);
			currCnt = (int)arr[i].size();	
		} else {
			v.push_back(arr[i]);
			currCnt += (int)arr[i].size();
		}
	}
	for(int i=0; i<(int)v.size(); i++) {
		if(i+1 == (int)v.size()) {
			cout << v[i] << endl;
		} else {
			cout << v[i] << " ";
		}
	}
}
int main(void) {
	FastIO;
	input();
	solve();
	return 0;
}
