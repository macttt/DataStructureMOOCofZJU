#include <stdio.h>

int main(int argc, char *argv[]) {
	//-10 -1 -2 -3 -4 -5 -23 -3 -7 -10
	int number;
	scanf("%d",&number);
	int *input = (int*)malloc(number*sizeof(int));
	int loopc,maxsum=-1,maxbegin=-1,maxend=-1,sum=0,begin=0,end=0;
	for(loopc=0;loopc<number;loopc++){
		scanf("%d",&input[loopc]);
	}
	for(loopc=0;loopc<number;loopc++){
		sum += input[loopc];
		if(sum<0){
			sum = 0;
			begin = loopc + 1;
			end = begin; 
			continue;			
		}else{
			end = loopc;
			if(sum > maxsum){
				maxend = end;
				maxbegin = begin;
				maxsum = sum;
			}
		}
	}
	if(maxsum==-1&&maxbegin==-1){
		printf("%d %d %d",0,input[0],input[number-1]);
	}else{
		printf("%d %d %d",maxsum,input[maxbegin],input[maxend]);		
	}
	return 0;
}
