#include <iostream>
/*
 * 插入查找：
        元素必须是有序的，如果是无序的则要先进行排序操作。
        二分查找中查找点计算如下：mid=(low+high)/2, 即mid=low+1/2*(high-low);
 *      通过类比，我们可以将查找的点改进为如下：mid=low+(key-a[low])/(a[high]-a[low])*(high-low)，
 *      基本思想：基于二分查找算法，将查找点的选择改进为自适应选择，可以提高查找效率。当然，差值查找也属于有序查找。
 *      对于表长较大，而关键字分布又比较均匀的查找表来说，插值查找算法的平均性能比折半查找要好的多。反之，数组中如果分布非常不均匀，那么插值查找未必是很合适的选择
 *
 *  时间复杂度：
        O(log2(log2n))
    空间复杂度：
        O(1)
 * */

/*
 * 插值查找:
 *基本思想：基于二分查找算法，将查找点的选择改进为自适应选择，可以提高查找效率。
 * mid=low+(key-a[low])/(a[high]-a[low])*(high-low)，
 * */

int InsertSearch(int* array,int length,int search_key){
    if(nullptr==array or length<=0){
        return -1;
    }
    int low,high,mid;
    low = 0;
    high = length -1;
    while (low<=high){
        mid = low+(search_key-array[low])/(array[high]-array[low])*(high-low);
//        mid = (high+low)/2;
        std::cout<<mid<<std::endl;
        if(search_key == array[mid]) return mid;
        else if(array[mid]>search_key){
            high = mid -1;
        }
        else if(array[mid]<search_key){
            low = mid+1;
        }
    }
    return -1;
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
    std::cout<<"Insert Search Algorithm"<<std::endl;
    int checkResArray[]={15,20,23,30,43,321,443,555,111111};
    size_t arrayLength=sizeof(checkResArray)/sizeof(int);
    int search_key = 23;
    std::cout<<"Src Array:";
    PrintArrayValue(checkResArray,arrayLength);

    int search_index = InsertSearch(checkResArray,arrayLength,search_key);
    std::cout<<"search key = "<<search_key<<",and seach index res = "<<search_index<<std::endl;

//    getchar();
    return 0;
}