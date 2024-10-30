#include<stdio.h>
#include<stdlib.h>
typedef struct dinaryTree {
	int date;
	struct dinaryTree* llist;
	struct dinaryTree* rlist;
}DT;
typedef struct queue {
	DT* arr[20];
	int rear;
	int top;
}Q;

typedef struct Stact {
	int top;
	DT* arr[8];
}S;
void inStact(S* stact, DT* dt);
void inqueue(Q* queue, DT* dt);
void outqueue(Q* queue);
void printfDTQ(DT* dt) {
	if (dt == NULL)
		return;
	Q* queue = (Q*)malloc(sizeof(Q));
	queue->rear =0;
	queue->top = 0;
	inqueue(queue, dt);
	while (queue->top != queue->rear) {
		printf("%d ", queue->arr[queue->rear]->date);
		if (queue->arr[queue->rear]->llist)
			inqueue(queue, queue->arr[queue->rear]->llist);
		if (queue->arr[queue->rear]->rlist)
			inqueue(queue, queue->arr[queue->rear]->rlist);
		outqueue(queue);
	}
}
void inqueue(Q* queue, DT* dt) {
	if ((queue->top - queue->rear) % 20 == 19)
		return;
	queue->arr[queue->top] = dt;
	queue->top = (queue->top + 1) % 20;
}
void outqueue(Q* queue) {
	if (queue->top == queue->rear)
		return;
	queue->arr[queue->rear] = NULL;
	queue->rear = (queue->rear + 1) % 20;
}
DT* creatdt(int n0) {
	DT* newdt = (DT*)malloc(sizeof(DT));
	newdt->date =n0;
	newdt->llist = NULL;
	newdt->rlist = NULL;
	return newdt;
}
void insertLeft(DT* node, int n) {
	DT* insertDt = creatdt(n);
	node->llist = insertDt;
}
void insertRight(DT* node, int n) {
	DT* insertDt = creatdt(n);
	node->rlist = insertDt;
}
void printDT(DT* dt1) {
	if (dt1 == NULL)
		return;
	printDT(dt1->llist);
	printf("%d ", dt1->date);
	printDT(dt1->rlist);
}
void printDTpro(DT* dt1) {
	S* stact = (S*)malloc(sizeof(S));
	stact->top=0;
	DT* q = dt1;
	DT* temp;
	while (q || stact->top) {
		if (q) {
			inStact(stact, q);
			q = q->llist;
		}
		else {
			printf("%d ", stact->arr[stact->top - 1]->date);
			q = stact->arr[stact->top - 1]->rlist;
			stact->top--;
		}
	}
}
void inStact(S* stact, DT* dt) {
	stact->arr[stact->top] = dt;
	stact->top++;
}
DT* creatDT() {
	char a;
	scanf("%c",&a);
	if (a == '#') {
		return NULL;
	}
	DT* newdt = (DT*)malloc(sizeof(DT));
	if (newdt==NULL)
	{
		return NULL;
	}
	newdt->date=a;
	newdt->llist=creatDT();
	newdt->rlist=creatDT();
	return newdt;
}
DT* copyDT(DT* root) {
	if (root == NULL) {
		return NULL;
	}

	// 创建新的节点
	DT* newNode = (DT*)malloc(sizeof(DT));
	newNode->date = root->date;
	newNode->llist = copyDT(root->llist);
	newNode->rlist = copyDT(root->rlist);

	return newNode;
}
int number(DT* root) {
	if (root == NULL)
		return 0;
	return number(root->llist)+number(root->rlist)+1;
}
int deepth(DT* root) {
	if (root == NULL)
		return 0;
	int m = deepth(root->llist);
	int n = deepth(root->rlist);
	if (m > n)
		return m + 1;
	else
		return n + 1;
}
int solochild(DT* root) {
	if (root == NULL)
		return 0;
	if (root->llist == NULL && root->rlist == NULL)
		return 1;
	return solochild(root->llist)+solochild(root->rlist);
}
int main() {
	DT* dt1 = creatdt(3);
	insertLeft(dt1, 2);
	insertLeft(dt1->llist, 4);
	insertRight(dt1->llist->llist, 5);
	insertRight(dt1, 1);
	insertRight(dt1->rlist, 6);
	insertLeft(dt1->rlist->rlist, 7);
	insertRight(dt1->rlist->rlist, 8);
	printDT(dt1);
	printf("\n");
	printDTpro(dt1);
	printf("\n");
	printfDTQ(dt1); 
	printf("\n");
	DT* dt2 = copyDT(dt1);
	printDT(dt2);
	printf("\n");
	int num = number(dt1);
	printf("%d\n", num);
	int deep = deepth(dt1);
	printf("%d\n", deep);
	int solo = solochild(dt1);
	printf("%d\n", solo);
	return 0;
}
