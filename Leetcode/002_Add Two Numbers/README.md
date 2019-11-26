
## Add Two Numbers    

  ### 题目：
  
   给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
   如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
   
     您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
     示例:
        输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
        输出：7 -> 0 -> 8
        原因：342 + 465 = 807

  ### 方法：
  1）遍历两个链表，只要两个链表都不为空，则取出对应的每个节点的元素（如果其中某个链表为空则对应节点值为0）  
  2）然后计算对应的节点之、以及上一次的进位的和，并把和值得高位保存在进位变量中，低位保存到待返回结果链表的对应节点上  
  3）当两个链表都为空，则看进位，如果进位值>0, 则新申请一个结果节点，保存该进位值
  4）注意：最终返回结果时的，应该返回 待返回结果链表的表头，而不是步骤3）或者步骤2）得到的待返回结果链表的尾
  
  
  #### 复杂度分析：
   时间复杂度：  O（n+m）
   空间复杂度：  O(n+m)

### 用python实现的代码示例：
   ````python
    class ListNode(object):
        def __init__(self, x):
            self.val = x
            self.next = None
    
    class Solution(object):
        def addTwoNumbers(self, l1, l2):
            """
            :type l1: ListNode
            :type l2: ListNode
            :rtype: ListNode
            """
            res = ListNode(0)
            cur = res
            carray = 0
            while l1 or l2:
                if l1 and l2:#如果连个链表都有节点，则取两个节点和进位一起计算和
                    _t = carray + l1.val +l2.val
                    l1 = l1.next
                    l2 = l2.next
                elif l1:    #否则，仅考虑当前节点 和进位 的和
                    _t = carray + l1.val
                    l1 = l1.next
                else:
                    _t = carray +l2.val
                    l2 = l2.next
    
                carray,val = divmod(_t,10)  #获取和的  高位  和   低位 
                cur.next = ListNode(val)    #申请一个结果节点，保存低位
                cur = cur.next
                
            if carray:                      #当计算完成后，如果还有进位，则需要额外申请节点来保存
                cur.next = ListNode(carray)
            return res.next
```


