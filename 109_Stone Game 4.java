// https://leetcode.com/problems/stone-game-iv/
class Solution {
    public boolean winnerSquareGame(int n) {
        Boolean memo[][] = new Boolean[n+1][2];
        return solve(n, 0, memo);
    }
    
    boolean solve(int n, int turn, Boolean memo[][]) {
        if(n == 0)
            return false;
        
        if(memo[n][turn] != null)
            return memo[n][turn];
        
        boolean canWin = false;
        for(int i = 1; i*i<=n;i++) {
            if(!solve(n-(i*i), 1 - turn, memo)) {
                canWin = true;
                break;
            }
        }
        
        memo[n][turn] = canWin;
        return memo[n][turn];
    }
}