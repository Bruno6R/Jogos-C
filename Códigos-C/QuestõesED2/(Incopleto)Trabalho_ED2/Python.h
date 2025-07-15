#define new(Type) new_##Type()

typedef struct Node{
	void *item;
	struct Node *next;
	struct Node *prev;
}Node;

typedef Node* Object;

Object new_Node(){
	Object no=malloc(sizeof(Node));
	no->item=NULL;   
	no->next=NULL;
	no->prev=NULL;
	return no;
}

Object new_Int(){
	Object novo=new(Node);
	novo->item=malloc(sizeof(int));
	int *v = novo->item;
	*v=0;
	return novo;
}

void setInt(Object self, int valor){
	int *v=self->item;
	*v=valor;
}

void printInt(Object self){
	int *v=self->item;
	int a=*v;
	printf("(%d)\n", a);
}

void destroy(Object obj){
	free(obj);
	obj->item=NULL;
}
