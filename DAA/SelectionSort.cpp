#include <iostream>
#include <vector>
void SelectionSort(std::vector<int>& list) 
{
    if(list.size()==0)
        return;

    for(int j=0; j< list.size()-1; j++)
    {
        int minValuIndex = j;
        for(int i=j+1; i<list.size(); i++)
        {
            if(list[minValuIndex] > list[i]){
                minValuIndex = i;
            }
        }
        std::swap(list[j],list[minValuIndex]);
    }

}


int main()
{
    std::vector<int> list = {4,9,5,6,7,8,6};
    SelectionSort(list);
    for(auto v: list){
        std::cout << v << " ";
    }
    std::cout<<std::endl;
}
    
