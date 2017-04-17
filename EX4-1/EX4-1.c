#include <stdio.h>
#include <stdlib.h>


typedef int elem;
typedef struct treenode* tree;
struct treenode{
	tree left;
	tree right;
	elem data;
};

//�������Ķ��У����ڱȽϸ���δ֪
typedef struct queuenode* quenode;
struct queuenode{
	int data;
	quenode next;	
};
typedef struct queuehead* queue;
struct queuehead{
	int count;
	quenode head;
	quenode rear;
};


//���еĲ���
void queinsert(int data,queue q){
	quenode newqnode=(quenode)malloc(sizeof(quenode));
	newqnode->data=data;
	q->rear->next=newqnode;
	q->rear=q->rear->next;
	q->count++;
} 

//�ж϶����Ƿ�Ϊ��
int isqueempty(queue q){
	return q->count==0;
} 

//���е����
int quepop(queue q){
	int pop=0;
	if(isqueempty(q)){
		return -1;
	}else{
		quenode qn=q->head->next;
		pop=qn->data;
		if(q->count==1){
			q->rear=q->head; 
		}
		q->count--; 
		q->head->next=qn->next;
		free(qn);
		return pop;
	}
} 

//�������У�����һ���սڵ�
queue createqueue(){
	queue newque=(queue)malloc(sizeof(queue));
	quenode qn=(quenode)malloc(sizeof(quenode));
	newque->count=0;
	qn->next=NULL;
	qn->data=0;
	newque->rear=qn;
	newque->head=qn;
	return newque;
} 
 
//�����������в����½ڵ� 
void insertnode(int nodedata,tree t){
	if(nodedata<t->data){
		if(t->left==NULL){
			tree newnode=(tree)malloc(sizeof(tree));
			newnode->data=nodedata;
			newnode->left=NULL;
			newnode->right=NULL;
			t->left=newnode;
		}else{
			insertnode(nodedata,t->left); 
		}
	}else if(nodedata>t->data){
		if(t->right==NULL){
			tree newnode=(tree)malloc(sizeof(tree));
			newnode->data=nodedata;
			newnode->left=NULL;
			newnode->right=NULL;
			t->right=newnode;
		}else{
			insertnode(nodedata,t->right); 
		}
	}else{
		
	}
	
} 

//�Ƚ϶������Ƿ���ͬ
int isSameTree(tree t1,tree t2){
	int l=0,r=0,mid=0;
	mid=(t1->data==t2->data);
	if(t1->left!=NULL&&t2->left!=NULL){
		l=isSameTree(t1->left,t2->left);
	}else if(t1->left==NULL&&t2->left==NULL){
		l=1;
	}else{
		l=0;
	}
	if(t1->right!=NULL&&t2->right!=NULL){
		r=isSameTree(t1->right,t2->right);
	}else if(t1->right==NULL&&t2->right==NULL){
		r=1;
	}else{
		r=0;
	}
	return mid&l&r;
} 

//��ȡ���� 
tree createtree(int nodecount){
	tree newtree=(tree)malloc(sizeof(tree));
	//int *datas=(*int)malloc(sizeof(int)*nodecount);
	int i,data=0;
	scanf("%d",&data);
	newtree->data=data;
	newtree->left=NULL;
	newtree->right=NULL;
	for(i=1;i<nodecount;i++){
		scanf("%d",&data);
		insertnode(data,newtree);
	}
	//scanf("\n");
	return newtree;
}

//������ 
int main() {
	int nodecount,comcount,result=0;
	queue que=createqueue();
	do{
		scanf("%d",&nodecount);
		if(nodecount==0){
			break;
		}else{
			scanf("%d",&comcount);
			//printf("nc:%d cc:%d\n",nodecount,comcount);
			tree tree0;
			tree0=createtree(nodecount);
			for(comcount;comcount>0;comcount--){
				tree comtree;
				comtree=createtree(nodecount);
				result=isSameTree(tree0,comtree);
				queinsert(result,que);
			}
		}	
	}while(1);
	while(!isqueempty(que)){
		result=quepop(que);
		if(result==1){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}
