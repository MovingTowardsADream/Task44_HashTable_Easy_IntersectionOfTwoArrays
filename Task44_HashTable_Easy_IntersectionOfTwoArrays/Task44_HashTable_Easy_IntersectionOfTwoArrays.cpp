#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    static std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> result;
        std::unordered_map<int, int> tmpmap;
        for (int i = 0;i < nums1.size();i++)
            tmpmap[nums1[i]]++;
        for (int i = 0;i < nums2.size();i++)
            if (tmpmap[nums2[i]] > 0)
                tmpmap[nums2[i]] = -1;
        for (auto i : tmpmap)
            if (i.second == -1)
                result.push_back(i.first);
        return result;
    }
};

int main()
{
    std::vector<int> nums1 = { 1,2,2,1 };
    std::vector<int> nums2 = { 2, 2 };
    for (int i : Solution::intersection(nums1, nums2)) {
        std::cout << i << " ";
    }
}