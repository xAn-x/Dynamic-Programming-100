//https://leetcode.com/problems/minimum-path-sum/submissions/
class Solution {
public:
    //Dp->Tabulation
    /*
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        
        vector< vector<int> >dp(r,vector<int>(c));
        
        //Meaning->dp[i][j]->matrix[i][j] cell se end mai jani ki min cost->
        
        dp[r-1][c-1]=grid[r-1][c-1];
        
        //If in last col->
        for(int i=r-2;i>=0;i--) dp[i][c-1]=grid[i][c-1]+dp[i+1][c-1];
        
        //In in last row
        for(int i=c-2;i>=0;i--) dp[r-1][i]=grid[r-1][i]+dp[r-1][i+1];
 
        //Rest matrix->
        for(int i=r-2;i>=0;i--){
            for(int j=c-2;j>=0;j--){
                dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
    */


    //Dp->Tabulation+Space-Optimisation->O(c) space
    int minPathSum(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        vector<int>prv_row_cost(cols);
        
        prv_row_cost[0]=grid[0][0];//1st cell cost

        //for remaining cell cost=cell_cost+cost_to_reach lft_cell
        for(int c=1;c<cols;++c) prv_row_cost[c]=grid[0][c]+prv_row_cost[c-1];
        
        //find cost for rest rows->
        for(int r=1;r<rows;++r){
            vector<int>curr_row_cost(cols);
            for(int c=0;c<cols;++c){
                int up=prv_row_cost[c];
                int left=(c==0)?INT_MAX:curr_row_cost[c-1];

                curr_row_cost[c]=grid[r][c]+min(up,left);
            }
            prv_row_cost=curr_row_cost;
        }
        return prv_row_cost[cols-1];            
    }   
};