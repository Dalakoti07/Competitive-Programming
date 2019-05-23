void rec(int maze[][20],int n,int visited[][20],int i=0,int j=0)
{
	//if(visited[i][j]==1)
	//	return;// no more visit it is already visited
	//cout<<"called at i = "<<i<<" j = "<<j<<endl;	
  if(i==n-1 and j==n-1)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cout<<visited[i][j]<<" ";
		cout<<endl;
	}
	else
	{
		if(j-1>=0 and maze[i][j-1]==1 and visited[i][j-1]==0)//go left
			{visited[i][j-1]=1;rec(maze,n,visited,i,j-1);}
		if(j+1<n and maze[i][j+1]==1 and visited[i][j+1]==0)//go right
			{visited[i][j+1]=1;rec(maze,n,visited,i,j+1);}
		if(i-1>=0 and maze[i-1][j]==1 and visited[i-1][j]==0)//up
			{visited[i-1][j]=1;rec(maze,n,visited,i-1,j);}
		if(i+1<n and maze[i+1][j]==1 and visited[i+1][j]==0)//down
			{visited[i+1][j]=1;rec(maze,n,visited,i+1,j);}
	}
	visited[i][j]=0;
}

void ratInAMaze(int maze[][20], int n)
{
	int visited[20][20]={0};// memset is called
	visited[0][0]=1;
	rec(maze,n,visited);	
}
