class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if (len(nums) == 0):
            return 0
        streak = 1
        biggest = 1
        nums.sort()
        for i in range(len(nums) - 1):
            if (nums[i + 1] - nums[i] == 1):
                streak = streak + 1
                biggest = max(streak, biggest)
            elif (nums[i] != nums[i + 1]):
                streak = 1
        return biggest