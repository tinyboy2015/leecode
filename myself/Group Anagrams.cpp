class hashIntarray{
public:
	int character[26];
	vector<int> vchars;
	hashIntarray(string str){
		memset(&character,0x00,sizeof(character));
		for(int i=0;i<str.size();i++){
			character[str[i]-'a']++;
		}
		for(int i=0;i<26;i++){
			vchars.push_back(character[i]);
		}
	}
};
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		map<vector<int>,vector<string>> maptemp;
		for(int i=0;i<strs.size();i++){
			hashIntarray a(strs[i]);
			maptemp[a.vchars].push_back(strs[i]);
		}
		map<vector<int>,vector<string>>::iterator it;
		for(it=maptemp.begin();it!=maptemp.end();++it){
			res.push_back(it->second);
		}
		return  res;
	}
};