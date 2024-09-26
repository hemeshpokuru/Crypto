#include<stdio.h>
#include<math.h>
int main(){
	int p,q,n,pn,m,e,d,en,de,a,b,c;
	printf("Enter p & q: ");
	scanf("%d %d",&p,&q);
	printf("Enter e: ");
	scanf("%d",&e);
	n=p*q;
	pn=(p-1)*(q-1);
	a=pow(e,-1);
	d=a%pn;
	printf("Public key: (%d, %d)\n",e,n);
	if(d==0){
		printf("Private key doesnot exist.\n");
	}
	else{
		printf("Private key: (%d, %d)\n",d,n);
	}
	printf("Enter message: ");
	scanf("%d",&m);
	b=pow(m,e);
	en=b%n;
	printf("Encrypted message = %d\n",en);
	c=(pow(en,d));
	de=c%n;
	printf("Decrypted message = %d",de);
}
