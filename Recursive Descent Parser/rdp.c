#include<stdio.h>
void E();
void E1();
void T();
void T1();
void F();
char a[20];
int z = 0, flag = 0;
int main()
{
    printf("\nEnter a string: ");
    scanf("%s",a);
    E();
    if(a[z] == '\0' && flag == 0)
        printf("\nValid");
    else
        printf("\nInvalid");
    return 0;
}

void E()
{
    T();
    E1();
}

void E1()
{
    if(a[z] == '+')
    {
        z++;
        T();
        E1();
    }    
}

void T()
{
    F();
    T1();
}

void T1()
{
    if(a[z] == '*')
    {
        z++;
        F();
        T1();
    }
}

void F()
{
    if(a[z] == '(')
    {
        z++;
        E();
        if(a[z] == ')')
            z++;
    }
    else if(a[z] == 'i')
        z++;
    else
        flag = 1;
}