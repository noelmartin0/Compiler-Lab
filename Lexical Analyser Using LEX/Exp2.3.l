%{
#include<stdio.h>
%}
letter [a-z|A-Z]
digit [0-9]
hash ['#']
keywords ["int"|"for"|"float"|"break"]
relop [">"|"<"|"<="|">="|"=="|"!="]
%%
{hash} {printf("%s is a hash function\n",yytext);}
{digit}+ {printf("%s is a digit\n",yytext);}
{keywords}+ {printf("%s is a keyword\n",yytext);}
{relop}+ {printf("%s is a relop\n",yytext);}
{letter}+{letter}*{digit}* {printf("%s is an identifier\n",yytext);}
. {printf("%s is a special character\n",yytext);}
%%

void main()
{
    yyin = fopen("input2.txt","r");
    yylex();
}

int yywrap()
{
}