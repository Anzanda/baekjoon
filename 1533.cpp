#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)
#define ff first
#define ss second

using ll = long long;
const ll MOD = 1000003;

struct Matrix {
	int size;
	vector<vector<ll>> arr;
	Matrix() {
		size = 0;
	}
	Matrix(int n) {
		size = n;
		arr = vector<vector<ll>>(n, vector<ll>(n));
	}
	Matrix operator * (const Matrix& x) {
		Matrix ret(size);
		for(int i=0; i<size; i++) {
			for(int j=0; j<size; j++) {
				for(int k=0; k<size; k++) {
					ret.arr[i][j] += arr[i][k] * x.arr[k][j];
					ret.arr[i][j] %= MOD;
				}
			}
		}
		return ret;
	}
};
int n, s, e, t;
Matrix ans;
void input() {
	cin >> n >> s >> e >> t;
	s--, e--;
	ans = Matrix(5*n);
	string s;
	for(int i=0; i<n; i++) {
		cin >> s;
		for(int j=0; j<n; j++) {
			int curr = s[j]-'0';
			if(curr >= 1) {
				ans.arr[i*5][j*5+(curr-1)] = 1;
			}
		}
	}
}
void start() {
	input();
	for(int i=0; i<n; i++) {
		for(int j=1; j<5; j++) {
			ans.arr[i*5+j][i*5+j-1] = 1;
		}
	}
}
Matrix multiply(Matrix x, ll t) {
	if(t == 1) {
		return x;
	}
	Matrix ret = multiply(x, t/2);
	ret = ret * ret;
	if(t&1)	ret = ret * x;
	return ret;
}
void solve() {
	Matrix fin = multiply(ans, t);
	cout << fin.arr[s*5][e*5] << endl;
}
int main(void) {
	FastIO;
	start();
	solve();
	return 0;
}
		
