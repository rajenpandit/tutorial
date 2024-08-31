
def InsertionSort(list):
    n = len(list);
    for j in range(1,n):
        key = list[j]
        index = 0
        for i in range(j,0,-1) :
            if list[i-1] > key :
                list[i] = list[i-1]
            else:
                index = i
                break
        list[index] = key


if __name__=="__main__":
    elements = [4,2,6,7,9,8]
    InsertionSort(elements)
    print(elements)


# [4,2,6,7,9,8]
# key = elements[1]; => key: 2
# i=1 to i>0
# elements[i-1] > key
#   elements[1] = elements[0] => [4,4,6,7,9,8]
# elements[0] = key => [2,4,6,7,9,8]
#
#
