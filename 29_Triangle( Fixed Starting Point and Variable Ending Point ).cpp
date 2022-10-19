//https://leetcode.com/problems/triangle/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Method-1=>Normal-recursion->O(2^(r*c))
    /*
    int helper(vector<vector<int>>&triangle,int r,int c){
        if(r==triangle.size()) return 0;
        else if(c==triangle[c].size()) return INT_MAX;

        return triangle[r][c]+min(helper(triangle,r+1,c),helper(triangle,r+1,c+1));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        return helper(triangle,0,0);
    }
    */

// ----------------------------------------------------------------------------------
    
    //Method-2=>Memoization=>
    /*
    int helper(vector<vector<int>>&triangle,int r,int c,vector<vector<int>>&cost){
        if(r==triangle.size()) return 0;
        else if(c==triangle[c].size()) return INT_MAX;
    
        if(cost[r][c]!=INT_MAX) return cost[r][c];
        return cost[r][c]=triangle[r][c]+min(helper(triangle,r+1,c,cost),helper(triangle,r+1,c+1,cost));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>cost;
        
        for(int i=0;i<n;++i){
            cost[i].push_back(vector<int>(i+1,INT_MAX));
        }
        return helper(triangle,0,0,cost);
    }
    */

// ----------------------------------------------------------------------------------

    //Method-3=>Tabultion=>
    /*
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();        
        vector<vector<int>>cost;

        for(int i=0;i<n;++i){
            cost.push_back(vector<int>(i+1,INT_MAX));
        }        
        
        cost[0][0]=triangle[0][0];

        for(int r=1;r<n;++r){
            for(int c=0;c<r+1;++c){
                int from_direct_up=INT_MAX;
                if(c<r) from_direct_up=cost[r-1][c];

                int from_upper_left=INT_MAX;
                if(c>0) from_upper_left=cost[r-1][c-1];
                
                cost[r][c]=triangle[r][c]+min(from_upper_left,from_direct_up); 
            }
        }
        
        int ans=INT_MAX;
        for(int i=0;i<n;++i){
            ans=min(ans,cost[n-1][i]);
        }
        return ans;
    }
    */

// ----------------------------------------------------------------------------------
    // Method-4->Tabulation+Space-Optimisation
    int minimumTotal(vector<vector<int>>& triangle) {
        //We don't need all rows just prv
        int n=triangle.size();

        vector<int>prv_cost(1);
        prv_cost[0]=triangle[0][0];

        for(int r=1;r<n;++r){
            vector<int>curr_cost(r+1);
            for(int c=0;c<r+1;++c){
                int from_direct_up=INT_MAX;
                if(c<r) from_direct_up=prv_cost[c];

                int from_upper_left=INT_MAX;
                if(c>0){
                    from_upper_left=prv_cost[c-1];
                }
                curr_cost[c]=triangle[r][c]+min(from_upper_left,from_direct_up); 
            }
            prv_cost=curr_cost;
        }    

        //since goal is to reach last row and not any particular cell We need to pick cell with min cost
        int ans=INT_MAX;
        for(int i=0;i<n;++i){
            ans=min(ans,prv_cost[i]);
        }
        return ans;
    }
};

int main(){
    int n;
    cin>>n;

    vector<vector<int>>triangle(n);
    for(int i=0;i<n;++i){
        vector<int>row(i+1);
        for(int &ele:row) cin>>ele;
        triangle[i]=row;
    }

    Solution obj;
    cout<<obj.minimumTotal(triangle)<<'\n';
}