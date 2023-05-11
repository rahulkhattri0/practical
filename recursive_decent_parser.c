#include <conio.h>
#include<stdio.h>
#include<string.h>
char input[100];
char prod[10][5];
int pos=-1,st=0,len=0,flag=1;
char id,num;
void E();
void Ed();
void T();
void Td();
void F();
void advance();
void main()
{
printf("\nEnter the input string for parsing:\n");
gets(input);
len=strlen(input);
input[len]='$';
advance();
E();
if(pos==len&&flag==1)
printf("Accepted");
else
printf("Not  Accepted");
getch();
}
void advance()
{
pos++;
//printf("%d",pos);
if(pos<len) {
if(input[pos]>='0'&&input[pos]<='9')
{
id='\0';
num=input[pos];
}
if((input[pos]>='A'&&input[pos]<='Z')||input[pos]>='a'&&input[pos]<='z')
{
id=input[pos];
num='\0';
}
}
}
void E()
{
//strcpy(prod[++st],"E->TE' ");
T();
Ed();
}
void Ed()
{
int p=1;
if(input[pos]=='+'||input[pos]=='-')
{
p=0;
//strcpy(prod[++st],"E'->+TE'||-TE' ");
advance();
T();
Ed();
}
if (p==1)
{
}
}
void T()
{
F();
Td();
}
void Td()
{ int p=1;
if(input[pos]=='*'||input[pos]=='/')
{    p=0;
advance();
F();
Td();
}
if (p==1)
{}
}
void F()
{
if(input[pos]==id)
{
       //strcpy(prod[++st],"F->id ");
advance();
}
else if(input[pos]=='(')
{   //strcpy(prod[++st],"F->(E) ");
advance();
E();
if(input[pos]==')')
{
//
advance();
}
}
else if(input[pos]==num)
{
//strcpy(prod[++st],"F->num ");
advance();
}
else
flag=0;
}
// a+b daaldo accept ho jayega