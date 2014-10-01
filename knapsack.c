#include <stdlib.h>
#include <stdio.h>

#define max 2000


/*int main(){
	int n,npeso,nitem,j,i,aux1,aux2;
	int** vet,vpeso[max],vvalor[max];



	while (scanf("%d",&npeso)!=EOF){
		scanf("%d",&nitem);

		vet = (int**)malloc(nitem*sizeof(int*));
		for(i=0;i<nitem;i++)
			vet[i]=(int*)malloc(npeso*sizeof(int));

		for(j=0;i<npeso;j++){
			for(i=0;i<nitem;i++){
				if(j==0)
					vet[i][j]=0;
				//else
					//vet[i][j]=2000;
			}
		}

		for(i=0;i<nitem;i++){
			scanf("%d",&vpeso[i]);
			scanf("%d",&vvalor[i]);
			vet[i][vpeso[i]] = vvalor[i];
		}
		for(j=1;j<npeso;j++){
			for(i=0;i<nitem;i++){
				aux1 = i-1;

				aux2 = j-vpeso[i];
				if(aux2 >=0){
					if(aux1 >= 0)
						aux2 = vet[aux1][aux2];
				}else
					aux2 = 0;

				if(vpeso[i]<=j)
					aux2 += vvalor[i];
				if(aux1 >=0)
					aux1 = vet[aux1][j];
				else
					aux1 = 0;

				vet[i][j] = aux1>=aux2?aux1:aux2;

			}
		}

		printf("%d\n",vet[nitem-1][npeso-1]);

	}
	return EXIT_SUCCESS;
}*/

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "limits.h"

#define ULL unsigned long long
#define MAX_N 2000
#define UNSET ULLONG_MAX
#define max(a, b) (a > b ? a : b)

ULL matrix[MAX_N+1];
int vpeso[MAX_N+1],vvalor[MAX_N+1];


ULL knapsack(int i, int P){
	if(i <= 0 || P <= 0)
		return 0;

	if(P - vpeso[i] < 0){
		return knapsack(i-1, P);
	}

	return max(knapsack(i-1, P), knapsack(i-1, P - vpeso[i]) + vvalor[i]);
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

