#include<stdio.h>
#include<stdlib.h>
typedef struct dinayrTree{
	int data;
    struct dinayrTree* lchild;
    struct dinayrTree* rchild;
}DT;
void creatDT(DT** node){
	int n;
	printf("请输入一个节点值，若节点值为#，则为NULL：");
	scanf("%d",&n);
	if(n==0){
		(*node)=NULL;
		return;
	}
	(*node)=(DT*)malloc(sizeof(DT));
	(*node)->data=n;
	creatDT(&((*node)->lchild));
	creatDT(&((*node)->rchild));
}
void printDT(DT* node){
	if(node==NULL)
	return;
	printf("%d ",node->data);
	printDT(node->lchild);
	printDT(node->rchild);
}
int main(){
	DT* tree1=NULL;
	creatDT(&tree1);
	printDT(tree1);
}
