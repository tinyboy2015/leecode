class Solution {
public:
	int lengthOfLastWord(string s) {
		int len=s.size(),count=0;
		int enterflag=0;
		for(int i=len-1;i>=0;i--){
			if(s[i]!=' '){
				enterflag=1;
				count++;
			}
			else if(s[i]==' '&&enterflag==1){
				break;
			}
		}
		return count;
	}
};