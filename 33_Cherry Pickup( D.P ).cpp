// https://leetcode.com/problems/cherry-pickup/

/*                          ----IDEA----
    Rather than starting from src and going to destn nad then coming back we can say say that 2 people start from src and explore diffrent paths so I can treat 1 path as going in for pick and other as cmoing back to src path 
*/

class Solution {
public:
    //Method-1=>Plain-Recursion
    /*
    int cherry_picker(vector<vector<int>>&grid,int n,int r1,int c1,int r2,int c2){
        if(r1==n or c1==n or r2==n or c2==n or grid[r1][c1]==-1 and grid[r2][c2]==-1) return -1e7;
        else if(r1==n-1 and c1==n-1 and r2==n-1 and c2==n-1) return grid[r1][c1];

        int cherry1=grid[r1][c1],cherry2=grid[r2][c2];
        //If both person are on same spot then only one will that else both will pick there own cherry
        int cherry_collected=(r1==r2 and c1==c2)?(cherry1):(cherry1+cherry2);
        grid[r1][c1]=0;grid[r2][c2]=0;

        int pth_1=cherry_picker(grid,n,r1,c1+1,r2,c2+1); // H-H
        int pth_2=cherry_picker(grid,n,r1,c1+1,r2+1,c2); // H-V
        int pth_3=cherry_picker(grid,n,r1+1,c1,r2,c2+1); // V-H
        int pth_4=cherry_picker(grid,n,r1+1,c1,r2+1,c2); // H-H

        grid[r1][c1]=cherry1;grid[r2][c2]=cherry2;

        return cherry_collected+max({pth_1,pth_2,pth_3,pth_4});
    }
    */

//----------------------------------------------------------------------------------------------------

    //Method-2=>Memoization->Time O(m*n) and space-O(m^2*n^2)
    /*
    int cherry_picker(vector<vector<int>>&grid,int n,int r1,int c1,int r2,int c2,int dp[51][51][51][51]){
        if(r1==n or c1==n or r2==n or c2==n or grid[r1][c1]==-1 or grid[r2][c2]==-1) return -1e7;
        else if(r1==n-1 and c1==n-1 and r2==n-1 and c2==n-1 ) return grid[n-1][n-1];

        if(dp[r1][c1][r2][c2]!=-1) return dp[r1][c1][r2][c2];

        int cherry1=grid[r1][c1],cherry2=grid[r2][c2];
        //If both person are on same spot then only one will that else both will pick there own cherry
        int cherry_collected=( (r1==r2 and c1==c2)?(cherry1):(cherry1+cherry2) );
        grid[r1][c1]=0;grid[r2][c2]=0;

        int pth_1=cherry_picker(grid,n,r1,c1+1,r2,c2+1,dp); // H-H
        int pth_2=cherry_picker(grid,n,r1,c1+1,r2+1,c2,dp); // H-V
        int pth_3=cherry_picker(grid,n,r1+1,c1,r2,c2+1,dp); // V-H
        int pth_4=cherry_picker(grid,n,r1+1,c1,r2+1,c2,dp); // V-V

        grid[r1][c1]=cherry1;grid[r2][c2]=cherry2;

        return dp[r1][c1][r2][c2]=cherry_collected+max({pth_1,pth_2,pth_3,pth_4});
    }
    */

//----------------------------------------------------------------------------------------------------
    //Method-3=Memoization+Space-Optimisation ->O(m^2*n) space  
    int cherry_picker(vector<vector<int>>&grid,int n,int r1,int c1,int r2,int dp[51][51][51]){
        int c2=r1+c1-r2;
        if(r1==n or c1==n or r2==n or c2==n or grid[r1][c1]==-1 or grid[r2][c2]==-1) return -1e7;
        else if(r1==n-1 and c1==n-1 and r2==n-1 and c2==n-1 ) return grid[n-1][n-1];

        if(dp[r1][c1][r2][c2]!=-1) return dp[r1][c1][r2][c2];

        int cherry1=grid[r1][c1],cherry2=grid[r2][c2];
        //If both person are on same spot then only one will that else both will pick there own cherry
        int cherry_collected=( (r1==r2 and c1==c2)?(cherry1):(cherry1+cherry2) );
        grid[r1][c1]=0;grid[r2][c2]=0;

        int pth_1=cherry_picker(grid,n,r1,c1+1,r2,dp); // H-H
        int pth_2=cherry_picker(grid,n,r1,c1+1,r2+1,dp); // H-V
        int pth_3=cherry_picker(grid,n,r1+1,c1,r2,dp); // V-H
        int pth_4=cherry_picker(grid,n,r1+1,c1,r2+1,dp); // V-V

        grid[r1][c1]=cherry1;grid[r2][c2]=cherry2;

        return dp[r1][c1][r2][c2]=cherry_collected+max({pth_1,pth_2,pth_3,pth_4});
    }

private:
    int dp[51][51][51][51];
    int dp2[51][51][51];


public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
//---------------------------------------------------------------------------------------------------------------------

        // int ans=cherry_picker(grid,n,0,0,0,0); // plain recursion

//---------------------------------------------------------------------------------------------------------------------

        // memset(dp,-1,sizeof(dp)); int ans=cherry_picker(grid,n,0,0,0,0,dp); // Memoization

//---------------------------------------------------------------------------------------------------------------------
        
        /*                              Space-optimisation-Idea=>
            In each step both of the person are moving any some dirn always by 1 step so,using this we can say->
                r1+c1=r2+c2 ==>c2=r1+c1-r2 so we only need 3 dimn we can calc 4th by ourself.                             */
        memset(dp2,-1,sizeof(dp2)); int ans=cherry_picker(grid,n,0,0,0,dp2);// Memoization+Space-Optimisation
        return (ans<=0) ? 0 : ans;

    }


};