// https://practice.geeksforgeeks.org/explore

class Solution{
public:
    static bool cmp(val &v1,val &v2){
        if(v1.first==v2.first) return v1.second<v2.second;
        return v1.first<v2.first;
    }
    int maxChainLen(struct val p[],int n){
        // This question is similar to LIS-->
        
        sort(p,p+n,cmp);
        vector<int>dp(n,1);
        int ans=1;
        
        for(int i=1;i<n;++i){
            for(int j=i-1;j>=0;--j){
                if(p[i].first>p[j].second){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }


    // <-------Binary-Search------->
     int maxChainLen(struct val p[],int n){
        // This question is similar to LIS-->
        sort(p,p+n,cmp);
        int ans=1;
        int prv=p[0].second;
        for(int i=1;i<n;++i){
           if(p[i].first>prv){
               ans++;
               prv=p[i].second;
           }
        }
        return ans;
    }
};