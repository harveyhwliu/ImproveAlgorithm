#include <iostream>
/*
 * 希尔排序： 增量递减排序算法，是插入算法的一种更高效的改进版本。
 *          充分插入算法在数据基本有序的时候效率接近线性的特点
 *
 *  时间复杂度：
        O(n^2)
    空间复杂度：
        O(1)

    选择排序非稳定排序（插入排序是稳定的，但希尔排序是分组的插入排序，因此不是稳定的）
 * */


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

/*
 * 插入排序，每次从待排序的数中选择第一个，插入到已经排序的区域的合适的位置
 * 优化方法是
 * */
int ShellSort(int* array,int length){
    if(nullptr==array or length<=1){
        return -1;
    }
    for(int gap = length/2;gap>0;gap/=2){       //增量递减，每个增量内其实就是插入排序
        for(int i =gap;i<length;i++){           //一个增量周期内
            int j = i-gap;                      //用来标记第几组，每组的个数是gap个
            int temp_value = array[i];          //每个组的最后一个数据
			for(;j>=0&&temp_value<array[j];j-=gap){//每个组中，采用插入排序，从后往前判断每个位置应该的数据
			    array[j+gap] = array[j];
			}
			array[j+gap] = temp_value;           //一个增量周期内，i的位置
//            PrintArrayValue(array,length);
        }
    }
    return 0;
}

int main(int argc,char * argv[]){
    std::cout<<"Shell Sort Algorithm"<<std::endl;
    int checkResArray[]={42,20,17,13,28,14,23,15};
    size_t arrayLength=sizeof(checkResArray)/sizeof(int);
    std::cout<<"Src Array:"<<std::endl;
    PrintArrayValue(checkResArray,arrayLength);

    std::cout<<"After Sorting:"<<std::endl;
	ShellSort(checkResArray,arrayLength);
    PrintArrayValue(checkResArray,arrayLength);


    return 0;
}