# https://practice.geeksforgeeks.org/problems/ways-to-tile-a-floor5836/1/
class Solution:
#Recursion -> 
    def __tile_floor(self,N):
        if(N==0 or N==1):
            return N
        return self.__tile_floor(N-1)+self.__tile_floor(N-2) #->Fibonacci-recurrence

    def numberOfWays(self, N):
    #Recursion->        
        # return self.__tile_floor(N) 
    

    #Tabulation->
        if(N==1 or N==0):
            return N
        
        prv,curr=1,2
        mod=int(1e9+7)

        for i in range(3,N+1):
            new=(prv+curr)%mod
            prv=curr 
            curr=new  
        return curr   