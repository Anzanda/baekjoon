#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)
#define MAX 50

using ll = long long;
const int MOD = 1000000007;

struct Matrix{
	int size;
	vector<vector<ll>> arr;
	Matrix() {
		size = 0;
	}
	Matrix(int n) {
		size = n;
		arr = vector<vector<ll>>(n, vector<ll>(n));
	}
	Matrix operator*(const Matrix& x) {
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

int n, m;
ll k;
Matrix mat;
void input() {
	cin >> n >> m;
	mat = Matrix(n);
	int a, b;
	for(int i=0; i<m; i++) {
		cin >> a >> b;
		a--;	b--;
		mat.arr[a][b] = 1;
		mat.arr[b][a] = 1;
	}
	cin >> k;
}
Matrix multiply(Matrix mat, ll curr) {
	if(curr == 1) {
		return mat;
	}
	Matrix ret = multiply(mat, curr/2);	
	ret = ret * ret;
	if(curr&1) {
		ret = ret * mat;
	}
	return ret;
}
void solve() {
	Matrix ans = multiply(mat, k);
	cout << ans.arr[0][0] << endl;
}
int main(void) {
	FastIO;
	input();
	solve();
	return 0;
}
	
