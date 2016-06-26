class Solution {
public:
    string simplifyPath(string path) {
        string res="/";
        string tmpstr;
        path+='/';
        for(int i=1;i<path.size();i++){
            if(path[i]=='/'){
                if(tmpstr==""||tmpstr==".") tmpstr="";
                else if(tmpstr==".."){
                    res=res.substr(0,res.find_last_of('/'));
                    res=res.length()>0?res:"/";
                }
                else{
                    res.length()>1?(res+='/'+tmpstr):(res+=tmpstr);
                }
                tmpstr="";
            }else{
                tmpstr+=path[i];
            }
        }
        return  res.length()>0?res:"/";
    }
};