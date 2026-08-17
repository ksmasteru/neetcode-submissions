class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        postfix = [1] * len(nums)
        prefix = [1] * len(nums)
        sol = [1] * len(nums)
        postfix[len(nums) - 1] = 1
        postfix[0] = 1
        for i in range(1,len(nums)):
            prefix[i] = prefix[i - 1] * nums[i - 1]
        for i in range(len(nums) - 2, -1, -1):
            postfix[i] = postfix[i + 1] * nums[i + 1]
        for i in range(len(nums)):
            sol[i] = prefix[i] * postfix[i]
        return sol