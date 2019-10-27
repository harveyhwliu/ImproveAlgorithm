#include <iostream>
/*
 * 堆排序： 不稳定的排序，堆分为大根堆和小根堆，是完全二叉树。大顶堆：在堆排序算法中用于升序排列；小顶堆：在堆排序算法中用于降序排列；
 *      堆排序的思想借助于二叉堆中的最大堆得以实现。首先，将待排序数列抽象为二叉树，并构造出最大堆；
 *      然后，依次将最大元素（即根节点元素）与待排序数列的最后一个元素交换（即二叉树最深层最右边的叶子结点元素）；
 *      每次遍历，刷新最后一个元素的位置（自减1），直至其与首元素相交，即完成排序。
 *
 *          最大堆要求节点的元素都要不小于其孩子，最小堆要求节点元素都不大于其左右孩子，那么处于最大堆的根节点的元素一定是这个堆中的最大值
     *          完全二叉树： 除了最后一层之外的其他每一层都被完全填充，并且所有结点都保持向左对齐。
     *              完全二叉树有个特性：左边子节点位置 = 当前父节点的两倍 + 1，右边子节点位置 = 当前父节点的两倍 + 2
                满二叉树：除了叶子结点之外的每一个结点都有两个孩子，每一层(当然包含最后一层)都被完全填充。
                完满二叉树：除了叶子结点之外的每一个结点都有两个孩子结点。
 *  时间复杂度：
        平均时间复杂度：O(NlogN)
    空间复杂度：

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
 * 最小堆排序
 * 从i节点开始调整,n为节点总数 从0开始计算 i节点的子节点为 2*i+1, 2*i+2
 * */
void MinHeapSort(int *array,int i,int n){
    int j = 2*i +1; //J表示是左孩子节点，i表示的是当前的父节点
    while(j<n){
        if(j+1<n && array[j+1]<array[j]){  //找到孩子节点中最大的哪那个值
            j++;
        }
        if(array[i]<=array[j]){            //父节点必须小于孩子节点，否则不满足最小堆的特点
            break;
        }
        ArraySwapValue(array,i,j);         //如果孩子节点值大于父节点，则需要交互两者
        i = j;                             //更新父节点和孩子节点的索引，并将孩子节点以下的看是否需要调整
        j = 2*i+1;
    }
}
/*
 * 最大堆排序
 * 从i节点开始调整,n为节点总数 从0开始计算 i节点的子节点为 2*i+1, 2*i+2
 * */
void MaxHeapSort(int *array,int i,int n){
    int j = 2*i +1; //J表示是左孩子节点，i表示的是当前的父节点
    while(j<n){
        if(j+1<n && array[j+1]>array[j]){  //找到孩子节点中最大的哪那个值
            j++;
        }
        if(array[i]>=array[j]){            //父节点必须大于孩子节点，否则不满足最大堆的特点
            break;
        }
        ArraySwapValue(array,i,j);         //如果孩子节点值大于父节点，则需要交互两者
        i = j;                             //更新父节点和孩子节点的索引，并将孩子节点以下的看是否需要调整
        j = 2*i+1;
    }
}
/*
 * 创建最小堆
 * 利用特性 父节点索引和左孩子节点索引的关系是 左孩子索引= 2*父节点索引+1
 * 找到最后一个结点，从它的父节点开始调整。根据性质，小的数字往上移动；
 * */
void CreateMinHeap(int* array,int array_lengh){
    for(int i=(array_lengh-1)/2;i>=0;i--){//从下往上构造树
        MinHeapSort(array,i,array_lengh);
    }
}

/*
 * 创建最大堆
 * 利用特性 父节点索引和左孩子节点索引的关系是 左孩子索引= 2*父节点索引+1
 * 找到最后一个结点，从它的父节点开始调整。根据性质，大的数字往上移动；
 * */
void CreateMaxHeap(int* array,int array_lengh){
    for(int i=(array_lengh-1)/2;i>=0;i--){//从下往上构造树
        MaxHeapSort(array,i,array_lengh);
    }
}

/*
 *最小堆排序，降序
 * */
void MinHeapSort(int* array,int array_lengh){
    CreateMinHeap(array,array_lengh);       //创建小堆
    for(int i=array_lengh-1;i>0;i--){       //降序排列，每次从堆顶取出一个最小值
        ArraySwapValue(array,0,i);        //将待排序的元素（最后一个值）与第一个元素替换（最小值），因此得到降序排序
        MinHeapSort(array,0,i);
    }
}

/*
 * 最大堆排序，升序
 * */
void MaxHeapSort(int* array,int array_length){
    CreateMaxHeap(array,array_length);      //创建最大堆
    for(int i=array_length-1;i>0;i--){       //升序排列，每次从堆顶取出一个最大值
        ArraySwapValue(array,0,i);        //将待排序的元素（最后一个值）与第一个元素替换（最大值），因此得到升序排序
        MaxHeapSort(array,0,i);
    }
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
    std::cout<<"Heap Sort Algorithm"<<std::endl;
    int checkResArray[]={42,20,17,13,28,14,23,15};
    size_t arrayLength=sizeof(checkResArray)/sizeof(int);
    std::cout<<"Src Array:"<<std::endl;
    PrintArrayValue(checkResArray,arrayLength);

    std::cout<<"After Sorting:"<<std::endl;
//    MinHeapSort(checkResArray,arrayLength);
    MaxHeapSort(checkResArray,arrayLength);
    PrintArrayValue(checkResArray,arrayLength);
//    getchar();
    return 0;
}