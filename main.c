#include "townCounter.h"

void printResults(int data[], int results[], int n, int numTowns);

int main(){
	
	int *data = NULL, *results = NULL;
	int n = 0, flag = 0, numTowns = 0;

	if(scanf("%d", &n) != 1 || (n > 25 && n < 5)){
		printf("\nInvalid size!\n");
		flag = 1;
	}
	else if(flag == 0){
		int size = n * n;
		int temp = 0;
		allocateMem(&data, size);
		allocateMem(&results, n);
		for(int y = 0; y < n; ++y){
			if(flag == 0){
				for(int x = 0; x < n; ++x){
					if(scanf("%1d", &temp) == 1 && (temp == 0 || temp == 1)){
						data[getPos(x, y, n)] = temp;
					}
					else{
						printf("\nInvalid input!\n");
						flag = 1;
					}
				}
			}
		}
		if(flag == 0){
			printResults(data, results, n, numTowns);
			free(results);
			free(data);
		}
	}
	return flag;
}

//Prints the results
void printResults(int data[], int results[], int n, int numTowns){
	countTown(data, results, n, &numTowns);
	printf("Number of towns: %d\n", numTowns);
	for(int i = 0; i < numTowns; ++i){
		printf("Town %d: %d blocks\n", i + 1,results[i]);
	}
}
