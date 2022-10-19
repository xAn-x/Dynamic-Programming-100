class Solution {
public:

//Plain-Recursion->Time-Complexity->exponential
	int helper(string &s,int idx,int len){
        if(idx==len) return 1;

        char char_1=s[idx];
        if(char_1=='0') return 0;
        
        int way1=0,way2=0;
        way1=helper(s,idx+1,len,dp);
        
        //We should have atleast 2-char left
        if(len-idx>=2){
            string two_letter=s.substr(idx,2);
            int val=stoi(two_letter);
            
            if(val>26)
                way2=0;
            else
                way2=helper(s,idx+2,len,dp);
        }
        
        return way1+way2;
    }


// Memoization->Time- and Space-Complexity=>O(n) 
    int helper(string &s,int idx,int len,vector<int>&dp){
        if(idx==len) return 1;
        
        if(dp[idx]!=-1) return dp[idx];
        
        char char_1=s[idx];
        if(char_1=='0') return 0;
        
        int way1=0,way2=0;
        way1=helper(s,idx+1,len,dp);
        
        //We should have atleast 2-char left
        if(len-idx>=2){
            string two_letter=s.substr(idx,2);
            int val=stoi(two_letter);
            
            if(val>26)
                way2=0;
            else
                way2=helper(s,idx+2,len,dp);
        }
        
        return dp[idx]=way1+way2;
    }
    
    int numDecodings(string s) {
        int len=s.size();
        if(s[0]=='0') return 0;

//Recursion
        // return helper(s,0,len); 

//--------------------------------------------------------------------------------------

//Memoization
        // vector<int>dp(len+1,-1);
        // return helper(s,0,len,dp); 

//--------------------------------------------------------------------------------------

// Tabulation

//explanation-> mst-watch ->https://www.youtube.com/watch?v=jFZmBQ569So&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=20
     	vector<int>dp(len);
     	if(s[0]=='0') return 0;

     	dp[0]=1;
     	for(int i=1;i<len;++i){
     		if(s[i-1]=='0' and s[i]=='0'){
     			dp[i]=0;
     		}
     		else if(s[i-1]=='0' and s[i]!='0'){
     			dp[i]=dp[i-1];
     		}
     		else if(s[i-1]!='0' and s[i]=='0'){
     			//because the two-letter value must be less than 26
     			if(s[i-1]=='1' or s[i-1]=='2'){
     				//ternary opr so to handle case if i=1
     				dp[i]=(i>=2)?dp[i-2]:1;
     			}else{
     				dp[i]=0;
     			}
     		}else{
     			int two_letter_val=stoi((s[i-1]+s[i]));
     			if(val<=26){
     				//ternary opr so to handle case if i=1
     				dp[i]=dp[i-1]+((i>=2)?dp[i-2]:1);
     			}else{
     				dp[i]=dp[i-1];
     			}
     		}		
     	}
     	return dp[len-1];
    }
};