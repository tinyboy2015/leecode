class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int maxLength=0;
		int tempLength=0;
		string strTmp;
		unsigned int j;
		char tmp[1];
		for(unsigned int i=0;i<s.length();i++)
		{
			strTmp.empty();
			tempLength=0;
			for(j=i;j<s.length();j++)
			{
				if(strTmp.find(s[j])!=-1)//说明找到了相同的字符
				{
					if(tempLength>maxLength)
						maxLength=tempLength;
					break;
				}
				tempLength++;
				tmp[1]=s[j];
				strTmp.append(tmp);//
			}
			if(j==s.length())
			{
				if(tempLength>maxLength)
					maxLength=tempLength;
			}
		}
		return maxLength;
	}
};