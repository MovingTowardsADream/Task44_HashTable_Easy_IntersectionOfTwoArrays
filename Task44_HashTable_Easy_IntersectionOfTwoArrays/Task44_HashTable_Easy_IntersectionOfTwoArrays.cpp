#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    static std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> result;
        std::unordered_map<int, int> tmpmap;
        for (int i = 0;i < nums1.size();i++) {
            tmpmap[nums1[i]]++;
        }
        for (int i = 0;i < nums2.size();i++) {
            if (tmpmap[nums2[i]] > 0) {
                tmpmap[nums2[i]] = -1;
            }
        }
        for (auto i : tmpmap) {
            if (i.second == -1) {
                result.push_back(i.first);
            }
        }
        return result;
    }
};

// Second solution

//class Solution {
//public:
//    static std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
//        std::sort(nums1.begin(), nums1.end());
//        std::sort(nums2.begin(), nums2.end());
//        int first = 0, second = 0, n = nums1.size(), m = nums2.size();
//        std::vector<int> result;
//        while (first < n && second < m) {
//            if (nums1[first] == nums2[second]) {
//                result.push_back(nums1[first]);
//                while (first < n - 1 && nums1[first] == nums1[first + 1]) first++;
//                first++;
//                while (second < m - 1 && nums2[second] == nums2[second + 1]) second++;
//                second++;
//            }
//            else if(nums1[first] < nums2[second]){
//                first++;
//            }
//            else {
//                second++;
//            }
//        }
//        return result;
//    }
//};

int main()
{
    std::vector<int> nums1 = { 4,9,5 };
    std::vector<int> nums2 = { 9,4,9,8,4 };
    for (int i : Solution::intersection(nums1, nums2)) {
        std::cout << i << " ";
    }
}