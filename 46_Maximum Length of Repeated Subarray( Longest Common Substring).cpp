// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
class Solution {
    //Brute->O(n^2*m^2*time for comparing vectors) time and O(n^2+m^2) space
    /*
    //Brute->O(n^2*m^2*max(n,m)) time and O(n^2+m^2) space
    vector<vector<int>>get_subarrays(vector<int>&nums){
        vector<vector<int>>sub_arrays;
        vector<int>sub_arr;
        int l=nums.size();

        for(int i=0;i<l;++i){
            for(int j=i;j<l;++j){
                sub_arr.push_back(nums[j]);
                sub_arrays.push_back(sub_arr);
            }
            sub_arr.clear();
        }
        return sub_arrays;
    }

    int helper(vector<int>&nums1,vector<int>&nums2){
        vector<vector<int>>sub_arr1,sub_arr2;
        sub_arr1=get_subarrays(nums1);
        sub_arr2=get_subarrays(nums2);

        int longest_len=0;
        for(vector<int>&sub1:sub_arr1){
            for(vector<int>&sub2:sub_arr2){
                if(sub1==sub2 and sub1.size()>longest_len) longest_len=sub1.size();
            }
        }
        return longest_len;
    }
    */

    //--------------------------------------------------------------------------------------------------------------------->

    // Note:- We don't need to find all subarrays at once what we can do is choose an ele in arr1 and then corres to that ele find longest common subarray in arr2

    //Optimisation over Brute->O(n*m*m) time and O(1) space
    int helper(vector<int>&nums1,vector<int>&nums2){
        if(nums1.size()<nums2.size()) return helper(nums2,nums1); //little optimisation

        int l1=nums1.size(),l2=nums2.size(),longest_len=0;

        for(int i=0;i<l1;++i){
            for(int j=0;j<l2;++j){
                if(nums1[i]==nums2[j]){
                    int len=0;
                    for(int k=j,l=0;k<l2;++k,++l){
                        if(nums1[i+l]!=nums2[k]) break;
                        ++len;
                    }
                    if(len>longest_len) longest_len=len;
                }
            }
        }

        return longest_len;
    }


public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // Brute->Find all subarrays of 1 and 2 and return onw with max len
        return helper(nums1,nums2);
    }
};