my:
class Solution {
public:
	int strStr(string haystack, string needle) {
        if(needle.empty()){
			return 0;
		}
	    if(haystack.empty()){
	        return -1;
	    }
		int lneed=needle.length();
		int lhays=haystack.length();
		for(int i=0;i<=lhays-lneed;i++){
			if(haystack.substr(i,lneed)==needle){
				return i;
			}
		}
		return -1;
	}
};
lizi£º
class Solution2 {
public:
	int strStr(string haystack, string needle) {
		int i, j, lenh = haystack.length(), lenn = needle.length();
		if (lenn == 0)  return 0;
		for (i = 0; i <= lenh - lenn; i++) {
			for (j = 0; j < lenn; j++)
				if (haystack[i + j] != needle[j]) break;
			// Æ¥Åä³É¹¦
			if (j == lenn)  return i;
		}
		return -1;
	}
};