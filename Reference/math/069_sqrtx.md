
### 069. Sqrt(x)

------

#### 目录

<!-- toc -->

####  题目

实现 ` int sqrt(x) `

1、给定的$$x$$是一个**非负数**时

2、计算并返回$$x$$的**平方根**$$p$$

3、仅保留**整数**部分 $$\rightarrow $$ 误差向下取整1



#### 思路（逐步优化）

##### 1、穷举法 - $$T(n) = n $$

给定$$x$$，则所求整数解$$p$$的范围为 $$(0,x)$$

从$$0 \rightarrow x$$，求平方 $$p_0^2$$，直至 $$p_n^2 \leq x $$  && $$(p_n+1)^2 > x$$

得出解 $$p$$

**解：**$$T(n) = n$$

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (0 == x || 1 == x) return x;
        for(int i = 2 ; i < x; ++i){
            if(i^i > x) return i-1
        }
        return -1;
    }
};
```

##### 2、二分求解 - $$T(n) = log_2  n$$

给定$$x$$, 则所求解$$p$$的范围为$$(0,x)$$

从$$ 0 \rightarrow p$$, 求平方 $$p^2$$，<span style="color:red">采用二分查找求解</span>

![二分法演示](../images/069_image_01.gif)

a. 当前区间 $$[0,x]$$ , 取中点标识位$$p_{0} = \frac{(0+x)}{2}$$

b. 当 $$p_{0} ^2  < x$$ ,取当前区间为 $$[ 0, p_0 ]$$ , 反之取 $$[p_0,x]$$

c. 重复$$a-b$$,  直至    $$p_0^2 \leq x $$  && $$(p_0+1)^2 > x$$

得出解 $$p_n$$

**解：** $$T(n) = log_2 n$$
```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (0 == x || 1 == x) return x;
        
        double res = 1, pre = 0;
        while (abs(res - pre) > 1e-6) {
            pre = res;
            res = (res + x / res) / 2;
        }
        return int(res);
    }
};
```

##### 3、牛顿迭代法 - $$  T(n) = log_2  n $$
> [牛顿迭代法(*Newton's method*)](https://en.wikipedia.org/wiki/Newton%27s_method)-求解$$f(x) = 0$$的解

给定$$x$$ , 求 $$p^2  = x$$

设 $$f(p) = x - p^2$$

问题转为  求 $$f(p) = x - p^2 = 0$$的解

**解：** $$T(n) = log_2 n$$ 
```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (0 == x || 1 == x) return x;
        
        double res = 1, pre = 0;
        while (abs(res - pre) > 1e-6) {
            pre = res;
            res = (res + x / res) / 2;
        }
        return int(res);
    }
};
```

<!-- endtoc -->
