#include<stdio.h>
#include<ctype.h>
#include<string.h>
struct expression{
    char op1,op2,operator,result;
}expr[10];
void main()
{
    int k=0,flag=0;
    char input[20],temp='x';
    printf("\nEnter the expression: ");
    scanf("%s",input);
    for(int i=2; input[i] != '\0'; i++)
    {
        if(flag == 2)
        {
            expr[k].op1 = expr[k-1].result;
            flag=1;
            if(!isalpha(input[i]))
            {
                expr[k].operator = input[i];
                continue;
            }
        }
        else if(isalpha(input[i]) && flag == 0)
        {
            expr[k].op1 = input[i];
            flag = 1;
        }
        else if(isalpha(input[i]))
        {
            expr[k].op2 = input[i];
            expr[k].result = temp;
            temp++;
            k++;
            flag = 2;
        }
        else
        {
            expr[k].operator = input[i];
        }
    }
    expr[k].result = input[0];
    expr[k].op1 = expr[k-1].result;
    k++;
    printf("\nIntermediate Code\n");
    for(int i=0; i<k; i++)
    {
        printf("%c = %c %c %c\n",expr[i].result,expr[i].op1,expr[i].operator,expr[i].op2);
    }
    printf("\nTRIPLE\n");
    for(int i = 0; i<k; i++)
    {
        if(i == k-1)
        {
            printf("[%d] = [%d]\n",i,i-1);
            break;
        }
        else if(i != 0)
        {
            printf("[%d] = %c [%d] %c\n",i,expr[i].operator,i-1,expr[i].op2);
        }
        else
            printf("[%d] = %c %c %c\n",i,expr[i].operator,expr[i].op1,expr[i].op2);
    }
    printf("\nQUADRUPLE\n");
    for(int i = 0; i<k; i++)
    {
        printf("[%d] = %c %c %c %c\n",i,expr[i].operator,expr[i].op1,expr[i].op2,expr[i].result);
    }
}