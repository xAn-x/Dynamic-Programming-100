// https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?


//explanation->https://www.youtube.com/watch?v=GS_OqZb2CWc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=17

// explanation-2-> https://www.youtube.com/watch?v=-GtpxG6l_Mc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=10
/*                                  ----IDEA----
    Note in subset with given sum dp[i][j] represent can we make sum j using first i elements of array.

    Now if so,the last row will contain true value against all sum possible till 
    s(if given sum is s)

    Now we can say that since all no in arr are>0 here our sum will lie in range
    [0-totalSum]({} , {-,--,all}) so do that and then in last row if prv[s] is true then It is sure totSum-s will also be so find one that yeilds min sum
*/

int minSubsetSumDifference(vector<int>& nums, int n){
    // Write your code here.
    int totSum=0;
    for(int i=0;i<n;++i) totSum+=nums[i];

    vector<bool>prv(totSum/2 + 1);
    vector<bool>curr(totSum/2+1);
    prv[0]=curr[0]=true;

    for(int i=1;i<=n;++i){
        for(int s=0;s<=(totSum/2);++s){
            if(nums[i-1]>s) curr[s]=prv[s];
            else curr[s]=(prv[s] or prv[s-nums[i-1]]);
        }
        prv=curr;
    }

    //Now traverse in prv ato find min diff->
    int minDiff=1e9;
    for(int s=0;s<=(totSum/2);++s){
        if(prv[s]){
            minDiff=min(abs((totSum-s)-s),minDiff);
        }
    }
    return minDiff;
}
