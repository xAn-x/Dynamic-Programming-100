// https://leetcode.com/problems/longest-common-subsequence/


// BruteForce->Find All subsequence of text1 and text2 -> count common =>O(2^l1)+O(2^l2)
class Solution {
	void get_subsets(string&text,string &subSeq,int idx,int len,unordered_set<string>&s){
		if(idx==len){
			s.insert(subSeq);
			return;
		}

		//not take ith char
		get_subsets(text,subSeq,idx+1,len,s);
		//take ith char
		subSeq.push_back(text[idx]);
		get_subsets(text,subSeq,idx+1,len,s);
		subSeq.pop_back();
	}
public:
    int longestCommonSubsequence(string text1, string text2) {
        unordered_set<string>s1,s2;
        string subSeq;
        get_subsets(text1,subSeq,0,text1.size(),s1);
        get_subsets(text2,subSeq,0,text2.size(),s2);

        int max_len=0;
        for(auto it:s1){
            // cout<<it<<"->"<<it.size()<<"\n";
        	if(s2.count(it) and max_len<it.size()){
        		max_len=it.size();
        	}
        }
        return max_len;
    }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*Method-2->IDEA
	IDEA-> We will have a function lcs(s1,i1,s2,i2) which tells us what is the lcs we can make if I Decide to use first i1 chars of s1 and first i2 char of s2.

	Now We will use Recursion to get us our answer
		if s1[i1]==s2[i2]:
			We will pick this ele as matching char will always contri to subseq
			so ans = 1+lcs(s1,i1-1,s2,i2-1)
		
		else:
			We will try both possiblities i.e->
			ans=max(lcs(s1,i1-1,s2,i2),lcs(s1,i1,s2,i2-1))

	Refrence->https://www.youtube.com/watch?v=NPZn9jBrX8U&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=26
*/

class Solution {
	
public:
	// Recursion->
	int lcs(string&s1,int idx1,string&s2,int idx2){
		if(idx1<0 or idx2<0){
			return 0;
		}

		if(s1[idx1]==s2[idx2]){
			return 1+lcs(s1,idx1-1,s2,idx2-1);
		}else{
			return max(lcs(s1,idx1-1,s2,idx2),lcs(s1,idx1,s2,idx2-1));
		}
	} 
    int longestCommonSubsequence(string text1, string text2) {
        return lcs(text1,text1.size()-1,text2,text2.size()-1);
    }


    // Memoization->
    int lcs(string&s1,int idx1,string&s2,int idx2,vector<vector<int>>&dp){
		if(idx1<0 or idx2<0){
			return 0;
		}

		if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

		if(s1[idx1]==s2[idx2]){
			return dp[idx1][idx2]=1+lcs(s1,idx1-1,s2,idx2-1,dp);
		}else{
			return dp[idx1][idx2]=max(lcs(s1,idx1-1,s2,idx2,dp),lcs(s1,idx1,s2,idx2-1,dp));
		}
	} 
    int longestCommonSubsequence(string text1, string text2) {
    	int l1=text1.length(),l2=text2.length();
    	vector<vector<int>>dp(l1,vector<int>(l2,-1));
        return lcs(text1,l1-1,text2,l2-1,dp);
    }


 // Tabulation--:>
	int longestCommonSubsequence(string text1, string text2) {
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

        return dp[l1][l2];
    }


    //  Tabulation+Space-Optimisation
	int longestCommonSubsequence(string text1, string text2) {
    	int l1=text1.length(),l2=text2.length();
        vector<int>prv(l2+1,0),curr(l2+1,0);
        
        for(int i=1;i<=l1;++i){
        	for(int j=1;j<=l2;++j){
        		if(text1[i-1]==text2[j-1]){
        			curr[j]=1+prv[j-1];
        		}else{
        	        curr[j]=max(curr[j-1],prv[j]);
        		}
        	}
            prv=curr;
        }

        return prv[l2];
    }
};


