#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1/

/*class Solution{
public:
	int longestCommonSubstr (string s1, string s2, int n, int m){
		// just for some space optimisation
        if(n>m){
        	return longestCommonSubstr(s2,s1,m,n);
        }
        unordered_set<string>s;
        for(int i=0;i<n;++i){
        	string str;
        	for(int j=i;j<n;++j){
        		str.push_back(s1[j]);
        		s.insert(str);
        	}
        }

        int max_len=0;
        for(int i=0;i<m;++i){
        	string str;
        	for(int j=i;j<m;++j){
        		str.push_back(s2[j]);
        		if(s.count(str)){
        			max_len=max(max_len,j-i+1);
        		}
        	}
        }

        return max_len;
    }
};*/


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Longest Common Substring -> Using -> Longest Common Subsequence

class Solution{
	/*
		IDEA-> Using Tabulationof LCS

		While doing tabulation->
			if s1[i-1]==s2[j-1]:
				dp[i][j]=1+dp[i-1][j]
			else:
				dp[i][j]=max(dp[i-1][j],dp[i][j-1])
				We will enter this else only if break happen-> i.e no more common substr forming
				so in longestCommonSubstr we will don't even use this condn we will simply put 0 here

			refrence->https://www.youtube.com/watch?v=_wP9mWNPL5w&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=28
	*/
public:
	int longestCommonSubstr(string &s1,string &s2,int n,int m){
		vector<vector<int>>dp(n+1,vector<int>(m+1));

		int max_len=0;
		for(int i=1;i<=n;++i){
			for(int j=0;j<=m;++j){
				if(s1[i-1]==s2[j-1]){
					dp[i][j]=1+dp[i-1][j-1];
					max_len=max(max_len,dp[i][j]);
				}
			}
		}

		return max_len;
	}
};

int main(){
	string s1,s2;
	cin>>s1>>s2;

	Solution obj;
	cout<<obj.longestCommonSubstr(s1,s2,s1.size(),s2.size());

}