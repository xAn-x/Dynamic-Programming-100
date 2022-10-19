class Solution {
public:
//  Recursion   
    int get_maxside_sqr(vector<vector<char>>&matrix,int r,int c,int &max_side){
        if(r>=matrix.size() or c>=matrix[0].size() or r<0 or c<0) return 0;
        
        int right=get_maxside_sqr(matrix,r,c+1,max_side);
        int down=get_maxside_sqr(matrix,r+1,c,max_side);
        int diag=get_maxside_sqr(matrix,r+1,c+1,max_side);
        
        if(matrix[r][c]=='1'){
            int side=1+min({right,down,diag});
            max_side=max(max_side,side);
            return side;
        }else return 0;
        
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int max_side=0;
        get_maxside_sqr(matrix,0,0,max_side);
        return max_side*max_side;
    }


// Memoization
    int get_maxside_sqr(vector<vector<char>>&matrix,int r,int c,int &max_side,vector<vector<int>>&dp){
        if(r>=matrix.size() or c>=matrix[0].size() or r<0 or c<0) return 0;
        
        if(dp[r][c]!=-1) return dp[r][c];
        
        int right=get_maxside_sqr(matrix,r,c+1,max_side,dp);
        int down=get_maxside_sqr(matrix,r+1,c,max_side,dp);
        int diag=get_maxside_sqr(matrix,r+1,c+1,max_side,dp);
        
        if(matrix[r][c]=='1'){
            int side=1+min({right,down,diag});
            max_side=max(max_side,side);
            return dp[r][c]=side;
        }else return dp[r][c]=0;
        
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int max_side=0,n=matrix.size(),m=matrix[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        get_maxside_sqr(matrix,0,0,max_side,dp);
        
        return max_side*max_side;
    }


//  Tabulation
    int maximalSquare(vector<vector<char>>& matrix) {
        int max_side=0,n=matrix.size(),m=matrix[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        for(int r=n-1;r>=0;--r){
            for(int c=m-1;c>=0;--c){
                int right=(c+1<m)?dp[r][c+1]:0;
                int down=(r+1<n)?dp[r+1][c]:0;
                int diag=(c+1<m and r+1<n)?dp[r+1][c+1]:0;
                
                if(matrix[r][c]=='1'){
                    int side=1+min({right,down,diag});
                    max_side=max(max_side,side);
                    dp[r][c]=side;
                }else dp[r][c]=0;
            }
        }
        
        return max_side*max_side;
    }

};