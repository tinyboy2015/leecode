my:
class Solution {
public:
	void generateStr(string outstring,int allLen,int leftLen,int rightLen,vector<string>&res)
	{
		if(allLen==0) res.push_back(outstring) ;
		if(allLen&&leftLen>rightLen) return;
		generateStr(outstring + "(" ,allLen-1,leftLen-1,rightLen,res);
		generateStr(outstring + ")" ,allLen-1,leftLen,rightLen-1,res);

	}

	vector<string> generateParenthesis(int n) {
		vector<string> res;
		generateStr("(",2*n-1,n-1,n,res);
		return res;
	}
};

fanli:

class Solution {
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        // Write your code here
        vector<string> res;
        string s;
        helper(s,res,0,0,n);
        return res;
    }
    void helper(string s,vector<string> &res,int l,int r,int n){
        if(r==n){
            res.push_back(s);
        }
        else if(l==n){
            s+=')';
            helper(s,res,l,r+1,n);
        }
        else{
            if(l>r)
                helper(s+')',res,l,r+1,n);
            helper(s+'(',res,l+1,r,n);
        }
    }
};

