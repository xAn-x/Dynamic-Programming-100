// Think which ballon should u burst at end -> what before it & so on in order to remove dependencies on other ballons parts.

// WATCH: https://www.youtube.com/watch?v=zfgZtcDQAxw 
// WATCH: https://www.youtube.com/watch?v=Yz4LlDSlkns&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=52
class Solution {
public:
    //Recursion-->
    int func(vector<int>&nums,int st,int end){
        if(st>end) return 0;
        
        //What balloon i should burst at end->
        int maxPoints=INT_MIN;
        for(int i=st;i<=end;++i){
            int points=nums[st-1]*nums[i]*nums[end+1]+func(nums,st,i-1)+func(nums,i+1,end);
            maxPoints=max(maxPoints,points);
        }
        return maxPoints;
    }
    
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        int n=nums.size();
        return func(nums,1,n-2);
    }
    
    
    //Memoization-->
    int func(vector<int>&nums,int st,int end,vector<vector<int>>&dp){
        if(st>end) return 0;
        
        if(dp[st][end]!=-1) return dp[st][end];

        //What balloon i should burst at end->
        int maxPoints=INT_MIN;
        for(int i=st;i<=end;++i){
            int points=nums[st-1]*nums[i]*nums[end+1]+func(nums,st,i-1,dp)+func(nums,i+1,end,dp);
            maxPoints=max(maxPoints,points);
        }
        return dp[st][end]=maxPoints;
    }
    
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return func(nums,1,n-2,dp);
    }
};