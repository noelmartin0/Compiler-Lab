#include<stdio.h>
#include<ctype.h>
void main()
{
	int n;
    char str[20][20];
	printf("\nEnter the number of expression: ");
	scanf("%d",&n);
	for(int i = 0; i<n; i++)
		scanf("%s",str[i]);
	printf("\nTarget code generation\n");
	printf("----------------------\n");
	for(int i = 0; i<n; i++)
	{
		if(!isalpha(str[i][2]))
			printf("\nMOV #%c, R%d",str[i][2],i);
		else
			printf("\nMOV %c, R%d",str[i][2],i);
		if(!isalpha(str[i][4]))
		{
			if(str[i][3] == '+')
				printf("\nADD #%c, R%d",str[i][4],i);
			else if(str[i][3] == '-')
				printf("\nSUB #%c, R%d",str[i][4],i);
			else if(str[i][3] == '*')
				printf("\nMUL #%c, R%d",str[i][4],i);
			else
				printf("\nDIV #%c, R%d",str[i][4],i);
		}
		else
		{
			if(str[i][3] == '+')
				printf("\nADD %c, R%d",str[i][4],i);
			else if(str[i][3] == '-')
				printf("\nSUB %c, R%d",str[i][4],i);
			else if(str[i][3] == '*')
				printf("\nMUL %c, R%d",str[i][4],i);
			else
				printf("\nDIV %c, R%d",str[i][4],i);
		}
		printf("\nMOV R%d, %c",i,str[i][0]);
	}
    printf("\n");
} 