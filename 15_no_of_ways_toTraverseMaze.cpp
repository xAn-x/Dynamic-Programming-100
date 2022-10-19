#include <bits/stdc++.h>
using namespace std;

void runTime();


/*Plain Recursion-->Time O(2^(r*c))=>

int count_Ways_to_traverse_maze(vector<vector<int>>&maze,int rows,int cols,int r=0,int c=0){
	if(r==rows-1 and c==cols-1){
		return 1;
	}if(maze[r][c]==1){
		return 0;
	}

	int no_of_ways=0;
	
	if(r<rows-1){
		no_of_ways+=count_Ways_to_traverse_maze(maze,rows,cols,r+1,c);
	}

	if(c<cols-1){
		no_of_ways+=count_Ways_to_traverse_maze(maze,rows,cols,r,c+1);
	}

	return no_of_ways;}

*/

//Tabulation->
int count_Ways_to_traverse_maze(vector<vector<int>>&maze,int rows,int cols){

//If Destination cell is blocked only=>
	if(maze[rows-1][cols-1]==1) return 0;

	vector<vector<int>>dp(rows,vector<int>(cols));

	//Meaning dp[r][c] ->No of Ways to reach bottom right cell from cell[r][c]=>

//Base-Case=>

	//If I am on last row->only 1 way traverse in right direction till reach bottom right cell or a blocked one
	for(int c=cols-1; c>=0; c--){
		if(maze[rows-1][c]!=1)
			dp[rows-1][c]=1;
		//Beacuse if we encounter a block cell -> cells before it has no way in ->
		else
			break;
	}

	//If I am on last col->only 1 way traverse in downward direction till reach bottom right cell
	for(int r=rows-1; r>=0; r--){
		if(maze[r][cols-1]!=1)
			dp[r][cols-1]=1;
		//Beacuse if we encounter a block cell cells before it has no way in ->
		else
			break;
	}

//Filling Rest Dp->
	for(int r=rows-2;r>=0;r--){
		for(int c=cols-2;c>=0;c--){
			if(maze[r][c]!=1){
				dp[r][c]=dp[r+1][c]+dp[r][c+1];
			}
		}
	}

  	for(int r=0;r<rows;r++){
  		for(int c=0;c<cols;c++){
  			cout<<dp[r][c]<<" ";
  		}cout<<'\n';
  	}
	//Ans Is no of ways from cell[0][0] to bottom right cell=>dp[0][0]
  	cout<<'\n';
	return dp[0][0];
}

int main() {

//add the two lines below for fast i/o
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	//For getting input from input.txt
	freopen("input.txt", "r", stdin);
	//For getting errors in error.txt
	freopen("error.txt","w",stderr);
	//For getting output in output.txt
	freopen("output.txt", "w", stdout);
#endif
    
  	int rows,cols;
  	scanf("%d %d",&rows,&cols);

  	vector<vector<int>>maze(rows,vector<int>(cols));

  	for(int r=0;r<rows;r++){
  		for(int c=0;c<cols;c++){
  			scanf("%d",&maze[r][c]);
  		}
  	}

  	int no_of_ways=count_Ways_to_traverse_maze(maze,rows,cols);
  	printf("no_of_ways: %d\n",no_of_ways);
  
  	runTime();

	return 0;
}

void runTime(){
	//cerr produce output in error.txt --> No need to remove
  cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}

