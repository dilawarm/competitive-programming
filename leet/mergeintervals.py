class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        intervals = sorted(intervals)
        merged = [intervals[0]]
        for i in range(1, len(intervals)):
            if intervals[i][0] <= merged[-1][1]:
                merged[-1] = (merged[-1][0], max(intervals[i][1], merged[-1][1]))
            else:
                merged.append((intervals[i][0], intervals[i][1]))
        return merged