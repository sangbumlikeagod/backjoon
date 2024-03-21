class Solution:
    def findPeakElement(self, nums):

        size = len(nums)
        if size <= 2:
            return 0
        

        def recur(l,r):
            print(l, r)

            if r - l <= 1:
                return l if max(nums[l], nums[r]) == nums[l] else r 
            mid = (l + r) // 2
            print(mid)
            if nums[mid - 1] < nums[mid] < nums[mid + 1]:
                return recur(mid+1, r)
            
            elif nums[mid - 1] > nums[mid] > nums[mid + 1]:
                return recur(l,mid-1)
            
            elif nums[mid - 1] < nums[mid] > nums[mid + 1]:
                print('찾았다')
                return mid
            else:
                left = recur(l,mid-1)
                if left == None:
                    left == 0
                right = recur(mid+1, r)
                if right == None:
                    right == 0
                
                return left or right
                
        return recur(0,size - 1)
        
a = Solution()
print(a.findPeakElement( [1,2,1,3,5,6,4]))
