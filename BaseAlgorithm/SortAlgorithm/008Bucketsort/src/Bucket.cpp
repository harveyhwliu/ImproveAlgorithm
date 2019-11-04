#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
/*
 *  桶排序：
 *      先将数组分到有限个桶（每个桶都是链表）中，再对每个桶中的数据进行排序，可以说是鸽巢排序的一种归纳结果（对每个桶中数据的排序可以是桶排序的递归，或其他算法，在桶中数据较少的时候用插入排序最为理想）
 *  时间复杂度：对桶内数据的排序，时间复杂度为∑ O(Ni*logNi) ，其中Ni 为第i个桶的数据量。
　　对于N个待排数据，M个桶，平均每个桶[N/M]个数据的桶排序平均时间复杂度为：O(N)+O(M*(N/M)*log(N/M))=O(N+N*(logN-logM))=O(N+N*logN-N*logM)，当N=M时，即极限情况下每个桶只有一个数据时。桶排序的最好效率能够达到O(N)。
　　对于相同数量的数据，桶的数量越多，数据分散得越平均，桶排序的效率越高，可以说，桶排序的效率是空间的牺牲换来的

    平均时间复杂度：O(n + k)
    最佳时间复杂度：O(n + k)
    最差时间复杂度：O(n ^ 2)
    空间复杂度：O(n * k)
    稳定性：稳定
 * */

const int BUCKET_NUM = 10;              //最大的桶的数量

//定义节点
struct ListNode{
    explicit ListNode(int i=0):m_data(i),m_pNext(nullptr){}
    ListNode* m_pNext;
    int m_data;
};

//链表插入
ListNode* insert(ListNode* head,int val){
    ListNode dummyNode;                     //待返回的结果
    ListNode *newNode = new ListNode(val);  //构造的节点，待插入到合适的桶的链表中
    ListNode *pre,*curr;
    dummyNode.m_pNext = head;
    pre = &dummyNode;
    curr = head;
    while(nullptr!=curr && curr->m_data<=val){ //从桶中链表中找到第一比该数据小的值，并插入到该数据的前面（为了最后结果是升序）
        pre = curr;
        curr = curr->m_pNext;
    }
    newNode->m_pNext = curr;
    pre->m_pNext = newNode;
    return dummyNode.m_pNext;
}
//将两个链表的数据合并
ListNode* Merge(ListNode *head1,ListNode *head2){
    ListNode dummyNode;
    ListNode *dummy = &dummyNode;
    while(nullptr!=head1 && nullptr!=head2){
        if(head1->m_data <= head2->m_data){
            dummy->m_pNext = head1;
            head1 = head1->m_pNext;
        }else{
            dummy->m_pNext = head2;
            head2 = head2->m_pNext;
        }
        dummy = dummy->m_pNext;
    }
    if(nullptr!=head1) dummy->m_pNext = head1;
    if(nullptr!=head2) dummy->m_pNext = head2;

    return dummyNode.m_pNext;
}

//桶排序
void BucketSort(int* array,int array_length){
    vector<ListNode*> buckets(BUCKET_NUM,(ListNode*)(nullptr)); //创建 BUCKET_NUM  大小的桶，每个桶都是一个链表

    for(int i=0;i<array_length;++i){
        int index = array[i]/BUCKET_NUM;   //按照数字的位数来设置桶，比如个位数的数字都放到一个桶中，十几的都放到一个桶中，一次类推
        ListNode *head = buckets.at(index);//operator[]和at的主要区别在于operator[]不做边界检查，而at会做边界检查,前者异常时，不能用try catch捕获，后者则可以
        buckets.at(index) = insert(head,array[i]);
    }
    ListNode *head = buckets.at(0);
    for(int i=1;i<BUCKET_NUM;++i){         //桶排序，每个桶都是有序的，那么需要做的就是把每个桶对应的链表合并成一个，并用head存放
        head = Merge(head,buckets.at(i));
    }
    for(int i=0;i<array_length;++i){        //从桶中取出每个结果，完成排序
        array[i] = head->m_data;
        head = head->m_pNext;
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
    std::cout<<"Bucket Sort Algorithm"<<std::endl;
    int checkResArray[]={42,20,17,13,28,14,23,15};
    size_t arrayLength=sizeof(checkResArray)/sizeof(int);
    std::cout<<"Src Array:"<<std::endl;
    PrintArrayValue(checkResArray,arrayLength);

    std::cout<<"After Sorting:"<<std::endl;
    BucketSort(checkResArray,arrayLength);
    PrintArrayValue(checkResArray,arrayLength);
//    getchar();
    return 0;
}