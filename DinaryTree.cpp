#include<stdio.h>
#include<stdlib.h>

typedef struct dinaryTree{
	int date;
	struct dinaryTree* llist;
	struct dinaryTree* rlist;
}DT; 
typedef struct Stact{
	int top;
	DT arr[8];
}S;
void inStact(S* stact,DT* dt,int top);
DT *creatdt(int n0){
	DT* newdt=(DT*)malloc(sizeof(DT));
	newdt->date=n0;
	newdt->llist=NULL;
	newdt->rlist=NULL;
	return newdt;
}
void insertLeft(DT* node,int n){
	DT* insertDt = creatdt(n);
	node->llist=insertDt;
}
void insertRight(DT* node,int n){
	DT* insertDt = creatdt(n);
	node->rlist=insertDt;
}
void printDT(DT* dt1){
	if(dt1==NULL)
	return;
	printDT(dt1->llist);	
	printf("%d\n",dt1->date);
	printDT(dt1->rlist);
}
void printDTpro(DT* dt1) {
	S* stact=(S*)malloc(sizeof(S));
	int top=0;
	DT* q=dt1;
	DT* temp;
	while(q||top){
		if(q){
			inStact(stact,q,top);
			q=q->llist;
		}else{
			printf("%d ",stact->arr[top-1]->date);
			q=arr[top-1]->rlist;
			top--;
		}
	}
}
void inStact(S* stact,DT* dt,int top){
	stact->arr[top]=dt;
	top++;
}
int main(){
	DT* dt1=creatdt(3);
	insertLeft(dt1,2);
	insertLeft(dt1->llist,4);
	insertRight(dt1->llist->llist,5);
	insertRight(dt1,1);
	insertRight(dt1->rlist,6);
	insertLeft(dt1->rlist->rlist,7);
	insertRight(dt1->rlist->rlist,8);
	printDTpro(dt1);
	return 0;
}
