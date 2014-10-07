#include <stdio.h>
#include <stdlib.h>

#define MAX_fat 1000000

typedef unsigned long long ull;

ull fat[MAX_fat+1];

int main(){

	ull i;
	int loop=1;

	fat[1] = 1;

	for(i=2;i<=MAX_fat;i++){
		fat[i] = (i* fat[i-1]);
		while((fat[i]%10)==0)
			fat[i]/=10;

		fat[i]%=MAX_fat;
	}

	while(scanf("%d",&i)!=EOF){
		printf("Instancia %d\n%llu\n",loop++,fat[i]%10);
	}

	return EXIT_SUCCESS;
}
