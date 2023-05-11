#include<stdio.h> 
#include<conio.h> 
#include<string.h> 
#include<ctype.h> 

int fail(int); 
void idorkeyword(char str[]); 
void main(void)
{ int i,j,state,l;
char s[100],temp[10],c; i=0;j=0;state=0;l=0; clrscr(); printf("Enter the expression:"); scanf("%[^\n]",s); 
l=strlen(s);
while(i<=l)
{
switch(state) 
{
case 0: 
c=s[i];
if(c==' ')
{state=0;i++;}
else if(c=='<')
{state=1;i++;} 
else if(c=='=')
{state=5;i++;} 
else if(c=='>')
{state=6;i++;} 
else state=fail(state);
break; 
case 1: c=s[i]; 
if(c=='=')
{state=2;i++;} 
else if(c=='>')
{state=3;i++;} 
else state=4;
break; 
case 2: 
printf("RELOP_LE ");
i++;state=9;
break; 
case 3: 
printf("RELOP_NE ");
i++;state=9;
break; 
case 4: 
printf("RELOP_LT ");
state=9;
break; 
case 5: 
printf("RELOP_EQ ");
i++;state=9;
break; 
case 6: 
c=s[i]; i
f(c=='=')
{state=7;i++;} 
else state=8;
break; 
case 7: 
printf("RELOP_GE ");
i++;state=9;break; 
case 8:
 printf("RELOP_GT ");
state=9;
break; 
case 9: 
c=s[i]; 
if(isalpha(c))
{state=10;i++;temp[j]=c;} 
else state=fail(state);
break; 
case 10: 
c=s[i]; 
if(isalpha(c))
{state=10;i++;j++;temp[j]=c;} 
else if(isdigit(c))
{state=10;i++;j++;temp[j]=c;} 
else 
state=11;
break; 
case 11: 
j++;temp[j]='\0';i
dorkeyword(temp);
j=0;
state=12;
break; 
case 12: 
c=s[i]; 
if(isdigit(c))
{state=13;i++;} 
else 
state=fail(state);
break; 
case 13: 
c=s[i]; 
if(isdigit(c))
{state=13;i++;} 
else if(c=='.')
{state=14;i++;} 
else if(c=='E')
{state=16;i++;} 
else state=19;
break; 
case 14:
 c=s[i]; 
if(isdigit(c))
{state=15;i++;} 
else 
printf("Error ");
break; 
case 15: 
c=s[i]; 
if(isdigit(c))
{state=15;i++;} 
else if(c=='E')
{state=16;i++;} 
else state=19;
break; 
case 16: c=s[i];
if(c=='+'||c=='-')
{state=17;i++;} 
else if(isdigit(c))
{state=18;i++;} 
else printf("Error ");
break;
case 17: 
c=s[i]; 
if(isdigit(c))
{state=18;i++;} 
else printf("Error ");
break; 
case 18: 
c=s[i]; 
if(isdigit(c)){state=18;i++;} 
else 
state=19;break; 
case 19: 
printf("NUM ");
state=0;
break; }
}
getch(); 
} 
int fail(int start)
{
switch(start) 
{
case 0: 
start=9;
break; 
case 9: 
start=12;
break; 
case 12: 
start=0;break; 
} 
return(start); 
} 
void idorkeyword(char str[10])
{ char *key1="if",*key2="then",*key3="else";
if ( strcmp(str,key1)==0||strcmp(str,key2)==0||strcmp(str,key3)==0) 
printf("%s ",str);
else 
printf("ID "); 
} 


