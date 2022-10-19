//problem link-->https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/

//HEADER FILES----------------------------------------------

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <ctime>
#include <math.h>
#include <cstring>
#include <climits>

using namespace std;


//MACROS-------------------------------------------------------

#define INF INT_MAX
#define neg_INF INT_MIN

#define loop(i,st,end,jump) for(auto i = st; i<=end; i+=jump)

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

typedef long long ll;
#define mod (1000000007);

void runTime();

//START---------------------------------------------------------------

//Method-1 =Plain recursion->Time Complexity=>O(2^n)-->
/*
int count_targetSum_subsets(int nums[],int n,int targetSum){
	if(n==0) return (targetSum==0)?1:0;
	if(targetSum<0) return 0;

	return count_targetSum_subsets(nums,n-1,targetSum) + count_targetSum_subsets(nums,n-1,targetSum-nums[n-1]);
}
*/

//Method-1 =Memoization->Time Complexity=>O(n)-->
/*
int count_targetSum_subsets(int nums[],int n,int targetSum,vector<vi>&dp){
	if(n==0) return (targetSum==0)?1:0;
	if(targetSum<0) return 0;

	// dp[i][j]->Suggest no of ways through which i can for sum j using first i elements

	if(dp[n][targetSum]!=-1) return dp[n][targetSum];
	return dp[n][targetSum]=count_targetSum_subsets(nums,n-1,targetSum,dp) + count_targetSum_subsets(nums,n-1,targetSum-nums[n-1],dp);
}
*/


// Method-3 = Tabulation->Time Complexity=>O(n) and O(n*targetSum) ->space :-
/*
int count_targetSum_subsets(int nums[],int n,int targetSum){
	int dp[n+1][targetSum+1];
	memset(dp,0,sizeof(dp));

	//if sum==0 there is only 1 way {}
	for(int i=0;i<=n;++i) dp[i][0]=1;

	//fill rest dp
	for(int i=1;i<=n;++i){
		for(int s=0;s<=targetSum;++s){
			if(nums[i-1]>s) dp[i][s]=dp[i-1][s];
			else dp[i][s]=dp[i-1][s]+dp[i-1][s-nums[i-1]];
		}
	} 

	return dp[n][targetSum];
}
*/


// Method-4 = Tabulation->Time Complexity=>O(n) and O(targetSum) ->space :-
int count_targetSum_subsets(int nums[],int n,int targetSum){
	vector<int>prv(targetSum+1),curr(targetSum+1);

	//if sum==0 there is only 1 way {}
	prv[0]=curr[0]=1;

	//fill rest dp
	for(int i=1;i<=n;++i){
		for(int s=0;s<=targetSum;++s){
			if(nums[i-1]>s) curr[s]=prv[s];
			else curr[s]=prv[s]+prv[s-nums[i-1]];
		}
		prv=curr;
	} 

	return prv[targetSum];
}

int main() {

//add the two lines below for fast i/o
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;

	int nums[n];
	loop(i,0,n-1,1) cin>>nums[i];	      
    
    int targetSum;
    cin>>targetSum;

    // cout<<count_targetSum_subsets(nums,n,targetSum)<<'\n'; ->Recursion

    // vector<vi> dp(n+1,vi(targetSum+1,-1));					
    // cout<<count_targetSum_subsets(nums,n,targetSum,dp)<<'\n'; ->Memoization

    cout<<count_targetSum_subsets(nums,n,targetSum)<<'\n'; //->Tabulation+spaceotimisation	
    
    runTime();
    return 0;
}

void runTime() {
	//cerr produce output in error.txt --> No need to remove
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
}