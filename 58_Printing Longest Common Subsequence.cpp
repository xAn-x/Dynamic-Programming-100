#include<bits/stdc++.h>
using namespace std;

// Method-1=>Find all subSequence and then print one which are lcs->	O(Exponential)

// Method-2=>
class Solution{
public:
	void print_longest_common_subSequence(string &text1,string &text2){
    	int l1=text1.length(),l2=text2.length();
    	vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
        
        for(int i=1;i<=l1;++i){
        	for(int j=1;j<=l2;++j){
        		if(text1[i-1]==text2[j-1]){
        			dp[i][j]=1+dp[i-1][j-1];
        		}else{
        			dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        		}
        	}
        }

        /*for(int i=0;i<=l1;++i){
        	for(int j=0;j<=l2;++j){
        		cout<<dp[i][j]<<" ";
        	}cout<<"\n";}*/
        
        /*
        	We will start from last cell dp[n][m]->
				if(s1[n-1]==s2[m-1]){
					then append char in ans and move to dp[n-1][m-1]  
				}else{
					Move to max(dp[n-1][m],dp[n][m-1])
				}
        */

        string ans;
        int len=dp[l1][l2];

        for(int i=l1;i>0;){
        	for(int j=l2;j>0;){
        		if(text1[i-1]==text2[j-1]){
        			ans=text1[i-1]+ans;
        			if(ans.size()==len) break;
        			i--;j--;
        		}else if(dp[i-1][j]>dp[i][j-1]){
        			i--;
        		}else{
        			j--;
        		}
        	}
        	if(ans.size()==len) break;
        }
        cout<<ans<<'\n';
	}
};


int main(){
	string txt1,txt2;
	cin>>txt1>>txt2;

	Solution obj;
	obj.print_longest_common_subSequence(txt1,txt2);
}