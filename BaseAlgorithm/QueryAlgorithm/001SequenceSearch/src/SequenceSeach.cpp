#include <iostream>
/*
 * 顺序查找：
 *      顺序查找也称为线形查找，属于无序查找算法。从数据结构线性表的一端开始，顺序扫描，依次将扫描到的结点关键字与给定值k相比较，
 *          若相等则表示查找成功；若扫描结束仍没有找到关键字等于k的结点，表示查找失败。
 *      适合于存储结构为顺序存储或链接存储的线性表
 *  时间复杂度：
        O(n)
    空间复杂度：
        O(1)
 * */

/*
 * 顺序查找:
 * 从数据结构线性表的一端开始，顺序扫描，依次将扫描到的结点关键字与给定值k相比较，若相等则表示查找成功；若扫描结束仍没有找到，表示查找失败。
 * */
int SequenceSearch(int* array,int length,int search_key){
    if(nullptr==array or length<=0){
        return -1;
    }
    for(int i =0;i<=length-1;i++){
        if (search_key == array[i]) {
            return i;
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
    std::cout<<"Sequence Search Algorithm"<<std::endl;
    int checkResArray[]={42,20,17,13,28,14,23,15};
    size_t arrayLength=sizeof(checkResArray)/sizeof(int);
    int search_key = 15;
    std::cout<<"Src Array:";
    PrintArrayValue(checkResArray,arrayLength);

    int search_index = SequenceSearch(checkResArray,arrayLength,search_key);
    std::cout<<"search key = "<<search_key<<",and seach index res = "<<search_index<<std::endl;
//    getchar();
    return 0;
}