class Solution:
	def longestPalindrome(self,s:str) -> str:
		size=len(s)
		res_st,res_end,max_len=-1,-1,0

		for i in range(size):
			# Odd Len Pallindrome Substring
			l,r=i,i
			while l>=0 and r<size and s[l]==s[r]:
				if(r-l+1>max_len):
					res_st,res_end=l,r
					max_len=r-l+1
				l-=1
				r+=1

			# Even Len Pallindrome Substring
			l,r=i,i+1
			while l>=0 and r<size and s[l]==s[r]:
				if(r-l+1>max_len):
					res_st,res_end=l,r
					max_len=r-l+1
				l-=1	
				r+=1

		ans=s[res_st:res_end+1]
		return ans