// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/
// Watch: https://www.youtube.com/watch?v=Ntzuz7XsdCI&list=PLDzeHZWIZsTomOPnCiU3J95WufjE36wsb&index=21

// LIS-Variation-->
class Solution {

public:
    //Simple LIS-->
    int maxHeight(vector<vector<int>>& cuboids) {
        //sort the dimn of all cuboids and let the max one be the height of cuboid
        for(vector<int>&cuboid:cuboids) 
            sort(cuboid.begin(),cuboid.end());
        
        
        // sort cuboids according to length and width
        sort(cuboids.begin(),cuboids.end());
            
        //Use LIS to get your answer
        int len=cuboids.size();
        
        //Initially put height of cuboids in dp array
        vector<int>dp(len);
        for(int i=0;i<len;++i) dp[i]=cuboids[i][2];
        
        int maxHt=dp[0];
        for(int i=1;i<len;++i){
            for(int j=i-1;j>=0;--j){
                if(cuboids[i][0]>=cuboids[j][0] and cuboids[i][1]>=cuboids[j][1] and cuboids[i][2]>=cuboids[j][2]){
                    dp[i]=max(dp[i],cuboids[i][2]+dp[j]);
                }
            }
            maxHt=max(maxHt,dp[i]);
        }
        return maxHt;
    }
};