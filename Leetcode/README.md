
## 001Two sum  -- 数组
   题目：给定一个序列nums和一个和Sum，找出序列中任意两个元素相加等于该和值Sum的对一个的下标序列。<br/>
   解法：<br/>
     -  遍历数组,若当前下标 i1 满足，则Sum-nums[ i1 ]一定也在nums里面，因此返回[ i1, nums[ i1 + 1: ].index(Sum - nums[ i1 ])]即可<br/>
     -  遍历数组，构建 缓存（map<int,int>）,如果当前遍历的下标 i1 满足条件，则Sums-nums[ i1 ]一定也在map中，否则缓存更新map[ nums[ i1 ] ] = i1, 最终返回[ i1, map[Sum - nums[ i1 ]]]<br/>




