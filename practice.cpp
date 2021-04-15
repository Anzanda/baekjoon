#include <stdio.h>

int main(void){
	int v[101]={0,};
	v[0] = 1;
	v[1] = 1;
	
	for(int i=2; i<100; i++){
		if(v[i]==1)	continue;
		for(int j=i*2; j<=100; j+=i){
			v[j] = 1;
		}
	}

	for(int i=2; i<=100; i++){
		if(v[i] == 0)	printf("%d ", i);
	}
	return 0;
}