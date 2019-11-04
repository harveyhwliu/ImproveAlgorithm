#include <iostream>
/*
 * 二分查找：
        元素必须是有序的，如果是无序的则要先进行排序操作。
        也称为是折半查找，属于有序查找算法。
        基本思想：用给定值k先与中间结点的关键字比较，中间结点把线形表分成两个子表，若相等则查找成功；
 *        若不相等，再根据k与该中间结点关键字的比较结果确定下一步查找哪个子表，这样递归进行，直到查找到或查找结束发现表中没有这样的结点。
 *      折半查找的前提条件是需要有序表顺序存储，对于静态查找表，一次排序后不再变化，折半查找能得到不错的效率。
 *      但对于需要频繁执行插入或删除操作的数据集来说，维护有序的排序会带来不小的工作量，那就不建议使用。
 *
 *  时间复杂度：
        O(log2n)
    空间复杂度：
        O(1)
 * */

/*
 * 二分查找:
 *基本思想：用给定值k先与中间结点的关键字比较，中间结点把线形表分成两个子表，若相等则查找成功；
 *        若不相等，再根据k与该中间结点关键字的比较结果确定下一步查找哪个子表，这样递归进行，直到查找到或查找结束发现表中没有这样的结点。
 * */


int BinarySearch1(int* array,int length,int search_key){
    if(nullptr==array or length<=0){
        return -1;
    }
    int low,high,mid;
    low = 0;
    high = length -1;
    while (low<=high){
        mid = (low+high)/2;
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

//二分查找，递归版本
int BinarySearch2(int array[],int search_key,int low,int high)
{
    if(nullptr==array or high<low or high<0){
        return -1;
    }
    int mid = (low+high)/2;
    if(array[mid]==search_key)
        return mid;
    else if(array[mid]>search_key)
        return BinarySearch2(array, search_key, low, mid-1);
    else if(array[mid]<search_key)
        return BinarySearch2(array, search_key, mid+1, high);
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
    std::cout<<"Binary Search Algorithm"<<std::endl;
    int checkResArray[]={15,20,23,30,43,321,443,555};
    size_t arrayLength=sizeof(checkResArray)/sizeof(int);
    int search_key = 23;
    std::cout<<"Src Array:";
    PrintArrayValue(checkResArray,arrayLength);

    int search_index = BinarySearch1(checkResArray,arrayLength,search_key);
    std::cout<<"search key = "<<search_key<<",and seach index res = "<<search_index<<std::endl;

    search_index = BinarySearch2(checkResArray,search_key,0,arrayLength-1);
    std::cout<<"search key = "<<search_key<<",and seach index res = "<<search_index<<std::endl;

//    getchar();
    return 0;
}