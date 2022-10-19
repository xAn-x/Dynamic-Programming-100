// https://leetcode.com/problems/edit-distance/

/*
Method-> Let be a function func(str,i,ptr,j)->representing no of ways I can make ptr till j index using first i char of str

	if str[i]==ptr[j]:
		->if both are matching no need to increase complexity try matching other chars
		return func(str,i-1,ptr,j-1)
	else:
		->hypothetically insert an element in front of i->since on insert j th char will match move it back
		insert=func(str,i,ptr,j-1)

		->to delete ele just move back i-pointer
		delete=func(str,i-1,ptr,j)

		->replace char with some ->since after matching both char become same try matching other
		replace=func(str,i-1,ptr,j-1)

		return min(insert,delete,replace)


	Base-Case
	if j<0:
		->if bith str and ptr get exhausted => we need no more oprn but if str is left then delete remn
		return (i<0)?0:i+1

	if i<0:
		return 1e8
*/


class Solution {
public:
//	Recursion->
	int stringMatching(string&word1,int i,string&word2,int j){
		if(j<0){
			// if bith str and ptr get exhausted => we need no more oprn but if str is left then delete remn
			return (i<0)?0:i+1;
		}else if(i<0){
			// if str get exhausted in that case just insert char to make it equal to ptr
			return j+1;
		}

		if(word1[i]==word2[j]) return 0+stringMatching(word1,i-1,word2,j-1);

		// ->if both are matching no need to increase complexity try matching other chars
		int insert=1+stringMatching(word1,i,word2,j-1);
		// ->to delete ele just move back i-pointer
		int del=1+stringMatching(word1,i-1,word2,j);
		// ->replace char with some ->since after matching both char become same try matching other
		int replace=1+stringMatching(word1,i-1,word2,j-1);

		return min({insert,replace,del});
	}

    int minDistance(string word1, string word2) {
    	int l1=word1.size(),l2=word2.size();
        return stringMatching(word1,l1-1,word2,l2-1);
    }


//	Memoization->
    int stringMatching(string&word1,int i,string&word2,int j,vector<vector<int>>&dp){
		if(j<0){
			// if bith str and ptr get exhausted => we need no more oprn but if str is left then delete remn
			return (i<0)?0:i+1;
		}else if(i<0){
			// if str get exhausted in that case just insert char to make it equal to ptr
			return j+1;
		}

		if(dp[i][j]!=-1) return dp[i][j];

		if(word1[i]==word2[j]) return dp[i][j]=0+stringMatching(word1,i-1,word2,j-1,dp);

		// ->if both are matching no need to increase complexity try matching other chars
		int insert=1+stringMatching(word1,i,word2,j-1,dp);
		// ->to delete ele just move back i-pointer
		int del=1+stringMatching(word1,i-1,word2,j,dp);
		// ->replace char with some ->since after matching both char become same try matching other
		int replace=1+stringMatching(word1,i-1,word2,j-1,dp);

		return dp[i][j]=min({insert,replace,del});
	}

    int minDistance(string word1, string word2) {
    	int l1=word1.size(),l2=word2.size();
    	vector<vector<int>>dp(l1,vector<int>(l2+1,-1));
        return stringMatching(word1,l1-1,word2,l2-1,dp);
    }


// 	Tabulation->
    int minDistance(string word1, string word2) {
    	int l1=word1.size(),l2=word2.size();
    	vector<vector<int>>dp(l1+1,vector<int>(l2+1,-1));
        
        // if str2 has no char then delete remn chars of str1 char to get string
        for(int i=0;i<=l1;++i)
        	dp[i][0]=i;

        // if str1 has no char then insert remn chars of str2 to make them same
        for(int j=0;j<=l2;++j)
        	dp[0][j]=j;  

        for(int i=1;i<=l1;++i){
        	for(int j=1;j<=l2;++j){
        		if(word1[i-1]==word2[j-1]){
        			dp[i][j]=dp[i-1][j-1];
        		}else{
        			int insert=1+dp[i][j-1];
        			int del=1+dp[i-1][j];
        			int replace=1+dp[i-1][j-1];

        			dp[i][j]=min({insert,replace,del});
        		}
        	}
        }
        return dp[l1][l2];
    }

// 	Tabulation + Space-optimisation->
    int minDistance(string word1, string word2) {
    	int l1=word1.size(),l2=word2.size();
    	vector<int>prv(l2+1),curr(l2+1);

    	// on 0th row each element of our col should be j
    	for(int j=0;j<=l2;++j) prv[j]=j;

        for(int i=1;i<=l1;++i){
            curr[0]=i;
            for(int j=1;j<=l2;++j){
        		if(word1[i-1]==word2[j-1]){
        			curr[j]=prv[j-1];
        		}else{
        			int insert=1+curr[j-1];
        			int del=1+prv[j];
        			int replace=1+prv[j-1];

        			curr[j]=min({insert,replace,del});
        		}
        	}
        	prv=curr;
        }
        return prv[l2];
    }
};

