学习笔记

回溯算法总结，这篇文章写的很好：
参考https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-xiang-jie-by-labuladong-2/

回溯算法其实也是一种递归

牢记上面链接给出的回溯算法模板：
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
		
某些题目需要剔除一些结果，这时就需要进行剪枝操作，模板跟上述可以一样
牢记上面链接给出的回溯算法模板：
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择（做剪枝）
        backtrack(路径, 选择列表)
        撤销选择
		
实际操作分析：		
77组合：https://leetcode-cn.com/problems/combinations/
按回溯算法模板往里面填代码：
public void backtrace(LinkedList<Integer> track, int num, int depth) {
	/* 退出条件 */
	if (track.size() == depth) {
		/* 加入结果 */
		res.add(new LinkedList(track));
		return;
	}

	/* 从选择列表，选路 */
	for(int i=1; i<=num; ++i) {
		/* 剔除错误路径 */
		if (track.contains(i)) {
			continue;
		} 

		/* 加入路径 */
		track.addLast(i);
		backtrace(track, num, depth);
		/* 回退 */
		track.removeLast();
	}
}
输出：[[1,2],[1,3],[1,4],[2,1],[2,3],[2,4],[3,1],[3,2],[3,4],[4,1],[4,2],[4,3]]
此时结果会有重复的结果，如[1,2] [2,1]这种相同数字顺序换了的。

所以要对结果进行剪枝。因为选择列表本身是有序的，最笨的就是，新加入的数据要大于已选入的数据所以，在加入路径前又加了个剪枝的判断：
/* 剪枝 */
if (track.size() != 0 && i < track.peekLast()) {
	continue;
}
此时就可以得到想要的结果。

最后总结，算法题很多很难，技巧性的掌握不了，但是有一点要记住，牢记常用算法模板，随手可写，实际需要时往里填代码即可。