
## 001Two sum  -- 数组
   
   题目：给定一个序列nums和一个和Sum，找出序列中任意两个元素相加等于该和值Sum的对一个的下标序列。<br/>
   
   解法：都需要遍历数组,当前遍历下标为 i ,则待查找值为t = Sums-nums[i]：<br/> 
     - 若 t 在 nums[i+1:] 里面,则返回 [i,i+1+ nums[i+1:].index(t)] <br/> 
     - 构建缓存map<int,int>，若缓存没找到num[i],则更新map[t] = i, 否则返回 [ map[num[i] ],i]<br/>

## 999DP  -- 动态规划相关题目
   题目1：最少零钱兑换<br/>
   题目2：最长上升子序列长度LIS<br/>




