
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node {
    int iValue;
    float fValue ;
    struct Node *next;
};

int main() {

    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->iValue = 5;
    head->fValue = 3.14;
	
	// Insert extra code here
    printf("%p\n:", &head); //address of head
    printf("%p\n:", head);  //value of head
    printf("%p\n:", &head->iValue); //address of iValue
	printf("%p\n:", &head->fValue); //address of fvalue
    printf("%p\n:", head->next);    //address of next
	
	return 0;
}