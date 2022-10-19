//problem link-->

#include <bits/stdc++.h>
using namespace std;

void runTime();


/*Method-1-->Time Complexity=>O(2^n) and Space Complexity=>O(n)
int countEncodings(string &str){
	int len=str.length();

	if(len==0 or len==1) return 1;
	
	int no_of_encodings=0;

	//When we take out 1 char 
	char ch=str[0];

	//If 1st char is itself is 0 then it is Invalid String so return 0-->
	if(ch=='0') return 0;

	str=str.substr(1);
	no_of_encodings+=countEncodings(str);

	//BackTrack to Original-->
	str=ch+str;


	//If We Decide to take !st 2 char-->
	if(len>=2){
		string twoChar=str.substr(0,2);


		//We can only Encode if its numeric value is <= 26 only-->
		if(stoi(twoChar)<=26){

			str=str.substr(2);
			no_of_encodings+=countEncodings(str);
		
			//BackTrack to Original-->
			str=twoChar+str;
		}

	}

	return no_of_encodings;}
*/



//Method-2=>Tabulation-->
int countEncodings(string &str){
//If 1st char is itself 0-->
	if(str[0]=='0') return 0;

	int len=str.length();

	vector<int>dp(len);

	//Meaning ->dp[i] contain no of encoding posiible if we process char till index i-->



	return dp[len-1];
}

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
	//For getting output in output.txt
	freopen("output.txt", "w", stdout);
#endif
    
  	string str;
  	cin >> str;

  	int no_of_encodings=countEncodings(str);
  	printf("no_of_encodings:%d\n",no_of_encodings);
  
  	runTime();

	return 0;
}

void runTime(){
	//cerr produce output in error.txt --> No need to remove
  cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
}

