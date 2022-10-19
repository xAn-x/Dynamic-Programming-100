//https://leetcode.com/problems/minimum-falling-path-sum-ii/
class Solution {
public:
    //Method-1=>Tabulation-->
    /*
    int minFallingPathSum(vector<vector<int>>& grid) {
        //Note->dp[i][j]=>min cost till ith row if i decide to do jth task->
        int rows=grid.size(),cols=grid[0].size();
        vector<vector<int>>dp(rows,vector<int>(cols));

        for(int c=0;c<cols;++c) dp[0][c]=grid[0][c];

        for(int r=1;r<rows;++r){
            for(int c=0;c<cols;++c){
                int min_cost=INT_MAX;
                for(int tsk=0;tsk<cols;++tsk){
                    if(tsk!=c) min_cost=min(min_cost,dp[r-1][tsk]);
                }
                dp[r][c]=grid[r][c]+min_cost;
            }
        }            
        //Now in last row find on which cell i have to land in order to get min_cost
        int ans=INT_MAX;
        for(int c=0;c<cols;++c) ans=min(dp[rows-1][c],ans);

        return ans;    
    }
    */

    //-------------------------------------------------------------------------------------------------

    //Method-2=>Tabulation+Space-Optimisation
    int minFallingPathSum(vector<vector<int>>& grid) {
        // Note we don't need whole grid just the prv_row's data that's it
        int rows=grid.size(),cols=grid[0].size();
        vector<int>dp(cols),temp(cols);

        for(int c=0;c<cols;++c) dp[c]=grid[0][c];

        for(int r=1;r<rows;++r){
            for(int c=0;c<cols;++c){
                int min_cost=INT_MAX;
                for(int tsk=0;tsk<cols;++tsk){
                    if(tsk!=c) min_cost=min(min_cost,dp[tsk]);
                }
                temp[c]=grid[r][c]+min_cost;
            }
            dp=temp;
        }            
        //Now in last row find on which cell i have to land in order to get min_cost
        int ans=INT_MAX;
        for(int c=0;c<cols;++c) ans=min(dp[c],ans);

        return ans;    
    }
};