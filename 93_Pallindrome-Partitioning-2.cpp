// https://www.youtube.com/watch?v=_H8V5hJUGd0&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=54
class Solution {
public:
//     Recursion-->

    bool is_pallindrome(string &s, int st, int end) {
        while (st < end) {
            if (s[st] != s[end]) return false;
            ++st; --end;
        }
        return true;
    }

    int fun(string &s, int idx, int len) {
        if (idx == len) return 0;

        int minCuts = 1e9;
        for (int i = idx; i < len; ++i) {
            if (is_pallindrome(s, idx, i)) {
                if (i == len - 1) minCuts = 0;

                int cuts = 1 + fun(s, i + 1, len);
                minCuts = min(minCuts, cuts);
            }
        }

        return minCuts;
    }

// Memoization-->
    bool is_pallindrome(string &s, int st, int end) {
        while (st < end) {
            if (s[st] != s[end]) return false;
            ++st; --end;
        }
        return true;
    }

    int fun(string &s, int idx, int len, vector<int>&dp) {
        if (idx == len) return 0;

        if (dp[idx] != -1) return dp[idx];

        int minCuts = 1e9;
        for (int i = idx; i < len; ++i) {
            if (is_pallindrome(s, idx, i)) {
                int cuts;
                if (i == len - 1) cuts = 0;
                else cuts = 1 + fun(s, i + 1, len, dp);

                minCuts = min(minCuts, cuts);
            }
        }

        return dp[idx] = minCuts;
    }

    int minCut(string s) {
        int len = s.size();
        vector<int>dp(len, -1);
        return fun(s, 0, len, dp);
    }


    // Tabulation-->
    bool is_pallindrome(string &s, int st, int end) {
        while (st < end) {
            if (s[st] != s[end]) return false;
            ++st; --end;
        }
        return true;
    }
    
    int minCut(string s) {
        int len = s.size();
        vector<int>dp(len + 1, INT_MAX);
        dp[len] = 0;

        for(int i=len-1;i>=0;--i){
            for(int j=i;j<len;++j){
                if(is_pallindrome(s,i,j)) dp[i]=min(dp[i],1+dp[j+1]);
            }
        }

        return dp[0]-1;
    }
};