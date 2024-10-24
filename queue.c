


typedef struct {
    int arr[10000];
    int top;
    int rear;
} Checkout;


Checkout* checkoutCreate() {
        Checkout* obj = (Checkout*)malloc(sizeof(Checkout));
    obj->rear=0;
    obj->top=0;
    return obj;
}

int checkoutGet_max(Checkout* obj) {
    	if(obj->rear==obj->top)
	return -1;
	int i;
	int max = obj->arr[obj->rear];
    for(i=obj->rear;i<obj->top;i++){
    	if(obj->arr[i]>max)
    	max = obj->arr[i];
	}
	return max;
}

void checkoutAdd(Checkout* obj, int value) {
        obj->arr[obj->top]=value;
    obj->top++;
}

int checkoutRemove(Checkout* obj) {
        if(obj->rear==obj->top)
    	return -1;
    	int e =obj->arr[obj->rear];
	obj->rear++;
	return e;
}

void checkoutFree(Checkout* obj) {
     free(obj);
}
