#include <stdio.h>

int main(){
	int positive = 0;
	int negative = 0;
	int num;
	int plusCounter = 0;
	int negCounter = 0;

do{
	printf("Please enter an integer: ");
	scanf("%d", &num);
		if(num > 0){
			positive = num + positive;
			plusCounter++;
		}
		else if(num < 0){
			negative = num + negative;
			negCounter++;
		}
		else{
			if(plusCounter != 0){ 
				int ans = positive/plusCounter;
				printf("Positive average: %d\n", ans);
			}
			if(negCounter != 0){
				int ans = negative/negCounter;
				printf("Negative average: %d\n", ans);
			}
		}
		
}while(num != 0);

return 0;
}

