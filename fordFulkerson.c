#include<stdio.h>
int E[6][6]={{0, 16, 13, 0, 0, 0}, 
	       {0, 0, 10, 12, 0, 0}, 
               {0, 4, 0, 0, 14, 0}, 
               {0, 0, 9, 0, 0, 20}, 
               {0, 0, 0, 7, 0, 4}, 
               {0, 0, 0, 0, 0, 0}}; 
struct rGraph
{
	int f;
	int b;
}R[100][100];
struct queue
{
	int top;
	int elements[100];
}q;
void enque(int x)
{
	q.top++;
	q.elements[q.top]=x;
}
int deque()
{
	int x=q.elements[0];
	int i;
	for(i=0;i<q.top-1;i++)
	{
		q.elements[i]=q.elements[i+1];		
	}
	q.top--;
	return x;
}
int parent[100];
int considered(int *C,int i,int n)
{
	int j;
	for(j=0;j<n;j++)
	{
		if(C[j]==i)
		{
			return 1;
		}
	}
	return 0;
}
int bfs(int s,int n,int t)
{
	int i,j;
	int C[100];
	enque(s);
	C[0]=s;int c=1;
	while(q.top!=-1)//||s!=t)
	{
		//printf("%d\n",q.elements[q.top]);
		s=deque();
		printf("%d\n",s);
		//printf("%d\n",s);
		for(i=0;i<n;i++)
		{	
			if(E[s][i]!=0 && considered(C,i,c)==0)
			{
				//printf("k\n");
				enque(i);
				parent[i]=s;
				C[c++]=i;
			}
		}
		
	}
	if(q.top==-1)
	{
		return 0;
	}
	if(s==t)
	{
		return 1;
	}
}
int min(int a,int b)
{
	if(a>b)
		return b;
	else
		return a;
}
int fordFulkersion(int s,int n,int t)
{
	int i;
	for(i=0;i<n;i++)
	{
		
	}
}

int main() 
{ 
    q.top=-1;
    printf ( "The maximum possible flow is %d ",  bfs( 0,6, 5));	
   // printf ( "The maximum possible flow is %d ",  fordFulkersion( 0,6, 5)); 
  
    return 0; 
} 
