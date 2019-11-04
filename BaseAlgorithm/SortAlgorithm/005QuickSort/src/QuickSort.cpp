#include <iostream>
/*
 * 快速排序： 分治的思想，冒泡排序的升级，首先找基准点（），然后从数组两端扫描数据，low指向起始位置，high指向末尾
 *          首先从后半部分往前开始，发现有元素大于基准点，交换low,high的位置，然后从前半部分开始扫描，发现有元素大于基准，交换low,high的位置,直到low>=high,基准点放到high位置
 *         一次排序完成后，发现基准点前面都是被基准点小的，基准点后面都是大于基准点的，然后对基准点前面、后面采用递归方式，最后就是有序的
 *
 *  时间复杂度：
        平均的时间复杂度是O（nlogn）,最坏的时间复杂度(O(n^2))
    空间复杂度：
        没有利用新的数组来帮助完成排序算法，我们认为其空间复杂度为O(1)
 * */

int getMiddle(int *array,int low,int high){
    int temp = array[low];//基准值这里用第一个元素
    while(low<high){
        while(low<high && temp <=array[high]){ //先从右边找到一个比基准值小的值
            high --;
        }
        array[low] = array[high];              //交换
        while(low<high && temp>=array[low]){   //然后从左边找到一个比基准值高的值
            low++;
        }
        array[high] = array[low];              //交换
    }
    array[low] = temp;                         //最后确定基准值得位置，并返回
    return low;
}

/*
 * 快速排序，分治的思想
 * */
int QuickSort(int* array,int low,int high){
    if(nullptr==array or low >=high){
        return -1;
    }
    if(low<high){
        int middle = getMiddle(array,low,high);
        QuickSort(array,low,middle-1);//对左子序进行排序
        QuickSort(array,middle+1,high);//对右子序进行排序
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
    std::cout<<"QUICK Sort Algorithm"<<std::endl;
    int checkResArray[]={42,20,17,13,28,14,23,15};
    size_t arrayLength=sizeof(checkResArray)/sizeof(int);
    std::cout<<"Src Array:"<<std::endl;
    PrintArrayValue(checkResArray,arrayLength);

    std::cout<<"After Sorting:"<<std::endl;
    QuickSort(checkResArray,0,arrayLength-1);
    PrintArrayValue(checkResArray,arrayLength);
//    getchar();
    return 0;
}