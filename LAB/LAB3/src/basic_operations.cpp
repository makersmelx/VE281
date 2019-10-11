#include "sort.h"
using namespace std;
void swap(int a,int b,int* nums)
{
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}
void printArray(int* nums,int length)
{
    for(int i = 0 ; i < length;i++)
    {
        cout << nums[i] << endl;
    }
}

void printSearch(int key,int value)
{
    cout << "The order-" << key <<" item is " << value << endl;
}