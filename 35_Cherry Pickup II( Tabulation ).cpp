// https://leetcode.com/problems/cherry-pickup-ii/
class Solution {
    vector<int>dirn_x={-1,0,1};
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        int dp[rows][cols][cols];
        // memset(dp,-1,sizeof(dp));        

        for(int rb1=0;rb1<cols;++rb1){
            for(int rb2=0;rb2<cols;++rb2){
                //if both robo are on same cell then only one will else both pick there own cherry
                if(rb1==rb2) dp[rows-1][rb1][rb2]=grid[rows-1][rb1];
                else dp[rows-1][rb1][rb2]=grid[rows-1][rb1]+grid[rows-1][rb2];
            }
        }


        //Fill rest dp->
        for(int r=rows-2;r>=0;--r){
            for(int rb1=0;rb1<cols;++rb1){
                for(int rb2=0;rb2<cols;++rb2){
                    int cherries=(rb1==rb2)?grid[r][rb1]:(grid[r][rb1]+grid[r][rb2]);
                    int maxi=-1e8;
                    //Find which dirn will get us max no of cherries->
                    for(int &r1:dirn_x){
                        for(int &r2:dirn_x){
                            int value=-1e8;
                            if(rb1+r1>=0 and rb1+r1<cols and rb2+r2>=0 and rb2+r2<cols){
                                value=dp[r+1][rb1+r1][rb2+r2];
                            }
                            maxi=max(maxi,value);
                        }
                    }
                    dp[r][rb1][rb2]=cherries+maxi;
                }
            }
        }
        
        //when robo 1 will reach 0 and robo 2 will reach cols-1 pos in 0 th row that would be ans
        int ans=dp[0][0][cols-1];
        
        return ans;
    }
};