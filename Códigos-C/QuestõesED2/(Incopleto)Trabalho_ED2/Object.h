#define new(Type) new_##Type()

typedef enum{
	PROFESSOR, 
	DISCIPLINA,
}TypeObject;

typedef struct Node{
	void *item;
	
	struct Node *next;
	struct Node *prev;
	
	//vars 
	int id;
	TypeObject type;
	//funcs da struct
	void (*print) (struct Node*);
	void (*set)();
	void (*destroy)();
}Node;

typedef Node* Object;

void destroy(Object obj){
	free(obj->item);
	free(obj);
}

Object new_Node(){
	Object no=malloc(sizeof(Node));
	no->item=NULL;   
	no->next=NULL;
	no->prev=NULL;
	no->destroy = destroy;
	no->set = NULL;
	no->print = NULL;
	return no;
}

Object new_Int(){
	Object novo=new(Node);
	novo->item=malloc(sizeof(int));
	int *v = novo->item;
	*v=0;
	return novo;
}
