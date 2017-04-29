#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct tnode* ptrtnode;
struct tnode{
	ptrtnode left;
	ptrtnode right;
	element data;
};
typedef ptrtnode tree;
typedef char ch[2]; 
int preorder[30];
int inorder[30];
int nodecount=0;

//树t的后序遍历 
void postordertraversal(tree t){
	if(t!=NULL){
		postordertraversal(t->left);
		postordertraversal(t->right);
		if(t->data==preorder[0]){
			printf("%d",t->data);
		}else{
			printf("%d ",t->data);
		}	
	}
}

//后序遍历的方式释放树的空间 
void postorderfree(tree t){
	if(t!=NULL){
		postordertraversal(t->left);
		postordertraversal(t->right);
		free(t);
	}
}

//从字符串中截取字符 
char* substring(char *str,int pos,int len){
	char* pch=str;
	char *ret=(char*)calloc(len+1,sizeof(char));
	int i=0;
	pch=pch+pos;
	for(i=0;i<len;i++){
		ret[i]=*(pch++);
	}
	ret[i]='\0';
	return ret;
}

//读入字符串数组
void read(int nodecount){
	int i=0,pre=0,in=0,tmpint=0;
	int stack[32];
	int stackcount=-1;
	char tmpstr[7],tmpdata[2];
	for(i;i<nodecount*2;i++){
		scanf("%s",tmpstr);
		if(strcmp(tmpstr,"Pop")==0){
			//strcpy(strs[i],tmpstr);
			inorder[in++]=stack[stackcount--];
		}else{
			strcat(tmpstr," ");
			scanf("%s",&tmpdata);
			preorder[pre++]=atoi(tmpdata);
			stack[++stackcount]=atoi(tmpdata);
		}
	}
} 

//在字符串中返回某个字符的索引，没有则返回-1
int find(int source[],int t){
	int i=0,r=-1;
	for(i;i<30;i++){
		if(source[i]==t){
			r=i;
			break;
		}
	}
	return r;
} 

//根据字符数组建立树
tree buildTree(int prehead,int precount,int inhead,int incount){
	int c=0,index=0,len=0;
	int prelh=0;
	int prelcount=0;
	int prerh=0;
	int prercount=0;
	int inlh=0;
	int inlcount=0;
	int inrh=0;
	int inrcount=0;
	if(precount<=0){
		return NULL;
	}else if(precount==1){
		tree newnode=(tree)malloc(sizeof(tree));
		newnode->left=NULL;
		newnode->right=NULL;
		newnode->data=preorder[prehead];
		return newnode;	
	}else{
		tree newnode=(tree)malloc(sizeof(tree));
		newnode->left=NULL;
		newnode->right=NULL;
		newnode->data=preorder[prehead];
		index=find(inorder,preorder[prehead]);
		prelh=prehead+1;
		prelcount=index-inhead;
		inlcount=index-inhead;
		inlh=inhead;
		prerh=prehead+prelcount+1;
		prercount=precount-prelcount-1;
		inrh=index+1;
		inrcount=inhead+incount-index-1;
		newnode->left=buildTree(prelh,prelcount,inlh,inlcount);
		newnode->right=buildTree(prerh,prercount,inrh,inrcount); 
		return newnode;
	}
} 

int main() {
	scanf("%d",&nodecount);
	read(nodecount);
	tree root=(tree)malloc(sizeof(tree));
	root->left=NULL;
	root->right=NULL;
	root=buildTree(0,nodecount,0,nodecount);
	postordertraversal(root);
	return 0;
}



/*
An inorder binary tree traversal can be implemented in a non-recursive way 
with a stack. For example, suppose that when a 6-node binary tree 
(with the keys numbered from 1 to 6) is traversed, 
the stack operations are: 
push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); 
push(6); pop(); pop(). 
Then a unique binary tree (shown in Figure 1) can be generated from this sequence of 
operations. Your task is to give the postorder traversal sequence of this tree.


Figure 1
Input Specification:

Each input file contains one test case. For each case, 
the first line contains a positive integer NN (\le 30≤30) 
which is the total number of nodes in a tree 
(and hence the nodes are numbered from 1 to NN). 
Then 2N2N lines follow, each describes a stack operation in the format: 
"Push X" where X is the index of the node being pushed onto the stack; 
or "Pop" meaning to pop one node from the stack.

Output Specification:

For each test case, print the postorder traversal sequence of the corresponding tree 
in one line. A solution is guaranteed to exist. All the numbers must be separated 
by exactly one space, and there must be no extra space at the end of the line.

Sample Input:

6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop

Sample Output:

3 4 2 6 5 1


*/
