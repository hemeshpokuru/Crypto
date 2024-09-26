#include<stdio.h>
#include<string.h>
int main(){
	int a[3][3]={{0,13,14},{19,7,4},{17,1,25}};
	int c[100],d[100],i,j,t;
	char msg[100];
	printf("Enter message: ");
	scanf("%s",&msg);
	for(i=0;i<strlen(msg);i++){
		c[i]=msg[i]-65;
		printf("%d ",c[i]);
	}
	for(i=0;i<3;i++){
		t=0;
		for(j=0;j<3;j++){
			t=t+(a[i][j]*c[j]);
		}
		d[i]=t%26;
	}
	printf("\nEncrypted = ");
	for(i=0;i<3;i++){
		printf("%c ",d[i]+65);
	}
}
