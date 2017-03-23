/*
Given a stack which can keep MM numbers at most.Push NN numbers 
in the order of 1, 2, 3, ..., NN and pop randomly. 
You are supposed to tell if a given sequence of numbers 
is a possible popsequence of the stack.
For example, if MM is 5 and NN is 7, 
we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, 
but not 3, 2, 1, 7, 5, 6, 4.

Input Specification:

Each input file contains one test case. 
For each case, the first line contains 3 numbers (all no more than 1000): 
MM (the maximum capacity of the stack), 
NN (the length of push sequence), 
and KK (the number of pop sequences to be checked). 
Then KK lines follow, each contains a pop sequence of NN numbers. 
All the numbers in a line are separated by a space.

Output Specification:

For each pop sequence, 
print in one line "YES" if it is indeed 
a possible pop sequence of the stack, 
or "NO" if not.


Sample Input:
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2

Sample Output:
YES
NO
NO
YES
NO

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ch[4];
typedef ch* str;
typedef str* strs;
typedef int data;
typedef int* sequence;
typedef struct snode* ptrnode;
typedef struct sheadnode* stack;
struct sheadnode{
	ptrnode next;
	int elementcount;
	int maxsize;
};
struct snode{
	ptrnode next;
	data element;	
};
 
typedef ptrnode node;

//堆栈的压入操作 
int push(data element,stack s){
	if(isfull(s)){
		return -1;
	}else{
		node pushnode=(node)malloc(sizeof(struct snode));
		pushnode->element=element;
		pushnode->next=NULL; 
		pushnode->next=s->next;
		s->next=pushnode;
		s->elementcount+=1;
		return 1;		
	}

}

//堆栈的弹出操作
data pop(stack s){
	node popnode;
	data retdata;
	if(isempty(s)){
		return -1;
	}else{
		popnode=s->next;
		s->next=s->next->next;
		popnode->next=NULL;
		retdata = popnode->element;
		free(popnode);
		s->elementcount--;
		return retdata;
	}
} 

//堆栈的创建操作
stack creatStack(int maxsize){
	stack s=(stack)malloc(sizeof(struct snode));
	s->elementcount=0;
	s->next=NULL;
	s->maxsize=maxsize;
	return s; 
} 

//判断堆栈是否为空 
int isempty(stack s){
	return (s->elementcount==0);
}

//判断堆栈是否已满
int isfull(stack s){
	return (s->elementcount==s->maxsize);
} 

//判断输入数字是否为pop队列
char* isPopSequence(stack s,sequence seq,int seqlength){
	int i=0,nowdig=0,pushresult=0,popc=0,printresult=0;
	pushresult=push(++nowdig,s);
	for(i;i<seqlength;i++){
		while(seq[i]>nowdig){
			pushresult=push(++nowdig,s);
			if(pushresult==-1){
				return "NO";
			}
		}
		popc=pop(s);
		if(popc==seq[i]){
			continue;
		}else{
			return "NO";
		}
	}
	return "YES";
} 

//主函数 
int main() {
	int M,N,K,i=0,j=0,tmp=0;
	str results;
	stack stk;
	scanf("%d %d %d",&M,&N,&K);
	sequence numbers=(sequence)malloc(sizeof(int)*N); 
	results=(str)malloc(sizeof(str)*K);
	stk=creatStack(M);
	for(i=0;i<K;i++){
		for(j=0;j<N;j++){
			scanf("%d",&tmp);
			numbers[j]=tmp;
		}
		strcpy(results[i],isPopSequence(stk,numbers,N));
		stk->elementcount=0;
		stk->next=NULL;
	}
	for(i=0;i<K;i++){
		if(i!=0){
			printf("\n");
		}
		printf("%s",results[i]);
	}
	return 0;
}
