#include<iostream>
using namespace std;
int main(){
    int arr[]={0,31,124,234,13,43,55};
    for(int i=2;i<7;i++){
    	if(arr[i]<arr[i-1]){
    		arr[0]=arr[i];
    		int low=1;
    		int high=i-1;
    		int mid;
    		while(low<=high){
    		 mid=(low+high)/2;
    			if(arr[0]<arr[mid])high=mid-1;
    			else low=mid+1;
			}
			//插入位置为high+1;
			for(int j=i-1;j>=high+1;j--){
				arr[j+1]=arr[j];
			} 
			arr[high+1]=arr[0];
		}
	}
	for(int i=1;i<7;i++){
		cout<<arr[i]<<" ";
	}
    return 0;
}
