# https://leetcode.com/problems/house-robber-ii/
class Solution:
    def rob(self, nums: List[int]) -> int:
        # Either I can loot starting house or can loot last house can't loot both        
        def helper(nums:List[int],st,end):
        	if(st==end) :
        		return nums[st]
        	if(end-st==1):
        		return max(nums[st],nums[end])
        	
        	arr=[nums[st],max(nums[st],nums[st+1])]
            
        	for i in range(st+2,end+1):
        		ans=max(nums[i]+arr[0],arr[1])
        		arr[0]=arr[1]
        		arr[1]=ans

        	return arr[1]


        l=len(nums)        
        if(l==1):
            return nums[0]
        
        start=helper(nums,0,l-2)
        end=helper(nums,1,l-1)
        return max(start,end) 