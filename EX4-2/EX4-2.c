#include <stdio.h>
#include <stdlib.h>

//����AVL�������ݽṹ
typedef struct AVLnode* avltree;
struct AVLnode{
	avltree left;
	avltree right;
	int data;
}; 

//��ȡ����ֵ
int getmax(int a,int b){
	return a>b?a:b;
} 

//�жϽڵ�߶�
int getheight(avltree root){
	int height;
	if(root){
		height=1+getmax(getheight(root->left,root->right));
	}else{
		height=0;
	}
	return height;
} 


//��ĳ�ڵ����RR��ת 
void RRrotate(avlree root){
	
}

//��ĳ�ڵ����LL��ת 
void RRrotate(avlree root){
	
}

//��ĳ�ڵ����RL��ת  ,��������ΪRRLL��ת 
void RRrotate(avlree root){
	
}

//��ĳ�ڵ����LR��ת ,��������ΪLLRR��ת 
void RRrotate(avlree root){
	
}

//����AVLTree
avltree createTree(int nodecount){
	avltree t=(avltree)malloc(sizeof(avltree));
	int i=0;
	for(i=0;i<nodecount;i++){
		//todo read input
		
	}
	return t;
} 

int main() {
	int nodecount=0;
	scanf("%d",&nodecount);
	avltree avl=createTree(nodecount);
	return 0;
}


/*
04-��5 Root of AVL Tree   (25��)
An AVL tree is a self-balancing binary search tree. 
In an AVL tree, the heights of the two child subtrees of any node differ by at most one; 
if at any time they differ by more than one, rebalancing is done to restore this property. 
Figures 1-4 illustrate the rotation rules.


Now given a sequence of insertions,
you are supposed to tell the root of the resulting AVL tree.
Input Specification:

Each input file contains one test case. For each case, 
the first line contains a positive integer NN (\le 20��20) 
which is the total number of keys to be inserted. 
Then NN distinct integer keys are given in the next line. 
All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the root of the resulting AVL tree in one line.

Sample Input 1:

5
88 70 61 96 120
Sample Output 1:

70
Sample Input 2:

7
88 70 61 96 120 90 65
Sample Output 2:

88

*/



