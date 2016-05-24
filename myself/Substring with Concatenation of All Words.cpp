class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> freq;
        for(auto w: words){
            freq[w]++;
        }        

        int n = s.size(), total = words.size(), len = words[0].size(); 
        vector<int> answer;

        for(int i = 0; i < n - total * len + 1; i++){
            int j = i;
            unordered_map<string, int> stats = freq;
            int covered = 0;
            while(covered < total && j + len - 1 < n) {
                string word = s.substr(j, len);
                if(stats.find(word) != stats.end() && --stats[word] >= 0) {
                    covered++;
                    j += len;
                }else break;
            }
            if(covered == total) answer.push_back(i);
        }

        return answer;
    }
};