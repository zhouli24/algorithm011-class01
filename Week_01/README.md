leetcode编程题：
删除排序数组中的重复项
移动零
设计循环双端队列

学习小结：
用 add first 或 add last 这套新的 API 改写 Deque 的代码：
import java.util.*;
public class MyNewDeque {
    public static void main(String[] args) {
        Deque<String> deque = new LinkedList<String>();

        deque.addFirst("a");
        deque.addFirst("b");
        deque.addFirst("c");
        System.out.println(deque);

        String str =deque.getFirst();
        System.out.println(str);
        System.out.println(deque);

        while (deque.size()>0) {
            System.out.println(deque.removeFirst());
        }
        System.out.println(deque);
    }
}


PriorityQueue:
1、PriorityQueue是一个类，继承AbstractQueue类
2、用数组实现了一个小顶堆
3、PriorityQueue，添加或者删除一个元素的时候，都需要对堆进行调整，调bubbleUp方法调整。
4、add​，offer	添加元素;时间复杂度O(logN)
poll()	获取并删除队首元素;时间复杂度O(N)
remove(Object o)	删除指定元素;时间复杂度O(N)
peek	访问队首元素，但不删除;时间复杂度O(1)
