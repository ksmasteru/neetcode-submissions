class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums_set = set(nums)
        longest = 0
        for i in range(len(nums)):
            streak = 1
            if (nums[i] - 1 in nums_set):
                continue
            else:
                to_find = nums[i] + 1
                while (to_find in nums_set):
                    streak = streak + 1
                    to_find = to_find + 1
            longest = max(streak, longest)
        return longest