#include <stdio.h>
#include <stdlib.h>
#define EMPTY -1

typedef int element;
typedef struct qnode* ptrqnode;
struct qnode{
	element data;
	ptrqnode next;
};
typedef struct queuestruct* queue;
struct queuestruct{
	ptrqnode head;
	ptrqnode rear;
};

element *flags,*lefts,*rights;  

//创建队列 
queue createQueue(){
	queue q=(queue)malloc(sizeof(struct queuestruct));
	q->head=(ptrqnode)malloc(sizeof(struct qnode));
	q->rear=(ptrqnode)malloc(sizeof(struct qnode));
	q->head->data=0;	
	q->head->next=NULL;
	q->rear->next=q->head;
	q->rear->data=0;
	return q;
}

//压入队列
void push(queue q,element inelement){
	ptrqnode in=(ptrqnode)malloc(sizeof(struct qnode));
	in->data=inelement;
	in->next=NULL;
	q->rear->next->next=in;
	q->rear->next=in;
	q->head->data+=1; 
} 

//浮出队列最先压入的一项（若队列不为空）
element pop(queue q){
	if(q->head->data>0){
		element popdata;
		ptrqnode popnode;
		popnode=q->head->next;
		q->head->next=q->head->next->next;
		popnode->next=NULL;
		popdata=popnode->data;
		free(popnode);
		q->head->data-=1;
		if(q->head->data==0){
			q->rear->next=q->head; 
		}
		return popdata;
	}else{
		printf("Queue is empty!");
		return -1;
	}
} 

//读取实验数据 
element read(int nodecount){	
	int i=0;	
	element root=0;
	char cl,cr;
	lefts=(element*)malloc(sizeof(int)*nodecount);
	rights=(element*)malloc(sizeof(int)*nodecount);
	flags=(element*)malloc(sizeof(int)*nodecount);
	
	for(i=0;i<nodecount;i++){
		lefts[i]=-1;
		rights[i]=-1;
		flags[i]=-1;
	} 
	for(i=0;i<nodecount;i++){
		scanf("\n%c %c",&cl,&cr);
		if(cl=='-'){
			lefts[i]=EMPTY;
		}else{
			lefts[i]=cl-'0';
			flags[lefts[i]]=1;
		}
		if(cr=='-'){
			rights[i]=EMPTY;
		}else{
			rights[i]=cr-'0';
			flags[rights[i]]=1;
		}
	} 
	
	for(i=0;i<nodecount;i++){
		if(flags[i]==-1){
			root=i;
			break;
		}
	} 
	return root;
}

void listLeaves(int root,queue q,int nodecount){
	push(q,root);
	element popn;
	char f='0';
	while(q->head->data>0){
		popn=pop(q);
		if(lefts[popn]==-1&&rights[popn]==-1){
			if(f=='0'){
				f='1';
				printf("%d",popn);
			}else{
				printf(" %d",popn);
			}
		}else{
			if(lefts[popn]!=-1){
				push(q,lefts[popn]);
			}
			if(rights[popn]!=-1){
				push(q,rights[popn]);
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int nodecount=0;
	scanf("%d",&nodecount);
	int broot=0;
	broot=read(nodecount);
	queue qu=createQueue();
	listLeaves(broot,qu,nodecount);
	return 0;
}
