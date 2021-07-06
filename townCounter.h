#include <stdio.h>
#include <stdlib.h>

void allocateMem(int *data[], int n);

int getPos(int x, int y, int n);

void sort(int array[], int first, int last);

void countTown(int data[],  int results[], int n, int *numTowns);

void DFS(int data[], int visited[], int y, int x, int n, int *occ_blocks);

int isSafe(int data[], int visited[], int y, int x, int n);