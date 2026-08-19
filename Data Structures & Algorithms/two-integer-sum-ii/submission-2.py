class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        first_p = 0
        second_p = len(numbers) - 1
        while (first_p != second_p):
            sum = numbers[first_p] + numbers[second_p]
            if (sum == target):
                break
            elif(sum > target):
                second_p = second_p - 1
            else:
                first_p = first_p + 1
        return [first_p + 1, second_p + 1]