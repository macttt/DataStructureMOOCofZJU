#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef char str[6];
typedef str* strc;
typedef int* dataStack; 
typedef struct node* ptrtoNode;
struct node{
	int data;			//设定head结点的data为revcount 
	ptrtoNode next;
	int address;
	int nextAdd;
};
typedef ptrtoNode list; 

//打印链表 
void Print( list L ){				 
	if(NULL == L->next){
		printf("0 0");
	}else{
		L = L->next;
		while(L){;
			if(L->next){
				printf("%05d %d %05d",L->address,L->data,L->next->address);
				printf("\n");
			}else{
				printf("%05d %d -1",L->address,L->data);
			}
			L = L->next;
		}
	}
}

//逆转链表函数
void reverseList(list in,int k,int listLength){
	if(in->next==NULL){
		Print(in);
	}else if(k==0){
		Print(in);; 
	} else{
		int i,j=0;
		list rear,head,tmphead,tmp;
		rear=(list)malloc(sizeof(struct node));
		head=(list)malloc(sizeof(struct node));
		tmphead=(list)malloc(sizeof(struct node));
		tmp=(list)malloc(sizeof(struct node));
		rear=head;
		head->next=NULL;
		tmp->next=NULL;
		tmp->data=0;
		tmphead=head; 
		rear->data=0;
		head->data=0;
		tmphead->data=0;
		for(i=k-1;i<listLength;i=i+k){
			for(j=0;j<k;j++){
				tmp=in->next;
				in->next=in->next->next;
				tmp->next=tmphead->next;
				tmphead->next=tmp;				
				if(j==0){
					rear=tmp;
				}
			}
			tmphead=rear;
		}
		rear->next=in->next;			
		Print(head); 
	}
} 

int main() {
	int i=0,j=0,listcount=0,revcount=0,tmpnodedata=0,nextaddtmp=0;
	str headaddress,paddtmp,naddtmp;
	list inhead,outhead,tmpnode,tmppnode,newnode,L,headtmp;
	dataStack ds;
	inhead=(list)malloc(sizeof(struct node));
	outhead=(list)malloc(sizeof(struct node));
	inhead->data=0;
	inhead->next=NULL; 
	scanf("%s %d %d",headaddress,&listcount,&revcount);
	dataStack add=(dataStack)malloc(sizeof(dataStack)*99999);	
	dataStack nAdds=(dataStack)malloc(sizeof(dataStack)*99999); 
	ds=(dataStack)malloc(sizeof(dataStack)*99999);
	for(i=0;i<listcount;i++){
		newnode=(list)malloc(sizeof(struct node));
		scanf("%s %d %s",&paddtmp,&tmpnodedata,&naddtmp);
		add[atoi(paddtmp)]=tmpnodedata;
		nAdds[atoi(paddtmp)]=atoi(naddtmp);		
	}
	nextaddtmp=atoi(headaddress);
	tmpnode=(list)malloc(sizeof(struct node));
	tmpnode=inhead;
	newnode=(list)malloc(sizeof(struct node));
	newnode->next=inhead->next;
	while(nextaddtmp!=-1){				//这个双重循环产生输入链表L		
		inhead->data+=1;
		newnode=(list)malloc(sizeof(struct node));
		newnode->next=NULL;
		newnode->data=add[nextaddtmp];
		newnode->address=nextaddtmp;
		tmpnode->next=newnode;
		tmpnode=tmpnode->next;
		nextaddtmp=nAdds[nextaddtmp];
	}
	reverseList(inhead,revcount,inhead->data);	
	return 0;
}

/*
 Reversing Linked List
Given a constant KK and a singly linked list LL, 
you are supposed to reverse the links of every KK elements on LL. 
For example, given LL being 1→2→3→4→5→6, if K = 3K=3, 
then you must output 3→2→1→6→5→4; if K = 4K=4, 
you must output 4→3→2→1→5→6.
Sample Input:

00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

Sample Output:

00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/
