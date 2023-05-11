#include<stdio.h>
#include<string.h>

void main()  {
    char *l,*r,*temp,tempprod[20],productions[25][50];
    int i=0,j=0,flag=0, n,k=0;
    printf("\nEnter the No. of productions: ");
    scanf("%d", &n);
    char input[n][100];
    for(k=0;k<n;k++)
   {
    printf("\nEnter the productions: ");
    scanf("%s",input[k]);
   }
    for(k=0;k<n;k++)
   {
    l = strtok(input[k],"->");
    r = strtok(NULL,"->");
    temp = strtok(r,"|");
    while(temp)  {
        if(temp[0] == l[0])  {
            flag = 1;
            sprintf(productions[i++],"%s'->%s%s'\0",l,temp+1,l);
        }
        else
           sprintf(productions[i++],"%s->%s%s'\0",l,temp,l);
        temp = strtok(NULL,"|");
    }
    sprintf(productions[i++],"%s’->\356\0",l);
    if(flag == 0)
        printf("The given productions don't have Left Recursion");
    else
        for(j=0;j<i;j++)  {
            printf("\n%s",productions[j]);
        }
    }
}

//input: 2 number of production daalo aur yeh production daalo:A->Ac B->Bd