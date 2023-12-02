%{
#include<stdio.h>
#include<stdlib.h>
%}
%token NUMBER ID;
%%
T:E {printf("\nResult is: %d\n",$$); return 0;}
E:E'+'E {$$ = $1 + $3;}
|E'-'E {$$ = $1- $3;}
|E'*'E {$$ = $1 * $3;}
|NUMBER {$$ = $1;}
%%
int main()
{
    printf("\nEnter the expression: ");
    yyparse();
}

int yyerror()
{
    printf("\nInvalid Expression");
}