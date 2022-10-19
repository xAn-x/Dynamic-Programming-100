# link-> https://nados.io/question/arrange-buildings?zen=true

# Time & Space Complexity->O(n)
def count_ways(n) :
	# If I decide to build a building on aplot then adj plot should contain space for sure but if we plan to leave that plot we can either build building in the next plot or leace that also
	
	lst_building,lst_space=1,1
	for i in range(1,n):
		curr_building=lst_space
		curr_space=lst_space+lst_building

		lst_space=curr_space
		lst_building=curr_building

	ways_on_oneSide=lst_space+lst_building
	totalWays=ways_on_oneSide**2

	return totalWays

n=int(input())
print(count_ways(n))	