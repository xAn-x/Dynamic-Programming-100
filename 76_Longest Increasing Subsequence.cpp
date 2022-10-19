// https://leetcode.com/problems/longest-increasing-subsequence/

// Method-1 => Find all subsequence and then return the length of LIS -> O(n*2^n) time 

// Method-2 => 

/*IDEA
	Let we have a function lis(nums,idx) -> return length of longest increasing subsequence till index idx
	
	->Base-Case
	if(idx==0) return 1;
	else if(idx<0) return 0;

	int lis_len=0;
	for(int i=idx-1;i>=0;--i){
		if(nums[idx]>nums[i]) lis_len=max(lis_len,1+lis(nums,i));
	}
	return lis_len; 	
*/
class Solution {
public:
// Recursion->
	int lis(vector<int>&nums,int idx){
		// ->Base-Case
		if(idx==0) return 1;
		else if(idx<0) return 0;

		int lis_len=1;
		for(int i=idx-1;i>=0;--i){
			if(nums[idx]>nums[i]) lis_len=max(lis_len,1+lis(nums,i));
		}
		return lis_len; 
	}

    int lengthOfLIS(vector<int>& nums) {
    	int len=nums.size();
        return lis(nums,len-1);
    }

// Memoization->
    int lis(vector<int>&nums,int idx,vector<int>&dp){
		// ->Base-Case
		if(idx==0) return 1;
		else if(idx<0) return 0;

		if(dp[idx]!=-1) return dp[idx];

		int lis_len=1;
		for(int i=idx-1;i>=0;--i){
			if(nums[idx]>nums[i]) lis_len=max(lis_len,1+lis(nums,i,dp));
		}
		return dp[idx]=lis_len; 
	}

    int lengthOfLIS(vector<int>& nums) {
    	int len=nums.size();
    	vector<int>dp(len,-1);
        return lis(nums,len-1,dp);
    }


// Better Recursive Way->
/*IDEA
	let we have a function lis(nums,idx,prv_idx) -> tell length of lis if I am on idx and last ele in subseq is at prv_idx
	
	->Base-Case
	if(idx==n)
		return 0

	if(prv_idx==-1 or nums[idx]>nums[prv_idx])
		return 1+lis(nums,idx+1,idx);
	else
		return lis(nums,idx+1,prv_idx);
*/


// Better Recursion
    int lis(vector<int>&nums,int idx,int prv_idx,int len){
    	if(idx==len) return 0;

    	int lis_len=0;
    	if(prv_idx==-1 or nums[idx]>nums[prv_idx])
    		lis_len=max(lis_len,1+lis(nums,idx+1,idx,len));
		
		lis_len=max(lis_len,0+lis(nums,idx+1,prv_idx,len));

		return lis_len;
    }

    int lengthOfLIS(vector<int>& nums) {
    	int len=nums.size(),prv=-1;
        return lis(nums,0,prv,len);
    }


// Better Memoization->
    int lis(vector<int>&nums,int idx,int prv_idx,int len,vector<vector<int>>&dp){
    	if(idx==len) return 0;

    	if(dp[idx][prv_idx+1]!=-1) return dp[idx][prv_idx+1];

    	int lis_len=0;
    	if(prv_idx==-1 or nums[idx]>nums[prv_idx])
    		lis_len=max(lis_len,1+lis(nums,idx+1,idx,len,dp));
		
		lis_len=max(lis_len,0+lis(nums,idx+1,prv_idx,len,dp));

		return dp[idx][prv_idx+1]=lis_len;
    }

    int lengthOfLIS(vector<int>& nums) {
    	int len=nums.size(),prv=-1;
    	vector<vector<int>>dp(len,vector<int>(len+1,-1));
        return lis(nums,0,prv,len,dp);
    }


// 	Tabulation->
    int lengthOfLIS(vector<int>& nums) {
    	int len=nums.size();
    	vector<int>dp(len,1);

    	int lis_len=1;
    	for(int i=1;i<len;++i){
    		for(int j=i-1;j>=0;--j){
    			if(nums[i]>nums[j]) dp[i]=max(dp[i],1+dp[j]);
    		}
    		lis_len=max(lis_len,dp[i]);
    	}
        
    	return lis;
    }
};