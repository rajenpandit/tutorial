
def minMaxDivide(arr):
    arrayLen = int(len(arr))
    subArraySize = int(arrayLen/2)
    # 1,2,3,4,5
    # 1,2   3,4,5
    #       3,4   5
    #
    # 1,2,3,4
    # 1,2   3,4
    if subArraySize > 1:
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
    if arrayLen == 3:
        #arr[0] = 3, arr[1]=4    arr[2] = 5
        min, max = minMaxDivide(arr[:2]) #[3,4]
        if arr[2] < min:
            return arr[2], max 
        elif arr[2] > max:
            return min, arr[2]
        else:
            return min, max

    if arr[0] < arr[1]:
       return arr[0], arr[1]
    return arr[1], arr[0]

if __name__ == "__main__":
    min,max = minMaxDivide([4,5,6,10,2,6,83,11,7,9])
    print("Min:",min)
    print("Max", max)
