class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        sorted_nums = sorted(nums)
        n = len(nums)
        res = []
        found = set()
        left = 1
        right = n - 1
        #[-1, -1, 1, 0]
        #nums=[-1,0,1,2,-1,-4,-2,-3,3,0,4]
        i = 0
        while (i < len(sorted_nums) - 2):
            if (sorted_nums[i] > 0):
                return res
            #while (i > 1 and i < len(sorted_nums) - 2 and sorted_nums[i - 1] == sorted_nums[i]):
            #    i = i + 1
            left = i + 1
            right = n - 1
            #nums=[-1,0,1,2,-1,-4,-2,-3,3,0,4]
            #sorted_nums=[-4,-3,-2,-1,-1,0,0,1,2,3,4]
            while (left < right):
                suma = sorted_nums[i] + sorted_nums[left] + sorted_nums[right]
                if (suma == 0):
                    if ((sorted_nums[i], sorted_nums[left], sorted_nums[right]) not in found):
                        found.add((sorted_nums[i], sorted_nums[left], sorted_nums[right]))
                        res.append([sorted_nums[i], sorted_nums[left], sorted_nums[right]])
                    left = left + 1
                    while (left < right and sorted_nums[left] == sorted_nums[left - 1]):
                        left = left + 1
                    right = right - 1
                    while (left < right and sorted_nums[right] == sorted_nums[right + 1]):
                        right = right - 1
                    continue
                if (left < right and suma > 0):
                    right = right - 1
                if (left < right and suma < 0):
                    left = left + 1
            i = i + 1
        return res