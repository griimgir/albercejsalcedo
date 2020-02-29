#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions
// Main function, DO NOT MODIFY!!!	
int main(int argc, char **argv) {
    int bSize = 15;
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
		return 2;
	}
    int i, j;
    FILE *fptr;
    char **block = (char**)malloc(bSize * sizeof(char*));
	char **words = (char**)malloc(50 * sizeof(char*));

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

	// Read puzzle block into 2D arrays
    for(i=0; i<bSize; i++){
        *(block+i) = (char*)malloc(bSize * sizeof(char));

        fscanf(fptr, "%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", *(block+i), 
        	*(block+i)+1, *(block+i)+2, *(block+i)+3, *(block+i)+4, *(block+i)+5,
        	*(block+i)+6, *(block+i)+7, *(block+i)+8, *(block+i)+9, *(block+i)+10, 
        	*(block+i)+11, *(block+i)+12, *(block+i)+13, *(block+i)+14 );
    }
	fclose(fptr);

	// Open file for reading word list
	fptr = fopen("states.txt", "r");
	if (fptr == NULL) {
        printf("Cannot Open Words File!\n");
        return 0;
    }
	
	// Save words into arrays
	for(i=0; i<50; i++){
		*(words+i) = (char*)malloc(20 * sizeof(char));
		fgets(*(words+i), 20, fptr);		
	}
	
	// Remove newline characters from each word (except for the last word)
	for(i=0; i<49; i++){
		*(*(words+i) + strlen(*(words+i))-2) = '\0';	
	}
	
	// Print out word list
	printf("Printing list of words:\n");
	for(i=0; i<50; i++){
		printf("%s\n", *(words + i));		
	}
	printf("\n");
	
	// Print out original puzzle grid
    printf("Printing puzzle before search:\n");
    printPuzzle(block, bSize);
	printf("\n");
	
	// Call searchPuzzle to find all words in the puzzle
	
	searchPuzzle(block, bSize, words, 50);
	printf("\n");
	
	// Print out final puzzle grid with found words in lower case
    printf("Printing puzzle after search:\n");
    printPuzzle(block, bSize);
	printf("\n");
	
    return 0;
}

void printPuzzle(char** arr, int n){
	// This function will print out the complete puzzle grid (arr). It must produce the output in the SAME format as the samples in the instructions.
	// Your implementation here
    for(int a = 0; a < n; a++){
			//printf("\n");
		for(int b = 0; b<n; b++){
			printf("%c ", *(*(arr+a)+b));
		}
		printf("\n");
	} 

}

//worked with Elyse Geimer on search Puzzle and recieved help from Andy Alvarega who took this call last semester.
void searchPuzzle(char** arr, int n, char** list, int listSize){
	// This function checks if arr contains words from list. If a word appears in arr, 
	//it will print out that word and then convert that word entry in arr into lower case.
	// Your implementation here
	//int* boolean;
	//char* queue = *arr;
	printf("start search: \n");
	for(int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			for(int z = 0; z < listSize; z++){
				//printf("debug 1:search start");
				//printf("%s ", *(list+z));
				int state = strlen(*(list + z));
				int checkRight = compareright(i, j, n, arr, *(list+z), state);
					if(checkRight == 1){
						int temp = 0;
						printf("|%d|%d|found: ", i, j);
						//printf("%c ", *(*(arr+i)+(k+j)));
						char* wordlook = *(list+z);
						
						while(*wordlook != '\0'){
							(*(*(arr + i)+(temp + j))) = tolower(*(*(arr + i)+(temp + j))); 
							printf("%c", *(*(arr + i)+(temp + j)));
							temp++;
							wordlook++;
						}printf("[down done]\n");
					}

				int foundd = comparedown(i, j, n, arr, *(list+z), state);
					if(foundd == 1){
						int temp = 0;
						printf("|%d|%d|found: ", i, j);

						char* wordlookOne = *(list + z);
						while(*wordlookOne != '\0'){
							//printf("converting");
							(*(*(arr+(temp + i)) + j)) = tolower(*(*(arr + (temp + i)) + j));
							printf("%c", *(*(arr + (temp + i)) + j));
							temp++;
							wordlookOne++;
						}printf("[down done]\n");
					}

				int foundu = compareup(i, j, n, arr, *(list+z), state);
					if(foundu == 1){
						int temp = 0;
						printf("|%d|%d|found: ", i, j);
						char* wordlookTwo = *(list+z);

						while(*wordlookTwo != '\0'){
							(*(*(arr+(temp + i)) + j)) = tolower(*(*(arr + (temp + i)) + j));
							printf("%c", *(*(arr+(temp + i)) + j));
							temp--;
							wordlookTwo++;
						}printf("[up done]\n");
					}
					
				int foundur = compareupright(i, j, n, arr, *(list+z), state);
					if(foundur == 1){
						int temp = 0;
						printf("|%d|%d|found: ", i, j);
						//printf("%c ", *(*(arr+(p+i))+j));
						char* wordlookThree = *(list+z);
						
						int temp2 = 0;
						while(*wordlookThree != '\0'){
							//printf("made it here");
							//printf("--conversion");
							(*(*(arr + (temp2 + i))+( j + temp))) = tolower(*(*(arr + (temp2 + i))+(j + temp)));
							printf("%c", *(*(arr + (temp2 + i))+(j + temp)));
							temp2--;
							temp++;
							wordlookThree++;
						}printf("[upright diagonal done]\n");
				}
				int founddr = comparedownright(i, j, n, arr, *(list+z), state);
					if(founddr == 1){
						printf("|%d|%d|found: ", i, j);
						char* wordlookFour = *(list+z);

						int temp = 0;
						while(*wordlookFour != '\0'){
							(*(*(arr+(temp + i))+(j + temp))) = tolower(*(*(arr + (temp + i))+(j + temp)));
							printf("%c", *(*(arr + (temp + i))+(j + temp)));
							wordlookFour++;
							temp++;
						}
						printf("[down right diagonal done]\n");
				}
			}
		}
	}	
}

int compareright(int i, int j, int size, char** array, char*wordptr, int count){
	int found = 1;
	if(count+j >= size){
		found = 0;
		return found;
	}

	for(int index = 0; index < count; index++){
		if(*(wordptr + index) != '\0'){
			if(toupper(*(*(array + i)+(index + j))) != toupper(*(wordptr + index))){
				found = 0;
				break;
			}
		}
	}
	return found;
}

int comparedown(int i, int j, int size, char** array, char*wordptr, int count){
	//printf("starting comparedown\n");
	//printf("CoDo%d,%d,%c,%d\n",i,j,*wordptr, count);
	int found = 1;
	if(count+i >= size){
		found = 0;
		//printf("fail");
		return found;
	}
	//printf("Made it here");
	for(int index = 0; index < count; index++){
		if(*(wordptr + index)!= '\0'){
			if(toupper(*(*(array + (index + i)) + j)) != toupper(*(wordptr + index))){
				found = 0;
				break;
			}
		}
	}
	return found;
}

int compareup(int i, int j, int size, char** array, char*wordptr, int count){
	//printf("startCOUP\n");
	int found = 1;
	int veto = i - size;
	//if word size is less than the size of word puzzle (15) + j
	if(veto <= 0){
		return found = 0;
	}
	//for(int index =; index < 15 - j; index++)
	//char* word = *(list + l);
	int add = 0;
	for(int index = i; add < count; index--){
		if(*(wordptr + add) != '\0'){
			if(toupper(*(*(array + (index)) + j)) != toupper(*(wordptr + add))){//arr[i][j] != 
				found = 0;
				break;
				//return found;
			}
			//else{
			//	return found;
			//}
		}add++;
	}
	return found;
}

int compareupright(int i, int j, int size, char** array, char*wordptr, int count){
	int found = 1;
	int veto = i - count;
	int vetoN = count + j;
	if(veto <= 0 || vetoN >= size){
		found = 0;
		return found;
	}

	int add = 0;
	for(int index = i; add < count; index--){
		if(toupper(*(*(array + (index))+(j + add))) != toupper(*(wordptr  + add))){
			found = 0;
			break;
		}add++;
	}
	return found;
}

int comparedownright(int i, int j, int size, char** array, char*wordptr, int count){
	int found = 1;
	if((count+i) >= size || (count+j) >= size){
		found = 0;
		return found;
	}
	//int add = 0;
	for(int index = 0; index < count; index++){
		if(toupper(*(*(array+(i + index))+(index + j))) != toupper(*(wordptr + index))){
			found = 0;
			break;
		}
	}
	return found;
}