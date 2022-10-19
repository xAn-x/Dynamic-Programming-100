// https://leetcode.com/problems/minimum-falling-path-sum/
class Solution {
public:
    //Method-1=>Plain-Recursion=>Time 3^(rows*cols)
    /*
    int fallingPathSum(vector<vector<int>>& matrix,int rows,int cols,int r,int c) {
        if(c<0 or c==cols) return INT_MAX;
        if(r==rows) return 0;

        int down=fallingPathSum(matrix,rows,cols,r+1,c);
        int lft_diag=fallingPathSum(matrix,rows,cols,r+1,c-1);
        int rt_diag=fallingPathSum(matrix,rows,cols,r+1,c+1);\

        return matrix[r][c]+min({down,lft_diag,rt_diag});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX,cols=matrix[0].size(),rows=matrix.size();

        //From each column of 0th row I am finding the min fall cost from here and return min of all 
        for(int i=0;i<cols;++i){
            ans=min(ans,fallingPathSum(matrix,rows,cols,0,i));
        }
        return ans;
    }
    */

//-----------------------------------------------------------------------------------------------

   //Method-2=>Memoization=>Time and space O(row*cols)
   /*  
   int fallingPathSum(vector<vector<int>>& matrix,int rows,int cols,int r,int c,vector<vector<int>>& cost) {
        if(c<0 or c==cols) return INT_MAX;
        if(r==rows) return 0;

        if(cost[r][c]!=INT_MAX) return cost[r][c];

        int down=fallingPathSum(matrix,rows,cols,r+1,c,cost);
        int lft_diag=fallingPathSum(matrix,rows,cols,r+1,c-1,cost);
        int rt_diag=fallingPathSum(matrix,rows,cols,r+1,c+1,cost);\

        return cost[r][c]=matrix[r][c]+min({down,lft_diag,rt_diag});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX,cols=matrix[0].size(),rows=matrix.size();
        vector<vector<int>>cost(rows,vector<int>(cols,INT_MAX));

        for(int i=0;i<cols;++i){
            ans=min(ans,fallingPathSum(matrix,rows,cols,0,i,cost));
        }
        return ans;
    }
    */

//-----------------------------------------------------------------------------------------------

    //Method-3=>Tabulation
    /*
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int cols=matrix[0].size(),rows=matrix.size();
        vector<vector<int>>cost(rows,vector<int>(cols,INT_MAX));

        for(int c=0;c<cols;++c) cost[rows-1][c]=matrix[rows-1][c];

        for(int r=rows-2;r>=0;--r){
            for(int c=0;c<cols;++c){
                int down=INT_MAX,left_diag=INT_MAX,rt_diag=INT_MAX;
                down=cost[r+1][c];
                if(c-1>=0) left_diag=cost[r+1][c-1];
                if(c+1<cols) rt_diag=cost[r+1][c+1];

                cost[r][c]=matrix[r][c]+min({down,left_diag,rt_diag});
            }
        }

        int ans=INT_MAX;
        for(int c=0;c<cols;++c){
            ans=min(ans,cost[0][c]);
        }    
        return ans;        
    }
    */

//-----------------------------------------------------------------------------------------------

    //Method-4=>Tabulation+Space-optimisation->
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int cols=matrix[0].size(),rows=matrix.size();
        vector<int>frontRow_cost(cols),currRow_cost(cols);

        for(int c=0;c<cols;++c) frontRow_cost[c]=matrix[rows-1][c];

        for(int r=rows-2;r>=0;--r){
            for(int c=0;c<cols;++c){
                int down=INT_MAX,left_diag=INT_MAX,rt_diag=INT_MAX;
                down=frontRow_cost[c];
                if(c-1>=0) left_diag=frontRow_cost[c-1];
                if(c+1<cols) rt_diag=frontRow_cost[c+1];

                currRow_cost[c]=matrix[r][c]+min({down,left_diag,rt_diag});
            }
            frontRow_cost=currRow_cost;
        }

        int ans=INT_MAX;
        for(int c=0;c<cols;++c){
            ans=min(ans,frontRow_cost[c]);
        }    
        return ans;        
    }       
};