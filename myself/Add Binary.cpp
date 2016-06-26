class Solution2 {
public:
	string addBinary(string a, string b) {
		int asize=a.length(),bsize=b.length();
		int carry=0,he;
		int len=max(asize,bsize);
		int templen=len;
		string temp(len+1,'0');
		while(asize>0&&bsize>0){
			he=a[asize-1]-'0'+b[bsize-1]-'0'+carry;
			if(he>=2){
				carry=1;
				temp[len]=he%2+'0';
			}else{
				carry=0;
				temp[len]=he+'0';
			}
			len--;asize--;bsize--;
		}
		while(asize)
		{
			he=a[asize-1]-'0'+carry;
			if(he>=2){
				carry=1;
				temp[len]=he%2+'0';
			}else{
				carry=0;
				temp[len]=he+'0';
			}
			len--;asize--;
		}
		while(bsize)
		{
			he=b[bsize-1]-'0'+carry;
			if(he>=2){
				carry=1;
				temp[len]=he%2+'0';
			}else{
				carry=0;
				temp[len]=he+'0';
			}
			len--;bsize--;
		}
		if(carry==1){
			temp[0]='1';
			return temp;
		}else{
			string temp2(temp,1,templen);
			return temp2;
		}
	}
};


别人家代码
class Solution
{
public:
	string addBinary(string a, string b)
	{
		string s = "";

		int c = 0, i = a.size() - 1, j = b.size() - 1;
		while(i >= 0 || j >= 0 || c == 1)
		{
			c += i >= 0 ? a[i --] - '0' : 0;
			c += j >= 0 ? b[j --] - '0' : 0;
			s = char(c % 2 + '0') + s;
			c /= 2;
		}

		return s;
	}
};