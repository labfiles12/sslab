%{
#include<stdio.h>
int i=0,single=0,multiple=0;
%}

%%
[/][/].* {if(i==0) single++;}
[/][*] {if (i==0) i++;}
[*][/] {if (i==1) i--,multiple++;}
. {if (i==0) ECHO;}
%%

int main()
{
	yyin=fopen("pg6.c","r");
	yyout=fopen("pg6.txt","w");
	yylex();
	printf("Single line comment is %d\n Multiline is %d\n",single,multiple);
}

int yywrap()
{
	return 1;
}

