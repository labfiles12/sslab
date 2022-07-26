%{
#include"y.tab.h"
%}

%%
[+|-|*|/] {return OP;}
[A-Za-z] {return ID;}
"void"|"main"|"char"|"scanf"|"int" {return KEY;}
%%

int yywrap(){return 1;}
 
