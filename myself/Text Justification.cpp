vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> ans, vs;
    string str;

    int len = 0;
    for (int i = 0; i < words.size(); ++i) {
        if (len + vs.size() + words[i].size() <= L) {
            // vs not full, need to get more words in the line
            vs.push_back(words[i]);
            len += words[i].size();
        }
        else {
            // vs full, get the whole line
            if (vs.size() == 1) {
                // just one word, the left justify
                str = vs[0];
                str.append(L - str.size(), ' ');
                ans.push_back(str);
            }
            else if (vs.size() > 1) {
                // the first "mod" words get "div+1" spaces
                // the remaining words get "div" spaces
                int div = (L - len) / (vs.size() - 1);
                int mod = (L - len) % (vs.size() - 1);
                str = vs[0];
                for (int j = 1; j < vs.size(); ++j) {
                    if (j <= mod) str.append(div+1, ' '); // one more space
                    else str.append(div, ' ');
                    str += vs[j];
                }
                ans.push_back(str);
            }

            vs.clear();
            vs.push_back(words[i]);
            len = words[i].size();
        }
    }

    // the last line, left justified and no extra space is inserted between words
    str = vs[0];
    for (int j = 1; j < vs.size(); ++j) str += ' ' + vs[j];
    str.append(L-str.size(), ' ');
    ans.push_back(str);
    return ans;
}





my code :
class Solution {
public:
	string Justify(vector<string> &strtmp,int blanknum)
	{
		string justifystr;
		int slotnum=strtmp.size()-1;
		for(int i=0;i<blanknum;i++){
			strtmp[i%slotnum]+=" ";
			//cout<<"["<<strtmp[i%slotnum]<<"]";
		}
		for(int i=0;i<strtmp.size();i++){
			justifystr+=strtmp[i];
		}
		return justifystr;
	}
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> res;
		vector<string> strtmp;
		int lentmp=0;
		int count=0;
		for(int i=0;i<words.size();i++){
			if(words[i].length()>maxWidth){
				return res;
			}
		}
		for(int i=0;i<words.size();i++){
			lentmp+=words[i].length();
			if(lentmp+count>maxWidth){
				res.push_back(Justify(strtmp,maxWidth-lentmp+words[i].length()));
				strtmp.clear();
				lentmp=0;count=0;
				i--;
			}else{
				strtmp.push_back(words[i]); 
				count++;//as a extra " ";
			}
		}
		if(!strtmp.empty()){
			string str;
			for(int i=0;i<strtmp.size();i++){
				if(i!=strtmp.size()-1){
					str+=strtmp[i];
					str+=" ";
				}else{
					str+=strtmp[i];
				}
			}
			res.push_back(str);
		}
		return res;
	}
};