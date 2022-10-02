# 二分查找
def search(a, target):
    n = len(a)
    low = 0
    high = n - 1
    while low <= high:
        mid = low + ((high - low) >> 1)
        if a[mid] > target:
            high = mid - 1
        elif a[mid] < target:
            low = mid + 1
        else:
            return mid
    return -1


if __name__ == '__main__':
    a = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    print(search(a, 5))
