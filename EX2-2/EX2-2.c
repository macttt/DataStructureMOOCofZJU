#include <stdio.h>
#include <stdlib.h>

/*
两个多项式的乘积和加法。 
*/ 

typedef int element;  //数字成员  
typedef struct node* ptrtoNode;		//一个指向node结构的指针类型 
struct node{
	element index;  //指数
	element cft;	//系数
	ptrtoNode next;
};
typedef ptrtoNode polyList;


//打印一个链表，链表为空（只有表头）时，打印"0 0"
void Print( polyList L ){			 
	if(NULL == L->next){
		printf("0 0");
	}else{
		printf("%d",L->next->cft);
		printf(" %d",L->next->index);
		L = L->next;
		while(L->next){
			L = L->next;
			printf(" %d",L->cft);
			printf(" %d",L->index);
		}
	}
	printf("\n");
}

//读取一个多项式链表第一个数字是项数，之后以系数和指数成对
polyList read(){				 
	polyList out,tmp;
	out=(polyList)malloc(sizeof(polyList));		//结构体指针类型必须先要分配内存空间进行初始化，否则为野指针。 
	tmp=(polyList)malloc(sizeof(polyList));
	out->next=NULL;
	out->cft=0;
	out->index=0; 
	tmp->next = out;
	int in1,i,cft,index;
	scanf("%d",&in1);
	out->index=in1; 				//为了节省空间和方便操作，头结点的指数设置为多项式的项数。 
	for(i=0;i<in1;i++){
		scanf(" %d %d",&cft,&index);
		polyList current=(polyList)malloc(sizeof(polyList));
		current->cft=cft;
		current->index=index;
		current->next=NULL;
		tmp->next->next=current;
		tmp->next=tmp->next->next;
	}
	return out;
}

//对两个多项式进行乘法运算
/*polyList multiply(polyList l1,polyList l2){
	polyList add(polyList,polyList);			 
	polyList result,currentadd,tmp,tmp2;
	result=(polyList)malloc(sizeof(polyList));
	current=(polyList)malloc(sizeof(polyList));
	tmp=(polyList)malloc(sizeof(polyList));
	tmp2=(polyList)malloc(sizeof(polyList));
	result->next=NULL;
	tmp->next=l1;
	tmp->next=l2;
	int i,j;
	while(tmp->next->next){
		tmp->next=tmp->next->next; 
		while(tmp2->next->next){
			tmp2->next=tmp2->next->next;
			tmp->cft=tmp2->next->
		}
	}
	return result;
}
*/

//用递归的方法对两个多项式进行乘法运算
polyList multiply2(polyList l1,polyList l2){
	polyList add(polyList,polyList);
	polyList multiply2(polyList,polyList);			 
	if(l1->next==NULL&&l2->next==NULL){
		return l1;
	}else if(l1->cft==0&&l1->next==NULL){
		return l1; 
	}else if(l2->cft==0&&l2->next==NULL){
		return l2;
	}else if(l1->next==NULL){
		polyList current,tmp1,tmpl2;
		tmp1=(polyList)malloc(sizeof(polyList));
		tmpl2=(polyList)malloc(sizeof(polyList));
		current=(polyList)malloc(sizeof(polyList));
		tmp1->index=0;
		tmp1->cft=0;
		current->next=tmp1;
		tmpl2->next=l2;
		while(tmpl2->next->next){
			tmpl2->next=tmpl2->next->next;
			polyList nd;
			nd=(polyList)malloc(sizeof(polyList));
			nd->cft=l1->cft*tmpl2->next->cft;
			nd->index=l1->index+tmpl2->next->index;
			current->next->next=nd;
			current->next=current->next->next;
		}
		return tmp1;
	}else{
		polyList tmp,ptrTmp;
		tmp=(polyList)malloc(sizeof(polyList));
		tmp->cft=l1->next->cft;
		tmp->index=l1->next->index;
		tmp->next=NULL;
		return add(multiply2(tmp,l2),multiply2(l1->next,l2));
	} 
}

//对两个多项式进行加法运算
polyList add(polyList l1,polyList l2){			
	polyList result,tmp,current;
	result=(polyList)malloc(sizeof(polyList));
	tmp=(polyList)malloc(sizeof(polyList));
	result->next=NULL;
	result->cft=0;
	result->index=l1->index; 
	tmp->next=result;
	while(l1->next&&l2->next){
		current=(polyList)malloc(sizeof(polyList));
		current->next=NULL;
		if(l1->next->index==l2->next->index){
			current->cft=l1->next->cft+l2->next->cft;
			if(current->cft==0){
				continue;
			}else{
				current->index=l1->next->index;
				tmp->next->next=current;
				tmp->next=current;
				l1=l1->next;
				l2=l2->next;
			}
		}else if(l1->next->index>l2->next->index){
			current->cft=l1->next->cft;
			current->index=l1->next->index;
			tmp->next->next=current;
			tmp->next=current;
			l1=l1->next;
		}else{
			current->cft=l2->next->cft;
			current->index=l2->next->index;
			tmp->next->next=current;
			tmp->next=current;
			l2=l2->next;
			result->index+=1;	
		}
	}
	if(l1->next!=NULL){			//合并两个链表剩下来的部分。 
		tmp->next->next = l1->next;
		l1->next = NULL;
	}
	if(l2->next!=NULL){
		tmp->next->next = l2->next;
		l2->next = NULL;
	}	
	return result;
}

int main(int argc, char *argv[]) {
	polyList multiplyout,addout,l1,l2;
	multiplyout=(polyList)malloc(sizeof(polyList));
	addout=(polyList)malloc(sizeof(polyList));
	l1=(polyList)malloc(sizeof(polyList));
	l2=(polyList)malloc(sizeof(polyList)); 
	l1=read();
	l2=read();
	Print(multiply2(l1,l2));
	Print(add(l1,l2));
	return 0;
}
