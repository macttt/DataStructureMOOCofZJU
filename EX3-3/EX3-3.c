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

//��t�ĺ������ 
void postordertraversal(tree t){
	if(t!=NULL){
		postordertraversal(t->left);
		postordertraversal(t->right);
		if(t->data==preorder[0]){
			printf("%c",t->data);
		}else{
			printf("%c ",t->data);
		}	
	}
}

//��������ķ�ʽ�ͷ����Ŀռ� 
void postorderfree(tree t){
	if(t!=NULL){
		postordertraversal(t->left);
		postordertraversal(t->right);
		free(t);
	}
}

//���ַ����н�ȡ�ַ� 
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

//�����ַ�������
void read(int nodecount){
	int i=0,pre=0,in=0;
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
	for(i=0;i<nodecount;i++){
		printf("%d ",preorder[i]);
	}
} 

//���ַ����з���ĳ���ַ���������û���򷵻�-1
int find(int source[],int t){
	int i=0,r=-1;
	for(i;i<strlen(source);i++){
		if(source[i]==t){
			r=i;
			break;
		}
	}
	return r;
} 

//�����ַ����齨����
tree buildTree(int pre[],int in[]){
	int c=0,index=0,len=0;
	len=strlen(pre);
	char *newlpre=malloc(sizeof(char)*len);
	char *newrpre=malloc(sizeof(char)*len);
	char *newlin=malloc(sizeof(char)*len);
	char *newrin=malloc(sizeof(char)*len);
	tree newnode=(tree)malloc(sizeof(tree));
	newnode->left=NULL;
	newnode->right=NULL;
	if(strlen(pre)==0){
		free(newlpre);
		free(newrpre);
		free(newlin);
		free(newrin);
		return NULL;
	}else{
		newnode->data=pre[0];
		index=find(in,pre[0]);
		newlpre=substring(pre,1,index);//�µ����������� 
		newlin=substring(in,0,index);//�µ�����������
		strcpy(newrpre,pre+index+1);//�µ�����������
		strcpy(newrin,in+index+1);//�µ�����������
		newnode->left=buildTree(newlpre,newlin);
		newnode->right=buildTree(newrpre,newrin); 
		free(newlpre);
		free(newrpre);
		free(newlin);
		free(newrin);
		return newnode;
	}
} 

int main() {
	int nodecount=0;
	scanf("%d",&nodecount);
	read(nodecount);
	tree root=(tree)malloc(sizeof(tree));
	root->left=NULL;
	root->right=NULL;
	root=buildTree(preorder,inorder);
	postordertraversal(root);
	return 0;
}
