// https://leetcode.com/problems/unique-paths-ii/submissions/
class Solution {
public:
    //Method-1=>Dp->Tabulation
    /*
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r=obstacleGrid.size(),c=obstacleGrid[0].size();

        vector<vector<long>> grid(r,vector<long>(c));

        bool obstacleEncounter=false;
        for(int i=c-1;i>=0;i--){
            if(obstacleGrid[r-1][i]) obstacleEncounter=true;
            grid[r-1][i]=(obstacleEncounter)?0:1;
        }

        obstacleEncounter=false;
        for(int i=r-1;i>=0;i--){
            if(obstacleGrid[i][c-1]) obstacleEncounter=true;
            grid[i][c-1]=(obstacleEncounter)?0:1;
        }

        for(int i=r-2;i>=0;--i){
            for(int j=c-2;j>=0;--j){
                if(obstacleGrid[i][j]==0){
                    grid[i][j]+=(grid[i][j+1]+grid[i+1][j]);
                }else grid[i][j]=0;
            }
        }

        return grid[0][0];
    }
    */


    //Method-2=>Dp->Tabulation+space-optimisatiom
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r=obstacleGrid.size(),c=obstacleGrid[0].size();

        if(obstacleGrid[r-1][c-1]==1) return 0; //if dest cell is bloaced itself

        //Note: We don't need whole grid but only the prv row in order to decide
        vector<int> prv_row(c,1);

        //filling lst row
        for(int i=c-2;i>=0;i--){
            if(obstacleGrid[r-1][i]==1){
                prv_row[i]=0;
                continue;
            }
            prv_row[i]=prv_row[i+1];
        }

        for(int i=r-2;i>=0;--i){
            vector<int> curr_row(c);
            for(int j=c-1;j>=0;--j){
                if(obstacleGrid[i][j]==1){
                    curr_row[j]=0;
                    continue;
                }
                int down=prv_row[j];
                int right=(j==c-1)?0:curr_row[j+1];
                curr_row[j]=down+right;       
            }
            prv_row=curr_row;
        }
        return prv_row[0];
    }
};