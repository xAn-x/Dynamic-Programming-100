// https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums){
        //Apply LIS in both direcnt <--- X --->
        
        int n=nums.size();
        vector<int>dp1(n,1),dp2(n,1);
        
        // LIS -->
        for(int i=1;i<n;++i){
            for(int j=i-1;j>=0;--j){
                if(nums[i]>nums[j] and dp1[i]<1+dp1[j]) dp1[i]=1+dp1[j];
            }
        }
        
        // <-- LIS
        for(int i=n-2;i>=0;--i){
            for(int j=i+1;j<n;++j){
                if(nums[i]>nums[j] and dp2[i]<1+dp2[j]) dp2[i]=1+dp2[j];
            }
        }
        
        int max_len=0;
        for(int i=0;i<n;++i){
            //the len of seq is dp1[i]+dp2[i]-1 as ith element is counted twice
            max_len=max(max_len,dp1[i]+dp2[i]-1);
        }
        
        return max_len;
	}
};