//problem link-->You have tp find length of longest moutain subSeq or dec subSeq--> 

#include <bits/stdc++.h>
using namespace std;

void runTime();

/* Method-1->TimeComplexity=>O(2^n * n) and SpaceComplexity=>O(n)

int longest_boitonicSubSeq(vector<int>&nums,int n,vector<int>&subSeq,int& maxLen,int idx=0){
	if(n==0 or n==1) return 0;

	if(idx==n){
		// cout<<subSeq<<endl;
		// Check if Biotonic-->
		int subSeqLen=subSeq.size();

		bool isDec=false,isInc=false;
		int len=0;

		int i=1;
		while(i<subSeqLen){
			if(subSeq[i]>subSeq[i-1]){
				if(isDec==true) break;
				
				isInc=true;
				len++;i++;
			}else if(subSeq[i]<subSeq[i-1]){
				isDec=true;
				len++;i++;
			}else{
				break;
			}
		}
	//For last ele as it also statisy condn but never checked inside loop-->
		if(i==subSeqLen) len++;

		maxLen=max(maxLen,len);
		return maxLen;
	}

	//If We decide to choose ele at idx->
	subSeq.push_back(nums[idx]);
	int if_choose=longest_boitonicSubSeq(nums,n,subSeq,maxLen,idx+1);

	//BackTrack
	subSeq.pop_back();
	int if_not_choose=longest_boitonicSubSeq(nums,n,subSeq,maxLen,idx+1);

	return maxLen;}

*/





/*Method-2-->Idea=>

Longest Biotonic Seq=max(LIS till a Point + LDS from that point) for all possiblle idx-->

#-LIS-->Longest Inc SubSeq
#-LDS-->Longest Dec SubSeq

*/

vector<int> longestIncreasing_subsequence(vector<int>&nums,int n){

	if(n==0) return vector<int>();

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


	//Now return dp containg LIS-->
	return dp;}

vector<int>longestDecreasing_subsequence(vector<int>&nums,int n){

	//Reversing Nums so can use LIS() for calculating LDS but it's order is reversed-->
	reverse(nums.begin(),nums.end());

	vector<int>LDS=longestIncreasing_subsequence(nums,n);

	//BackTrack-->So Order became Same again=>
	reverse(LDS.begin(),LDS.end());

	return LDS;}

long longest_boitonicSubSeq(vector<int>&nums,int n){
	vector<int> LIS_length=longestIncreasing_subsequence(nums,n);
	vector<int> LDS_length=longestDecreasing_subsequence(nums,n);


	int maxLen=0;
	for(int idx=0;idx<n; idx++){
		//lis-lds-1 as One Ele is Overlapping in Both so Subtract it-->
		maxLen=max(LIS_length[idx]+LDS_length[idx]-1,maxLen);
	}

	return maxLen;}

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
  	for(int idx =0;idx<n;idx++) scanf("%d",&nums[idx]);

  	// vector<int>subSeq;int maxLen=0;
  	// int longest_mountainLen=longest_boitonicSubSeq(nums,n,subSeq,maxLen,0);

  	int longest_mountainLen=longest_boitonicSubSeq(nums,n);
  	printf("length of logest moutain seq: %d\n",longest_mountainLen);
  

  	runTime();

	return 0;
}

void runTime(){
	//cerr produce output in error.txt --> No need to remove
  cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}