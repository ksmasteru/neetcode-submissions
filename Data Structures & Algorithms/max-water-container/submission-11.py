class Solution:
    def maxArea(self, heights: List[int]) -> int:
        n = len(heights)
        lefties = [0]
        max_height =  sorted(heights)[n - 1]
        left, right = 0, n - 1
        max_area = 0
        topr = n-1
        topl = 0
        max_area = max(max_area, (right - left) * min(heights[left],heights[right]))
        while (left < right):
            while (left < right and heights[left] != max_height):
                left = left + 1
                if (heights[left] > heights[topl]):
                    max_area = max(max_area,(right-left)*min(heights[left],heights[right]))
                    lefties.append(left)
                    topl = left
            while (right > left and heights[right] != max_height):
                right = right - 1
                if (heights[right] > heights[topr]):
                    for x in lefties:
                        max_area = max(max_area, (right-x)*min(heights[x], heights[right]))
                    topr = right
            if (heights[left] == heights[right] == max_height):
                break
        return max_area