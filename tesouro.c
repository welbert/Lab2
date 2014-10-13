//Biblioteca--------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//------------------------

//Typedef-----------------
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;

//------------------------

//Constantes--------------
#define UI_MAX 65535
#define MAX_TES 5100
#define MAX_N 100

//------------------------

//Funtions----------------

//------------------------

//VARIAVEIS GLOBAIS-------
bool visited[MAX_TES +1];
int valor[MAX_N];

//------------------------

//MAIN--------------------
int main (){
	int x,y,n,loop=1;
	int i,j,soma;

	while(scanf("%d",&x)!=EOF){
		if(x==0)
			break;

		scanf("%d",&y);
		scanf("%d",&n);

		soma = x+y;

		for(i=0;i<n;i++){
			scanf("%d",&j);
			valor[i]= j;
			soma+=j;
		}

		printf("Teste %d\n",loop++);

		if(soma%2 != 0)
			printf("N\n\n");
		else{
			int cap;

			if(x>y){
				cap = (soma/2)-x;
				if(cap<0)
					cap = (soma/2)-y;
			}else{
				cap = (soma/2)-y;
				if(cap<0)
					cap = (soma/2)-x;
			}

			memset(visited, 0, sizeof(visited));
			visited[0]=true;

			int k = 0;

			for(i=0;i<n;i++){
				for(j=k;j>=0;j--){
					if(visited[j])
						visited[j+valor[i]] = true;
				}
				if(visited[cap])
					break;
				k+=valor[i];
				if(k>cap)
					k=cap;
			}

			if(visited[cap])
				printf("S\n\n");
			else
				printf("N\n\n");

		}


	}

	return EXIT_SUCCESS;
}
