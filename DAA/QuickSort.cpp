#include <vector>
#include <iostream>

int Partition(std::vector<int>& elements, int startIndex, int endIndex)
{
    int pivot = elements[endIndex];
    int i = startIndex -1; // left elements from i will be lesser than pivot
    for(int j=startIndex; j<endIndex; j++){
        if(elements[j]<=pivot){
            i = i+1;
            std::swap(elements[i], elements[j]);
        }
    }
    i = i+1;
    std::swap(elements[i],elements[endIndex]);
    return i;
}

void QuickSort(std::vector<int>& elements, int startIndex, int endIndex)
{
    if(startIndex >= endIndex)
        return;
    int partitionIndex = Partition(elements, startIndex, endIndex);
    QuickSort(elements, startIndex, partitionIndex-1);  // Left SubArray
    QuickSort(elements, partitionIndex+1, endIndex);  // Right SubArray
}

int main()
{
    std::vector<int> elements = {5,7,2,8,4,1,3};
    QuickSort(elements, 0, elements.size()-1 );
    for(auto elem: elements)
    {
        std::cout << elem << " ";
    }
    std::cout<<std::endl;
}


//     j           p
//    [5,7,2,8,4,1,3]
//  ^
// i=-1
//

//       j         p
//    [5,7,2,8,4,1,3]
//  ^
// i=-1
//


//         j       p               j       p
//    [5,7,2,8,4,1,3]    =>   [2,7,5,8,4,1,3]
//  ^                          ^
// i=-1                        i
//

//           j     p
//    [2,7,5,8,4,1,3]
//     ^
//     i
//             j   p
//    [2,7,5,8,4,1,3]
//     ^
//     i
//
//               j p                            j p                        j p
//    [2,7,5,8,4,1,3]  => i++     => [2,7,5,8,4,1,3] => swap => [2,1,5,8,4,7,3]
//     ^                                ^                          ^
//     i                                i                          i
//
//     if j==endIndex
//     i++                  j
//     swap => [2,1,3,8,4,7,5]
//                  i
//

// 2nd iteration => 3 as sorted
//  [2,1]  [8,4,7,5]

