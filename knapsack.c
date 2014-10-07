#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "limits.h"

#define ULL unsigned long long
#define MAX_N 2000
#define UNSET 18446744073709551615ULL
#define max(a, b) (a > b ? a : b)

ULL matrix[MAX_N+1][MAX_N+1];
int vpeso[MAX_N+1],vvalor[MAX_N+1];


ULL knapsack(int i, int P){
	if(i <= 0 || P <= 0)
		return 0;

	if(matrix[i][P] != UNSET)
		return matrix[i][P];

	if(P - vpeso[i] < 0){
		return (matrix[i][P] = knapsack(i-1, P));
	}

	return (matrix[i][P] =  max(knapsack(i-1, P), knapsack(i-1, P - vpeso[i]) + vvalor[i]));
}

int main(){
	int npeso,nitem,i;
	while (scanf("%d",&npeso)!=EOF){
		scanf("%d",&nitem);
		memset(matrix, 0xFF, sizeof(matrix));

		for(i=1;i<=nitem;i++){
			scanf("%d",&vpeso[i]);
			scanf("%d",&vvalor[i]);
		}

		printf("%llu\n", knapsack(nitem, npeso));


	}
return EXIT_SUCCESS;
}



