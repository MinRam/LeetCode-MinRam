/**
 * @Problem https://leetcode.com/problems/median-of-two-sorted-arrays/
 * @Author MinRam
 * @Date  02/23/2019
 */

static const auto __ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();

		// Invalid sample isolation
		if (0 == m && 0 == n)
			return 0;
		else if (0 == m)
			return n % 2 == 0 ? ((double)(nums2[n / 2 - 1] + nums2[n / 2])) / 2 : nums2[n / 2];
		else if (0 == n)
			return m % 2 == 0 ? ((double)(nums1[m / 2 - 1] + nums1[m / 2])) / 2 : nums1[m / 2];


		if (m > n) {
			swap(nums1, nums2);
			int tmp = m;
			m = n;
			n = tmp;
		}

		int iMin = 0;
		int iMax = m;
		int halfLen = (m + n + 1) / 2;
		while (iMin <= iMax) {
			int i = (iMin + iMax) / 2;
			int j = halfLen - i;

			if (i<iMax && nums2[j - 1]>nums1[i]) iMin = i + 1;
			else if (i > iMin && nums1[i - 1] > nums2[j]) iMax = i - 1;
			else {
				int maxLeft = 0;
				if (i == 0) maxLeft = nums2[j - 1];
				else if (j == 0) maxLeft = nums1[i - 1];
				else maxLeft = max(nums1[i - 1], nums2[j - 1]);

				if ((m + n) % 2 == 1) return maxLeft;

				int minRight = 0;
				if (i == m) minRight = nums2[j];
				else if (j == n) minRight = nums1[i];
				else minRight = min(nums1[i], nums2[j]);
				return (maxLeft + minRight) / 2.0;
			}

		}
		return 0;
	}
};