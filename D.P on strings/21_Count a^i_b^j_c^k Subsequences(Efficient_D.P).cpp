#include<iostream>
#include<vector>
using namespace std;

	/*													----IDEA----
		This is for sure that our subseqn will start fom 'a' and end at 'c' so if at every point I can some-how know the count of all subseq which follor our order and end at a,b and c then for new char I can calculate res using prv results->

		if curr char is 'a' ->Can only append it in front of subseq which end at a or leave them or start new subseqn
			-> now no of subseqn ending at 'a'=2*prv_count(include or not include) + 1(start new)

		if curr char is 'b' ->Can only append it in front of subseq which end at 'b' or leave them or append them in front of subseq ending at 'a' so to extend them and make them end at 'b' 
			-> now no of subseqn ending at 'b'=2*prv_count(include or not include) + sub_seqn_ending at 'a'
		
		if curr char is 'c' ->Can only append it in front of subseq which end at 'c' or leave them or append them in front of subseq ending at 'b' so to extend them and make them end at 'c' 
			-> now no of subseqn ending at 'c'=2*prv_count(include or not include) + sub_seqn_ending at 'b'		

		NOTE:- b and c itself can't start a new subseqn at they must start with 'a' and end at 'c'
	*/


int count_req_subSeqn(string&str){
	int len=str.size();
	vector<vector<int>>dp(3,vector<int>(len+1,0));
	for(int i=1;i<=len;++i){
		char ch=str[i-1];
        
        //rest ele should remain same as prv
        dp[0][i]=dp[0][i-1];
        dp[1][i]=dp[1][i-1];
        dp[2][i]=dp[2][i-1];

		if(ch=='a'){
			dp[0][i]=2*dp[0][i-1]+1;
		}else if(ch=='b'){
			dp[1][i]=2*dp[1][i-1]+dp[0][i-1];
		}else{
			dp[2][i]=2*dp[2][i-1]+dp[1][i-1];
		}
	}

	return dp[2][len];
}


// Tabulation+Space-Optimisation=>O(1) space
int count_req_subSeqn(string&str){
	int len=str.size();
	
    int prv_count_a=0,prv_count_b=0,prv_count_c=0;

	for(int i=0;i<len;++i){
		char ch=str[i];
        
        //rest ele should remain same as prv
        
        int new_count_a=prv_count_a;
        int new_count_b=prv_count_b;
        int new_count_c=prv_count_c;

		if(ch=='a'){
			new_count_a=2*prv_count_a + 1;
		}else if(ch=='b'){
			new_count_b=2*prv_count_b + prv_count_a;
		}else{
			new_count_c=2*prv_count_c + prv_count_b;
		}

        prv_count_a=new_count_a;
        prv_count_b=new_count_b;
        prv_count_c=new_count_c;
	}

	return prv_count_c;
}


int main(){
 //add the two lines below for fast i/o
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
      
	string str;
	cin>>str;

	cout<<count_req_subSeqn(str)<<"\n";

	return 0;
}