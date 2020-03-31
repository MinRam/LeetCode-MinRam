
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

设 $$f(p) = p^2 - x$$ ， 同求 $$f(p) =  p^2 - x= 0$$的解

通过牛顿迭代法,不断逼近真实解

两边求导： $$f'(p) = 2p$$

1. 取初始点$$p_0$$，则得图像点$$(p_0, f(p_0))$$
2. 该点切线方程： $$ y_{p_0} = f'(p_0)(x - p_0) + f(p_0) $$
3. 易得，同x轴交点 $$( p_0- \frac{f(p_0)}{f'(p_0)}) ， 0  )$$，
4. 判断

推理过程如图：

![切线迭代过程](./images/069_sqrtx_01.jpg)

图形演示过程：

{% graph %}
{
    "title": "x^2",
    "grid": true,
    "yAxis": {
        "domain": [-1, 9]
    },
    "xAxis":{
        "domain": [-1, 10]
    },
    "data": [{
        "fn": "x^2 - 4",
        "derivative": {
            "fn": "2*x",
            "updateOnMouseMove":"true"
        }
        
    }]
}
{% endgraph %}

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
