#include<stdio.h>
#include<conio.h>
#include<string.h>
char prod[50][50];
char input[100];
int pos=-1;
int flag=0;
int st=-1;
int reject=0,k=0;
char id[100],num[100];
void E();
void Ed();
void T();
void Td();
void F();
void advance();
void E()
{
       //strcpy(prod[++st]," E->TE' ");
    T();
    Ed();
}
void Ed()
{
    int p=1;
    if(input[pos]=='+')
    {
    p=0;
    strcpy(prod[++st]," E'->+TE' ");
    advance();
    T();
    Ed();
    }
    else if(input[pos]=='-')
    {
    p=0;
    strcpy(prod[++st]," E'->-TE' ");
    advance();
    T();
    Ed();
    }
    if(p==1)
    {
    strcpy(prod[++st]," E'->null ");

    }
}
void T()
{
       //strcpy(prod[++st]," T->FT' ");
    F();
    Td();
}
void Td()
{
    int p=1;
    if(input[pos]=='*')
    {
    p=0;
    strcpy(prod[++st]," E'->*FT' ");
    advance();
    F();
    Td();
    }
    else if(input[pos]=='/')
    {
    p=0;
    strcpy(prod[++st]," T'->/FT' ");
    advance();
    F();
    Td();
    }
    if(p==1)
    {
    strcpy(prod[++st]," T'->null ");
    //advance();
    }
}
void F()
{
    if(input[pos]=='(')
    {
    advance();
    E();
    if(input[pos]==')')
    {
    advance();
    strcpy(prod[++st],"F->(E)");
    }
    }
    else if(input[pos]==id[k] || input[pos]==num[k])
    {
    advance();
    }

}
void advance()
{
flag=0;
pos++;
k=0;
if (input[pos]>='0'&&input[pos]<='9')
{
do
{
    if(input[pos]>='a'&&input[pos]<='z')
    {
    reject=1;
    }
    num[k]=input[pos];
    k++;
    pos++;
    flag=1;
}
while (input[pos]>='0'&&input[pos]<='9');
}
else if(input[pos]>='a'&&input[pos]<='z')
{       pos++;
    flag=1;
    do
    {
    id[k]=input[pos];
    pos=pos+1;
    k++;
    }while((input[pos]>='a'&&input[pos]<='z')||(input[pos]>='0'&&input[pos]<='9'));
}
if(flag==1)
{
pos--;
k--;
}
}
void main()
{
int l;

printf("Enter String \n");
gets(input);
l=strlen(input);
input[l]='$';
advance();
E();
if(pos==l &&reject!=1)
{
printf("Accepted");
}
else
printf("rejected");
getch();
}
// id+id daal do