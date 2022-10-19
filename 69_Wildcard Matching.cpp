// https://leetcode.com/problems/wildcard-matching/

/*Method->
	
	let we have a function func(str,i,ptr,j) that tell weather we can match j chars of ptr with i char of str

	if(str[i]==ptr[j]){
		return func(str,i-1,ptr,j-1);
	}
	if(ptr[j]=='?'){
		return func(str,i-1,ptr,j-1);
	}
	if(ptr[j]=='?'){
		-> '?' can be matched with any no of char so try all

		->till -1 to handle case like -> "aaa" , "*"
		for(int idx=i;i>=-1;--i){
			if(func(str,idx,ptr,j-1)) return true;
		} 
		return false;
	}
	->to handle case when ptr[j] belongs to {a,z} but str[i]!=ptr[j]
	else return false;

	Base-Case->
	if(j<0) return i<0;
	if(i<0) {
		-->to handle this case => "" , "*" or "","*****"
		for(int idx=j;idx>=0;--idx){
			->all remn char in ptr should be '*' only if want to match 
			if(ptr[idx]!='*') return false;
		}
		return true;
	}
*/
class Solution {
public:
// 	Recursion->
	bool isMatch(string &str,int i,string &ptr,int j){
		// Base-Cases
		if(j<0){
			return i<0;
		}
		if(i<0){
			for(int idx=j;idx>=0;--idx)
                if(ptr[idx]!='*') return false;
			return true;
		}

		if(str[i]=='?'){
			return isMatch(str,i-1,ptr,j-1);
		}
        else if(ptr[j]=='*'){
            /*
            	for(int idx=i;idx>=-1;--idx) if(isMatch(str,idx,ptr,j-1,dp)) return dp[i][j]=true;

            	rather than this for loop we can simply do one thing
				
			->replace '*' with ''	 ->match it with ptr[j] and move since we can again take it don't move i
            return isMatch(str,i-1,ptr,j-1,dp) or isMatch(str,i,ptr,j-1,dp);
            */
            return false;
        }
        else if(str[i]==ptr[j]){
            return isMatch(str,i-1,ptr,j-1);
        }
        else{
            return false;
        } 
            
	}

    bool isMatch(string s, string p) {
    	int l1=s.size(),l2=p.size();
        return isMatch(s,l1-1,p,l2-1);
    }


// 	Memoization->
    bool isMatch(string &str,int i,string &ptr,int j,vector<vector<int>>&dp){
		if(j<0){
			return i<0;
		}
		if(i<0){
			for(int idx=j;idx>=0;--idx)
                if(ptr[idx]!='*') return false;
			return true;
		}


		if(dp[i][j]!=-1) return dp[i][j];

		if(ptr[j]=='?'){
			return dp[i][j]=isMatch(str,i-1,ptr,j-1,dp);
		}
        else if(ptr[j]=='*'){
            for(int idx=i;idx>=-1;--idx){
                // cout<<idx<<"->";
                if(isMatch(str,idx,ptr,j-1,dp)) return dp[i][j]=true;
            }
            return dp[i][j]=false;
        }
        else if(str[i]==ptr[j]){
            return dp[i][j]=isMatch(str,i-1,ptr,j-1,dp);
        }
        else{
            return dp[i][j]=false;
        } 
            
	}

    bool isMatch(string s, string p) {
    	int l1=s.size(),l2=p.size();

    	vector<vector<int>>dp(l1,vector<int>(l2,-1));
        return isMatch(s,l1-1,p,l2-1,dp);
    }


// Efficient Memoization->
    bool isMatch(string &str,int i,string &ptr,int j,vector<vector<int>>&dp){
		if(j<0){
			return i<0;
		}
		if(i<0){
			for(int idx=j;idx>=0;--idx)
                if(ptr[idx]!='*') return false;
			return true;
		}


		if(dp[i][j]!=-1) return dp[i][j];

		if(ptr[j]=='?'){
			return dp[i][j]=isMatch(str,i-1,ptr,j-1,dp);
		}
        else if(ptr[j]=='*'){
            /*
            	for(int idx=i;idx>=-1;--idx) if(isMatch(str,idx,ptr,j-1,dp)) return dp[i][j]=true;

            	rather than this for loop we can simply do one thing
				
			->replace '*' with ''	 ->match it with ptr[j] and move since we can again take it don't move i
            return isMatch(str,i-1,ptr,j-1,dp) or isMatch(str,i,ptr,j-1,dp);
            */
            return dp[i][j]=isMatch(str,i-1,ptr,j-1,dp) or isMatch(str,i,ptr,j-1,dp);
        }
        else if(str[i]==ptr[j]){
            return dp[i][j]=isMatch(str,i-1,ptr,j-1,dp);
        }
        else{
            return dp[i][j]=false;
        } 
            
	}

    bool isMatch(string s, string p) {
    	int l1=s.size(),l2=p.size();

    	vector<vector<int>>dp(l1,vector<int>(l2,-1));
        return isMatch(s,l1-1,p,l2-1,dp);
    }

// 	Tabulation->
// 	Tabulation->
    bool isMatch(string str, string ptr) {
    	int l1=str.size(),l2=ptr.size();

    	vector<vector<bool>>dp(l1+1,vector<bool>(l2+1,false));
    	dp[0][0]=true;

    	for(int j=1;j<=l2;++j){
    		if(ptr[j-1]=='*') dp[0][j]=dp[0][j-1];
    	}

    	for(int i=1;i<=l1;++i){
    		for(int j=1;j<=l2;++j){
    			if(ptr[j-1]=='?'){
    				dp[i][j]=dp[i-1][j-1];
    			}
    			else if(ptr[j-1]=='*'){
    				dp[i][j]=dp[i-1][j] or dp[i][j-1];
    			}
    			else if(str[i-1]==ptr[j-1]){
    				dp[i][j]=dp[i-1][j-1];
    			}
    			else{
    				dp[i][j]=false;
    			}
    		}
    	}
    	return dp[l1][l2];
    }
};

