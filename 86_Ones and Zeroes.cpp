class Solution {
public:
    int helper(vector<vector<int>>&vec,int idx,int zeroes,int ones){
        if(zeroes<0 or ones<0) return -1e9;
        
        if(zeroes==0 and ones==0 or idx==vec.size()) return 0;
        
        
        //If i decide to choose a string
        int cnt1=1+helper(vec,idx+1,zeroes-vec[idx][0],ones-vec[idx][1]);
        
        //If i decide not to choose this string
        int cnt2=helper(vec,idx+1,zeroes,ones);
        
        return max(cnt1,cnt2);
        
    }
    
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>vec;
        for(string &str:strs){
            int cnt0=0,cnt1=0;
            for(char &ch:str){
                if(ch=='0') cnt0++;
                else  cnt1++;
            }
            
            vector<int>v={cnt0,cnt1};
            vec.push_back(v);
        }
        
        
        return helper(vec,0,m,n);
    }

    // Memoization
    int helper(vector<vector<int>>&vec,int idx,int zeroes,int ones,vector<vector<vector<int>>>&dp){
        if(zeroes<0 or ones<0) return -1e9;
        
        if(zeroes==0 and ones==0 or idx==vec.size()) return 0;
        
        if(dp[idx][zeroes][ones]!=-1) return dp[idx][zeroes][ones];
        //If i decide to choose a string
        int cnt1=1+helper(vec,idx+1,zeroes-vec[idx][0],ones-vec[idx][1],dp);
        
        //If i decide not to choose this string
        int cnt2=helper(vec,idx+1,zeroes,ones,dp);
        
        return dp[idx][zeroes][ones]=max(cnt1,cnt2);
        
    }
    
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>vec;
        for(string &str:strs){
            int cnt0=0,cnt1=0;
            for(char &ch:str){
                if(ch=='0') cnt0++;
                else  cnt1++;
            }
            
            vector<int>v={cnt0,cnt1};
            vec.push_back(v);
        }
        
        vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return helper(vec,0,m,n,dp);
    }


};