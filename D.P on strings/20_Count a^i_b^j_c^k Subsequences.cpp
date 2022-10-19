#include<iostream>
#include<unordered_map>
using namespace std;

// Brute->find all subsequence and then traverse in them and count all which follow req condn
// time complexity=>O(2^n * (len_of_subSeq)*3 )
/*
int countSubsets(string&str,int len,int idx,string&subSeq){
	if(idx==len){
		int i=0,l=subSeq.size();
		for(char ch='a';ch<='c';++ch){
			if(i==l) return 0;
			int cnt=0;
			while(i<l){
				if(subSeq[i]!=ch) break;
				++cnt;
				++i; 
			}
			if(cnt==0) return 0;
		}
		return (i==l)?1:0;
	}
	
	int totWays=0;
	totWays+=countSubsets(str,len,idx+1,subSeq);
	subSeq.push_back(str[idx]);
	totWays+=countSubsets(str,len,idx+1,subSeq);
	subSeq.pop_back();

	return totWays;
}
*/

int countSubsets(string&str,int len,int idx,string&subSeq,unordered_map<string,int>&dp){
	if(idx==len){
		int i=0,l=subSeq.size();
		for(char ch='a';ch<='c';++ch){
			if(i==l) return 0;
			int cnt=0;
			while(i<l){
				if(subSeq[i]!=ch) break;
				++cnt;
				++i; 
			}
			if(cnt==0) return 0;
		}
		return (i==l)?1:0;
	}

	string req_string=subSeq+"-"+to_string(idx);
	if(dp.count(req_string)){
		// cout<<"Bhai iska hai: "<<req_string<<endl;
		return dp[req_string];
	}
	
	int totWays=0;
	totWays+=countSubsets(str,len,idx+1,subSeq,dp);
	subSeq.push_back(str[idx]);
	totWays+=countSubsets(str,len,idx+1,subSeq,dp);
	subSeq.pop_back();

	return dp[req_string]=totWays;
}

int count_req_subSeqn(string&str){
	int len=str.size();
	string subSeq;

	//Recursion->
	// return countSubsets(str,len,0,subSeq);

	//Memoization->
	// Note to store state store both subSeqn+idx for which we are deciding-> 
	
	//very Minute-Optimisation->
	unordered_map<string,int>dp(len+1);
	return countSubsets(str,len,0,subSeq,dp);
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