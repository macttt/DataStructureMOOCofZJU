#include <stdio.h>
#include <stdlib.h>

typedef int nodeElement;
typedef struct Node* ptrtoNode;
struct Node{
	nodeElement element;
	ptrtoNode next;
};
typedef ptrtoNode list;

void printtest(list l1){
	if(NULL == l1->next){
		printf("NULL");
	}else{
		printf("%d",l1->next->element);
		l1 = l1->next;
		while(l1->next){
			l1 = l1->next;
			printf(" %d",l1->element);
		}
	}
}

int testmain(int argc, char *argv[]) {
	list l1,l2,p1,p2,p3,tmpptr;
	l1 = (list)malloc(sizeof(list));
	l2 = (list)malloc(sizeof(list));
	p1 = (list)malloc(sizeof(list));
	p2 = (list)malloc(sizeof(list));
	p3 = (list)malloc(sizeof(list));
	//tmpl1 = (list)malloc(sizeof(list));
	tmpptr = (list)malloc(sizeof(list));
	//tmpl1->element = -1;
	l2->element = 0;
	l2->next = NULL; 
	l1->next = p1;
	p1->element = 1;
	l1->next->next = p2;
	p2->element = 2;
	l1->next->next->next = p3;
	p3->element = 3;
	p3->next = NULL;
	//tmpl1->next = l1;
	printf("l1:");
	printtest(l1);
	tmpptr->next=l2;
	while(l1->next){
		tmpptr->next->next = l1->next;
		tmpptr->next = tmpptr->next->next;
		l1->next = l1->next->next;
		//tmpl1->next=tmpl1->next->next;
		tmpptr->next->next = NULL;
	} 
	printf("\nl2:");
	printtest(l2); 
	return 0;
}
