// https://leetcode.com/problems/target-sum/submissions/

/*Plain-Recursion
class Solution {
public:
    int helper(vector<int>&nums,int n,int idx,int target){
        if(idx==n and target==0) return 1;
        else if(idx==n) return 0;
        
        int ways=0;
        //if i choose +ve sign
        ways+=helper(nums,n,idx+1,target-nums[idx]);
        //if i choose -ve sign
        ways+=helper(nums,n,idx+1,target+nums[idx]);
        
        return ways;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return helper(nums,n,0,target);
    }
};
*/



//Tabulation->
class Solution {
public:
//This question is same as count of number of subsets with given difference
    int countSubsets(vector<int>& nums, int n, int M){
        int t[n + 1][M + 1];
        
       for(int i = 0; i <= n; i++){
            for(int j = 0; j <= M; j++){
                if(i == 0)
                    t[i][j] = 0;
                if(j == 0)
                    t[i][j] = 1;
            }
        }
        //t[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= M; j++){
                if(nums[i - 1] <= j)
                    t[i][j] = t[i - 1][j - nums[i - 1]] + t[i - 1][j];
                else
                    t[i][j] = t[i - 1][j];
            }
        }
        
        return t[n][M];  
    }
    
    int findTargetSumWays(vector<int>& nums, int target)
     {
         target = abs(target);
         int n = nums.size();
         int sum = 0;
         for(int i = 0; i < n; i++)
             sum += nums[i];
         
        int M = (sum + target)/2;
        if(sum < target || (sum + target) % 2 != 0)
            return 0;
         return countSubsets(nums, n, M);
     }
};