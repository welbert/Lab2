#include <string.h>
#include <stdlib.h>
#include <stdio.h>

long int entrada;

int last_number(int n){
	char c[2];
	int aux;
	sprintf(c,"%d",n);
	if(c[1]=='0' || c[1]=='\0'){
		aux = c[0]-'0';
		return aux;
	}else{
		aux = c[1]-'0';
		return aux;
	}
}

int twoLastNumber(int n){
	char c[3];
	sprintf(c,"%d",n);
	char result[2];
	int lenght,aux;
	lenght = strlen(c);
	if(lenght>2){
		while(c[lenght-2]=='0')
			lenght--;
		result[0]=c[lenght-2];
		result[1]=c[lenght-1];
		aux = (result[0]-'0');
		aux= aux*10;
		aux = aux+(result[1]-'0');
		return aux;
	}else
		return n;
}

float fatorial1 (float n)
{
	if(n==0)
		return 1;
    if(n==1)
        return n;
    return twoLastNumber(fatorial1(n-1) * n);
}

int fatorial (int n)
{
	if(entrada==0)
		return 1;
    if(n==entrada)
        return n;
    return (fatorial(n+1)%10) * (n%10);
}

int main(int argc, char **argv) {
	int instancia=1,i;
	long int saida;


	while (scanf("%ld",&entrada)!=EOF){

		for (i=entrada - 1;i>=1;i--){
			entrada = last_number(entrada) * i;
		}
		saida = entrada;
		//saida = fatorial(1);
		//saida = last_number(saida);
		printf("Instancia %d\n%ld\n\n",instancia,saida);
		instancia++;
	}
	return EXIT_SUCCESS;
}
