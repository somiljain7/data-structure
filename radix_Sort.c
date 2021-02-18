#include<stdio.h>

#define SIZE 10

void radixSort(int arr[]);

int main()
{
	int arr[SIZE];
	int i = 0; 

	printf("Enter %d elements: ", SIZE);
	for(i = 0; i < SIZE; i++)
	{
		scanf("%d", &arr[i]);
	}

	radixSort(arr);

	return 0;
}//main fn ends

void radixSort(int arr[])
{
	int bucket[10][SIZE], count[10];
	int divisor = 1;
	int i = 0, max = 0, len = 0, j = 0, temp = 0, k = 0, l = 0;

	//find max element in entire array
	for(max = arr[0], i = 1; i < SIZE; i++)
	{
		if(max < arr[i])
		{
			max = arr[i];
		}
	}

	//find no of digits in max number of array (ie, length of the max num of array)
	if(max == 0)
	{
		len = 1;
	}
	else
	{
		while(max != 0)
		{
			len++;
			max /= 10;
		}
	}


	for(divisor = 1, i = 1; i <= len; i++)
	{
		//initialize count array with 0
		for(j = 0; j < 10; j++)
		{
			count[j] = 0;
		}

		//place element in bucket (2D arr) and inc its count in count arr
		for(j = 0; j < SIZE; j++)
		{
			temp = (arr[j]/divisor) % 10;
			bucket[temp][count[temp]] = arr[j];
			count[temp]+=1;
		}

		//replacing orig arr with elmnts from bucket (2D arr)
		for(l = 0, j = 0; j < 10; j++)
		{
			for(k = 0; k < count[j]; k++)
			{
				arr[l] = bucket[j][k];
				l++;
			}
		}

		divisor *= 10;

		//printing orig arr for every pass. Last pass will give final ans.
		printf("Pass no. %d: ", i);
		for(j = 0; j < SIZE; j++)
		{
			printf("%d ", arr[j]);
		}
		printf("\n");
	}//outermost for loop ends
}//fn radixSort ends
