//Program to perform binary search on an array
#include <iostream>
#include<algorithm>
using namespace std;
void binsearch(int *A,int s){
   int mid;
    low=0;
   high=n-1;                        //Initially our search space is the whole array
   while(low<=high)
   {
       mid=low+((high-low)/2);
       if(A[mid]==s)
            break;
        else if(A[mid]>s)           // The element we are searching lies on the left side of middle element
            high=mid-1;
        else
            low=mid+1;             // The element we are searching lies on the right side of middle element
   }
   
    if(low<=high)
        cout<<"Element is present at index "<<mid;
    else
        cout<<"Element not present in the array";
    
   return 0;
}

int main() {
   int n,s,i,low,high,mid;
   cout<<"Enter the number of elements";
   cin>>n;
   
   int A[n];
   cout<<"Enter the elements of array";
   for(i=0;i<n;i++)
   {
       cin>>A[i];
   }
   
   cout<<"Enter the element to be searched";
   cin>>s;
   
   sort(A,A+n); 
   binsearch(A,s);//Binary search is applicable only on sorted array
}
