#include <iostream>
using namespace std;
int Max(int a,int b,int c)
{
	return (a>b && a>c)? a: (b>c)? b :c;
}
int Max(int arr[], int n)
{
	int max=arr[0];
	for(int i=0;i<n;i++)
		max= (arr[i]>max) ? max= arr[i] : max;
	return max;
}
int main()
{
	int a,b,c;
	cout<<"Enter 3 numbers :";
	cin>>a>>b>>c;
	cout<<"Maximum of three numbers = "<<Max(a,b,c)<<endl;
	int n;
	cout<<"Enter the size of array = ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of the array =";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Maximum element of the array = "<<Max(arr,n);
}

