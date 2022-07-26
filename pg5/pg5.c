#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char op[2],arg1[5],arg2[5],result[5];
void main()
{
	FILE *fp1,*fp2;
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	while(!feof(fp1))
	{
		fscanf(fp1,"%s%s%s%s",result,arg1,op,arg2);
		if(strcmp(op,"+")==0)
		{
			printf("\nMOV R0,%s",arg1);
			printf("\nADD R0,%s",arg2);
			printf("\nMOV %s,R0",result);
		}
		if(strcmp(op,"*")==0)
		{
			printf("\nMOV R0,%s",arg1);
			printf("\nMUL R0,%s",arg2);
			printf("\nMOV %s,R0",result);
		}
		if((strcmp(op,"-")==0))
		{
			printf("\nMOV R0,%s",arg1);
			printf("\nNEG R0");
			//fprintf(fp2,"\nMOV %s,R0",result);
		}
		if(strcmp(op,"/")==0)
		{
			printf("\nMOV R0,%s",arg1);
			printf("\nDIV R0,%s",arg2);
			printf("\nMOV %s,R0",result);
		}
		if(strcmp(op,"=")==0)
		{
			printf("\nMOV R0,%s",arg1);
			printf("\nMOV %s,R0",result);
		}
	}
	fclose(fp1);
	fclose(fp2);
}
