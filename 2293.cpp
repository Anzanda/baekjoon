#include <stdio.h>
#include <string.h>

int n,k;
int arr[105];
int dp[105][10005];
int solve(int now, int k) {
	if(k == 0)	return 1;
	if(now > n-1)	return 0;
	int* ret = &dp[now][k];
	if(*ret != -1)	return *ret;
	*ret = 0;	
	for(int i=0; k-(arr[now]*i)>=0; i++) {
		*ret += solve(now+1, k-(arr[now]*i));
	}
	return *ret;
}
int main(void) {
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	memset(dp, -1, sizeof dp);
	printf("%d", solve(0, k));
	return 0;
}
