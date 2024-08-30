#include <iostream>
#include <vector>
void SelectionSort(std::vector<int>& list) 
{
    if(list.size()==0)
        return;
    int n = list.size();
    for(int j=0; j< n-1; j++) // n-1 times
    {
        int minValuIndex = j;
        for(int i=j+1; i<n; i++) // j:0 => n-1, j:1 => n-2, j:2 => n-3... j: n-2 => n-(n-2+1) = n-n+2-1 = 1
        {
            if(list[minValuIndex] > list[i]){
                minValuIndex = i;
            }
        }
        std::swap(list[j],list[minValuIndex]);
    }

}

// (n-1) + (n-2) + (n-3) ..... + 1 
// x + x-1 + x-2 + x-3 .... + 2 + 1
// x(x+1)/2 
// (n-1)(n-1+1)/2 
// (n-1)n/2 
// (n^2 - n)/2 
// O(n^2)

int main()
{
    std::vector<int> list = {4,9,5,6,7,8,6};
    // [4,9,5,6,7,8,6]  => j = 0
    // [4,5,9,6,7,8,6]  => j = 1
    // [4,5,9,6,7,8,6]  => j = 2
    // [4,5,6,9,7,8,6]  => j = 2
    // [4,5,6,6,7,8,9]  => j = 3, minValuIndex:6, i:7
    //
    SelectionSort(list);
    for(auto v: list){
        std::cout << v << " ";
    }
    std::cout<<std::endl;
}
    
