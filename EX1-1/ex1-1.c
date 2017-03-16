#include <stdio.h>

int main(int argc, char *argv[]) {
	int number;
	scanf("%d",&number);
	int *input = (int*)malloc(number*sizeof(int));
	int loopc,maxsum=0,maxbegin=0,maxend,sum=0,begin=0,end;
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
			if(sum >= maxsum){
				maxend = end;
				maxbegin = begin;
				maxsum = sum;
			}
		}
	}
	printf("%d",maxsum);
	return 0;
}
