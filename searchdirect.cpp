#include<iostream>
using namespace std;
int main(){
	int i,j;
    int arr[]={0,31,124,234,13,43,55};
    for( i=2;i<7;i++){
    	if(arr[i]<arr[i-1]){
    		arr[0]=arr[i];
    		for( j=i-1;arr[j]>arr[0];j--){
    			arr[j+1]=arr[j];
			}
			arr[j+1]=arr[0];
		}
	}
	for(int i=1;i<7;i++){
		cout<<arr[i]<<" ";
	}
    return 0;
}
