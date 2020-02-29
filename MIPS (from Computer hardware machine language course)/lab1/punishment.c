#include <stdio.h>
#include <stdbool.h>
int main(){
	int numPun;
	int numTypo;
	int i;
	int test = 10;
	bool check = true;
	
	while(check = true){
	printf("Enter the number of lines for the punishment: ");
	scanf("%d", &numPun);
		if(numPun < 0){
			printf("Not a valid entry!\n");
		continue;
		}
		else{
		break;
		}
	}
	
	printf("Number of punishment was: %d\n", numPun);

	while(check = true){
	printf("Enter the line for which we want to make a typo: ");
	scanf("%d", &numTypo);
		if(numTypo < 0){
		printf("Not a valid Entry!\n");
		continue;
		}
		else{
		break;
		}
	}
	printf("Number of type was: %d\n",numTypo);
	
	for(i = 1; i < numPun + 1; i++){
		if(i == numTypo){
		printf("C++ programming language is the best!\n");
		}
		else{
		printf("C programming language is the best!\n");
		}
	}
	return 0;
}
