// https://leetcode.com/problems/cherry-pickup/

/*                                  ----ALGO-IDEA----
    Idea is to traverse all path while going down and then when reach our dest we try traversing all paths from dest to src again.

    We optimally collected cherry while going in and coming back thus always get correct answer
*/
class Solution {
private:
    int max_collected=0;

    void come_back(vector<vector<int>>&grid,int n,int r,int c,int cherry_collected){
        if(r<0 or c<0 or grid[r][c]==-1) return ;
        if(r==0 and c==0){
            int cherry=grid[r][c];
            grid[r][c]=0;
            max_collected=max(max_collected,cherry_collected+cherry);
            grid[r][c]=cherry;
            return;
        }

        int cherry=grid[r][c];
        grid[r][c]=0;

        come_back(grid,n,r-1,c,cherry_collected+cherry);
        come_back(grid,n,r,c-1,cherry_collected+cherry);

        grid[r][c]=cherry;       
    }

    void cherry_picker(vector<vector<int>>&grid,int n,int r,int c,int cherry_collected){
        if(r==n or c==n or grid[r][c]==-1) return ;
        if(r==n-1 and c==n-1){
            come_back(grid,n,r,c,cherry_collected);
            return;
        }

        int cherry=grid[r][c];
        grid[r][c]=0;

        cherry_picker(grid,n,r+1,c,cherry_collected+cherry);
        cherry_picker(grid,n,r,c+1,cherry_collected+cherry);

        grid[r][c]=cherry;
    }    

public:

    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int cherry_collected=0;
        cherry_picker(grid,n,0,0,cherry_collected);

        return max_collected;    
    }
};