// https://leetcode.com/problems/largest-divisible-subset/
class Solution {
public:
    /* ---IDEA---
        Sort the array and find the longest inc subset ending at each index
        
        How sorting help-->
            If a<b<c<d<e... and i have to check weather 
            b%a==0 and c%b==0 and c%a==0---> I can check it in O(1) for any n>=2

            if b%a==0 => b=m*a
            if c%b==0 => c=n*b  => c=n*m*a {==> c%a==0}
            ...so on
    */
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        //Idea is to store the index of last largest subset for which largest div subset end at index i
        int n=nums.size();
        
        //vector<max_size,last_ele_index>
        vector<pair<int,int>>dp(n,{1,-1});
        int max_subset_size=1,ending=0;

        for(int i=1;i<n;++i){
            for(int j=i-1;j>=0;--j){
                if(nums[i]%nums[j]==0 and dp[i].first<1+dp[j].first){
                        dp[i].first=1+dp[j].first;
                        dp[i].second=j;
                }
            }
            if(dp[i].first>max_subset_size){
                max_subset_size=dp[i].first;
                ending=i;
            }
        }

        vector<int>ans;
        while(ending!=-1){
            int ele=nums[ending];
            ans.push_back(ele);

            // cout<<ending<<"-> ";
            ending=dp[ending].second;            
        }

        return ans;

    }
};