class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n,vector<int>(n,0));
		int rowup=0,colunmleft=0;
		int rowdown=n-1,colunmright=n-1;
		int num=0;
		while(rowup<=rowdown&&colunmleft<=colunmright&&num<n*n){

			for(int i=colunmleft;i<=colunmright;i++){
				res[rowup][i]=++num;
			}
			rowup++;
			for(int i=rowup;i<=rowdown;i++){
				res[i][colunmright]=++num;
			}
			colunmright--;
			if(rowdown>=rowup){
				for(int i=colunmright;i>=colunmleft;i--){
					res[rowdown][i]=++num;
				}
				rowdown--;
			}
			if(colunmright>=colunmleft){
				for(int i=rowdown;i>=rowup;i--){
					res[i][colunmleft]=++num;
				}
				colunmleft++;
			}
		}
		return res;
	}
};