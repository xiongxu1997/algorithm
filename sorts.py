
# 快速排序
def quick_sort(nums, i, j):
    if i >= j:
        return list
    pivot = nums[i]
    low = i
    high = j
    while i < j:
        while i < j and nums[j] >= pivot:
            j -= 1
        nums[i] = nums[j]
        while i < j and nums[i] <= pivot:
            i += 1
        nums[j] = nums[i]
    nums[j] = pivot
    quick_sort(nums, low, i-1)
    quick_sort(nums, i+1, high)
    return nums


if __name__ == '__main__':
    print('this is a my sort algorithm!')
    nums = [30, 24, 5, 58, 18, 36, 12, 42, 39]
    print(quick_sort(nums, 0, len(nums)-1))
