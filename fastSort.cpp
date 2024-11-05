#include<iostream>
using namespace std;
void fastSort(int* arr,int low,int high){
	if(low>=high)
	return;
	int temp=high;
	int pivot=arr[low];
	while(low<high){
		while(low<high&&arr[high]>=pivot)
		high--;
		arr[low]=arr[high];
		while(low<high&&arr[low]<=pivot)
		low++;
		arr[high]=arr[low];
	}
	arr[high]=pivot;
	fastSort(arr,0,low-1);
	fastSort(arr,high+1,temp);
}
int main(){
	int arr[8]={21,312,324,12,53,72,173,31};
	int len=8;
	fastSort(arr,0,7);
	for(int i=0;i<8;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
