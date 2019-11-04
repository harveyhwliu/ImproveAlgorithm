#include <iostream>
#include <memory>
/*
 * Fibonacci 查找：
        基本思想：也是二分查找的一种提升算法，通过运用黄金比例的概念在数列中选择查找点进行查找，提高查找效率。
        同样地，斐波那契查找也属于一种有序查找算法。

 *  时间复杂度：
        O(log2(n))
    空间复杂度：
        要求开始表中记录的个数为某个斐波那契数，及length=F(k)-1;  O(F(k)-1)
 * */

/*
 *Fibonacci 查找:
    斐波那契查找与折半查找很相似，他是根据斐波那契序列的特点对有序表进行分割的。
    他要求开始表中记录的个数为某个斐波那契数，及n=F(k)-1;
    开始将k值与第F(k-1)位置的记录进行比较(及mid=low+F(k-1)-1),比较结果也分为三种

　　1）相等，mid位置的元素即为所求
　　2）>，low=mid+1,k-=2;
　　  说明：low=mid+1说明待查找的元素在[mid+1,high]范围内，
            k-=2 说明范围[mid+1,high]内的元素个数为n-(F(k-1))= Fk-1-F(k-1)=Fk-F(k-1)-1=F(k-2)-1个，所以可以递归的应用斐波那契查找。
　　3）<，high=mid-1,k-=1。
　　  说明：low=mid-1说明待查找的元素在[low,mid-1]范围内
        k-=1 说明范围[low,mid-1]内的元素个数为F(k-1)-1个，所以可以递归 的应用斐波那契查找
 * */

/*
 * 构造一个斐波那契数组,长度为n_lenght
 * */
void Fibonacci(int * F,int n_length)
{
    F[0]=0;
    F[1]=1;
    for(int i=2;i<n_length;++i)
        F[i]=F[i-1]+F[i-2];
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

int FibonacciSearch(int* array,int length,int search_key){
    if(nullptr==array or length<=0){
        return -1;
    }
    int low,high,mid;
    low = 0;
    high = length -1;
    int Fibonacci_array[length];
    Fibonacci(Fibonacci_array,length);

    int k = 0;  //计算length位于斐波那契数列的位置
    while(length>Fibonacci_array[k]-1)
        k++;

    int  *temp;//将数组a扩展到F[k]-1的长度
    temp=new int [Fibonacci_array[k]-1];
    memcpy(temp,array,length*sizeof(int));

    for(int i=length;i<Fibonacci_array[k]-1;++i)//将原查找表扩展为长度为F[n](如果要补充元素，则补充重复最后一个元素，直到满足F[n]个元素)
        temp[i]=array[length-1];

    while(low<=high)
    {
        mid=low+Fibonacci_array[k-1]-1;   //优点是它只涉及加法和减法运算，而不用除法
        if(search_key<temp[mid]){
            high=mid-1;
            k-=1;
        }
        else if(search_key>temp[mid]){
            low=mid+1;
            k-=2;
        }
        else{
            if(mid<=length-1)
                return mid; //若相等则说明mid即为查找到的位置
            else
                return length-1; //若mid>=n则说明是扩展的数值,返回n-1
        }
    }
    delete [] temp;
    return -1;
}

int main(int argc,char * argv[]){
    std::cout<<"Fibonacci Search Algorithm"<<std::endl;
    int checkResArray[]={15,20,23,30,43,321,443,555,111111};
    size_t arrayLength=sizeof(checkResArray)/sizeof(int);
    int search_key = 111111;
    std::cout<<"Src Array:";
    PrintArrayValue(checkResArray,arrayLength);

    int search_index = FibonacciSearch(checkResArray,arrayLength,search_key);
    std::cout<<"search key = "<<search_key<<",and seach index res = "<<search_index<<std::endl;

//    getchar();
    return 0;
}