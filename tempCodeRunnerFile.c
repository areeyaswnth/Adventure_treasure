#include <stdio.h>

int count = 0;
void readSquare(int size, int sq[size][size]);
int findMaxSum(int size, int sq[size][size]);
int main ()
{
	int N, sq[20][20], maxSum;
	printf ("Enter size of your square: ");
	scanf ("%i", &N);
	while (N < 3 || N > 20) {
		printf ("Invalid Input!!\n");
		printf ("Enter size of your square: ");
		scanf ("%i", &N);
	}	
	printf ("Enter your square: ");
	readSquare (N, sq);
	maxSum = findMaxSum(N, sq);
	if(count != 0 ) {
		printf("Your square is NOT a magic square.\n");
		printf("The maximum sum is %i", maxSum);
	}
	else if(count == 0) {
		printf("Your square is a magic square!!\n");
		printf("The magic constant is %i", maxSum);
	}
	
	return 0;
}

void readSquare(int size, int sq[size][size]) 
{
	int r, i;
	for (r = 0 ; r < size ; r++) {
		for (i = 0 ; i < size ; i++) {
			scanf ("%i", &sq[r][i]);
		}
	}
}

int findMaxSum(int size, int sq[size][size])
{
	int i, j, k, rowSum = 0, colSum = 0, diagSum1 = 0, diagSum2 = 0, sum[(size*2)+2];
	k = size;
		
	for(i = 0 ; i < size ; i++) {
		for(j = 0 ; j < size ; j++) {
			if (i == j)
			diagSum1 = diagSum1 + sq[i][j]; 
		}
	}
	
	for(i = 0 ; i < size ; i++) {
		for(j = (size-1)-i ; j == (size-1)-i ; j++)
			diagSum2 = diagSum2 + sq[i][j];
	}
	
	for(i=0; i < size ;i++){
		for(j=0; j < size ;j++){
			rowSum = rowSum + sq[i][j];
			colSum = colSum + sq[j][i];
		}		
		sum[i] = rowSum;
		sum[k] = colSum;
		k++;
		rowSum = 0;
		colSum = 0;
	}
	
	sum[k] = diagSum1;
	sum[k+1] = diagSum2;
	
	int temp = sum[0];
	for(i = 0 ; i < size*2+2 ; i++) {
		if(sum[i] > temp)
			temp = sum[i] ;
		for(j = 0 ; j < size*2+2 ;j++) {
			if(sum[i] != sum[j])
			{
				count++;
			}
		}
	}
	
	return temp;
}