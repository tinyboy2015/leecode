��ʵ�������ĵ���������ȱ�����һ�����ӣ��º��ҵ��˶��ɿ������������������ı��Σ�����ٸ������Կ�����Ҷ�ӽڵ�ĸ������տ�ʼ�Ƚ���������ʲô�ݹ��ף�����������ͨ�ˡ����Լ��Ĵ������£���ʱ�ˡ����������ȷ�ġ�
class Solution {
public:
	int uniquePaths(int m, int n) {
		int count1=0,count2=0;
		if(m==1&&n==1) return 1;
		if(m!=1) count1=uniquePaths(m-1,n);
		if(n!=1) count2=uniquePaths(m,n-1);
		return count1+count2;
	}
};

�������˼·Ҳ�ܺã�ĳ���ڵ�Ĳ���������ϵĸ�������ĸ���֮�;��������ϲ����඼����ֵ1�������ۼ�����Ҳ�ܺ�д���������õ���С����vector��ά����ĳ�ʼ����
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > path(m, vector<int> (n, 1));
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                path[i][j] = path[i - 1][j] + path[i][j - 1];
        return path[m - 1][n - 1];
    }
};
��һ���Ż���ֻ�����С��Ϳ�
class Solution {
    int uniquePaths(int m, int n) {
        if (m > n) return uniquePaths(n, m); 
        vector<int> pre(m, 1);
        vector<int> cur(m, 1);
        for (int j = 1; j < n; j++) {
            for (int i = 1; i < m; i++)
                cur[i] = cur[i - 1] + pre[i];
            swap(pre, cur);
        }
        return pre[m - 1];
    }
};
��һ���Ż�
class Solution {
    int uniquePaths(int m, int n) {
        if (m > n) return uniquePaths(n, m);
        vector<int> cur(m, 1);
        for (int j = 1; j < n; j++)
            for (int i = 1; i < m; i++)
                cur[i] += cur[i - 1]; 
        return cur[m - 1];
    }
}; 