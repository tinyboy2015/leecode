/**
 * �������ɾ����㷨�༭�ṩ��û�а�Ȩ��ӭת����
 * - �����㷨�����ڰ��������й����ҵ��õĹ�������ʦ�ŶӾ����Թ�Ⱥ͹��ڵ�һ�ߴ�˾��ְ����ʦ��
 * - ���е�������ѵ�γ̰����������㷨�࣬ϵͳ��ư࣬BAT���ڰ�
 * - ������������ٷ���վ��http://www.jiuzhang.com/
 */

class Solution {
public:
    /*
    ����һ������Ϊn������������a����nΪ��������λ��Ϊa[n / 2 + 1] , 
    ��nΪż��������λ��(a[n / 2] + a[n / 2 + 1]) / 2
    ������ǿ��������������������KС��Ԫ�أ�����Խ��������
    ����������AԪ�ظ���Ϊn������BԪ�ظ���Ϊm�����������������kСԪ��
    ȡA[k / 2] B[k / 2] �Ƚϣ�
    ��� A[k / 2] > B[k / 2] ��ô�������Ԫ�ر�Ȼ����B��ǰk / 2��Ԫ����(֤����֤��)
    ��֮����Ȼ����A��ǰk / 2��Ԫ���У��������ǿ��Խ�A��B���е�ǰk / 2Ԫ��ɾȥ����ʣ���������е�
    k - k / 2СԪ�أ����ǵõ������ݹ�ģ��С��ͬ�����⣬�ݹ���
    ��� k / 2 ����ĳ���и���������Ԫ�ر�Ȼ������һ���е�ǰk / 2��Ԫ���У�ͬ�ϲ����ͺá�
    */
    double findKth(vector<int>& A, vector<int>& B, int A_st, int B_st, int k) {
        // �߽��������һ����Ϊ��
        if (A_st >= A.size()) {
            return B[B_st + k - 1];
        }
        if (B_st >= B.size()) {
            return A[A_st + k - 1];
        }
        // k����1ʱ��ʾȡ��Сֵ��ֱ�ӷ���min
        if (k == 1) return min(A[A_st], B[B_st]);
        int A_key = A_st + k / 2 - 1 >= A.size() ? INT_MAX : A[A_st + k / 2 - 1];
        int B_key = B_st + k / 2 - 1 >= B.size() ? INT_MAX : B[B_st + k / 2 - 1];
        if (A_key < B_key){
            return findKth(A, B, A_st + k / 2, B_st, k - k / 2);
        } else {
            return findKth(A, B, A_st, B_st + k / 2, k - k / 2);
        }
        
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();
        double ret;
        
        if (sum & 1) {
            ret = findKth(nums1, nums2, 0, 0, sum / 2 + 1);
        } else {
            ret = ((findKth(nums1, nums2, 0, 0, sum / 2)) +
                    findKth(nums1, nums2, 0, 0, sum / 2 + 1)) / 2.0;
        }
        return ret;
    }
};