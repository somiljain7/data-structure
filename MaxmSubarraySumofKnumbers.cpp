//Window Sliding Algorithm to find maximum subarray sum of k numbers
#include <iostream>
#include <algorithm>
using namespace std;
int Sum(int arr[],int n,int k)
{
	int sum = 0;
	
	for(int i=0;i<k;i++)
	sum+=arr[i];
	
	int maxmSum = sum;
	
	for(int i=k;i<n;i++)
	{
	sum+=arr[i]-arr[i-k];
	maxmSum = max(maxmSum,sum);
	}
	return maxmSum;
}
int main()
{
	int arr[] = {19,-1,34,-37,0,56,23};
	int n = sizeof(arr)/sizeof(int);
	int k;
	cout<<"Enter the subarray length:";
	cin>>k;
	cout<< "The Maximum subarry sum:"<<Sum(arr,n,k);
}