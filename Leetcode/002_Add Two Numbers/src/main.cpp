#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p_res = new ListNode(0);      //要标记链表头部
        ListNode *p = l1, *q = l2, *curr = p_res;  //标记l1,l2,以及最终返回结果的当前位置（因为每次都会更新当前位置以往下一个位置前进）
        int carry = 0;
        while (p != nullptr || q != nullptr) {
            int x = (p != nullptr) ? p->val : 0;    //只要链表不为空，去取节点的值，为空则取0
            int y = (q != nullptr) ? q->val : 0;
            int sum = carry + x + y;                //求对应两个节点的和
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);//注意进位，因为题目要求，每位只能保存1位数
            curr = curr->next;                     //注意更新  两个链表下一次待处理的位置，以及返回结果下一次保存数据的位置
            if (p != nullptr) p = p->next;
            if (q != nullptr) q = q->next;
            if(p!= nullptr or q!= nullptr){

            }
        }
        if (carry > 0) {                           //当两个链表执行到最后且进位大于1时，要额外申请一个节点
            curr->next = new ListNode(carry);
        }
        return p_res->next;                        //由于初始化的时候表头为空，因此这里返回的因为是标记表头的next
    }
};

void printListNode(const ListNode* l){
    while(l!=nullptr){
        cout<<l->val<<" ->";
        l = l->next;
    }
    cout<<endl;
}

int main(int argc,char * argv[]){
    ListNode* l1 = new ListNode(2);
    ListNode* l1_1 = new ListNode(4);
    ListNode* l1_2 = new ListNode(3);
    l1_1->next = l1_2;
    l1->next = l1_1;

    ListNode* l2 = new ListNode(5);
    ListNode* l2_1 = new ListNode(6);
    ListNode* l2_2 = new ListNode(7);
    l2_1->next = l2_2;
    l2->next = l2_1;

    Solution obj = Solution();
    ListNode* p_res = obj.addTwoNumbers(l1,l2);
    printListNode(l1);
    printListNode(l2);
    printListNode(p_res);

    return 0;
}