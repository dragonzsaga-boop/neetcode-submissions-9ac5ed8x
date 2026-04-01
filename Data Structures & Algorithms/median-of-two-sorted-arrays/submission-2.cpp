class Solution {

    /*
    even find 2 numbers, [(x/2)-1] numbers smaller and greater than them
    odd find 1 number with (x/2) numbers smaller and greater than it

    1 3 4 6 7 9
    0 2 4 8
    0 1 2 3 4 4 6 7 8 9

    0 1 2 3 4 5 6 7 8 9
    1 3 6 7 8 9
    0 2 4 5

    take m=(l+r)/2 element in larger array, 
        find its probable index in second array = t
        if(m+t) > (x/2), number is too large, try reducing r=m-1
        if(m+t) < (x/2), number is too small, try increasing l=m+1
        if(m+t) == (x/2), number is exact median, 
                if total elements in arrays even take its preceding value as well
    */
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        int half = (nums1.size() + nums2.size() + 1)/2;
        int l = 0, r = nums1.size();
        while(l <= r) {
            int m = (l + r)/2;
            int n = half - m;

            int l1 = (m > 0) ? nums1[m-1] : INT_MIN;
            int r1 = (m < nums1.size()) ? nums1[m] : INT_MAX;
            int l2 = (n > 0) ? nums2[n-1] : INT_MIN;
            int r2 = (n < nums2.size()) ? nums2[n] : INT_MAX;

            if((l1 <= r2) && (l2 <= r1)) {
                if((nums1.size()+nums2.size()) & 1) {
                    return max(l1,l2);
                }
                return static_cast<double>((max(l1,l2)+min(r1,r2)))/2.00;
            }
            if((l1 > r2)) {
                r = m-1;
            }
            else {
                l = m+1;
            }
        }
        return -1;
    }
};
