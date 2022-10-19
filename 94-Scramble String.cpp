// Watch: https://www.youtube.com/watch?v=MDmZm_aVDF8
class Solution {
public:
    //Recursive-->
    bool solve(string s1,string s2){
        int len=s1.size();
        if(len==0) return true;
        if(len==1) return s1==s2;
        
        
        for(int i=1;i<len;++i){
            if(solve(s1.substr(0,i),s2.substr(0,i)) and solve(s1.substr(i),s2.substr(i)))
                return true;
            
            if( solve(s1.substr(0,i),s2.substr(len-i)) and solve(s1.substr(i),s2.substr(0,len-i)) )
                return true;
        }
        
        return false;
    }
    
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        
        return solve(s1,s2);
    }


    // Memoization-->
     bool solve(string s1,string s2,unordered_map<string,bool>&dp){
        int len=s1.size();
        if(len==0) return true;
        if(len==1) return s1==s2;
        
        string str=s1+"#"+s2;
        if(dp.count(str)) return dp[str];

        for(int i=1;i<len;++i){
            if(solve(s1.substr(0,i),s2.substr(0,i),dp) and solve(s1.substr(i),s2.substr(i),dp))
                return dp[str]=true;
            
            if( solve(s1.substr(0,i),s2.substr(len-i),dp) and solve(s1.substr(i),s2.substr(0,len-i),dp) )
                return dp[str]=true;
        }
        
        return dp[str]=false;
    }
    
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        unordered_map<string,bool>dp;
        return solve(s1,s2,dp);
    }



    // Memoization+Pruning-->
    
    // 2 string can be scrambled only if both string have same chars so we can use it to remove un-neccesary calls,but if all chars are there this doesn't mean that strings will be scrambled we need to chk them then
    bool solve(string s1,string s2,unordered_map<string,bool>&dp){
        int len=s1.size();
        if(len==0) return true;
        if(len==1) return s1==s2;
        
        string str=s1+"#"+s2;
        if(dp.count(str)) return dp[str];
        
        vector<int>freq1(26),freq2(26);
        for(int i=0;i<len;++i){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        
        if(freq1!=freq2){
            return dp[str]=false;
        }

        for(int i=1;i<len;++i){
            if(solve(s1.substr(0,i),s2.substr(0,i),dp) and solve(s1.substr(i),s2.substr(i),dp))
                return dp[str]=true;
            
            if( solve(s1.substr(0,i),s2.substr(len-i),dp) and solve(s1.substr(i),s2.substr(0,len-i),dp) )
                return dp[str]=true;
        }
        
        return dp[str]=false;
    }
    
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        unordered_map<string,bool>dp;
        return solve(s1,s2,dp);
    }
};