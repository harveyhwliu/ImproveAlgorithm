#include <iostream>
/*
 * 选择排序： 将一个数组分为2类区域，一类是已排序的，一类是待排序的，每次从遍历数组（从第1，2，3，4，，，）
 *             找到未排序中的最小的放到已排序的最后一个（放到底1，2，3，4，，，）
 *
 *  时间复杂度：
        两层循环，第1次遍历n次(n个元素)，第二次遍历n-1次，... 依次类推。
        因此，表达式如下：n + (n - 1) + (n - 2) + ... + 1 = n * (n + 1) / 2 = O(n^2)
    空间复杂度：
        没有利用新的数组来帮助完成排序算法，我们认为其空间复杂度为O(1)

    选择排序不是稳定排序，因为不能保证值相等的元素相对位置不变，例如【3，4，3，1，5】，第一次交换，3和1交换，此时两个3的相对位置已经发生了变化
 * */

/*
 * 数组中交换指定两个位置的数据
 * */
int ArraySwapValue(int* array,int i,int j)
{
    int temp;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
/*
 * 选择排序，每次从待排序的数中选择一个最小的放到已经排序的数字后面
 * 优化方法是，设计标记位，针对循环比较相邻两位都不会发生交换的场景（表面已经有序了），进行甄别并及时退出
 * */
int SelectSort(int* array,int length){
    if(nullptr==array or length<=1){
        return -1;
    }
    int minNum = -1;
    for(int i =0;i<length-1;i++){
        minNum = i;
        for(int j =i+1;j<length;j++){
            if (array[j]<array[minNum]){
                minNum = j;
            }
        }
        if(minNum !=i)
            ArraySwapValue(array,minNum,i);
    }
    return 0;
}
void PrintArrayValue(int *array,int length){
    if(nullptr == array || length<=0){
        std::cout<<"数组异常，无法打印"<<std::endl;
        return;
    }
    for(int i = 0;i<length;i++){
        std::cout<<array[i]<<" , ";
    }
    std::cout<<std::endl;
}

int main(int argc,char * argv[]){
    std::cout<<"Select Sort Algorithm"<<std::endl;
    int checkResArray[]={42,20,17,13,28,14,23,15};
    size_t arrayLength=sizeof(checkResArray)/sizeof(int);
    std::cout<<"Src Array:"<<std::endl;
    PrintArrayValue(checkResArray,arrayLength);

    std::cout<<"After Sorting:"<<std::endl;
    SelectSort(checkResArray,arrayLength);
    PrintArrayValue(checkResArray,arrayLength);
//    getchar();
    return 0;
}