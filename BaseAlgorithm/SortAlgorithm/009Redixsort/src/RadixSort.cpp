#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
/*
 *  基数排序：是在桶排序的基础上发展而来的，两种排序都是分配排序的高级实现。
 *      分配排序(Distributive Sort)的基本思想：排序过程无须比较关键字，而是通过“分配”和“收集”过程来实现排序。它们的时间复杂度可达到线性阶：O(n)。
 *      但桶排序的缺点是：首先是空间复杂度比较高，需要的额外开销大。排序有两个数组的空间开销，一个存放待排序数组，一个就是所谓的桶，
 *          比如待排序值是从0到m-1，那就需要m个桶，这个桶数组就要至少m个空间。其次待排序的元素都要在一定的范围内等等。
        基数排序是对桶排序的一种改进，这种改进是让“桶排序”适合于更大的元素值集合的情况，而不是提高性能。
        其原理是将整数按位数切割成不同的数字，然后按每个位数分别比较。由于整数也可以表达字符串（比如名字或日期）和特定格式的浮点数，所以基数排序也不是只能使用于整数。
 *
 * */

/*
 * 求数组中的最大值
 * */
int getArrayMaxValue(const int* array,int array_length){
    int max = array[0];
    for(int i=0;i<array_length;i++){
        if(array[i]>max){
            max = array[i];
        }
    }
    return max;
}
/*
 * 求一个整数是几位数
 * */
int getNumBitCounts(int num){
    int bitCount = 0;
    while(num>0){
        num /= 10;
        bitCount++;
    }
    return bitCount;
}
void RadixSort(int* array,int array_length){
    int max = getArrayMaxValue(array,array_length);
    int bitCount = getNumBitCounts(max);

    int *tmp = new int[array_length];           //桶的个数
    int *count = new int[10];                   //计数器
    int i, j, k;
    int radix = 1;
    for(i = 1; i <= bitCount; i++)              //进行 bitCount 次 排序
    {
        for(j = 0; j < 10; j++)
            count[j] = 0;
        for(j = 0; j < array_length; j++)
        {
            k = (array[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
        for(j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶

        for(j = array_length - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
        {
            k = (array[j] / radix) % 10;
            tmp[count[k] - 1] = array[j];
            count[k]--;
        }

        for(j = 0; j < array_length; j++) //将临时数组的内容复制到data中
            array[j] = tmp[j];
        radix = radix * 10;
    }
    delete []tmp;
    delete []count;
}

void PrintArrayValue(int *array,int length){
    if(nullptr == array || length<=0){
        std::cout<<"数组异常，无法打印"<<std::endl;
        return;
    }
    for(int i = 0;i<length;i++){
        std::cout<<array[i]<<"  ";
    }
    std::cout<<std::endl;
}

int main(int argc,char * argv[]){
    std::cout<<"Radix Sort Algorithm"<<std::endl;
    int checkResArray[]={42,20,17,13,28,14,23,15};
    size_t arrayLength=sizeof(checkResArray)/sizeof(int);
    std::cout<<"Src Array:"<<std::endl;
    PrintArrayValue(checkResArray,arrayLength);

    std::cout<<"After Sorting:"<<std::endl;
    RadixSort(checkResArray,arrayLength);
    PrintArrayValue(checkResArray,arrayLength);
//    getchar();
    return 0;
}