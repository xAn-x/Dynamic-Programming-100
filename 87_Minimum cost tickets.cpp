class Solution {
public:
    // Method-1 Recurstion
    int helper(vector<int>&days,vector<int>&cost,int idx,int lastDay){
        if(idx==days.size()) return 0;
        
        //We we have some exisiting pass don't buy a new pass
        if(days[idx]<=lastDay) return helper(days,cost,idx+1,lastDay);
        
        int cst=1e8;
        for(int i=0;i<3;++i){
            if(i==0) lastDay=days[idx];
            else if(i==1) lastDay=days[idx]+6;
            else lastDay=days[idx]+29;
            
            cst=min(cst,cost[i]+helper(days,cost,idx+1,lastDay));
        }
                
        return cst;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return helper(days,costs,0,0);
    }



     // Method-2:Recursion
    int helper(vector<int>&days,vector<int>&cost,int idx){
        int n=days.size();
        if(idx==n) return 0;

        int cst=1e8;
        for(int i=0;i<3;++i){
            int lastDay;
            if(i==0) lastDay=days[idx];
            else if(i==1) lastDay=days[idx]+6;
            else lastDay=days[idx]+29;

            int temp=idx;
            while(temp<n and days[temp]<=lastDay) ++temp;

            int restCost=0;
            if(temp!=n) restCost=helper(days,cost,temp);

            cst=min(cst,cost[i]+restCost);
        }

        return cst;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return helper(days,costs,0);
    }


    // Memoization-->
    int helper(vector<int>&days,vector<int>&cost,int idx,vector<int>&dp){
        int n=days.size();
        if(idx==n) return 0;

        if(dp[idx]!=-1) return dp[idx];
        
        int cst=1e8;
        for(int i=0;i<3;++i){
            int lastDay;
            if(i==0) lastDay=days[idx];
            else if(i==1) lastDay=days[idx]+6;
            else lastDay=days[idx]+29;

            int temp=idx;
            while(temp<n and days[temp]<=lastDay) ++temp;

           
            cst=min(cst,cost[i]+helper(days,cost,temp,dp));
        }

        return dp[idx]=cst;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n+1,-1);
        return helper(days,costs,0,dp);
    }

    // Tabulation--->
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n+1,1e8);
        dp[n]=0;

        for(int idx=n-1;idx>=0;--idx){
            for(int i=0;i<3;++i){
                int lastDay;
                if(i==0) lastDay=days[idx];
                else if(i==1) lastDay=days[idx]+6;
                else lastDay=days[idx]+29;

                int j;
                for(j=idx;j<n and days[j]<=lastDay;++j) ;

                dp[idx]=min(dp[idx],costs[i]+dp[j]);    
            }
        }

        return dp[0];
    }
};