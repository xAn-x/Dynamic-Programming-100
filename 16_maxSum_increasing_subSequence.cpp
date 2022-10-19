//problem link-->Find inc subsequence whose sum is max-->

#include <bits/stdc++.h>
using namespace std;

void runTime();


/*Plain Recursion-->Time O(2^n * n) Space->O(n)

void maxSum_of_incSubSeq(vector<int>&nums,int n,long & maxSum,string &subSeq,int idx=0){
	if(idx==n){
		//Check if subSeq Is Inc-->
		long sum=subSeq[0]-'0',subSeq_len=subSeq.length();

		int idx;
		for(idx=1;idx<subSeq_len;idx++){
			if(subSeq[idx-1]>subSeq[idx]){
				break;
			}
			sum+=(subSeq[idx]-'0');
		}

		if(idx==subSeq_len){
			maxSum=max(maxSum,sum);
		}

		return;
	}

	// if I choose to have idx ele in subseq-->
	subSeq+=to_string(nums[idx]);

	
	maxSum_of_incSubSeq(nums,n,maxSum,subSeq,idx+1);
	
	//BackTrack-->
	subSeq.erase(subSeq.end()-1);
	maxSum_of_incSubSeq(nums,n,maxSum,subSeq,idx+1);

}

*/


//Tabulation-->Time Complexity=>O(n^2) and Space Complexity=>O(n)-->
long maxSum_of_incSubSeq(vector<int>&nums,int n){
	//If no ele->
	if(n==0) return 0;

	vector<long>dp(n);

	//Meaning of dp[i]=>Max sum of longest inc subseq ending at idx.

	//Base Case if only One Ele-->
	dp[0]=nums[0];

	for(int processing_idx=1;processing_idx<n;processing_idx++){

//Minimum of nums[processing_idx] can be for dp[processing_idx]-->
		dp[processing_idx]=nums[processing_idx];

		for(int idx=processing_idx-1;idx>=0;idx--){
			if(nums[processing_idx]>nums[idx]){
				dp[processing_idx]=max(dp[processing_idx],dp[idx]+nums[processing_idx]);
			}

		}
	}

	//Traverse whole dp to find maxSum
	long maxSum = dp[0];

	for(int idx=1;idx<n;idx++){
		maxSum=max(maxSum,dp[idx]);
	}

	return maxSum;
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
    
    int n;
    scanf("%d",&n);

    vector<int>nums(n);
	for(int idx=0; idx<n; idx++){
		scanf("%d",&nums[idx]);
	}

/* Plain Recursion Method-->
	
	long maxSum=-1;
	string subSeq;
	maxSum_of_incSubSeq(nums,n,maxSum,subSeq,0);  	
  
  	cout<<maxSum<<'\n';

*/

	//Tabulation Method->
	long maxSum=maxSum_of_incSubSeq(nums,n);
	printf("maxSum: %ld",maxSum);
  	runTime();

	return 0;
}

void runTime(){
	//cerr produce output in error.txt --> No need to remove
  cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}

