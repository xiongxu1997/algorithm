# 获取斐波那契数列中第k个值
def getF(k):
    if k == 1 or k == 2:
        return 1
    first = 1
    second = 2
    for i in range(k-3):
        first, second = second, first+second
    return second


if __name__ == '__main__':
    # 1 1 2 3 5 8 13 21
    print(getF(8))

