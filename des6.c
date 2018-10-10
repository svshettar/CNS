#include<stdio.h>
#include<math.h>
int l[32],r[32],er[48],bink[48];
int e_bit[8][6]={
32,1,2,3,4,5,
4,5,6,7,8,9,
8,9,10,11,12,13,
12,13,14,15,16,17,
16,17,18,19,20,21,
20,21,22,23,24,25,
24,25,26,27,28,29,
28,29,30,31,32,1
};

void converttobinary(int hex[16],int bin[64])
{
	int i;
	for(i=0;i<64;i++)
		bin[i]=0;
	long int rem,count;
	for(i=0;i<16;i++)
	{
		count=1;
		while (hex[i]>0)
		{
			rem=hex[i]%2;
			bin[(i+1)*4-count]=rem;
			hex[i]=hex[i]/2;
			count++;
		}
	}
}

void etable()
{
	int i,j,k=0;
	for(i=0;i<8;i++)
	{
		for(j=0;j<6;j++)
		{
			er[k++]=r[e_bit[i][j]-1];
		}
	}
}

void xor48()
{
	int i;
	for(i=0;i<48;i++)
	{
		if(er[i]==bink[i])
			er[i]=0;
		else
			er[i]=1;
	}
}
int main()
{
	int i,j,hex[64],bin[64],k[12];
	FILE *input,*key;
	
	input=fopen("plain.txt","r");
	for(i=0;i<16;i++)
		fscanf(input,"%x",&hex[i]);
	converttobinary(hex,bin);
	printf("Input from i-1th round\n");
	for(i=0;i<64;i++)
		printf("%d",bin[i]);
	printf("\n");
	
	j=0;
	printf("Right most 32 bits of input plain text\n");
	for(i=32;i<64;i++)
		r[j++]=bin[i];
	for(i=0;i<32;i++)
		printf("%d",r[i]);
	etable();
	printf("\n");
	printf("input after expansion table\n");
	for(i=0;i<48;i++)
		printf("%d",er[i]);
	
	key=fopen("input.txt","r");
	printf("\ntaking the sub key -1 \n");
	for(j=0;j<12;j++)
		fscanf(key,"%x",&k[j]);
	converttobinary(k,bink);
	for(j=0;j<48;j++)
		printf("%d",bink[j]);
	printf("\n");
	xor48();
	printf("After xor\n");
	for(i=0;i<48;i++)
	{
		printf("%d",er[i]);
	}
	fclose(key);
	fclose(input);
	return 0;
}
