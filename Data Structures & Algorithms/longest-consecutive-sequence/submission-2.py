class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums_set = set(nums)
        max_streak = 0
        #if element has no prev then it is the start of a set
        for i in range(len(nums)):
            streak = 1
            if (nums[i] - 1 in nums_set):
                continue
            else:
                to_find = nums[i] + 1
                while (to_find in nums_set):
                    streak = streak + 1
                    to_find = to_find + 1
            max_streak = max(streak, max_streak)
        return max_streak