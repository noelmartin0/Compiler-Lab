#include<stdio.h>
#include<ctype.h>
#include<string.h>
char grammar[20][20], f[10];
int m,n;
void first(char k)
{
    if(islower(k))
        f[m++] = k;
    for(int i=0; i<n; i++)
    {
        if(k == grammar[i][0])
        {
            if(islower(grammar[i][2]))
                f[m++] = grammar[i][2];
            else
                first(grammar[i][2]);
        }
    }
}
void follow(char k)
{
    if(grammar[0][0] == k)
        f[m++] = '$';
    for(int i=0; i<n; i++)
    {
        for(int j=2; j<strlen(grammar[i]); j++)
        {
            if(grammar[i][j] == k)
            {
                if(grammar[i][j+1] != '\0')
                    first(grammar[i][j+1]);
                if(grammar[i][j+1] == '\0' && k != grammar[i][0])
                    follow(grammar[i][0]);
            }
        }
    }
}

void main()
{
    printf("\nEnter the number of grammar: ");
    scanf("%d",&n);
    printf("\nEnter the grammar: \n");
    for(int i=0; i<n; i++)
        scanf("%s",grammar[i]);
    for(int i=0; i<n; i++)
    {
        m=0;
        char k = grammar[i][0];
        first(k);
        printf("\n FIRST (%c) = { ",k);
        for(int i = 0; i<m; i++)
            printf("%c, ",f[i]);
        printf("\b\b }\n");
        strcpy(f,"");
        m=0;
        follow(k);
        printf("\n FOLLOW (%c) = { ",k);
        for(int i = 0; i<m; i++)
            printf("%c, ",f[i]);
        printf("\b\b }\n");
    }
}