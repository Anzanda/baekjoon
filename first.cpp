#include <bits/stdc++.h>
using namespace std;

int main(void){
	int sdcp[8] = {800, 950, 650, 750, 300, 400, 20, 50};
	int dne[2] = {980,20};
	int cw[2] = {705, 295};
	int p[2] = {190, 810};

	unsigned long long int total=0;
	int sdcpIdx=0;
    char a,b,c;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++){
                if(i)   a='F';
                else    a='T';
                if(j)   b='F';
                else    b='T';
                if(k)   c='F';
                else    c='T';
                printf("when %c %c %c| ", a,b,c);
                printf("%lf * %lf * %lf * %lf |val: %d\n", sdcp[sdcpIdx]/1000.0, dne[i]/1000.0, cw[j]/1000.0, p[k]/1000.0, sdcp[sdcpIdx]*dne[i]*cw[j]*p[k]);
                total += sdcp[sdcpIdx++]*dne[i]*cw[j]*p[k];
            }
        }
    }
	printf("total: %d", total);
	return 0;
}