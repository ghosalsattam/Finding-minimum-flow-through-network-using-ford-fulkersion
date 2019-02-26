#include<bits/stdc++.h>
using namespace std;
struct residual
{
	int f;
	int b; 
}R[100][100]; 
int E[6][6]={{0, 16, 13, 0, 0, 0}, 
	       {0, 0, 10, 12, 0, 0}, 
               {0, 4, 0, 0, 14, 0}, 
               {0, 0, 9, 0, 0, 20}, 
               {0, 0, 0, 7, 0, 4}, 
               {0, 0, 0, 0, 0, 0}}; 
int considered(int *C,int v,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(C[i]==v)
			return 0;
	}
	return 1;
}
queue<int> q;
int P[100];
int bfs(int s,int n,int t)
{
	
	int v,i,C[100],c=1,k=0;
	for(i=0;i<n;i++)
	{
		C[i]=0;
		P[i]=-1;
	}
	q.push(s);
	C[0]=s;
	while(!q.empty())
	{
		v=q.front();
		q.pop();
		//printf("%d\n",v);
		if(v==t)
			k= 1;
		for(i=0;i<n;i++)
		{
			if(R[v][i].f!=0 && considered(C,i,n)!=0)
			{
				q.push(i);
				P[i]=v;
				C[c++]=i;
			}
		}
	}
	//printf("k\n");
	return k;
}
int findMin(int *P,int n,int s, int t)
{
	int min=R[P[1]][1].f,i;
	if(bfs(s,n,t)==1)
	{
	for(i=t;i!=s;i=P[i])
	{//printf("%d %d\n",i,P[i]);
		if(min>R[P[i]][i].f)
		{
			min=R[P[i]][i].f;
		}
	}
	}
	return min;
}
int fordFulkersion(int s,int n,int t)
{
	int i,j,min,pf=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			R[i][j].f=E[i][j];
		}
	}
	while(bfs(s,n,t)==1)
	{
		//printf("c\n");
		/*for(i=0;i<n;i++)
		{
			printf("%d %d\n",i,P[i]);
		}*/
		min=findMin(P,n,s,t);
		for(i=t;i!=s;i=P[i])
		{
				R[P[i]][i].f=R[P[i]][i].f-min;
				R[P[i]][i].b=R[P[i]][i].b+min;
			//printf("%d\n",pf);
		}
		
		pf=pf+min;
		//printf("%d\n",pf);
	}
return pf;

}
int main()
{
	int i,s=0;
	s=fordFulkersion(0,6,5);
	printf("Maximum flow :%d\n",s);
}
