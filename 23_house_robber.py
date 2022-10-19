# https://leetcode.com/problems/house-robber/
class Solution(object):
# Dp ->Tabulation + space Optimisation
    def rob(self, nums):
            """
            :type nums: List[int]
            :rtype: int
            """

            n=len(nums)  
            # If only 1 house loot it
            if n==1:
                return nums[0]
                # If 2 then loot one with max loot
            elif n==2:
                return max(nums[0],nums[1])
            
            arr=[nums[0],max(nums[0],nums[1])]
            ans=arr[1]
            
            for i in range(2,n):
                ans=max(nums[i]+arr[0],arr[1])
                arr[0]=arr[1]
                arr[1]=ans
            
            return arr[1]