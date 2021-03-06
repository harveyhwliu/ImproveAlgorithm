﻿#include <iostream>
/*
 * 归并排序： 稳定的排序，采用分治法（Divide and Conquer）,速度仅次于 快速排序，一般用于  对总体无序，但是各子项相对有序的数列
 *  先把数列分解为若干个子序列，然后依次进行归并
 *      将原始序列从中间分为左，右两个子列，此时序列为2
 *      将左序列和右序列再分别从中间分为左、右两个子序列，此时序列数为4
 *      重复上面的步骤，知道每个子序列都只有一个元素，可以认为每一个子序列都是有序的
 *      最后一次进行归并操作，知道序列数为1
 *  时间复杂度：
        平均的时间复杂度是O（nlogn）
    空间复杂度：
        归并排序需要一个与原数组相同长度的数组做辅助，空间复杂度为O(n)
 * */


void MergeSort_Merge(int *array,int left,int middle,int right,int* temp_array){
    int i = left;       //左序列
    int j = middle+1;   //右序列
    int t = 0;          //临时数据
    while (i<=middle && j<= right){
        temp_array[t++] = (array[i]<=array[j])? array[i++] : array[j++];
    }
    while(i<=middle){   //左边没有全部放到临时数组中
        temp_array[t++] = array[i++];
    }
    while(j<=right){    //右边没有全部放到临时数组中
        temp_array[t++] = array[j++];
    }
    t = 0;
    while(left <= right){//将temp中的元素全部拷贝到原数组中
        array[left++] = temp_array[t++];
    }
}


void MergeSortHandler(int *array,int left,int right,int* temp_array){
    if(left>=right) return;
    int middle = (left+right)/2;
    MergeSortHandler(array,left,middle,temp_array);      //左边归并排序，使得左子序列有序
    MergeSortHandler(array,middle+1,right,temp_array);   //右子序归并排序，使得右子序列有序
    MergeSort_Merge(array,left,middle,right,temp_array);//将两个有序进行合并
}
/*
 * 归宿排序，分治的思想，先分裂成有序，在合并，需要利用额外的空间
 * */
int MergeSort(int* array,int length){
    if(nullptr==array or length<=1){
        return -1;
    }
    int *temp_array = (int*) malloc(sizeof(int)*length); //需要申请额外的空间
    MergeSortHandler(array,0,length-1,temp_array);
    free(temp_array);
    temp_array = nullptr;

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
    std::cout<<"Merge Sort Algorithm"<<std::endl;
    int checkResArray[]={42,20,17,13,28,14,23,15};
    size_t arrayLength=sizeof(checkResArray)/sizeof(int);
    std::cout<<"Src Array:"<<std::endl;
    PrintArrayValue(checkResArray,arrayLength);

    std::cout<<"After Sorting:"<<std::endl;
    MergeSort(checkResArray,arrayLength);
    PrintArrayValue(checkResArray,arrayLength);
//    getchar();
    return 0;
}