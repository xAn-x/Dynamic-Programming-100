#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution{
    int mod=1e9+7;
public:
    ll helper(int index,int n,vector<bool>&s){
        if(index==n) return 1;
        
        ll cnt=0ll;
        for(int ele=0;ele<n;++ele){
            if(ele==index or s[ele]) continue;
            s[ele]=true;
            int c=helper(index+1,n,s);
            cnt=(cnt%mod+c%mod)%mod;
            s[ele]=false;
        }
        return cnt;
    }

    long long int countDerangements1(int n) {
        //For each index i have n-1 choice {1,n}-i
        vector<bool>s(n,false);
        return helper(0,n,s);
    }

// ----- Recursion but efficient ------->

    ll countDerangements2(int n) {
        if(n==1 or n==2) return n-1;
        return ( ((n-1)%mod)*(countDerangements2(n-2)%mod+countDerangements2(n-1)%mod)%mod )%mod;
    }


//---------- Memoization -------->
    ll helper(int n,unordered_map<int,int>&ds){
        if(n<=2) return n-1;

        if(ds.count(n)) return ds[n];
        return ds[n]=( ((n-1)%mod)*(helper(n-2,ds)%mod+helper(n-1,ds)%mod)%mod )%mod;
    }

    ll countDerangements(int n){
        unordered_map<int,int>ds;
        return helper(n,ds);
    }


//---------- Tabulation ---------->
    ll countDerangements(int n){
        int arr[n+1]={0,1};
        for(int i=2;i<=n;--i){
            arr[i]=(i-1)*(arr[i-1]+arr[i-2]);
        }
        return arr[n];
    }

};

