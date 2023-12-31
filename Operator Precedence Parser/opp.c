#include<stdio.h>
#include<string.h>
void main()
{
    char stack[20],ip[20],opt[10][10][1],ter[10];
    int i,j,k,n,top=0,row,col,flag;
    printf("\nEnter the number of terminals: ");
    scanf("%d",&n);
    printf("\nEnter the terminals: ");
    scanf("%s",ter);
    printf("\nEnter the table values:\n");
    for(i=0;i<n; i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\nEnter the value for %c %c: ",ter[i],ter[j]);
            scanf("%s",opt[i][j]);
        }
    }
    printf("\nOPERATOR PRECEDENCE TABLE:\n");
    for(i=0;i<n;i++)
    {
        printf("\t%c",ter[i]);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("\n%c",ter[i]);
        for(j=0;j<n;j++)
        {
            printf("\t%c",opt[i][j][0]);
        }
    }
    stack[top]='$';
    printf("\nEnter the input string: ");
    scanf("%s",ip);
    i=0;
    printf("\nSTACK\t\t\tINPUT STRING\t\tACTION\n");
    printf("\n%s\t\t\t%s\t\t\t",stack,ip);
    while(i<=strlen(ip))
    {
        for(k=0;k<n;k++)
        {
            if(stack[top]==ter[k])
                row=k;
            if(ip[i]==ter[k])
                col=k;
        }
        if(stack[top] == '$' && ip[i] == '$')
        {
            printf("String is accepted");
            break;
        }
        else if(opt[row][col][0] == '<' || opt[row][col][0] == '=')
        {
            flag = 0;
            for(int x = 0; x < n; x++)
            {
                if(ip[i] == ter[x])
                    flag = 1;
            }
            if(flag == 0)
            {
                printf("String is not accepted");
                break;
            }
            stack[++top] = opt[row][col][0];
            stack[++top] = ip[i];
            printf("Shift %c",ip[i]);
            i++;
        }
        else
        {
            if(opt[row][col][0] == '>')
            {
                while(stack[top] != '<')
                    --top;
                top = top-1;
                printf("Reduce");
            }
            else
            {
                printf("String is not accepted");
                break;
            }
        }
        printf("\n");
        for(k=0;k<=top;k++)
        {
            printf("%c",stack[k]);
        }
        printf("\t\t\t");
        for(k=i;k<strlen(ip);k++)
        {
            printf("%c",ip[k]);
        }
        printf("\t\t\t");
    }
    printf("\n");
}
