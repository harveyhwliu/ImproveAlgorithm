#include <iostream>
/*
 * 冒泡排序： 相邻的两个数进行比较，较大的数下沉，较小的数冒起来。是一种稳定的排序
 *
 *  时间复杂度：
        两层循环，第1次遍历n次(n个元素)，第二次遍历n-1次，... 依次类推。
        因此，表达式如下：n + (n - 1) + (n - 2) + ... + 1 = n * (n + 1) / 2 = O(n^2)
    空间复杂度：
        没有利用新的数组来帮助完成排序算法，我们认为其空间复杂度为O(1)
 * */

/*
 * 数组中交换指定两个位置的数据
 * */
void ArraySwapValue(int* array,int i,int j){
    int temp;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
/*
 * 冒泡排序，核心是比较相邻的两个数字
 * 优化方法是，设计标记位，针对循环比较相邻两位都不会发生交换的场景（表面已经有序了），进行甄别并及时退出
 * */
int BubbleSort(int* array,int length){
    if(nullptr==array or length<=1){
        return -1;
    }
    bool isSortedFlag= false;//标记是否已经有序了
    for(int i =0;i<length-1;i++){
        for(int j =length-1;j>i;j--){
            if (array[j]<array[j-1]){
                ArraySwapValue(array,j,j-1);
                isSortedFlag = true;
            }
        }
        if(!isSortedFlag){
            return 0;
        }
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
    std::cout<<"Bubble Sort Algorithm"<<std::endl;
    int checkResArray[]={42,20,17,13,28,14,23,15};
    size_t arrayLength=sizeof(checkResArray)/sizeof(int);
    std::cout<<"Src Array:"<<std::endl;
    PrintArrayValue(checkResArray,arrayLength);

    std::cout<<"After Sorting:"<<std::endl;
    BubbleSort(checkResArray,arrayLength);
    PrintArrayValue(checkResArray,arrayLength);
//    getchar();
    return 0;
}