/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(Interval a,Interval b)
{
  return a.start<b.start; //升序排列，如果改为return a>b，则为降序
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
    	vector<Interval> res;
    	if(intervals.empty()) return res;
        sort(intervals.begin(),intervals.end(),compare);
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
        	int rstart=res[res.size()-1].start;
        	int rend=res[res.size()-1].end;
        	if(rend>=intervals[i].start){
        		res[res.size()-1]=Interval(min(rstart,intervals[i].start),max(rend,intervals[i].end));
        	}
        	else{
        		res.push_back(intervals[i]);
        	}
        }
        return res;
    }
    	
};
