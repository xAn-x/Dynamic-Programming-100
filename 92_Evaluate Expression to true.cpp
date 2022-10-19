class Solution {
public:
    //recursion-->
    int mod = 1e9 + 7;

// Recursion-->
// pair<true,false>
    pair<int, int> get_expVal(string &exp, int st, int end) {
        if (st == end) {
            if (exp[st] == 'T') return {1, 0};
            else return {0, 1};
        }

        int count_true = 0, count_false = 0;
        for (int i = st + 1; i < end; i += 2) {
            pair<int, int>p1 = get_expVal(exp, st, i - 1);
            pair<int, int>p2 = get_expVal(exp, i + 1, end);

            int cnt_true = 0, cnt_false = 0;
            if (exp[i] == '&') {
                cnt_true = p1.first * p2.first;
                cnt_false = (p1.first * p2.second) + (p1.second * p2.first) + (p1.second * p2.second);
            } else if (exp[i] == '|') {
                cnt_true = (p1.first * p2.first) + (p1.first * p2.second) + (p1.second * p2.first);
                cnt_false = p1.second * p2.second;
            } else {
                cnt_true = (p1.first * p2.second) + (p1.second * p2.first);
                cnt_false = (p1.first * p2.first) + (p1.second * p2.second);
            }

            count_true = (count_true % mod + cnt_true % mod) % mod;
            count_false = (count_false % mod + cnt_false % mod) % mod;
        }

        return {count_true, count_false};
    }

    int evaluateExp(string & exp) {
        int n = exp.size();
        return get_expVal(exp, 0, n - 1).first;
    }


    // Memoization-->
    typedef long long ll;  
    pair<ll, ll> get_expVal(string &exp, int st, int end,vector<vector<pair<ll,ll>>>&dp) {
        if (st == end) {
            if (exp[st] == 'T') return {1, 0};
            else return {0, 1};
        }

        if(dp[st][end].first!=-1 and dp[st][end].second) return dp[st][end];

        int count_true = 0, count_false = 0;
        for (int i = st + 1; i < end; i += 2) {
            pair<int, int>p1 = get_expVal(exp, st, i - 1,dp);
            pair<int, int>p2 = get_expVal(exp, i + 1, end,dp);

            int cnt_true = 0, cnt_false = 0;
            if (exp[i] == '&') {
                cnt_true = p1.first * p2.first;
                cnt_false = (p1.first * p2.second) + (p1.second * p2.first) + (p1.second * p2.second);
            } else if (exp[i] == '|') {
                cnt_true = (p1.first * p2.first) + (p1.first * p2.second) + (p1.second * p2.first);
                cnt_false = p1.second * p2.second;
            } else {
                cnt_true = (p1.first * p2.second) + (p1.second * p2.first);
                cnt_false = (p1.first * p2.first) + (p1.second * p2.second);
            }

            count_true = (count_true % mod + cnt_true % mod) % mod;
            count_false = (count_false % mod + cnt_false % mod) % mod;
        }

        return dp[st][end]={count_true, count_false};
    }

    int evaluateExp(string & exp) {
        int n = exp.size();
        vector<vector<pair<ll,ll>>>dp(n,vector<pair<ll,ll>>(n,{-1,-1}));
        return get_expVal(exp, 0, n - 1,dp).first;
    }
}