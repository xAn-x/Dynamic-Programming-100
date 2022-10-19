// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/

// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/submissions/

/*  This is hard as  it is not visible to know why we want to use dp--> chk this test case:-
    [0,4,4,5,9]
    [0,1,6,8,10]
    +
    A dp parameter is hidden i.e weather u reach here by swaping previous element or
    not this should also be handelled--> as else all case's wouldn't be covered
*/
class Solution {
public:
    //Recursion-->
    int minMoves(vector<int>& nums1, vector<int>& nums2, int idx, int n) {
        if (idx == n) return 0;

        //If nums1[idx]>nums1[idx-1] and nums2[idx]>nums2[idx-1] in this case I have 2 choice swap or not
        if (nums1[idx] > nums1[idx - 1] and nums2[idx] > nums2[idx - 1]) {
            //But i can only swap if after swaping also the sequnce remain increasing
            int if_swap = 1e9;
            if (nums2[idx] > nums1[idx - 1] and nums1[idx] > nums2[idx - 1]) {
                swap(nums1[idx], nums2[idx]);
                if_swap = 1 + minMoves(nums1, nums2, idx + 1, n);
                swap(nums1[idx], nums2[idx]);
            }

            int if_didnt_swap = minMoves(nums1, nums2, idx + 1, n);

            return min(if_swap, if_didnt_swap);
        }
        //Else we have to swap
        else {
            swap(nums1[idx], nums2[idx]);
            int if_swap = 1 + minMoves(nums1, nums2, idx + 1, n);
            swap(nums1[idx], nums2[idx]);

            return if_swap;
        }
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //Let put -1 in front of both arrays
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        int n = nums1.size();

        return minMoves(nums1, nums2, 1, n);
    }



    //Memoization-->
    int minMoves(vector<int>& nums1, vector<int>& nums2, int idx, int n, bool swapped, vector<vector<int>>&dp) {
        if (idx == n) return 0;

        if (dp[idx][swapped] != -1) return dp[idx][swapped];

        //If nums1[idx]>nums1[idx-1] and nums2[idx]>nums2[idx-1] in this case I have 2 choice swap or not
        if (nums1[idx] > nums1[idx - 1] and nums2[idx] > nums2[idx - 1]) {
            //But i can only swap if after swaping also the sequnce remain increasing
            int if_swap = 1e9;
            if (nums2[idx] > nums1[idx - 1] and nums1[idx] > nums2[idx - 1]) {
                swap(nums1[idx], nums2[idx]);
                if_swap = 1 + minMoves(nums1, nums2, idx + 1, n, true, dp);
                swap(nums1[idx], nums2[idx]);
            }

            int if_didnt_swap = minMoves(nums1, nums2, idx + 1, n, false, dp);

            return dp[idx][swapped] = min(if_swap, if_didnt_swap);
        }
        //Else we have to swap
        else {
            swap(nums1[idx], nums2[idx]);
            int if_swap = 1 + minMoves(nums1, nums2, idx + 1, n, true, dp);
            swap(nums1[idx], nums2[idx]);

            return dp[idx][swapped] = if_swap;
        }
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //Let put -1 in front of both arrays
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        int n = nums1.size();
        bool swapped = false;

        vector<vector<int>>dp(n, vector<int>(2, -1));
        return minMoves(nums1, nums2, 1, n, swapped, dp);
    }
};