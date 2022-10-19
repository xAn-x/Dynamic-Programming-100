// https://www.youtube.com/watch?v=on2hvxBXJH4&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=44
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	int longest_increasing_subsequence(vector<int>nums){
		vector<int>vec;
		vec.push_back(nums[0]);
		int s=1;
		
		for(int i=1;i<nums.size();++i){
			if(vec[s-1]<nums[i]){
				vec.push_back(nums[i]);
				++s;
			}else{
				auto it=lower_bound(vec.begin(),vec.end(),nums[i]);
				*it=nums[i];
			}
		}

		return s;
	}
};

int main(){
	int n;cin>>n;
	vector<int>nums(n);
	for(int &e:nums) cin>>e;

	Solution obj;
	cout<<obj.longest_increasing_subsequence(nums)<<"\n";
}