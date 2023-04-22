class FirstAndLastElement:
    
    @staticmethod
    def searchRange(nums, target):
        first = FirstAndLastElement.findFirstOccurance(nums, target, 0, len(nums) - 1)
        last = FirstAndLastElement.findLastOccurance(nums, target, 0, len(nums) - 1)
        return [first, last]
    
    @staticmethod
    def findFirstOccurance(nums, target, start, end):
        index = -1
        while start <= end:
            mid = start + (end - start) // 2
            if nums[mid] == target:
                end = mid - 1
                index = mid
            elif nums[mid] > target:
                end = mid - 1
            else:
                start = mid + 1
        return index
    
    @staticmethod
    def findLastOccurance(nums, target, start, end):
        index = -1
        while start <= end:
            mid = start + (end - start) // 2
            if nums[mid] == target:
                start = mid + 1
                index = mid
            elif nums[mid] > target:
                end = mid - 1
            else:
                start = mid + 1
        return index
    
res = FirstAndLastElement.searchRange([5,7,7,8,8,10], 8)
print(f"{{{res[0]} {res[1]}}}")
res = FirstAndLastElement.searchRange([5,7,7,8,8,10], 6)
print(f"{{{res[0]} {res[1]}}}")
res = FirstAndLastElement.searchRange([], 0)
print(f"{{{res[0]} {res[1]}}}")
