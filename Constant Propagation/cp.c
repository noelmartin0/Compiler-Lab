#include<stdio.h>
#include<ctype.h>
#include<string.h>
int z = 0;
struct constant
{
    char var;
    int value;
}con[10];
void findConstant(char exp[20])
{
    if(isdigit(exp[3]))
    {
        con[z].var = exp[1];
        con[z].value = exp[3] - 48;
        z++;
    }
}
void main()
{
    int n,flag=0,count=1,op1=-1,op2=-1;
    char exp[20][20];
    printf("\nEnter the number of expression: \n");
    scanf("%d",&n);
    printf("\nEnter the expression in quadruple form: \n");
    for(int i = 0; i < n; i++)
        scanf("%s",exp[i]);
    printf("\nOptimized Code:\n");
    for(int i = 0; i < n; i++)
    {
        if(exp[i][0] == '=')
            findConstant(exp[i]);
    }
    for(int i = 0; i < n; i++)
    {
        if(exp[i][0] != '=')
        {
            printf("%c ",exp[i][0]);
            char operator = exp[i][0];
            for(int j=1; exp[i][j] != '\0'; j++)
            {
                flag = 0;
                for(int k=0; k<z; k++)
                {
                    if(con[k].var == exp[i][j])
                    {
                        printf("%d ",con[k].value);
                        flag = 1;
                        if(count == 1)
                        {
                            op1 = con[k].value;
                            count++;
                        }
                        else
                        {
                            op2 = con[k].value;
                            count = 1;
                        }
                        break;
                    }
                }
                if(flag == 0)
                    printf("%c ",exp[i][j]);
                if(exp[i][j+1] == '\0' && (op1 != -1 && op2 != -1))
                {
                    switch(operator)
                    {
                        case '+': op1=op1+op2;
                                  con[z].var = exp[i][j];
                                  con[z].value = op1;
                                  z++;
                                  op1=-1;
                                  op2=-1;
                                  break;
                        case '-': op1=op1-op2;
                                  con[z].var = exp[i][j];
                                  con[z].value = op1;
                                  z++;
                                  op1=-1;
                                  op2=-1;
                                  break;
                        case '*': op1=op1*op2;
                                  con[z].var = exp[i][j];
                                  con[z].value = op1;
                                  z++;
                                  op1=-1;
                                  op2=-1;
                                  break;
                        case '/': op1=op1/op2;
                                  con[z].var = exp[i][j];
                                  con[z].value = op1;
                                  z++;
                                  op1=-1;
                                  op2=-1;
                                  break;
                    }
                }
                else
                    count = 1;
            }
            printf("\n");
        }
    }
}