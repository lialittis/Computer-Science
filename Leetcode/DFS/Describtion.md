# DFS 

Depth First Search

```
result = []
def backtrack(path, options):
    if condition is sat:
        result.add(path);
        return
    for choice in options:
        make choice
        backtrack(path, options);
        withdraw the choice
```

* 剪枝与优化的原则

1. 正确性 不丢失最优解

2. 准确性

3. 高效性 减少搜索次数，减少程序运行时间

* 一般入手点

1. 优化搜索顺序
可以优先通过对子问题分支进行分析（可以考虑先从大的task进行）

2. 排除冗余信息
对限制条件进行分析

3. 可行性剪枝
对显然不包含目标状态的搜索方向及时停止搜索

4. 最优性剪枝
每次搜索完后更新当前最优解

5. 记忆化搜索

* 普通的DFS - 优化

1. sort 倒序，task先做大的，可以积累时间先达到终止条件
2. global的result，如果我们求最小值，当过程中出现已经大于res的时候我们就直接停止
3. 跳过重复的元素
4. 改变搜索思路，遍历task或者遍历worker可以大幅提升速度

## permutations II - 47

Given a collection of numbers, nums, that might contain duplicates, return all
possible unique permutations in any order.

### example

Inputs : nums = [1,1,2]

Output : [[1,1,2],[1,2,1],[2,1,1]]

### implementation

```
sort nums
res = {}
backtrack :
    i start from 0
    for all positions as k of nums:
        if k = i, or nums[i] == nums[k] continue
        else swap nums[i] and nums[k]
        backtrack(i+1)
    when i == nums.size()-1:
        add nums to res
```
## find minimum time to finish all jobs

### implementation

keys : sort ; assign from the biggest ; prune

prunes : sort ; too large value ; redundant steps (same tasks for different workers)


## minimum number of work sessions to finish the tasks

n tasks,

## conclusion

剪枝的题目也可以用二分法或状态压缩dp来做。

常见剪枝方法 ： 
1. sort倒序
2. global的result更新
3. 跳过重复元素
4. 改变搜索思路，单向遍历较多的task可以大幅提升速度。一般大的数据单向遍历，小的数据增加backtracking的遍历。


### 模板流程

```
int res
public min{
    sort;
    dfs;
    return res;
}

private dfs{
    if() return; // global
    if() return; //
    for(){ // 常规backtracking；尝试较小部分
        if() continue; // 重复
        +=
        dfs
        -=
    }
}
```

## 类似题目

1125

1434

