#include<stdio.h>
#include<string.h>
#include<ctype.h>
FILE *fp,*fp1;
int count=0;

int findInSymbolTable(char s[])
{
    char c[26],d[10];
    fseek(fp1,0,SEEK_SET);
    while(1)
    {
        if(feof(fp1))
            return 0;
        fscanf(fp1,"%s %s",c,d);
        if(strcmp(c,s) == 0)
        {
            if(strcmp(d,"i")==0)
            {
                printf("%s - Identifier, %d\n",s,count);
            }
            else
            {
                printf("%s - %s\n",s,d);
            }
            return 1;
        }
        count++;
    } 
}

int main()
{
    char c,result[26];
    int state = 0, i = 0, k = 0;
    fp = fopen("input.txt","r");
    fp1 = fopen("symboltable.txt","r+");
    while(1)
    {
        if(feof(fp))
        {
            break;
        }
        c = fgetc(fp);
        switch(state)
        {
            case 0:
            if(isalpha(c))
            {
                state = 1;
                result[i++] = c;
            }
            else if(isdigit(c))
            {
                state = 3;
                result[i++] = c;
            }
            break;

            case 1:
            if(isalnum(c) || isalpha(c))
            {
                state=1;
                result[i++] = c;
                break;
            }
            else
                state=2;
            
            case 2:
                result[i] = '\0';
                k = findInSymbolTable(result);  
                if(k == 0)
                {
                    fprintf(fp1,"\n%s i",result);
                    printf("%s - Identifier, %d\n",result,count);
                }
                if(c == '=')
                {
                 printf("%c - assign\n",c);
                }
                strcpy(result,"");
                state=0;
                i=0;
                count=0;
                break;
            case 3 : 
            if(isdigit(c))
            {
                result[i++]=c;
                break;
            }
            if(isalpha(c))
            {
                strcpy(result,"");
                state=0;
                i=0;
                printf("Error\n");
                break;
            }
            else
            {
                state=4;
            }
            case 4 : 
            result[i]='\0';
            printf("%s - Number\n",result);
            strcpy(result,"");
            state=0;
            i=0;
            count=0;
            break;
        }
    }
    return 0;
}
                