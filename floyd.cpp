#include<stdio.h>
#define MAX 100
int main(){
	int D[4][4]={{0,10,3,MAX},
	             {9,0,8,7},
				 {MAX,5,0,2},
				 {MAX,6,MAX,0}};
	int P[4][4]={{-1,0,0,-1},
	             {1,-1,1,1},
				 {-1,2,-1,2},
				 {-1,3,-1,-1}};
	for(int a=0;a<4;a++){
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++){
			if(i==a||j==a||i==j)
			continue; 
			else{
				int temp=D[i][a]+D[a][j];
				if(temp<D[i][j]){
					D[i][j]=temp;
					if(P[a][j]==a){
						P[i][j]=a;
					}else{
						P[i][j]=P[a][j];
					}
				}
			}
		}
	}
}
	for(int a=0;a<4;a++){
	for(int i=0;i<4;i++){
		printf("%d ",D[a][i]);
	}
	printf("\n");
	}
		for(int a=0;a<4;a++){
	for(int i=0;i<4;i++){
		printf("%d ",P[a][i]);
	}
	printf("\n");
	}
	return 0;
}
