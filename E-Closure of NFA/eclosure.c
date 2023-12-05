#include<stdio.h>

struct transition
{
    int source,input,dest;
}nfa[10];

int n;

void findTrans(int src)
{
    for(int i = 0; i < n; i++)
    {
        if((nfa[i].input == -1) && (nfa[i].source == src))
        {
            findTrans(nfa[i].dest);
            printf("q%d ",nfa[i].dest);
            break;
        }
    }
}

void main()
{
    int src,states_no;
    printf("\nNumber of states: ");
    scanf("%d",&states_no);
    printf("\nNumber of transitions: ");
    scanf("%d",&n);
    int states[states_no];
    for(int i=0; i<states_no; i++)
        states[i] = i+1;
    printf("\nEnter transition details: ");
    printf("\nSource Input Target\n");
    for(int i = 0; i<n; i++)
        scanf("%d%d%d",&nfa[i].source,&nfa[i].input,&nfa[i].dest);
    printf("\nEpsilon Transition:\n");
    for(int i=0; i<states_no; i++)
    {
        src=states[i];
        printf("q%d = { ",src);
        findTrans(src);
        printf("q%d }\n",src);
    }
}