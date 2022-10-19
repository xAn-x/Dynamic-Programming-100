// https://leetcode.com/problems/number-of-longest-increasing-subsequence/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        //vector<lis_len>  vector<count_of_lis>
        vector<int>dp(n,1),count(n,1);


        int lis_len=1,cnt=0;
        for(int i=1;i<n;++i){
            for(int j=i-1;j>=0;--j){
                if(nums[i]>nums[j]){
                    if(dp[i]<1+dp[j]){
                        dp[i]=1+dp[j];
                        count[i]=count[j];
                    }else if(dp[i]==1+dp[j]){
                        count[i]+=count[j];
                    }
                }
            }

            if(lis_len<dp[i]){
                lis_len=dp[i];
            }
        }

        for(int i=0;i<n;++i){
            if(dp[i]==lis_len){
                cnt+=count[i];
            }
        }

        return cnt;
    }
};