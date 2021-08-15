#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
//1,000,000,000 10^9까지 나옴.

int n;
int cnt[10][10][10];
/*
 * i: 10^i승일 때 
 * j: j를 머리로 계산했을 때
 * k: idx에 매칭되는 숫자가 나온 cnt를 세준다.
 */
int ans[10];
int main(void) {
	FastIO;
	cin >> n;
	for(int i=0; i<10; i++) {
		cnt[0][i][i] = 1;
	}
	for(int i=1; i<10; i++) {
		for(int j=0; j<10; j++) {
			for(int k=0; k<10; k++) {
				for(int l=0; l<10; l++) {
					cnt[i][j][l] += cnt[i-1][k][l];
				}
			}
			cnt[i][j][j] += pow(10, i);
		}
	}
	int tmpCnt = 0;
	int i = 0;
	while(n) {
		int tmp = n%10;
		ans[tmp] += tmpCnt+1;
		for(int j=tmp-1; j>=0; j--) {
			for(int k=0; k<10; k++) {
				ans[k] += cnt[i][j][k];
				tmpCnt += cnt[i][j][k];
			}
		}
		if(n/10 == 0) {
			for(int j=i; j>=0; j--) {
				ans[0] -= pow(10, j);
			}
		}
		n/=10;
		i++;
	}
	for(int i=0; i<10; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
