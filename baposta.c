#include <stdio.h>
#include <stdlib.h>

typedef unsigned int ui;

int main(){

	int i,aux;
	ui n;
	long somatotal,increment;

	while(scanf("%u",&n)){
		if(n==0)
			break;
		somatotal=0;increment=0;
		for(i=0;i<n;i++){
			scanf("%d",&aux);
			increment = (increment+aux>=0 ? increment+aux : 0);
			if(increment > somatotal)
				somatotal = increment;
		}

		if(somatotal > 0)
			printf("The maximum winning streak is %u.\n",somatotal);
		else
			printf("Losing streak.\n");
	}

	return EXIT_SUCCESS;
}
