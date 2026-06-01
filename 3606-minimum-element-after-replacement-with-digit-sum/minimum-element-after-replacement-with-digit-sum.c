int sum(int n){
    int res=0;
    while(n>0){
        res+=n%10;
        n/=10;
    }
    return res;
}
int minElement(int* nums, int numsSize) {
    int *a=(int*)malloc(numsSize*sizeof(int));
    for(int i=0;i<numsSize;i++){
        a[i]=sum(nums[i]);
    }
    int min=INT_MAX;
    for(int i=0;i<numsSize;i++){
        if(a[i]<min)
            min=a[i];
    }
    return min;
}