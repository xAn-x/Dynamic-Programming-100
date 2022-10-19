"""
Basic Idea is ->take count of day on ehich u r training + the task u perfom yesterday as u can't perfom same task 2 days consecutively
"""

from typing import *

# explanation->https://www.youtube.com/watch?v=AE39gJYuRog&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=8


# Dp->Tabulation
"""
def ninjaTraining(n: int, points: List[List[int]]) -> int:
    # Creating a grid to store what max points I can achive till ith day by performing jth task

    rows,cols=len(points),3
    score=[ [] for i in range(rows)]

    # On day 0->
    for i in range(cols):
        score[0].append(points[0][i])
    
    for i in range(1,rows):
        # This is new_score to store max points I can get if I perform some task
        new_score=[0 for i in range(cols)]
        
        for tsk in range(cols):
           max_points=-1 
           for j in range(cols):
                # if j==tsk i can't use these points as i am performing same task on 
               if(j==tsk):
                   continue
               max_points=max(max_points,score[i-1][j])

           # point i get= point to prfm tsk + max_points from prv_day
           new_score[tsk]=points[i][tsk]+max_points
        
        # update max_points score for new day    
        score[i]=new_score    

    #return max among all task at end    
    return max(score[n-1])
"""




# Dp->Tabulation+space-Optimisation->O(n) space and O(1) space
def ninjaTraining(n: int, points: List[List[int]]) -> int:
    # Creating an score to store what max points i can get if i perform ith tsk till now
    score=[points[0][i] for i in range(3)]
    rows,cols=len(points),3

    for i in range(1,rows):
        # This is new_score to store max points I can get if i perform some task
        new_score=[0 for i in range(cols)]
        for tsk in range(cols):
           max_points=-1 
           for j in range(cols):
                # if j==tsk i can't use these points as i am performing same task on 
               if(j==tsk):
                   continue
               max_points=max(max_points,score[j])

           # point i get= point to prfm tsk + max_points from prv_day
           new_score[tsk]=points[i][tsk]+max_points
        
        # update max_points score for new day    
        score=new_score    

    #return max among all task at end    
    return max(score)