#include <stdio.h>
#include <stdlib.h>

#define MAX 2000

typedef unsigned int ui;


char matrix[MAX+1][MAX+1], str[MAX+1];
ui v[MAX+1];

char pal(int a, int b){
	if(a > b) return 1;
		if(matrix[a][b] == -1){
			if(str[a] == str[b] && pal(a+1, b-1)) return (matrix[a][b] = 1);
				return (matrix[a][b] = 0);
	}
return matrix[a][b];
}


int main(){
	int i, j, tam, loop = 1;

	while(scanf("%d",&tam) != EOF){
		if(tam==0)
			break;

		scanf("%s",&str[1]);

		memset(v,0xFF,sizeof(v));
		v[0]=0;
		memset(matrix,-1,sizeof(matrix));

		for(i=1;i<=tam;i++)
			matrix[i][i]=1;

		for(i=0;i<tam;i++){
			for(j=i + 1;j<=tam;j++){
				if(pal(i+1,j)==1)
					if(v[i]+1<v[j])
						v[j]=v[i]+1;
			}
		}

		printf("Teste %d\n%u\n\n",loop++,v[tam]);
	}
return EXIT_SUCCESS;
}

