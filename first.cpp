#include <stdio.h>
#include <stdlib.h>
int solution(int brickCount, int* idx){
	int answer;
    answer = 1;
    int* dp = (int*)malloc(sizeof(int)*(brickCount+1));
	dp[1] = 1;
    for(int i=1; i<=brickCount-1; i++){
		dp[i+1] = 1;
        if(idx[i] < idx[i+1]){
            dp[i+1] = dp[i]+1;
        }
        answer = answer > dp[i+1] ? answer : dp[i+1];
    }
	
	return (brickCount - answer);
}

int main() {
	int brickCount;
	scanf("%d", &brickCount);
	int* brickNumber = (int*)malloc(sizeof(int)*(brickCount+1));
	for(int i=0; i<brickCount; i++){
		int number;
		scanf("%d", &number);
		brickNumber[number] = i;
	}

	printf("%d", solution(brickCount, brickNumber));
	return 0;
}