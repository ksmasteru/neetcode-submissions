class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = []
        for i in range(0, len(nums)) :
            prod = 1;
            for j in range(0, len(nums)) :
                if j != i:
                    prod *= nums[j]
            res.append(prod)
        return res