%{
    #include<stdio.h>
    int vow=0,con=0;
%}
%%
[A|E|I|O|U|a|e|i|o|u] {vow++;}
[A-Z|a-z] {con++;}
%%

void main()
{
    yyin = fopen("input.txt","r");
    yylex();
    printf("\nNumber of vowels: %d\nNumber of consonants: %d\n",vow,con);
}

int yywrap()
{

}