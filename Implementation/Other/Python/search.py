def linearSearch(array, x):
    for i in range(0, len(array)):
        if array[i] == x:
            return i
    return 0

def binarySearch(array, x):
    start = 0
    end = len(array)-1
    middle = 0
    while(start < end):
        middle = (start+end) // 2
        if(array[middle] >= x):
            end = middle
        else:
            start = middle + 1
    if (start == end):
        return start
    return 0


def main():
    arr = [2,3,4,5,2,6]
    x = 4
    print(linearSearch(arr, x))
    print(binarySearch(arr, x))

if __name__ == "__main__":
    main()