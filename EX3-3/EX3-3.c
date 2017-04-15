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
