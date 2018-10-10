#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void generateRandomKey(char []);

int main()
{
    FILE * fp1, *fp2;
	char chars[26]={'\0'},t;
	int i;
	float sum=0,count[26]={0};
    fp1=fopen("plaintext.txt","r");
    fp2=fopen("ciphertext.txt","w");
    if(fp1==NULL && fp2==NULL)
    {
        printf("file does not exist\n");
        return 0;
    }
    generateRandomKey(chars);
    while((fscanf(fp1,"%c",&t))!=EOF)
    {
    	sum++;
    	count[t-97]++;
        fprintf(fp2,"%c",chars[t-97]);
    }
    printf("Frequency\tPlaintext\tCiphertext\n");
    for(i=0;i<26;i++)
    {
    	printf("    %4.2f  \t    %c    \t    %c    \n",count[i]/sum*100,i+97,chars[i]);
    }
	fclose(fp1);
	fclose(fp2);
	return 0;
}

void generateRandomKey(char chars[26])
{
    int i;
	srand(time(NULL));
    for(i=0;i<26;i++)
    {
        int random_index;
        while(chars[random_index=rand()%26]);
            chars[random_index]='a'+i;
    }
}
