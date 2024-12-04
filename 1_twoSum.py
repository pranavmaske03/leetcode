
class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        seen = {} # number -> idx

        for i in range(len(nums)):
            diff = target - nums[i]
            if diff in seen:
                return [i, seen[diff]]
            seen[nums[i]] = i

        return [-1,-1]


nums = [2,7,11,15]
target = 9

obj = Solution()
print(obj.twoSum(nums,target))