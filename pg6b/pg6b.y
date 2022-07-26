%{
#include<stdio.h>
int id=0,op=0,key=0;

int yylex();
int yyerror();

extern FILE *yyin;
%}

%token OP ID KEY

%%
input: 	ID input {id++;}
	| OP input {op++;}
	| KEY input {key++;}
	| ID {id++;}
	| OP{op++;}
	| KEY{key++;}
%%

int main()
{
	yyin=fopen("pg6.txt","r");
	yyparse();
	printf("keyword %d\n",key);
	printf("identfier %d\n",id);
	printf("operator %d",op);
}
int yyerror(){return 1;}
