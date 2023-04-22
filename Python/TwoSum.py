from typing import List

class Solution(object):
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        mp = {}
        for i in range(len(nums)):
            if target - nums[i] in mp:
                return [mp[target - nums[i]], i]
            mp[nums[i]] = i
        return [-1, -1]

# Create an instance of the Solution class
s = Solution()
nums = [2, 7, 11, 15]
target = 9
res = s.twoSum(nums, target)
print("{" + str(res[0]) + " " + str(res[1]) + "}")

nums = [3, 2, 4]
target = 6
res = s.twoSum(nums, target)
print("{" + str(res[0]) + " " + str(res[1]) + "}")

nums = [3, 3]
target = 6
res = s.twoSum(nums, target)
print("{" + str(res[0]) + " " + str(res[1]) + "}")