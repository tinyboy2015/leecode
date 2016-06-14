其实这是树的典型深度优先遍历的一个例子，下和右的运动可看成左子树和右子树的变形，求多少个，可以看成求叶子节点的个数，刚开始比较晕老想用什么递归套，后来终于想通了。我自己的代码如下，超时了。但结果是正确的。
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

而下面的思路也很好，某个节点的步骤个数由上的个数和左的个数之和决定，而上侧和左侧都是死值1，这样累加起来也很好写。而且又用到了小技巧vector二维数组的初始化。
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
进一步优化，只需两行。就可
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
进一步优化
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