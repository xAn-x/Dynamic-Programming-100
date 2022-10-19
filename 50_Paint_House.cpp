// https://nados.io/question/paint-house?zen=true
#include<iostream>
#include<vector>
using namespace std;

//Recusrion->
int helper(vector<vector<int>>&costs,int n,int lst_paint){
	if(n==0) return 0;
 	
 	int minCost=INT_MAX;
	for(int i=0;i<3;++i){
		if(lst_paint==i) continue;
		minCost=min(minCost,costs[n-1][i]+helper(costs,n-1,i));
	}
	return minCost;
}

//Memoization->
int helper(vector<vector<int>>&costs,int n,int lst_paint,vector<vector<int>>&dp){
	if(n==0) return 0;
 	if(dp[n][lst_paint]!=-1) return dp[n][lst_paint];

 	int minCost=INT_MAX;
	for(int i=0;i<3;++i){
		if(lst_paint==i) continue;
		minCost=min(minCost,costs[n-1][i]+helper(costs,n-1,i,dp));
	}
	dp[n][lst_paint]=minCost;
	return minCost;
}

int paintHouses(vector<vector<int>>&costs){
	int n=costs.size(),lst_paint=3;
	//Recursion->
	// return helper(costs,n,lst_paint);


	//Memoization->
	// vector<vector<int>> dp(n+1,vector<int>(4,-1));
	// return helper(costs,n,lst_paint,dp);


	//Tabulation+Space-Optimisation
	vector<int>prv={costs[0][0],costs[0][1],costs[0][2]};
	vector<int>curr(3);

	for(int i=1;i<n;++i){
		for(int pnt=0;pnt<3;++pnt){
			int minCost=INT_MAX;
			for(int p=0;p<3;++p){
				if(p==pnt) continue;
				minCost=min(minCost,prv[p]);
			}
			curr[pnt]=costs[i][pnt]+minCost;
		}
		prv=curr;
	}

	int minCost=1e9;
	for(int i=0;i<3;++i){
		minCost=min(minCost,prv[i]);
	}

	return minCost;
}

int main(){
 //add the two lines below for fast i/o
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
      
	int n;
	cin>>n;

	vector<vector<int>>costs(n,vector<int>(3));
	for(int i=0;i<n;++i){
		for(int &cst:costs[i]) cin>>cst;
	}
    
    cout<<paintHouses(costs)<<"\n";
	return 0;
}
