#include "mandatory.h"

//Allocates the an array of size n and initializes it's values with 0, if it can't allocate the memory the program exits with code 1
void allocateMem(int **data, int n){
	*data = (int*)calloc(n, sizeof(int));
	if(*data == NULL){
		printf("\nMemory not allocated!\n");
		exit(1);
	}
}
//Returns the position in a 1D array as if it were a NxN matrice
int getPos(int x, int y, int n){
	return ((x * n) + y);
}

//Simple quicksort algorithm to sort out the occupied blocks by ascending order in the end
void sort(int array[], int first, int last){ 
	if(first < last){
		int i = first, j = last, pivot = first, aux;
     		while(i < j){
         		while(array[i] <= array[pivot] && i < last)	i++;
         		while(array[j] > array[pivot])	j--;
        		if(i < j){
            			aux = array[i];
            			array[i] = array[j];
            			array[j] = aux;
         		}
      		}
		aux = array[pivot];
		array[pivot] = array[j];
		array[j] = aux;
		sort(array, first, j - 1);
		sort(array, j + 1, last);
   	}
}

//Checks the border cases of a given cell and if it has already been visited, returns 0 if it is not "safe" and 1 if it is
int isSafe(int data[], int visited[], int y, int x, int n){ 
    return ((x >= 0 && x < n && y >= 0 && y < n) && (data[getPos(x, y, n)] == 1 && !visited[getPos(x, y, n)])); 
} 
  
//Checks all 4 directions and if it is "safe" it'll  increment the occurence of blocks and then call itself in recursion
void DFS(int data[], int visited[], int y, int x, int n, int *occBlocks){ 
    static int row[] = { 0, -1, 0, 1 }; 
    static int col[] = { -1, 0, 1, 0 }; 
    visited[getPos(x, y, n)] = 1; 
    for (int k = 0; k < 4; ++k){
        if (isSafe(data, visited, y + row[k], x + col[k], n)){
        	*occBlocks = (*occBlocks + 1);
            DFS(data, visited, y + row[k], x + col[k], n, occBlocks);
        }
    }
} 
  
//Counts the number of blocks in a town and the number of towns using a depth first search algorithm
void countTown(int data[], int results[], int n, int *numTowns){
    int *visited = NULL;
    allocateMem(&visited, (n * n));
    int townSize = 1, j;
    for(int y = 0; y < n; ++y){
		for(int x = 0; x < n; ++x){
			if(data[getPos(x, y, n)] && !visited[getPos(x, y, n)]){
				DFS(data, visited, y, x, n, &townSize);
                if(townSize > 1){
                	results[*numTowns] = townSize;
                	*numTowns = (*numTowns + 1);
                	townSize = 1;
                }
			}
		}
	}
	free(visited);
	sort(results, 0, *numTowns - 1);
	for(j = 0; results[j] != 0; ++j){}
	results = (int*)realloc(results, j);
} 