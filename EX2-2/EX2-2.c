#include <stdio.h>
#include <stdlib.h>

/*
��������ʽ�ĳ˻��ͼӷ��� 
*/ 

typedef int element;  //���ֳ�Ա  
typedef struct node* ptrtoNode;		//һ��ָ��node�ṹ��ָ������ 
struct node{
	element index;  //ָ��
	element cft;	//ϵ��
	ptrtoNode next;
};
typedef ptrtoNode polyList;


//��ӡһ����������Ϊ�գ�ֻ�б�ͷ��ʱ����ӡ"0 0"
void Print( polyList L ){			 
	if(NULL == L->next){
		printf("0 0");
	}else{
		L = L->next;
		while(L){
			printf("%d",L->cft);
			printf(" %d",L->index);
			L = L->next;
			if(L){
				printf(" ");
			}
		}
	}
	printf("\n");
}

//��ȡһ������ʽ�����һ��������������֮����ϵ����ָ���ɶ�
polyList read(){				 
	polyList out,tmp,current;
	out=(polyList)malloc(sizeof(polyList));		//�ṹ��ָ�����ͱ�����Ҫ�����ڴ�ռ���г�ʼ��������ΪҰָ�롣 
	tmp=(polyList)malloc(sizeof(polyList));
	out->next=NULL;
	out->cft=0;
	out->index=0; 
	tmp->next = out;
	int in1=0,i=0,cft=0,index=0;
	scanf("%d",&in1);
	out->index=in1; 				//Ϊ�˽�ʡ�ռ�ͷ��������ͷ����ָ������Ϊ����ʽ�������� 
	for(i=0;i<in1;i++){
		scanf(" %d %d",&cft,&index);
		current=(polyList)malloc(sizeof(polyList));
		current->cft=cft;
		current->index=index;
		current->next=NULL;
		tmp->next->next=current;
		tmp->next=tmp->next->next;
	}
	return out;
}

//�����ڵ����������
polyList multipl(polyList element,polyList lst2){
	polyList head,tmp1,nd;
	head=(polyList)malloc(sizeof(polyList));
	tmp1=(polyList)malloc(sizeof(polyList));
	head->cft=0;
	head->index=lst2->index;					//���Ӧ����l2������ͬ 
	tmp1->index=0;
	tmp1->cft=0;
	tmp1->next=head;
	lst2=lst2->next;
	while(lst2){
		nd=(polyList)malloc(sizeof(polyList));
		nd->cft=element->cft*lst2->cft;
		nd->index=element->index+lst2->index;
		nd->next=NULL;
		tmp1->next->next=nd;
		tmp1->next=tmp1->next->next;
		lst2=lst2->next;
	}
	return head;
} 

//�õݹ�ķ�������������ʽ���г˷�����
polyList multiply2(polyList l1,polyList l2){
	polyList add(polyList,polyList);
	polyList multipl(polyList,polyList);
	polyList result=(polyList)malloc(sizeof(struct node));
	result->cft=0;
	result->index=0;
	result->next=NULL;
	if(l1->index==0&&l2->index==0){
		return l1;
	}else if(l1->index==0){
		return l1; 
	}else if(l2->index==0){
		return l2;
	}else{
		l1=l1->next;
		while(l1){
			result=add(result,multipl(l1,l2));
			l1=l1->next;
		}
		return result;
	} 
}

//����������ʽ���мӷ�����
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
				l1=l1->next;
				l2=l2->next;
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
	if(l1->next!=NULL){			//�ϲ���������ʣ�����Ĳ��֡� 
		tmp->next->next = l1->next;
		l1->next = NULL;
	}
	if(l2->next!=NULL){
		tmp->next->next = l2->next;
		l2->next = NULL;
	}	
	return result;
}

int main(){
	polyList l1,l2;
	void Print(polyList);
	polyList add(polyList,polyList);
	l1=(polyList)malloc(sizeof(polyList));
	l2=(polyList)malloc(sizeof(polyList)); 
	l1=read();
	l2=read();
	Print(multiply2(l1,l2));
	Print(add(l1,l2));
	return 0;
}
