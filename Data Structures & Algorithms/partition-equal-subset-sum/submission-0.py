class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        total_sum = sum(nums)
        if total_sum % 2 != 0:
            return False
        target = total_sum // 2
        dp = [[False for j in range(target + 1)] for i in range(n)]
        for i in range(n):
            dp[i][0] = True
        if nums[0] <= target:
            dp[0][nums[0]] = True
        for i in range(1, n):
            for j in range(1, target + 1):
                if dp[i - 1][j]:
                    dp[i][j] = dp[i - 1][j]
                elif j >= nums[i]:
                    dp[i][j] = dp[i - 1][j - nums[i]]
        return dp[n - 1][target]