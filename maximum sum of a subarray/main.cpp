#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

/**
 * Function to find the median of two sorted arrays using binary search.
 * The algorithm ensures O(log(min(m, n))) time complexity.
 */
double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2)
{
    const vector<int>& A = (nums1.size() <= nums2.size()) ? nums1 : nums2;
    const vector<int>& B = (nums1.size() <= nums2.size()) ? nums2 : nums1;

    int m = A.size();
    int n = B.size();
    int low = 0, high = m;

    while (low <= high)
    {
        int i = (low + high) / 2;
        int j = (m + n + 1) / 2 - i;

        int Aleft = (i == 0) ? INT_MIN : A[i - 1];
        int Aright = (i == m) ? INT_MAX : A[i];
        int Bleft = (j == 0) ? INT_MIN : B[j - 1];
        int Bright = (j == n) ? INT_MAX : B[j];

        if (Aleft <= Bright && Bleft <= Aright)
        {
            if ((m + n) % 2 == 0)
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            else
                return max(Aleft, Bleft);
        }
        else if (Aleft > Bright)
            high = i - 1;
        else
            low = i + 1;
    }
    throw runtime_error("Invalid input");
}

/**
 * Demonstrates the median finding function with example inputs.
 */
int main()
{
    vector<int> nums1 = { 1, 2 };
    vector<int> nums2 = { 3, 4 };

    double median = findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << median << endl;

    return 0;
}
