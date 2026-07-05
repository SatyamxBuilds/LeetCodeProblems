int findMin(int a, int b)
{
    return (a < b) ? a : b;
}

int findMax(int a, int b)
{
    return (a > b) ? a : b;
}

int maxProfit(int* prices, int pricesSize)
{
    if(pricesSize == 0)
        return 0;

    int minPrice = prices[0];
    int maxProfit = 0;

    for(int i = 1; i < pricesSize; i++)
    {
        minPrice = findMin(minPrice, prices[i]);
        maxProfit = findMax(maxProfit, prices[i] - minPrice);
    }

    return maxProfit;
}