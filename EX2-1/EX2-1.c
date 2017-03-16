#include <stdio.h>

typedef int DataType;
typedef struct Node *PtrToNode;
struct Node {
    DataType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Merge(List l1,List l2){		//合并两个有序链表,返回结果链表头 
	List tmpptr,result;
	tmpptr = (List)malloc(sizeof(List));
	result = (List)malloc(sizeof(List));
	if(l1->Next==NULL&&l1->Next==NULL){
		return result;
	}else if(l1->Next==NULL){
		return l2;
	}else if(l2->Next==NULL){
		return l1;
	}else{
		result->Data = 0;
		tmpptr->Data = 0;
		tmpptr->Next = result;
		while(l1->Next&&l2->Next){						//开始合并链表，直到某一个链表合完。 
			if(l1->Next->Data<l2->Next->Data){
				tmpptr->Next->Next = l1->Next;
				l1->Next = l1->Next->Next;
				tmpptr->Next = tmpptr->Next->Next;
				tmpptr->Next->Next = NULL;			
			}else{
				tmpptr->Next->Next = l2->Next;
				l2->Next = l2->Next->Next;
				tmpptr->Next = tmpptr->Next->Next;
				tmpptr->Next->Next = NULL;
			}
			
		}
		if(l1->Next!=NULL){			//合并两个链表生下来的部分。 
			tmpptr->Next->Next = l1->Next;
			l1->Next = NULL;
		}
		if(l2->Next!=NULL){
			tmpptr->Next->Next = l2->Next;
			l2->Next = NULL;
		}
		free(tmpptr);
		return result;	
	}
}

List read(){
	//void Print(List);
	List out,current;
	out=(List)malloc(sizeof(List));
	current=(List)malloc(sizeof(List));
	out->Next=NULL;
	current->Next = out;
	//out->Data=NULL;			//表头第一个元素设NULL 
	int in1,i,number;
	scanf("%d",&in1);
	for(i=0;i<in1;i++){
		scanf("%d",&number);
		List tmp = (List)malloc(sizeof(List));
		tmp->Data=number;
		tmp->Next=NULL;
		current->Next->Next=tmp;
		current->Next=current->Next->Next;
	}
	return out;
}

void Print( List L ){			//打印一个链表，链表为空（只有表头）时，输出NULL 
	if(NULL == L->Next){
		printf("NULL");
	}else{
		printf("%d",L->Next->Data);
		L = L->Next;
		while(L->Next){
			L = L->Next;
			printf(" %d",L->Data);
		}
	}
	printf("\n");
}

int main(int argc,  char ** argv){
	List l1,l2,out;
	l1=(List)malloc(sizeof(List));
	l2=(List)malloc(sizeof(List));
	out=(List)malloc(sizeof(List));
	l1=read();
	l2=read();
	out=Merge(l1,l2);
	Print(out);
	Print(l1);
	Print(l2);
	return 0;
}


