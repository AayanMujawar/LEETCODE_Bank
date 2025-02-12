int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int *p;
    *returnSize = numsSize;
    p=(int*)malloc(numsSize*sizeof(int*));
for(int i = 0;i<numsSize;i++)
    {
     int count = 0;
        for(int j = 0;j<numsSize;j++)
        {
         if((i != j) && (nums[j]<nums[i]))
            {
                count+=1;
            }
            
        }
        p[i]=count;

    }
    return  p;
    
}

