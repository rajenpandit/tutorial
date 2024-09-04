#include <vector>
#include <iostream>


void merge(std::vector<int>& elements, int start, int middle, int end)
{
    std::vector<int> left(elements.begin()+start, elements.begin()+middle); // copy from start to middle -1 
    std::vector<int> right(elements.begin()+middle, elements.begin()+end);
    int leftIndex=0;
    int rightIndex=0;
    int arrayIndex = start;
    while(leftIndex < left.size() && rightIndex < right.size())
    {
        if(left[leftIndex] < right[rightIndex])
        {
            elements[arrayIndex++] = left[leftIndex++];
        }
        else{
            elements[arrayIndex++] = right[rightIndex++];
        }
    }

    while(leftIndex < left.size()){
        elements[arrayIndex++] = left[leftIndex++];
    }
    while(rightIndex < right.size()){
        elements[arrayIndex++] = right[rightIndex++];
    }
}

void split(std::vector<int>& elements, int start, int end)
{
    int middle = (start+end)/2;   // 5/2 = 2  [1,2][3,4,5], 4/2 = 2, [1,2][3,4]
    if(middle > 0 && start!=middle) {
        std::cout<<"Befor FistSplit:"<< "start:"<<start << " middled:" << middle << " end:"<< end << std::endl;
        split(elements, start, middle);
        std::cout<<"Befor Second Split:"<< "start:"<<start << " middled:" << middle << " end:"<< end << std::endl;
        split(elements, middle, end);
        std::cout<<"Befor Merge Split:"<< "start:"<<start << " middled:" << middle << " end:"<< end << std::endl;
        merge(elements, start, middle, end);
    }
}

int main()
{
    std::vector<int> elements = {3,7,6,9, 4,8,10,5};
    split(elements, 0, 8);

    for(auto elem: elements)
    {
        std::cout << elem << std::endl;
    }
}
