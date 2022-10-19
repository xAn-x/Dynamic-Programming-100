// Knap-Sack but we can use an element one or more time->
class Solution{
	// Recursion->O(2^n)
	int unbounded_knapSack(vector<int>&values,vector<int>&weight ,int capacity,int n){
		if(n==0 or capacity==0) return 0;

		//if wt of item > capacity we can't include it
		if(weight[n-1]>capacity) return unbounded_knapSack(values,weight,capacity,n-1);

		int if_not_include=unbounded_knapSack(values,weight,capacity,n-1);
		//if we decide to include item than we can do so in next turn also so don't skip it for now->
		int if_include=values[n-1]+unbounded_knapSack(values,weight,capacity-weight[n-1],n);

		return max(if_include,if_not_include);
	}

	int unbounded_knapSack(vector<int>&values,vector<int>&weight ,int capacity,int n,vector<vector<int>>&dp){
		if(n==0 or capacity==0) return 0;

		if(dp[n][capacity]!=-1) return dp[n][capacity];

		//if wt of item > capacity we can't include it
		if(weight[n-1]>capacity) return dp[n][capacity]=unbounded_knapSack(values,weight,capacity,n-1);

		int if_not_include=unbounded_knapSack(values,weight,capacity,n-1);
		//if we decide to include item than we can do so in next turn also so don't skip it for now->
		int if_include=values[n-1]+unbounded_knapSack(values,weight,capacity-weight[n-1],n);

		return dp[n][capacity]=max(if_include,if_not_include);
	}

public:
	int unbounded_knapSack(vector<int>&values,vector<int>&weight ,int capacity){
		int n=values.size();
		// recursion
		unbounded_knapSack(values,weight,capacity,n);

		// Memoization
		vector<vector<int>>dp(n+1,vector<int>(capacity+1,-1));
		unbounded_knapSack(values,weight,capacity,n);

        int n=values.size();
		vector<int>prv(capacity+1),curr(capacity+1);

		for(int item=1;item<=n;++item){
			for(int cap=0;cap<=capacity;++cap){
				if(weight[item-1]>cap) curr[cap]=prv[cap];
				else curr[cap]=max(prv[cap],values[item-1]+curr[cap-weight[item-1]]);
			}
            prv=curr;
		}
        return prv[capacity];
	}
};