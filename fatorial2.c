#include <stdlib.h>
#include <stdio.h>

int last_digit(int n){
	int tmp;
	while((tmp = n % 10)==0){
		n /=10;
	}
	return tmp;
}

int main(){



	return EXIT_SUCCESS;
}
