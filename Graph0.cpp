#include<stdio.h>
#include<stdlib.h>
typedef struct Graph{
	char ves[100];
	int  arcs[100][100];
	int vesnum,arcnum; 
}G;
void creatUDWG(G* g){
	int row,col;
	printf("�������ܱ���:\n");
	scanf("%d",&(g->arcnum));
	printf("�������ܶ�����:\n");
	scanf("%d",&(g->vesnum));
	for(int i=0;i<(g->vesnum);i++){
		printf("��������������Ϣ:");
		scanf(" %c",&(g->ves[i]));
	}
	for(int a=0;a<g->vesnum;a++){
		for(int b=0;b<g->vesnum;b++){
			g->arcs[a][b]=0;
		}
	}
	for(int j =0;j<(g->arcnum);j++){
		printf("������Ҫ�������ߵĶ���:");
		scanf("%d%d",&row,&col);
		g->arcs[row][col]=1;
		g->arcs[col][row]=1;
	}
}
int main(){
	G* G1=(G*)malloc(sizeof(G));
	creatUDWG(G1);
	return 0;
} 
