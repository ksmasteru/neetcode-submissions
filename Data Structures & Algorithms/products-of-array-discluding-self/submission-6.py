class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        #the proct at each index is simply the product of prefix and postfix
        postfix = [i for i in range(len(nums))]
        prefix = [i for i in range(len(nums))]
        res = [i for i in range(len(nums))]
        prefix[0], postfix[len(nums) - 1] = 1, 1
        for i in range(1, len(nums),  1):
            prefix[i] = prefix[i - 1] * nums[i - 1]
        for i in range(len(nums) - 2, -1,  -1):
            postfix[i] = postfix[i + 1] * nums[i + 1]
        for i in range(len(nums)):
            res[i] = postfix[i] * prefix[i]
        return res