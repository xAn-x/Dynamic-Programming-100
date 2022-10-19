#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//Method-1=>Get-all SubSequence of str1 and str2 and then print one which is lcs->expo Time-Compl

// Explanation->https://www.youtube.com/watch?v=-zI4mrF2Pb4&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=27
void print_lcs(string&text1,string&text2){
	int l1=text1.size(),l2=text2.size();
	vector<vector<int>>dp(l1+1,vector<int>(l2+1));

	for(int s1=1;s1<=l1;++s1){
		for(int s2=1;s2<=l2;++s2){
			if(text1[s1-1]==text2[s2-1]) dp[s1][s2]=1+dp[s1-1][s2-1];
			else dp[s1][s2]=max(dp[s1-1][s2],dp[s1][s2-1]);
		}
	}

	// Traverse from very end and find lcs->
	int r=l1,c=l2,lcs_len=dp[l1][l2];
	string lcs(lcs_len,'*');
	int idx=lcs_len-1;

	while(r>0 and c>0){
		if(text1[r-1]==text2[c-1]){
			lcs[idx]=text1[r-1];
			--r;--c;--idx;
		}else if(dp[r-1][c]>dp[r][c-1]){
			--r;
		}else{
			--c;
		}
	}

	cout<<lcs<<"\n";
}

int main(){
 //add the two lines below for fast i/o
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
      
	string text1,text2;
	cin>>text1>>text2;
 
	print_lcs(text1,text2);

	return 0;
}