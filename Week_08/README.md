学习笔记

冒泡排序：
public void bubble(int [] nums) {
	int len = nums.length;
	int temp;
	for (int i=0; i<len-1; i++) {
		for (int j=0; j<len-i-1; j++) {
			if (nums[j] > nums[j+1]) {
				temp = nums[j+1];
				nums[j+1] = nums[j];
				nums[j] = temp;
			}
		}
	}

}

选择排序：
public void selection(int [] nums) {
	int len = nums.length;
	int minId, temp;

	for (int i=0; i<len-1; i++) {
		minId = i;
		for (int j=i+1; j<len; j++) {
			if (nums[minId] > nums[j]) {
				minId = j;
			}
		}
		/* swap */
		temp = nums[i];
		nums[i] = nums[minId];
		nums[minId] = temp;
	}
}

插入排序：
public void insertion(int [] nums) {
	int len = nums.length;
	int curVal;

	for (int i = 0; i< len-1; i++) {
		int j = i+1;
		curVal = nums[j];
		while (j>=1 && (curVal < nums[j-1])) {
		   nums[j] = nums[j-1];
		   j--;
		}
		nums[j] = curVal;
	}
}
