#include<stdio.h> 
#include<conio.h>

void main()
{ int n, v, u,cost[10][10], visited[10]={0}, i, j; int count=1, mincost=0, min, a, b;

printf("Enter number of vertices:"); scanf("%d",&n); printf("\nEnter cost matrix (For infinity, put 999):\n");

for(i=1;i<=n;i++) for(j=1;j<=n;j++)
{
scanf("%d",&cost[i][j]); if(cost[i][j]==0) cost[i][j]=999;
}

visited[1]=1;
printf("\nThe edges of spanning tree are: \n");

while(count<n)
{
min=999; for(i=1;i<=n;i++) for(j=1;j<=n;j++) if(cost[i][j]<min) if(visited[i]==0) continue; else
{
min=cost[i][j]; a=u=i;
b=v=j;
}
if(visited[u]==0 || visited[v]==0)
{ count++;
printf("\nEdge(%d, %d) = %d", a, b, min); mincost+=min; visited[b]=1;
}
cost[a][b]=cost[b][a]=999; }

printf("\nMinimum cost = %d", mincost); }


