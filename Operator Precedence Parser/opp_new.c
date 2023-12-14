#include<stdio.h>
#include<string.h>

char input[50], lasthandle[6],stack[50],handles[][5]={")E(","E*E","E+E","i","E^E"};
int i=0, top=0,l;
//(E) becomes )E( when pushed to stack
char prec[4][4]={

            /*stack    +    *   i   $  */

            /*  + */  '>', '<','<','>',

            /*  * */  '>', '>','<','>',

            /*  i */  '>', '>','>','>',

            /*  $ */  '<', '<','<','<',

                };

int getindex(char c)
{
switch(c)
    {
    case '+':return 0;
    case '*':return 1;
    case 'i':return 2;
    case '$':return 3;
    }
}


void shift()
{
stack[++top]=input[i++];
stack[top+1]='\0';
}


int reduce()
{
int len,found,t;
for(int i=0;i<5;i++)//selecting handles
    {
    len=strlen(handles[i]);
    if(stack[top]==handles[i][0]&&top+1>=len)
        {
        found=1;
        for(t=0;t<len;t++)
            {
            if(stack[top-t]!=handles[i][t])
                {
                found=0;
                break;
                }
            }
        if(found==1)
            {
            stack[top-t+1]='E';
            top=top-t+1;
            strcpy(lasthandle,handles[i]);
            stack[top+1]='\0';
            return 1;//successful reduction
            }
        }
   }
return 0;
}

void dispstack()
{
for(int j=0;j<=top;j++)
    printf("%c",stack[j]);
}

void dispinput()
{
for(int j=i;j<l;j++)
    printf("%c",input[j]);
}

void main()
{
//int j;
printf("\nEnter the string\n");
scanf("%s",input);
l=strlen(input);
strcpy(stack,"$");
printf("\nSTACK\tINPUT\tACTION");
while(i<=l)
	{
	shift();
	printf("\n");
	dispstack();
	printf("\t");
	dispinput();
	printf("\tShift");
	if(prec[getindex(stack[top])][getindex(input[i])]=='>')
		{
		while(reduce())
			{
			printf("\n");
			dispstack();
			printf("\t");
			dispinput();
			printf("\tReduced: E->%s",lasthandle);
			}
		}
	}
if(strcmp(stack,"$E$")==0)
    printf("\nAccepted;");
else
    printf("\nNot Accepted\n");
}
