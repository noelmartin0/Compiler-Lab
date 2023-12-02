%{
#include<stdio.h>
#include "y.tab.h"
extern int yylval;
%}
%%
[0-9]+ {yylval = atoi(yytext); return NUMBER;}
[a-zA-Z][_a-zA-Z]* {return ID;}
\n {return 0;}
. {printf("\nInvalid Identifier"); exit(0);}
%%
int yywrap()
{
}