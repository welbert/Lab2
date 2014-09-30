#include <stdlib.h>
#include <stdio.h>

#define max 2000


int main(){
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
}
