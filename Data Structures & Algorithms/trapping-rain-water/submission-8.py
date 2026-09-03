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
    #the max . no if you are a max height that's a wall
    #height=[5,4,1,2] -- [4,5,1,5,5] if you are at max height
    # and your max height % 2 == 1 stop
    #the max hight issue
    def trap(self, height: List[int]) -> int:
        sorted_heights = sorted(height)
        maxheight = sorted_heights[len(height) - 1]
        max_height_number = 1
        for i in range(len(height) - 2, 0,-1):
            if (maxheight == sorted_heights[i]):
                max_height_number += 1
            else:
                break
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