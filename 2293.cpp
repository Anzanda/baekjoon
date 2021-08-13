#include <stdio.h>
#include <string.h>

#define MAX 100007

int n, k;
int arr[MAX];
int dp[MAX];
int main(void) {
	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; i++) {
		scanf("%d", &arr[i]);
	}
	dp[0] = 1;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=k; j++) {
			if(arr[i] > j) {
				continue;
			}
			dp[j] += dp[j-arr[i]];
		}
	}
	printf("%d\n", dp[k]);
	return 0;
}