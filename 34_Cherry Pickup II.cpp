// https://leetcode.com/problems/cherry-pickup-ii/
class Solution {
private:
    vector<int>dirn_x={-1,0,1};
    int dp[70][70][70][70];
    int dp2[70][70][70];

public:
    //Method-1 =>Plain-Recursion
    /*
    int cherry_picker(vector<vector<int>>&grid,int rows,int cols,int r1,int c1,int r2,int c2){
        if(r1<0 or r2<0 or c1==cols or c2==cols or c1<0 or c2<0) return 0;
        else if(r1==rows-1 and r2==rows-1){
            if(c1==c2) return grid[rows-1][c1];
            else return grid[rows-1][c1]+grid[rows-1][c2];
        } 

        int cherry1=grid[r1][c1],cherry2=grid[r2][c2];
        grid[r1][c1]=grid[r2][c2]=0;

        int cherry_collected=(r1==r2 and c1==c2)?cherry1:(cherry1+cherry2);

        int max_from_rest=-1;
        for(int &x:dirn_x){
            for(int &X:dirn_x){
                max_from_rest=max(cherry_picker(grid,rows,cols,r1+1,c1+x,r2+1,c2+X),max_from_rest);
            }
        }
        
        grid[r1][c1]=cherry1;grid[r2][c2]=cherry2;
        return cherry_collected+max_from_rest;
    }
    */

//-------------------------------------------------------------------------------------------------------

    //Method-2=>Memoization->
    /*
    int cherry_picker(vector<vector<int>>&grid,int rows,int cols,int r1,int c1,int r2,int c2,int dp[70][70][70][70]){
        if(r1==rows or r2==rows or c1==cols or c2==cols or c1<0 or c2<0) return 0;
        else if(r1==rows-1 and r2==rows-1){
            if(c1==c2) return grid[rows-1][c1];
            else return grid[rows-1][c1]+grid[rows-1][c2];
        } 

        if(dp[r1][c1][r2][c2]!=-1) return dp[r1][c1][r2][c2];

        int cherry1=grid[r1][c1],cherry2=grid[r2][c2];
        grid[r1][c1]=grid[r2][c2]=0;

        int cherry_collected=(r1==r2 and c1==c2)?cherry1:(cherry1+cherry2);

        int max_from_rest=-1;
        for(int &x:dirn_x){
            for(int &X:dirn_x){
                max_from_rest=max(cherry_picker(grid,rows,cols,r1+1,c1+x,r2+1,c2+X,dp),max_from_rest);
            }
        }
        
        grid[r1][c1]=cherry1;grid[r2][c2]=cherry2;
        return dp[r1][c1][r2][c2]=(cherry_collected+max_from_rest);
    }
    */

//-------------------------------------------------------------------------------------------------------
    
    //Method-3=>Memoization->
    int cherry_picker(vector<vector<int>>&grid,int rows,int cols,int r,int c1,int c2,int dp[70][70][70]){
        if(c1==cols or c2==cols or c1<0 or c2<0) return 0;
        else if(r==rows-1){
            if(c1==c2) return grid[rows-1][c1];
            else return grid[rows-1][c1]+grid[rows-1][c2];
        } 

        if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];

        int cherry1=grid[r][c1],cherry2=grid[r][c2];
        grid[r][c1]=grid[r][c2]=0;

        int cherry_collected=(c1==c2)?cherry1:(cherry1+cherry2);

        int max_from_rest=-1;
        for(int &x:dirn_x){
            for(int &X:dirn_x){
                max_from_rest=max(cherry_picker(grid,rows,cols,r+1,c1+x,c2+X,dp),max_from_rest);
            }
        }
        
        grid[r][c1]=cherry1;grid[r][c2]=cherry2;
        return dp[r][c1][c2]=(cherry_collected+max_from_rest);
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        // int ans=cherry_picker(grid,rows,cols,0,0,0,cols-1); -->plain recursion

        //Memoization
        memset(dp,-1,sizeof(dp));
        int ans=cherry_picker(grid,rows,cols,0,0,0,cols-1,dp)

        //Memoization+space-Optimisation
        /*                              ----IDEA-----
            Note no matter how the 2 rob's move but they always move 1 step down in each move
            Now both start from same row so they will reach the last row together so r1=r2=r
        */

        memset(dp2,-1,sizeof(dp2));
        int ans=cherry_picker(grid,rows,cols,0,0,cols-1,dp2);

        return ans;
    }
};