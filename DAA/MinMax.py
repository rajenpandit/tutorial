
def minMaxDivide(arr):
    subArraySize = int(len(arr)/2)
    if subArraySize > 0:
        leftArr = arr[:subArraySize]
        rightArr = arr[subArraySize:]
        lMin, lMax = minMaxDivide(leftArr)
        rMin, rMax = minMaxDivide(rightArr)
        min = lMin
        max = lMax
        if min > rMin:
            min = rMin
        if max < rMax:
            max = rMax
        return min, max;
    return arr[0], arr[0]

if __name__ == "__main__":
    min,max = minMaxDivide([4,5,6,10,2,6,83,11,7,9])
    print("Min:",min)
    print("Max", max)
