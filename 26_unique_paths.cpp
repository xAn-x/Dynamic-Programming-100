// link-> https://leetcode.com/problems/unique-paths/

/*Method-1 -> D.P = Tabulation->Time and space => O(m*n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>paths(m,vector<int>(n,1));

        for(int r=m-2;r>=0;r--){
            for(int c=n-2;c>=0;c--){
                paths[r][c]=paths[r][c+1]+paths[r+1][c];
            }
        }

        return paths[0][0];
    }
};
*/



//Method-2=>Dp->Tabulation+Space-Optimisation->Time ->O(m*n) + Space ->O(n)
/*
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prv_row(n,1);
        for(int r=m-2;r>=0;r--){
            vector<int> curr_row(n,-1);
            for(int c=n-1;c>=0;c--){
                int down=prv_row[c];
                int right = (c==n-1) ? 0 : curr_row[c+1]; //if nothing on left then 0 else calculated value
                curr_row[c]=down+right;   
            }
            prv_row=curr_row;
        }
        return prv_row[0];
    }
};
*/



//Method-3 => Using Combinatorics => Time O(rows) or O(cols) and space ->O(1)
class Solution {
public:
    /*                                  ---Algo---
        Note ->We can observe that if i am on a cell->then 
            no of right Moves + no of down moves = (m-1) + (n-1)
            
            Now we have total of -> m+n-2 choices and if i can choose either (n-1) choices or (m-1) choices then rest will contain the other dirn moves only
    
            so ans-> (n+m-2)-C-(n-1) moves
    */

    int uniquePaths(int m, int n) {
        int N=n+m-2,r=m-1;
        int val=1;
        for(int i=1;i<r;++i){
            val=val*(n-r+i)/i;
        }

        return val;
    }
};
