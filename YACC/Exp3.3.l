%{
#include<stdio.h>
#include"y.tab.h"  
extern int yylval;  
%}
%%
[0-9]+ {yylval = atoi(yytext); return NUMBER;}
[a-zA-Z][a-zA-Z0-9]* {return ID;}
\t
\n {return 0;}
['+'|'-'|'*'|'/'] {return yytext[0];}
. {printf("\nInvalid Expression"); exit(0);}
%%
int yywrap()
{}