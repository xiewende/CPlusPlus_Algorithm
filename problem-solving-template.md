
## 总结做题的技巧

### 1、子数组问题 

#### 解题思路1：**数组前缀和 + HashMap**

- 题目和题解：
  - 523.连续的子数组和 ==> [题目](https://leetcode.cn/problems/continuous-subarray-sum/)，[题解](https://github.com/xiewende/CPlusPlus_Algorithm/blob/main/array/five-two-three.cpp)
  - 525.连续数组 ==> [题目](https://leetcode.cn/problems/contiguous-array/)，[题解](https://github.com/xiewende/CPlusPlus_Algorithm/blob/main/array/five-two-five.cpp)
  - 560.和为k的子数组 ==> [题目](https://leetcode.cn/problems/subarray-sum-equals-k/)，[题解](https://github.com/xiewende/CPlusPlus_Algorithm/blob/main/array/five-six-zero.cpp)
  - 974.使数组和能被 K 整除 ==> [题目](https://leetcode.cn/problems/subarray-sums-divisible-by-k/)，[解题](https://github.com/xiewende/CPlusPlus_Algorithm/blob/main/array/nine-seven-four.cpp)
  - 1590.使数组和能被 P 整除 ==> [题目](https://leetcode.cn/problems/make-sum-divisible-by-p/)，[题解](https://github.com/xiewende/CPlusPlus_Algorithm/blob/main/array/one-five-nine-zero.cpp)
  - 面试题 17.05. 字母与数字 ==> [题目](https://leetcode.cn/problems/find-longest-subarray-lcci/)，[题解](https://github.com/xiewende/CPlusPlus_Algorithm/blob/main/array/one-seven-zero-five.cpp)
  - 1124.表现良好的最长时间段 ==> [题目](https://leetcode.cn/problems/longest-well-performing-interval/)，[题解](https://github.com/xiewende/CPlusPlus_Algorithm/blob/main/array/one-one-two-four.cpp)
  - 2488.统计中位数为 K 的子数组 ==> [题目](https://leetcode.cn/problems/count-subarrays-with-median-k/)，[题解](https://github.com/xiewende/CPlusPlus_Algorithm/blob/main/array/two-four-eight-eight.cpp)
  
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
  - 209.长度最小的子数组 ==> [题目](https://leetcode.cn/problems/minimum-size-subarray-sum/)，[题解]()
  - 713.乘积小于K的子数组 ==> [题目](https://leetcode-cn.com/problems/subarray-product-less-than-k/)，[题解]()
  - 2261.含最多K个可整除元素的子数组 ==> [题目](https://leetcode.cn/problems/k-divisible-elements-subarrays/)，[题解]()



#### 解题思路3：动态规划

- 题目和题解
  - 53.最大子数组和 ==> [题目](https://leetcode-cn.com/problems/maximum-subarray/)，[题解]()
  - 152.乘积最大子数组 ==> [题目](https://leetcode-cn.com/problems/maximum-product-subarray/)，[题解]()
  - 718.最长重复子数组 ==> [题目](https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/)，[题解]()



### 2、单调栈问题

  单调栈一般指的是 栈底大栈顶小的顺序，专门解决 Next Greater Number 问题，一但要求下一个更大的元素，单调栈
  - 496.下一个更大的元素1==>[题目](https://leetcode.cn/problems/next-greater-element-i/description/)，[题解](https://github.com/xiewende/CPlusPlus_Algorithm/blob/main/stack/four-nine-six.cpp)
  - 503.下一个更大的元素2==>[题目](https://leetcode.cn/problems/next-greater-element-ii/)，[题解](https://github.com/xiewende/CPlusPlus_Algorithm/blob/main/stack/five-zero-three.cpp)
  - 2454.下一个更大的元素3==>[题目](https://leetcode.cn/problems/next-greater-element-iv/)，[题解]()
  - 739.每日温度==>[题目](https://leetcode.cn/problems/daily-temperatures/)，[题解]()
  - 456.132模式==>[题目](https://leetcode.cn/problems/132-pattern/)，[题解](https://github.com/xiewende/CPlusPlus_Algorithm/blob/main/stack/four-five-six.cpp)
  - 901.股票价格跨度==>[题目](https://leetcode.cn/problems/online-stock-span/)，[题解]()
  - 解题模板：
    ```
    int function(vector<int> nums){ //数组 nums 也可以多个nums数组
      //1、创建单调栈，**一般栈底大，栈顶小**
      stack<int> order_stack;
      // 进入循环
      for(int i=0; i< nums.size(); i++){
        int target = nums[i] // 当前值
        // 在栈不为空的时候，判断当前元素和栈顶元素的大小关系，满足的话就退出栈顶元素
        while(!order_stack.empty() && curr > order_stack.top()){
          order_stack.pop();
        }
        //判断栈是否为空来保存此步骤的答案
        ans[i] =.....(order_stack.top(), 栈顶元素居多，或者为不满足的情况-1)
        // 当前元素入栈
      }
      return ans；
    }
    ```



### 3、前缀和+差分数组

#### 前缀和

- 一维前缀和：给定一维数组`nums[n]`，前缀和数组 $sum[i] = \sum_{i=0}^{n}nums[i]$ 

- 二维前缀和：给定二维数组`nums[n][m]`，前缀和数组 $sum[i][j] = \sum_{i=0}^{n}\sum_{j=0}^{m} nums[i][j]$

- 二维前缀和例子

  > 数组：
  >
  > 1 2 4 3 
  >
  > 5 1 2 4 
  >
  > 6 3 5 9
  >
  > 二维前缀和：
  >
  > 1  3  7  10 
  >
  > 6  9  15 22 
  >
  > 12 18 29 45

- 求解过程：递归求  `sum[i][j] `的过程，状态转移方程：$sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1]$
- 应用过程：例如求 $(x_1, y_1) ==》 (x_2,y_2)$ 的子矩阵的和：$sum[x_2][y_2] - sum[x_1-1][y_2] - sum[x_2][y_1-1] + sum[x_1-1][y_1-1]$



#### 差分数组

- 定义：对于数组 `nums[n]` ，其对应的差分数组 d 为：
  $$
  d[i]=\left\{\begin{array}{ll}
  a[0], & i=0 \\
  a[i]-a[i-1], & i \geq 1
  \end{array}\right.
  $$
  

  - 性质1：从左到右累加d中的元素，也就是前缀和，可以恢复得到原数组 nums

  - 性质2：下面两个操作是一致的：

    **区间操作：** 把原数组的子数组 nums[i], nums[i+1],....,nums[j]，都加上x

    **单点操作：** 把 d[i]+x，d[j+1]-x，如果j+1=n的话，只需要 d[i]+x

  - 利用性质2，可以在`o(1)`的时间就完成对原数组nums的区间操作，再利用性质1可以从差分数组复原出园数组

- 例子：

  考虑数组 nums=【1, 3, 3, 5, 8】，对其中的相邻元素两两作差（右边减左边），得到数组  【2, 0, 2, 3】。然后在开头补上 a【0】，得到差分数组：
  $$
  d=[1,2,0,2,3]
  $$
  这有什么用呢？如果从左到右累加 dd 中的元素，我们就**「还原」**回了 nums 数组【1, 3, 3, 5, 8】。

  这又有什么用呢？现在把连续子数组 nums【1】, nums【2】, nums【3】 都加上 10，得到 nums'=【1, 13, 13, 15, 8】 。再次两两作差，并在开头补上 nums'【0】 ，得到差分数组：
  $$
  d 
  ′
   =[1,12,0,2,−7]
  $$
  对比 d 和 d'，你会发现，对 nums 中连续子数组的操作，可以转变成对差分数组 d 中**两个数**的操作。

- 代码模板

  ```
  // 常规数组
  // 你有一个长为 n 的数组 a，一开始所有元素均为 0。
  // 给定一些区间操作，其中 queries[i] = [left, right, x]，
  // 你需要把子数组 a[left], a[left+1], ... a[right] 都加上 x。
  // 返回所有操作执行完后的数组 a。
  vector<int> solve(int n, vector<vector<int>> queries) {
      vector<int> diff(n); // 差分数组
      for (auto &q: queries) {
          int left = q[0], right = q[1], x = q[2];
          diff[left] += x;
          if (right + 1 < n) {
              diff[right + 1] -= x;
          }
      }
      for (int i = 1; i < n; i++) {
          diff[i] += diff[i - 1]; // 直接在差分数组上复原数组 a
      }
      return diff;
  }
  
  // 有时候差分数组的大小不好控制，哈希表实现（Map）来代替差分数组，只需要考虑开始begin下标和结束end下标的变量就好，这两个位置的值才是会改变的。其余位置是不变的，不用考虑，哈希表（Map）一定得是有序的哈希表，因为我们需要按照哈希表的key进行排序，这样才可以从小到大遍历位置了。不可使用unordered_map。
  ```

  - 1094.拼车==>[题目](https://leetcode.cn/problems/car-pooling/description/)，[题解](https://github.com/xiewende/CPlusPlus_Algorithm/blob/main/difference-array/one-zero-nine-four.cpp)
  - 1109.航班预订统计==>[题目](https://leetcode.cn/problems/corporate-flight-bookings/)，[题解](https://github.com/xiewende/CPlusPlus_Algorithm/blob/main/difference-array/one-one-zero-nine.cpp)
  - 2046.将区间分为最少组数==>[题目](https://leetcode.cn/problems/divide-intervals-into-minimum-number-of-groups/)，[题解](https://github.com/xiewende/CPlusPlus_Algorithm/blob/main/difference-array/two-four-zero-six.cpp)