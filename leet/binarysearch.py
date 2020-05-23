def binarySearch(arr: [int], left: int, right: int, target: int) -> bool:
    if (left > right):
        return False

    mid = (left + right) // 2

    if arr[mid] == target:
        return True
    
    if arr[mid] < target:
        return binarySearch(arr, mid+1, right, target)
    return binarySearch(arr, left, mid-1, target)

if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5]
    n = len(arr)
    print(binarySearch(arr, 0, n-1, 0))