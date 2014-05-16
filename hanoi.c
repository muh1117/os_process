#include <stdio.h>

int count=0;

void hanoi(char a, char b, char c, int n);

void main(){
	int n;
	printf("Disk: ");
	scanf("%d",&n);
	hanoi('A','B','C',n);
}

void hanoi(char from, char temp, char to, int n){
	if(n==1){
		++count;
		printf("%5d: From %c to %c disk %d\n", count, from, to, 1);
	}
	else{
		hanoi(from, to, temp, n-1);
		++count;
		printf("%5d: From %c to %c disk %d\n", count, from, to, n);
		hanoi(temp, from, to, n-1);
	}
}
