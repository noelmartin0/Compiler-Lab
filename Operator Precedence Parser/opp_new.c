#include<stdio.h>
#include<string.h>
int i=0,l,top=0;
char input[20],lasthandle[20],stack[30],handles[][5] = {")E(","E+E","E*E","i","E^E"};
char prec[4][4] = {//+   *   i   $
                // +   '>','<','<','>',
                // *   '>','>','<','>',
                // i   '>','>','>','>',
                // $   '<','<','<','<'
};
int getIndex(char c)
{
    switch(c)
    {
        case '+': return 0;
        case '*': return 1;
        case 'i': return 2;
        case '$': return 3;
    }
}
void shift()
{
    stack[++top] = input[i++];
    stack[top+1] = '\0';
}
int reduce()
{
    int t,found,len;
    for(int i=0; i<5; i++)
    {
        len = strlen(handles[i]);
        if(stack[top]==handles[i][0] && top+1 >= len)
        {
            found = 1;
            for(t=0;t<len;t++)
            {
                if(stack[top-t] != handles[i][t])
                {
                    found = 0;
                    break;
                }
            }
            if(found == 1)
            {
                stack[top-t+1] = 'E';
                top = top-t+1;
                stack[top+1] = '\0';
                strcpy(lasthandle,handles[i]);
                return 1;
            }
        }
    }
    return 0;
}
void dispStack()
{
    for(int j=0; j<=top; j++)
        printf("%c",stack[j]);
}
void dispInput()
{
    for(int j=i; j<=l; j++)
        printf("%c",input[j]);
}
void main()
{
    printf("\nEnter the string: ");
    scanf("%s",input);
    l=strlen(input);
    strcpy(stack,"$");
    printf("\nSTACK\tINPUT\tACTION");
    while(i<=l)
    {
        shift();
        printf("\n");
        dispStack();
        printf("\t");
        dispInput();
        printf("\t");
        printf("Shift");
        if(prec[getIndex(stack[top])][getIndex(input[i])] == '>')
        {
            while(reduce())
            {
                printf("\n");
                dispStack();
                printf("\t");
                dispInput();
                printf("\tReduce E->%s",lasthandle);  
            }
        }
    }
    if(strcmp(stack,"$E$") == 0)
        printf("\nAccepted\n");
    else
        printf("\nRejected\n");
}