%{
#include<stdio.h>
#include<stdlib.h>
%}
%token NUMBER ID;
%%
T:E {printf("Valid Expression"); return 0;}
E:E'+'E
|E'-'E
|E'*'E
|E'/'E
|NUMBER
|ID;
%%
int main()
{
    printf("\nEnter the expression: ");
    yyparse();
}
int yyerror()
{
    printf("\nInvalid Expression");
    return 1;
}