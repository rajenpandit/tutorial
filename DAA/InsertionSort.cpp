
#include <vector>
#include <iostream>
#if 0
void insertionSort(std::vector<int>& elements)
{
    // [5,2,1,6,7]

    // [2,5,1,6,7]
    // [1,2,5,6,7]
    int n = elements.size();
    for(int j=1; j<n; j++)
    {
        for(int i=j; i>0; i--)
        {
            if(elements[i-1] > elements[i])
            {
                std::swap(elements[i-1],elements[i]); 
            }
        }
    }
}
#endif

void insertionSort(std::vector<int>& elements)
{
    int n = elements.size();
    for(int j=1; j<n; j++)
    {
        int key = elements[j];
        int index = 0;
        for(int i=j; i>0; i--)
        {
            if(elements[i-1] > key)
            {
                elements[i] = elements[i-1];
            }
            else{
                index = i;
                break;
            }
        }
        elements[index] = key;
    }
}

int main()
{
    std::vector<int> elements = {41,22,63,14,55,36};
    insertionSort(elements);
    for(auto i: elements) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}
