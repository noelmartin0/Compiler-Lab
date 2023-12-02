%{
#include<stdio.h>
int w=0,l=1,c=0;
%}
%%
[a-z|A-Z|0-9] {c++;}
["\n"] {l++;}
[" "] {w++;}
%%
void main()
{
    yyin = fopen("input.txt","r");
    yylex();
    printf("\nNumber of characters: %d\nNumber of words: %d\nNumber of Lines: %d\n",c,w+l,l);
}

int yywrap()
{

}