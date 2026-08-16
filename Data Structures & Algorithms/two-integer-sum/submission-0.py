class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        my_list = []
        my_dict = {} # stores value : index
        for i, num in enumerate(nums):
            if ((target - num) in my_dict):
                my_list.append(my_dict[target-num])
                my_list.append(i)
                return my_list
            else:
                my_dict[num] = i
        return my_list