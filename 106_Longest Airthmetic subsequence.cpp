// Method-1: Find all subsequence and then get maxlen AP => O(2^n*n)

// Method-2: At Each point u have 2 choices 1 to put a num in sequence or start new use this to find AP=>O(2^n)

// Method-3 Optimise Method-2 using DP=>
class Solution {
    int count=0;
public:
    int solve(vector<int>&nums,int idx,int n,int last_ele,int cd){
        if(idx>=n) return 0;
        
        int len1=-1e9,len2=-1e9;
        if(last_ele==-1){
            len1=1+solve(nums,idx+1,n,nums[idx],cd);
            len2=solve(nums,idx+1,n,last_ele,cd);
            
            return max(len1,len2);
        }else{
            if(cd==-1e9 or nums[idx]-last_ele==cd){
                len1=1+solve(nums,idx+1,n,nums[idx],nums[idx]-last_ele);
            }
            
            len2=solve(nums,idx+1,n,last_ele,cd);
            
            return max(len1,len2);
        }
    }
    
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size(),idx=0,last_ele=-1,cd=-1e9;
        return solve(nums,idx,n,last_ele,cd); 
    }

    // Weak-Memoization:
    int solve(vector<int>&nums,int idx,int n,int last_ele,int cd,unordered_map<string,int>&dp){
        if(idx>=n) return 0;
        
        string str=to_string(idx)+"#"+to_string(last_ele)+"#"+to_string(cd);
        if(dp.count(str)) return dp[str];
        
        count++;

        int len1=-1e9,len2=-1e9;
        if(last_ele==-1){
            len1=1+solve(nums,idx+1,n,nums[idx],cd,dp);
            len2=solve(nums,idx+1,n,last_ele,cd,dp);
            
            return dp[str]=max(len1,len2);
        }else{
            if(cd==-1e9 or nums[idx]-last_ele==cd){
                len1=1+solve(nums,idx+1,n,nums[idx],nums[idx]-last_ele,dp);
            }
            
            len2=solve(nums,idx+1,n,last_ele,cd,dp);
            
            return dp[str]=max(len1,len2);
        }
    }
    
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size(),idx=0,last_ele=-1,cd=-1e9;
        count=0;
        unordered_map<string,int>dp;
        int ans=solve(nums,idx,n,last_ele,cd,dp); 
        cout<<count<<"\n";
        return ans;
    }

    // Method-2=>https://www.youtube.com/watch?v=YaMcX7sem70&list=PLDzeHZWIZsTomOPnCiU3J95WufjE36wsb&index=24

    // Recursion
    int solve(int nums[],int idx,int diff){
        if(idx<0) return 0;

        int len=0;
        for(int j=idx-1;j>=0;--j){
            if(nums[idx]-nums[j]==diff)
                len=max(len,1+solve(nums,j,diff));
        }
        return len;
    }
    
    int lengthOfLongestAP(int nums[], int n) {
        if(n<=2) return n;
                
        int max_len=0;
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                int cd=nums[j]-nums[i],last_ele_idx=i,len=2;
                max_len=max(max_len,2+solve(nums,i,cd);
            }
        }
        
        return max_len;
    }

    //Memoization->
    int solve(int nums[],int idx,int diff,vector<unordered_map<int,int>>&dp){
        if(idx<0) return 0;
        
        if(dp[idx].count(diff)) return dp[idx][diff];
        
        int len=0;
        for(int j=idx-1;j>=0;--j){
            if(nums[idx]-nums[j]==diff)
                len=max(len,1+solve(nums,j,diff,dp));
        }
        return dp[idx][diff]=len;
    }
    
    int lengthOfLongestAP(int nums[], int n) {
        if(n<=2) return n;
        
        
        vector<unordered_map<int,int>>dp(n);
        int max_len=0;
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                int cd=nums[j]-nums[i],last_ele_idx=i,len=2;
                max_len=max(max_len,2+solve(nums,i,cd,dp));
            }
        }
        
        return max_len;
    }


    // Tabulation->
    int lengthOfLongestAP(int nums[], int n) {
        if(n<=2) return n;
        
        vector<unordered_map<int,int>>dp(n);
        int ans=0;
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                int diff=nums[i]-nums[j];
                int cnt=1;

                if(dp[j].count(diff))
                    cnt=dp[j][diff];

                dp[i][diff]=1+cnt;
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
    }

    // Way to do it without unordered_map->
    int longestArithSeqLength(vector<int> &nums){
        int n = nums.size();
        int dp[n][1001];
        memset(dp, 0, sizeof(dp));

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int d = nums[i] - nums[j] + 500;  //to handle negative difference add 500

                dp[i][d] = dp[j][d] + 1;

                ans = max(ans, dp[i][d]);
            }
        }
        return ans + 1;
    }
};