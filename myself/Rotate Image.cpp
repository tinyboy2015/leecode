my:
struct coordinate{
	int x;
	int y;
	coordinate(int a,int b):x(a),y(b){};
};

class Solution {
public:
	void printMartrix(vector<vector<int>>& matrix)
	{
		cout<<"========="<<endl;
		for(int i=0;i<matrix.size();i++){
			for(int j=0;j<matrix.size();j++){
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	void rotateOneCircle(vector<vector<int>>& matrix,coordinate upleft,coordinate upright,coordinate downleft, coordinate downright,int len)
	{
		int *temp=new int[len];
		for(int i=0;i<len;i++)
		{
			//save upright
			temp[i]=matrix[upright.x+i][upright.y];
			//upleft--upright
			matrix[upright.x+i][upright.y]=matrix[upleft.x][upleft.y+i];
			printMartrix(matrix);
			//downleft--upleft
			matrix[upleft.x][upleft.y+i]=matrix[downleft.x-i][downleft.y];
			printMartrix(matrix);
			//downright--downleft
			matrix[downleft.x-i][downleft.y]=matrix[downright.x][downright.y-i];
			printMartrix(matrix);
			//upright--downright
			matrix[downright.x][downright.y-i]=temp[i];
			printMartrix(matrix);
		}
		delete temp;

	}
	
	void rotate(vector<vector<int>>& matrix) {
		int row=matrix.size();
		int column=matrix[0].size();
		//i,j分别表示最小和最大边界值。初始为0和matrix.size()-1;
		int i=0,j=matrix.size()-1;
		for(i=0,j=row-1;i<=row/2&&i<j;i++,j--)
		{
			 coordinate upleft=coordinate(i,i);
			 coordinate upright=coordinate(i,j);
			 coordinate downleft=coordinate(j,i);
			 coordinate downright=coordinate(j,j);
			 rotateOneCircle(matrix,upleft,upright,downleft,downright,i+j);
		}
	}
};

standard:
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(),matrix.end());
        for(int i=0;i<matrix.size();++i){
            for(int j=i+1;j<matrix[i].size();++j){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};