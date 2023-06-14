
## 总结做题的技巧

### 子数组问题 

#### 解题思路1：**数组前缀和 + HashMap**

- 题目和题解：
  - 523.连续的子数组和 ==> [题目](https://leetcode.cn/problems/continuous-subarray-sum/), [题解](https://github.com/xiewende/CPlusPlus_Algorithm/blob/main/array/five-two-three.cpp)
  - 525.连续数组 ==> [题目](https://leetcode.cn/problems/contiguous-array/), [题解](https://github.com/xiewende/CPlusPlus_Algorithm/blob/main/array/five-two-five.cpp)
  - 560.和为k的子数组 ==> [题目](https://leetcode.cn/problems/subarray-sum-equals-k/), [题解](https://github.com/xiewende/CPlusPlus_Algorithm/blob/main/array/five-six-zero.cpp)
  - 974.使数组和能被 K 整除 ==> [题目](https://leetcode.cn/problems/subarray-sums-divisible-by-k/), [解题](https://github.com/xiewende/CPlusPlus_Algorithm/blob/main/array/nine-seven-four.cpp)
  - 1590.使数组和能被 P 整除 ==> [题目](https://leetcode.cn/problems/make-sum-divisible-by-p/), [题解](https://github.com/xiewende/CPlusPlus_Algorithm/blob/main/array/one-five-nine-zero.cpp)
  - 面试题 17.05. 字母与数字 ==> [题目](https://leetcode.cn/problems/find-longest-subarray-lcci/), [题解](https://github.com/xiewende/CPlusPlus_Algorithm/blob/main/array/one-seven-zero-five.cpp)
  - 1124.表现良好的最长时间段 ==> [题目](https://leetcode.cn/problems/longest-well-performing-interval/), [题解](https://github.com/xiewende/CPlusPlus_Algorithm/blob/main/array/one-one-two-four.cpp)
  - 2488.统计中位数为 K 的子数组 ==> [题目](https://leetcode.cn/problems/count-subarrays-with-median-k/), [题解](https://github.com/xiewende/CPlusPlus_Algorithm/blob/main/array/two-four-eight-eight.cpp)
  
- 数组前缀和：
  - 给定数组 nums[n], 得到前缀和数组sum[n]。 sum[idx]代表数组 nums 到下标 idx 的累和。
  - sum[i] - sum[j] (i>j) : 就是 nums[j]...nums[i]这个子数组的和，这个和常 **作为条件**
  - 例如：寻找和为 K 的子数组，也就是寻找 nums[j]...nums[i] 这个子数组和为 K，可以转变为寻找 sum[i] - sum[j] = K 是否存在
  - 考虑到是否存在的问题，选取 **HashMap** 就是优解。
  - **需要善于将不一样的题目建模成数组为 1 0 -1 的代表，这样才可以合理利用前缀和的性质** （例如：1124，2488，面试题17.05）
  
- 解题的模板：

  ```
  int function(vector<int> nums, int k){ //数组 nums 的子数组满足 K 的条件
  	//1、创建map
  	//key:主要取与前缀和有关(前缀和OR前缀和取余等）value：主要取和题目所问有关(若求最长最短子数组取index，求次数就是count)
  	unordered_map<int, int> map; 
  	//map 初始值,方便后续程序的统一,按照题目意思设定
  	map[0] = -1 OR map[0]= 1 // index or count
  	// 进入循环
  	for(int i=0; i< nums.size(); i++){
  		sum = sum + nums[i];
  		int target = sum..... // 根据题意子数组需要满足K的条件
  		// 在map寻求是否存在
  		if(map.count(target)){ //寻找到一个满足的子数组
  			// 求解答案 OR 计算次数 OR 计算最大最小
  		}else{  // 题目有必要时需要在此更新map
  			map[target(sum)] = i OR map[target(sum)]++;
  		}
  		//更新map
  		map[target(sum)] = i OR map[target(sum)]++;
  	}
  	return ans；
  }
  ```

- Note：与动态规划解决的 [最大子数组](https://leetcode.cn/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/description/) 和 [乘积最大子数组](https://leetcode.cn/problems/maximum-product-subarray/description/) 不一样, 这两者并没有说是满足什么条件的情况下的子数组，而是最值，并且这两者并没有和**数组前缀和**产生关系，所以求解就不是 **前缀和+HashMap**，而是经典的**动态规划**问题；但是有类似 [连续数组](https://leetcode.cn/problems/contiguous-array/)，这是在基于满足条件 K 的情况下求最短或者最长的子数组，并且其和前缀和能够发生一定关系，所以这种题采取 **前缀和+HashMap**。
- 取余的一点点东西： 
  - 若 (x-y) % p == 0，则 x 和 y 对 模 p 同余 ；
  - 若 (z-y) % p ==x 则 y % p  == （z-x） % p



#### 解题思路2：滑动窗口

- 题目和题解：
  - 209.长度最小的子数组 ==> [题目](https://leetcode.cn/problems/minimum-size-subarray-sum/), [题解]()
  - 713.乘积小于K的子数组 ==> [题目](https://leetcode-cn.com/problems/subarray-product-less-than-k/), [题解]()
  - 2261.含最多K个可整除元素的子数组 ==> [题目](https://leetcode.cn/problems/k-divisible-elements-subarrays/), [题解]()

#### 解题思路3：动态规划

- 题目和题解
  - 53.最大子数组和 ==> [题目](https://leetcode-cn.com/problems/maximum-subarray/), [题解]()
  - 152.乘积最大子数组 ==> [题目](https://leetcode-cn.com/problems/maximum-product-subarray/), [题解]()
  - 718.最长重复子数组 ==> [题目](https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/), [题解]()


## 单调栈问题
  单调栈一般指的是 栈底大栈顶小的顺序，专门解决 Next Greater Number 问题，一但要求下一个更大的元素，单调栈