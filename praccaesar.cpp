#include<stdio.h>
#include<string.h>
int main(){
	int c[100],d[100],i,j,t;
	char msg[100];
	printf("Enter msg: ");
	scanf("%s",&msg);
	for(i=0;i<strlen(msg);i++){
		c[i]=msg[i]-65;
	}
	printf("Encrypted message: ");
	for(i=0;i<strlen(msg);i++){
		c[i]=(c[i]+5)%26;
		printf("%c ",c[i]+65);
	}
	printf("\nDecrypted message: ");
	for(i=0;i<strlen(msg);i++){
		d[i]=c[i];
		d[i]=(d[i]-5)%26;
		printf("%c ",d[i]+65);
	}
}
