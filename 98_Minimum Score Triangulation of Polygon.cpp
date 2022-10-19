// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/

class Solution {
public:
    // Recursion-->
    int solve(vector<int>&values,int st,int end){
        if(end-st+1==3){
            int ans=1;
            for(int i=st;i<=end;++i) ans*=values[i];
            return ans;
        }else if(end-st+1<3) return 0;
        
        //Choose the 3rd point(it can any one that is left)
        int minArea=1e9;
        for(int k=st+1;k<end;++k){
            int area=values[st]*values[end]*values[k]+solve(values,st,k)+solve(values,k,end);
            minArea=min(minArea,area);
        }
        return minArea;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        int len=values.size();
        return solve(values,0,len-1);
    }


    // Memoization-->
    int solve(vector<int>&values,int st,int end,vector<vector<int>>&dp){
        if(end-st+1<3) return 0;
        
        if(dp[st][end]!=-1) return dp[st][end];

        //Choose the 3rd point(it can any one that is left)
        int minArea=1e9;
        for(int k=st+1;k<end;++k){
            int area=values[st]*values[end]*values[k]+solve(values,st,k,dp)+solve(values,k,end,dp);
            minArea=min(minArea,area);
        }
        return dp[st][end]=minArea;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        int len=values.size();
        vector<vector<int>>dp(len,vector<int>(len,-1));
        return solve(values,0,len-1,dp);
    }


    // Tabulation-->
    int minScoreTriangulation(vector<int>& values) {
        int len=values.size();
        vector<vector<int>>dp(len,vector<int>(len,0));

        for(int i=len-1;i>=0;--i){
            for(int j=i+1;j<len;++j){
                if(j-i+1<3) continue;
                int val=1e9;
                for(int k=i+1;k<j;++k){
                    val=min(val,values[i]*values[j]*values[k]+dp[i][k]+dp[k][j]);
                }
                dp[i][j]=val;
            }
        }
        return dp[0][len-1];
    }
};