#include <bits/stdc++.h>
using namespace std;

#define MAX 100
#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int n,k;
int cows[MAX];
int A[2];
int B[2];
int cycle[MAX][MAX];
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
int originCows[MAX];
bool isSame(int* a, int* b) {
	for(int i=0; i<n; i++) {
		if(a[i] != b[i]) {
			return false;
		}
	}
	return true;
}
int getPeriod(int* arr) {
	memcpy(originCows, cows, sizeof cows);
	int periodCount = 0;
	while(true) {
		for(int i=0; i<n; i++) {
			cycle[i][periodCount] = cows[i]; // 그냥 한 번에 cycle배열까지 초기화 해줌.
			//쓰레기 코드 죄송...
		}
		makeReverse(cows);
		periodCount++;
		if(isSame(originCows, cows)) {
			break;
		}
	}
	return periodCount;
}
void solve() {
	int period = getPeriod(cows);
	for(int i=0; i<n; i++) {
		cout << cycle[i][k%period]+1 << endl;
	}
}
int main(void) {
	input();
	solve();
	return 0;	
}
