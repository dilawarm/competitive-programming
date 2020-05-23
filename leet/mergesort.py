def mergesort(arr: [int]) -> [int]:
    if len(arr) < 2:
        return arr

    mid = len(arr) // 2
    right_arr = arr[:mid]
    left_arr = arr[mid:]

    sorted_left = mergesort(left_arr)
    sorted_right = mergesort(right_arr)

    sorted_arr = []
    left_index = 0
    right_index = 0

    while len(sorted_arr) < len(left_arr) + len(right_arr):
        if (left_index < len(left_arr)) and (right_index == len(right_arr) or (sorted_left[left_index] < sorted_right[right_index])) :
            sorted_arr.append(sorted_left[left_index])
            left_index += 1
        else:
            sorted_arr.append(right_arr[right_index])
            right_index += 1
    
    return sorted_arr

if __name__ == "__main__":
    arr = [4, 5, 6, 5, 1]
    arr = mergesort(arr)
    print(arr)      