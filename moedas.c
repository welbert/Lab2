#include <stdio.h>
#include <stdlib.h>

#define MAX_valor 50000
#define MAX_moedas 100
#define MAX_int 32767

int moedas[MAX_moedas+1],valor[MAX_valor+1];

int MIN(int x,int y){
	if(x<=y)
		return x;
	else
		return y;
}

int main(){
	int preco,nmoedas, i,j;

	while(scanf("%d",&preco)!=EOF){
		if(preco==0)
			break;

		scanf("%d",&nmoedas);

		for(i=0;i<nmoedas;i++)
			scanf("%d",&moedas[i]);

		valor[0]=0;

		for(i=1;i<=preco;i++)
			valor[i]=MAX_int;

		for(i=0;i<preco;i++)
			if(valor[i]!= MAX_int)
				for(j=0;j<nmoedas;j++)
					if(i+moedas[j]<=preco)
						valor[i+moedas[j]] = MIN(valor[i+moedas[j]],valor[i]+1);

		if(valor[preco]!=MAX_int)
			printf("%d\n",valor[preco]);
		else
			printf("Impossivel\n");



	}
return EXIT_SUCCESS;
}
