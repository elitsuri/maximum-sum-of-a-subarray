#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

double findMiddle(const vector<int>& merged)
{
    int size = merged.size();


    if (size % 2 == 0)
        return (merged[size / 2 - 1] + merged[size / 2]) / 2.0; 
    else    
        return merged[size / 2];   
}

void mergeVectors(const vector<int>& vec1, const vector<int>& vec2, vector<int>& merged)
{
    for (int i = 0; i < vec1.size(); i++)
        merged.push_back(vec1[i]);
    for (int i = 0; i < vec2.size(); i++)
        merged.push_back(vec2[i]);
}

double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2)
{
    int n = nums2.size();
    int m = nums1.size();
    double ret;
    vector<int> merged;


    mergeVectors(nums1, nums2, merged);
    sort(merged.begin(), merged.end());

    return(findMiddle(merged));
}

/**
 * Demonstrates the median finding function with example inputs.
 */
int main()
{
    vector<int> nums1 = { 1, 2 ,1};
    vector<int> nums2 = { 3, 4 };

    double median = findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << median << endl;
    cin.get();
    return 0;
}
