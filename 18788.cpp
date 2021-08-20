#include <bits/stdc++.h>
using namespace std;

#define MAX 100
#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int n,k;
int cows[MAX];
int A[2];
int B[2];
int cycle[MAX][4];
void input() {
	FastIO;
	cin >> n >> k;
	cin >> A[0] >> A[1];
	cin >> B[0] >> B[1];
	for(int i=0; i<n; i++) {
		cows[i] = i;
	}
}
void reverseArr(int* arr, int lf, int rg) {
	while(lf < rg) {
		swap(arr[lf], arr[rg]);
		lf++;
		rg--;
	}
}
void makeReverse(int* arr) {
	reverseArr(arr, A[0]-1, A[1]-1);
	reverseArr(arr, B[0]-1, B[1]-1);
}
void solve() {
	for(int i=0; i<4; i++) {
		for(int j=0; j<n; j++) {
			cycle[j][i] = cows[j];
		}
		makeReverse(cows);
	}
	for(int i=0; i<n; i++) {
		cout << cycle[i][k%4]+1 << endl;
	}
}
int main(void) {
	input();
	solve();
	return 0;	
}
