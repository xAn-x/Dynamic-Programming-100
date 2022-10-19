// https://leetcode.com/problems/longest-string-chain/
class Solution {
public:
    static bool cmp(string &s1,string &s2){
        return s1.size()<s2.size();
    }
    
    bool can_make(string &src,string &dest){
        //Keep 2 pointer at start of string and check weather they just differ by atmost 1 char only
        int src_i=src.size()-1,dest_i=dest.size()-1,append_cnt=0;

        while(dest_i>=0 and src_i>=0){
            if(src[src_i]==dest[dest_i]){
                src_i--; dest_i--;
                continue;
            }

            append_cnt++;
            if(append_cnt>1) break;
            dest_i--;
        }

        return append_cnt<=1;
    }
    
    int longestStrChain(vector<string>& words) {
        //Sort words according to their size as we want longer string as we move ahead
        sort(words.begin(),words.end(),cmp);
        
        //This is same as lis but we just have to chk that can we make next string by appending just 1 char
        int n=words.size();
        vector<int>dp(n,1);

        int max_len=1;
        for(int i=1;i<n;++i){
            for(int j=i-1;j>=0;--j){
                //As we need to append char in order in increase chain length
                if(words[j].size()==words[i].size()) continue;

                if(can_make(words[j],words[i]) and dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                }
            }
            max_len=max(dp[i],max_len);
        }

        return max_len;
    }
    
};
