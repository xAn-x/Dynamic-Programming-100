// https://leetcode.com/problems/longest-common-subsequence/
class Solution {
	//Method-1=>Find all subsequence of str1 and str2 and then return one which is common in both and has longest length

	//Time-Complexity-> O(2^n * 2^m)
	/*
	void find_subSeq(string&str,int len,int idx,string&subseq,vector<string>&subseq_list){
		if(idx==len){
			subseq_list.push_back(subseq);
			return;
		}

		find_subSeq(str,len,idx+1,subseq,subseq_list);
		
		subseq.push_back(str[idx]);
		find_subSeq(str,len,idx+1,subseq,subseq_list);;
		subseq.pop_back();
	}

	int lcs(string&txt1,string&txt2){
		vector<string>txt1_lst,txt2_lst;
		string subSeq="";

		find_subSeq(txt1,txt1.size(),0,subSeq,txt1_lst);
		find_subSeq(txt2,txt2.size(),0,subSeq,txt2_lst);

		int lcs_len=0;
		for(string &sub1:txt1_lst){
			for(string &sub2:txt2_lst){
				if(sub1==sub2 and lcs_len<sub1.size()){
					lcs_len=sub1.size();
				}
			}
		}
		return lcs_len;
	}
	*/


// -------------------------------------------------------------------------------------------------------------------------

	int lcs(string&txt1,int l1,string&txt2,int l2,string&s1,string&s2){
		if(l1==0 or l2==0){
            if(s1==s2) { return s1.size();}
            else return 0;
            
        }
		// else if(l1==0 or l2==0) return 0;
		
		//decide to choose char
		s1.push_back(txt1[l1-1]);
		int len1=lcs(txt1,l1-1,txt2,l2,s1,s2); 
		
		s2.push_back(txt2[l2-1]);
		int len2=lcs(txt1,l1-1,txt2,l2-1,s1,s2); 
		
		s1.pop_back();
        //here decrease both as i have decide for txt1 above only
		int len3=lcs(txt1,l1-1,txt2,l2-1,s1,s2); 

		s2.pop_back();
		int len4=lcs(txt1,l1-1,txt2,l2-1,s1,s2); 
        
        return max({len1,len2,len3,len4});
	}




public:

    int longestCommonSubsequence(string text1, string text2) {
        // Brute->
        return lcs(text1,text2);
    }
};