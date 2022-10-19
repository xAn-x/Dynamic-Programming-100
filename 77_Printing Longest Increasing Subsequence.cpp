// https://www.geeksforgeeks.org/construction-of-longest-increasing-subsequence-using-dynamic-programming/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
/*IDEA->
To print lis We will use tabulation Method->
	In dp[i] -> we will store what is the max_len lis till index i and also store the prv element of the sequence
*/
	vector<int> get_lis(vector<int>nums){
		int n=nums.size();
		// initialize whole dp with {1,-1} signifying the lis_len till here so far is 1 and there is no prv ele in the sequence
		vector<pair<int,int>>dp(n,{1,-1});

		int lis_end=-1,lis_len=0;
		for(int i=1;i<n;++i){
			for(int j=i-1;j>=0;--j){
				if(nums[i]>nums[j]){
					int len=1+dp[j].first;
					if(dp[i].first<len){
						dp[i].first=len; dp[i].second=j;
					}
				}
			}
			if(lis_len<dp[i].first){
				lis_len=dp[i].first; lis_end=i;
			}
		}


		vector<int>lis(lis_len);
		int idx=lis_len-1;

		while(idx>=0){
			lis[idx]=nums[lis_end];
			lis_end=dp[lis_end].second; --idx;
		}

		return lis;
	}
};

int main(){
	int n;
	cin>>n;

	vector<int>nums(n);
	for(int &e:nums) cin>>e;

	Solution obj;
	vector<int>lis=obj.get_lis(nums);

	for(int &e:lis) cout<<e<<" ";
}