
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)
        x, y = len(nums1), len(nums2)
        l, r = 0, x
        while l <= r:
            midx = (l + r)//2
            midy = (x+y+1)//2 - midx
            
            if midx == 0:
                maxx = -float('inf')
            else:
                maxx = nums1[midx-1]
            
            if midx == x:
                minx = float('inf')
            else:
                minx = nums1[midx]
            
            if midy == 0:
                maxy = -float('inf')
            else:
                maxy = nums2[midy-1]
            
            if midy == y:
                miny = float('inf')
            else:
                miny = nums2[midy]
            
            if maxx <= miny and maxy <= minx:
                if (x + y) % 2:
                    return float(max(maxx, maxy))
                else:
                    return float((max(maxx, maxy)+min(minx, miny)))/2
            elif maxx > miny:
                r = midx - 1
            else:
                l = midx + 1