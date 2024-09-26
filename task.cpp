class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, vector<int>& nums2) {
        int l1, r1, l2, r2, lr, rr, target, m1, m2;
        l1 = 0; l2 = 0;
        lr = rr = 0;
        r1 = nums1.size() - 1; r2 = nums2.size() - 1;
        target = (r1 + r2)/2;
        bool two_right = false;
        bool two = (r1 + r2)%2 == 0;
        int where = std::abs(rr - lr) - (r1 - l1 + r2 - l2);
        int mid2 = -1;
        while(where <= 0) {
            
            m1 = mid(l1,r1);
            m2 = mid(l2,r2);
            if(nums1[m1] < nums2[m2]){
                lr += m1 - l1;
                l1 = m1;
                rr += r2 - m2;
                r2 = m2;
                two_right = true;
            }
            else {
                lr += m2 - l2;
                l2 - m2;
                rr += r1 - m1;
                r1 = m1;
                two_right = false;
            }
            where = std::abs(rr - lr) - (r1 - l1 + r2 - l2 + 2);
            if(two && where == 0){
                if(rr > lr){
                    if(two_right){
                        mid2 = nums2[r2 + 1];
                    }
                    else {
                        mid2 = nums1[r1 + 1];
                    }
                }
                else {
                    if(two_right){
                        mid2 = nums2[l2 - 1];
                    }
                    else{
                        mid2 = nums1[l1 - 1];
                    }
                }
            }
        }
        int left = 0;
        double ret = 0;
        if(rr > lr)
        {
            left = target - lr - (r1 - l1 + r2 - l2) + 1;
            if(two_right){
                ret = nums2[r2+left]; 
            }
            else {
                ret = nums1[r1 + left];
            }
        }
        else {
            left = target - rr - (r1 - l1 + r2 - l2) + 1;
            if(two_right){
                ret = nums2[l2 - left]; 
            }
            else {
                ret = nums1[l1 - left];
            }
        }
        /*
        */
        if(two)
            ret = (ret + mid2)/2;
        return ret;
    }
    int mid(int x, int y){
        return (x + y)/2;
    }
};