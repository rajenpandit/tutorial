#include <vector>
#include <iostream>

int knapsack(std::vector<int>& profitList, std::vector<int>& weightList, int length, int Capacity)
{
    if (length == 0){
        return 0;
    }

    if (weightList[length-1] > Capacity)
    {
        return 0;
    }

    // Select the item
    int profit = profitList[length-1];
    int restItemsProfit = knapsack(profitList, weightList, length-1, Capacity-weightList[length-1]);
    profit = profit + restItemsProfit;

    // Dont select the item 
    int profit2 = knapsack(profitList, weightList, length-1, Capacity );

    return std::max(profit, profit2);
}

// P    W 
// [], [], Capacity = 4
// [4], [5], Capacity = 4
// [10,2,3,4], [4,2,3,5] , Capacity=4
//


int main() {
    std::vector<int> profitList = {60,100,120};
    std::vector<int> weightList = {10,20,30};
    int maxProfit = knapsack(profitList, weightList, profitList.size(), 50) ;
    std::cout << "Max Profit:" << maxProfit<< std::endl;
}
