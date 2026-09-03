class Solution:
    #@function calculate water between two gaps.
    def cal_water(self, start, stop, height):
        #the gap stop when a level higher than the first water appears
        boulder_height = min(height[start], height[stop])
        water_area = 0
        for i in range(start + 1, stop):
            if (boulder_height > height[i]):
                water_area += boulder_height - height[i]
        return water_area
    def trap(self, height: List[int]) -> int:
        left, right = 0, len(height) - 1
        water_area = 0
        while (left < right and height[left] == 0):
            left = left + 1
        while (right > 0 and height[right] == 0):
            right = right - 1
        while (left < right):
            boulder = left
            found = False
            left = left + 1
            while (left < right and height[left] < height[boulder]):
                found = True
                left = left + 1
            if (found):
                water_area += self.cal_water(boulder, left, height)
            found = False
            boulder = right
            right = right - 1
            while (left < right and height[right] < height[boulder]):
                found = True
                right = right -  1
            if (found):
                water_area += self.cal_water(right, boulder, height)
        return water_area