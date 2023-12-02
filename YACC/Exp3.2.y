%{
#include<stdio.h>
#include<stdlib.h>
%}
%token NUMBER ID;
%%
T:E {printf("\nIt is an identifier"); return 0;}
E: ID E F | ID
F: ID | NUMBER
%%

int main()
{
    printf("\nEnter an identifier: ");
    yyparse();
}

int yyerror()
{
    printf("\nInvalid Identifier");
}