#include <stdio.h>

int main()
{
    int nums[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int size = sizeof(nums) / sizeof(nums[0]);

    int length =0 ;
    for(int i=0 ; i<size;i++)
    {
        int temp_length = 1;
        int temp=i;
        for(int j=i+1;j<size;j++)
        {
            if(nums[temp]< nums[j])
            {
                temp = j;
                temp_length++;
            }
        }

        if(length < temp_length)
        {
            length = temp_length;
        }
    }
    printf("%d",length);
    return length;

}