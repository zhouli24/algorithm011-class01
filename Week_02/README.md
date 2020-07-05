学习笔记
堆
理论：
1、JAVA的PriorityQueue底层就是采用堆排序实现，队列首元素为最小值（小顶堆）。
2、​采用Java的PriorityQueue，可以自己定义大顶堆或者小顶堆，使用PriorityQueue​(Comparator<? super E> comparator)
构造函数可以实现。

实践：
1、leetcode 347. 前 K 个高频元素一题， 可以先对各个元素的频次进行统计（采用HashMap数据结构），统计完后，构造一个大顶堆的PriorityQueue，这样队列
中最大的元素，前K个高频就连续出K次队列首元素即可。

2、leetcode 剑指 Offer 59 - I. 滑动窗口的最大值。第一种解法，采用Heap，构造一个堆，堆的大小就是滑动窗口长度，采用大顶堆。算法从0开始循环，先去除上个滑动
窗口的第一个元素，然后加入当前滑动窗口需要新加入的元素，堆会自动调整，此时首元素即是当前窗口的最大值。后面每重复一次，堆就会自动调整。循环执行nums.length-k。
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums.length == 0) {
            int[] result = new int[0];
            return result;
        }
        PriorityQueue <Integer> heap = new PriorityQueue​<>((a, b)->(b.intValue()-a.intValue()));

        for(int i=0; i<k; ++i) {
            heap.add(nums[i]);
        }

        int[] result = new int[nums.length-k+1];
        result[0] = heap.peek();
        int j=1;
        for (int i=0; i<nums.length-k; ++i) {
            heap.remove(nums[i]);
            heap.add(nums[i+k]);
            result[j++] = heap.peek();
        }

        return result;
    }
}
此算法的时间复杂度并不好。leetcode 239. 滑动窗口最大值这题，题目完全一样，堆算法就无法通过。采用如下双指针的算法即可通过：

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int *result;
    int curMax;
    int m=1;
    
    if ((nums==NULL) || (numsSize==0)) {
        *returnSize = 0;
        return NULL;
    } 
    result = (int *)malloc((numsSize - k + 1) * sizeof(int));

    curMax = nums[0];

    for (int i=1; i<k; ++i) {
        if (nums[i] > curMax) {
            curMax = nums[i];
        }
    }
    result[0] = curMax;
    for(int i=1; i+k<=numsSize; i++) {
        if (nums[i-1] < curMax) {
            if (curMax < nums[i+k-1]) {
                curMax = nums[i+k-1];
            }
        } else {
            if (curMax < nums[i+k-1]) {
                curMax = nums[i+k-1];
            } else {
                curMax = nums[i];
                for (int j=i+1; j<i+k; ++j) {
                    if (nums[j] > curMax) {
                        curMax = nums[j];
                    }
                } 
            }
        }
        result[m++] = curMax;
    }
    *returnSize = m;
    return result;
}

2种方法，第一种的时间复杂度 O（n^2logn），第2种方法（O(n^2)）.

HashMap:
1、常用接口：
1)、增加元素：public V put​(K key, V value)
2)、获取某个key对应的值；public V get​(Object key)
3)、判断是否存在某个key：public boolean containsKey​(Object key)

2、实现：
1)put-->
	putVal(int hash, K key, V value, boolean onlyIfAbsent,boolean evict) 用hash(key)做索引，在hash桶，寻找对应位置，没有出现hash碰撞的时候，
	直接新建添加节点。出现hash碰撞，需要区分树和链表处理，在对应的桶里往后遍历，出现key相等时直接退出遍历；或者返回一个插入的位置，防止新增节点。
	
	
2)get-->
	final Node<K,V> getNode(int hash, Object key) 用key的hash值，去遍历hash桶，如果是桶节点直接返回；否则遍历每个hash(key)对应的hash链表查找该节点。

3)containsKey->
	final Node<K,V> getNode(int hash, Object key) 与2)中实现基本一致，存在节点返回非空即为true;反之找不到返回空，则为false。