#include<stdio.h>
#include<stdlib.h>
typedef struct arcnode{
	int tag;
	struct arcnode* next;
}AN;
typedef struct vesnode{
	char name;
	AN* outnode;
	AN* innode;
}VN;
typedef struct {
	int vesnum, arcnum;
	VN** arr;
}G;
int findVN(G* g,char ch) {
	for (int i = 0; i < g->vesnum; i++) {
		if (g->arr[i]->name == ch)
			return i;
	}
	return -1;
}
void creatG(G* g) {
	printf("�������Ľ����:");
	scanf("%d",&(g->vesnum));
	g->arr = (VN **)malloc(sizeof(VN) * g->vesnum);
	for (int i = 0; i < g->vesnum; i++) {
		g->arr[i] =(VN*) malloc(sizeof(VN));
		printf("�����%d��������(��Сд��ĸ��ʾ):",i);
		scanf(" %c",&(g->arr[i]->name));
		g->arr[i]->innode = NULL;
		g->arr[i]->outnode = NULL;
	}
	printf("�������ı���:");
	scanf("%d",&g->arcnum);
	char a, b;
	for (int j = 0; j < g->arcnum; j++) {
		printf("��ֱ���������������(�������Ҫ˳��):");
		scanf (" %c %c",&a,&b);
		int htag = findVN(g, a);
		int ttag = findVN(g, b);
		AN* inan = (AN*)malloc(sizeof(AN));
		AN* outan = (AN*)malloc(sizeof(AN));
		AN* temp;
		inan->tag = ttag;
		outan->tag = htag;
		outan->next = NULL;
		temp = g->arr[htag]->outnode;
		g->arr[htag]->outnode = inan;
		inan->next = temp;
		temp = g->arr[ttag]->innode; 
		g->arr[ttag]->innode = outan;
		outan->next = temp;
	}
}
int main() {
	G* g0 = (G*)malloc(sizeof(G));
	creatG(g0);
	return 0;
}