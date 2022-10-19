//problem link-->

#include <bits/stdc++.h>
using namespace std;

void runTime();


/*Method 1->Plain Recursion=>Time Complexity=O(2^n + 2^n) , Space=O(n)=>

int longestIncreasing_subsequence(vector<int>&nums,int n,int idx,string &subSeq){
	if(idx==n){
		int len=subSeq.length(),i=1;
		for(;i<len;i++){
			if(subSeq[i-1]>subSeq[i]){
				break;
			}
		}

		return (i==len) ? len : 0;
	}


	//Whem we decide to pick a num from array
	subSeq+=to_string(nums[idx]);

	int len_when_picked=longestIncreasing_subsequence(nums,n,idx+1,subSeq);

	//BackTrack-->
	subSeq.erase(subSeq.end()-1);



	int len_when_Notpicked=longestIncreasing_subsequence(nums,n,idx+1,subSeq);


	return max(len_when_Notpicked,len_when_picked);}

*/ 


//Method -2 =>Tabulation->
int longestIncreasing_subsequence(vector<int>&nums,int n){

	if(n==0) return 0;

	vector<int>dp(n,1);

/*  Meaning->dp[i] tell what is max subSeq length till ending at i ->
	
	Why-->If We have longestIncreasing_subsequence ending at i then for next Ele we know that for idx=i longestIncreasing_subsequence end at i i.e last ele of sequence is nums[i] so for dp[j] I need to chk if nums[j] is greater than nums[i] if Yes then we can extened longestIncreasing_subsequence ending at i.

	Now Since We are Storing longestIncreasing_subsequence ending at i in our dp vector and it is for sure that for our vector longestIncreasing_subsequence will end at 1 ele then for its length--> traverse and find.
*/
	for(int processing_idx=1; processing_idx<n; processing_idx++){
//We are trying to extend all prv LIS and Store max len upto which I can extend 
		for(int idx=processing_idx-1; idx>=0; idx--){
			if(nums[processing_idx]>nums[idx]){
				dp[processing_idx]=max(dp[processing_idx],1+dp[idx]);
			}
		}
	}


//Now dp contain max len inc. subsequence ending at a particular idx so traverse and find max Len->

	int maxLen=dp[0];
	for(int idx=1;idx<n;idx++){
		maxLen=max(maxLen,dp[idx]);
	}

	return maxLen;
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
  	cin >> n;

  	vector<int>nums(n);
  	for(int idx=0; idx<n; idx++){
  		cin>>nums[idx];
  	}

  	string subSeq;
  	//Plain Recursion=>
  	// int length=longestIncreasing_subsequence(nums,n,0,subSeq);

  	//Tabulation-->
  	int length=longestIncreasing_subsequence(nums,n);
  	cout<<"max length: "<<length<<"\n";
  
  	runTime();

	return 0;
} 

void runTime(){
	//cerr produce output in error.txt --> No need to remove
  cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}

