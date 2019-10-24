#include <iostream>
/*
 * 插入排序： 将一个数组分为2类区域，一类是已排序的，一类是待排序的，每次从待排序的中拿出第一个元素，插入到有序区域中的合适位置
 * 			在要排序的一组数中，假定前n-1个数已经排好序，现在将第n个数插到前面的有序数列中，使得这n个数也是排好顺序的。如此反复循环，直到全部排好顺序
 *
 *  时间复杂度：
        O(n^2)
    空间复杂度：
        O(1)

    选择排序是稳定排序
 * */

/*
 * 数组中交换指定两个位置的数据
 * */
void ArraySwapValue(int* array,int i,int j)
{
    int temp;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
/*
 * 插入排序，每次从待排序的数中选择第一个，插入到已经排序的区域的合适的位置
 * 优化方法是
 * */
int InsertSort(int* array,int length){
    if(nullptr==array or length<=1){
        return -1;
    }
    for(int i =1;i<length;i++){
        for(int j =i-1;j>=0&array[j]>array[j+1];j--){
			ArraySwapValue(array,j,j+1);
        }

    }
    return 0;
}

/*
 * 插入排序，每次从待排序的数中选择第一个，插入到已经排序的区域的合适的位置
 * 优化方法是:
 * 			上面的算法的缺点：在第i-1趟插入时，需要把第i个元素插入到前面的i-1个元素中，该算法总是从i-1个元素开始逐个比较之前的每个元素，
 * 					直到找到第i个元素的插入位置，这显然没有利用前面0~i-1个元素已经有序的特点

			优化：在0~i-1个有序元素给第i个元素寻找插入的位置时，使用二分查找法可以有效提高查找插入位置的时间效率，经过优化的插入排序称为折半插入排序

 * */
int BinaryInsertSort(int* array,int length){
	if(nullptr==array or length<=1){
		return -1;
	}
	int _index_left =0;
	int _index_right = 0;
	int _index_middle = 0;
	for(int i =1;i<length;i++){
		//采用二分查找快速找到i应该插入的位置
		_index_left = 0;
		_index_right = i-1;
		while(_index_left<=_index_right){
			_index_middle = (_index_left+_index_right)/2;
			if(array[i]>array[_index_middle]){
				_index_left = _index_middle+1;
			}else{
				_index_right = _index_middle-1;
			}
		}
		for(int j =i;j>_index_left;j--){
			ArraySwapValue(array,j,j-1);
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
    std::cout<<"Insert Sort Algorithm"<<std::endl;
    int checkResArray[]={42,20,17,13,28,14,23,15};
    size_t arrayLength=sizeof(checkResArray)/sizeof(int);
    std::cout<<"Src Array:"<<std::endl;
    PrintArrayValue(checkResArray,arrayLength);
//
//    std::cout<<"After Sorting:"<<std::endl;
//	InsertSort(checkResArray,arrayLength);
//    PrintArrayValue(checkResArray,arrayLength);



	std::cout<<"After Sorting:"<<std::endl;
	BinaryInsertSort(checkResArray,arrayLength);
	PrintArrayValue(checkResArray,arrayLength);


//    getchar();
    return 0;
}