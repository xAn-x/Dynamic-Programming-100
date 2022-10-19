# https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1/
class Solution:
	def __pairFriends(self,n):
		if(n==1 or n==2):
			return n
		#This is fibonacci recurence with slights change-> 
		go_alone,pair_up=self.__pairFriends(n-1),(n-1)*self.__pairFriends(n-2)
		return go_alone+pair_up

    def countFriendsPairings(self, n):
    #Recurssive-Way->	
        # return self.__pairFriends(n)

    #Tabulation+Space-Optimisation->
    	if(n==1 or n==2):
    		return n
    		
    	prv,curr=1,2
    	for i in range(3,n+1):
    		new=curr+prv*(i-1)
    		prv=curr
    		curr=new
    	return curr
