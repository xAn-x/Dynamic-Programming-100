/*	Problem-->
		You have given a no. X and u can perfor 3 steps-->
			*Divide by 2 if divisible by 2 
			*Divide by 3 if divisible by 3 
			*Sub 1 from X

		your tak is to find minimum no of steps req to reduce X to 1.

		Eg: X=7-->(-1)-->6(/3)-->3(/3)-->1  ==> ans - 3. 


Wrong approach-->first try divide by 3 if possible as cause max reduction then by 2 followed by 1 but try for test case X=10.

This approach-->
	X=10-->(/2)-->5(-1)-->4(/2)-->2(/2)-->1  ==> ans - 4

But Ans Is 3->
	X=10-->(-1)-->9(/3)-->3(/3)-->1 ==> ans - 3

*/

#include <bits/stdc++.h>
using namespace std;

/*Method-1-->Plain Recursion=>

long reduceTo1(int num){
	
	if(num==0) return INT_MAX;
	else if(num==1) return 0;
	else if(num==2 or num==3) return 1;

	long if_divBy_3=(num%3==0)?1+reduceTo1(num/3):INT_MAX;
	long if_divBy_2=(num%2==0)?1+reduceTo1(num/2):INT_MAX;
	long if_sub1=1+reduceTo1(num-1);

	return min(if_sub1,min(if_divBy_2,if_divBy_3));}

*/

//Method-2-->Tabulation=>Time Complexity->O(num) and Space Complexity->O(num)

long reduceTo1(int num){
	int dp[num+1]={0};

//Meaning -> dp[n]=min steps req to reduce n to 1

//Base Case=>
	dp[0]=INT_MAX;dp[1]=0;dp[2]=dp[3]=1;

//Filling rest dp=>
	for(int idx=4;idx<=num;idx++){
		long if_divBy_3=(idx%3==0)?1+dp[idx/3]:INT_MAX;
		long if_divBy_2=(idx%2==0)?1+dp[idx/2]:INT_MAX;
		long if_sub1=1+dp[idx-1];

		dp[idx]=min(if_sub1,min(if_divBy_2,if_divBy_3));
	}

	return dp[num];
}

void runTime();

int main() {

//add the two lines below for fast i/o
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	//For getting input from input.txt
	freopen("input.txt", "r", stdin);
	//For getting errors in error.txt
	freopen("error.txt","w",stderr);
	//For getting output to output.txt
	freopen("output.txt", "w", stdout);
#endif
    
    int num;
    scanf("%d",&num);

    int minStepsReq=reduceTo1(num);
    printf("Minimum steps req: %ld\n",minStepsReq);
  	
  
  	runTime();

	return 0;
}

void runTime(){
	//cerr produce output in error.txt --> No need to remove
  cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}

