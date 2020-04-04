### 146_LRU Cache

------

#### 目录

<!-- toc -->

#### 题目

实现***LRU Cache*** 算法

- <code> get(key) </code>  返回对应值，不存在时返回<span style="color:blue">-1</span>
- <code>put(key,value)</code> 存入新键值对。当<span style="color:blue">key</span>已存在时候，修改新值；
- 要求<code>get(key) & put(key, value)</code> 时间复杂度为 **O(1)**;

样例数据：

  ```cpp
LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(2, 3);    
cache.get(2);       // returns 3
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(2);       // returns 3  
cache.get(4);       // returns 4
  ```



#### 思路（逐步优化）

##### 1、单链表实现

模拟LRU Cache机制；

```cpp
struct ListNode{
    int key;
    int value;
    ListNode * next;
    ListNode(int tmpKey, int tmpValue):key(tmpKey),value(tmpValue),next(nullptr){}
};   // 链表节点结构
ListNode * head;  // 链表哨兵头节点
ListNode * tail;  // 始终指向链表的尾部
```

- <code> get(key)</code>    

  ​    复杂度： **O(n) = n**

   	从 <span style="color:blue">head</span> $$ \rightarrow $$ <span style="color:blue">tail</span> 进行遍历，

  - 当节点<span style="color:#FF8C00">key</span>等于所求值，返回value，并将该节点移到队尾； 
  - 当找不到<span style="color:#FF8C00">key</span>, 返回value;

- <code>put(key, value)</code>

     复杂度：**O(n) = n**

  ​    从 <span style="color:blue">head</span> $$ \rightarrow $$ <span style="color:blue">tail</span> 进行遍历，

  - 当节点<span style="color:#FF8C00">key</span>存在时，修改value，并将该节点移到队尾； 
  - 当节点<span style="color:#FF8C00">key</span>不存在时, 在链尾加入新节点(更新<span style="color:blue">map</span>,若容量超额，删除首节点<span style="color:blue">head</span>(更新<span style="color:blue">map</span>)；

##### 2、单链表 + 哈希表实现 （内存消耗少，时间多）

模拟LRU Cache机制；

```cpp
struct ListNode{
    int key;
    int value;
    ListNode * next;
    ListNode(int tmpKey, int tmpValue):key(tmpKey),value(tmpValue),next(nullptr){}
};   // 链表节点结构
ListNode * head;  // 链表哨兵头节点
ListNode * tail;  // 始终指向链表的尾部
unordered_map<int, ListNode *> map; // 存放<键，键对应节点的前一个节点>  , 无排序关系，选择unordered_map
```

- <code>get(key)</code>

  复杂度： **O(n) = 1**

  从<span style="color:blue">map</span>，获取对应<span style="color:#FF8C00">key</span>节点的前一个节点<span style="color:blue"> map->second</span>;

  - 当对应<span style="color:#FF8C00">key</span>的节点不为<span style="color:blue">tail</span>，更新<span style="color:blue">map</span>节点（<span style="color:#FF8C00">key</span>的节点，以及<span style="color:#FF8C00">key</span>下一节点）信息，将该节点移动到队尾；
  - 返回 **value**;

- <code>put(key, value)</code>

  复杂度： **O(n)=1 **

  从<span style="color:blue">map</span>, 获取对应<span style="color:#FF8C00">key</span>节点是否存在；

  - 当节点<span style="color:#FF8C00">key</span>不存在时, 在链尾加入新节点（更新<span style="color:blue">map</span>),若容量超额，删除首节点<span style="color:blue">head</span>(更新<span style="color:blue">map</span>)，；
  - 当对应<span style="color:#FF8C00">key</span>节点存在，且不为<span style="color:blue">tail</span>，修改<span style="color:#FF8C00">value</span>,并更新<span style="color:blue">map</span>节点（<span style="color:#FF8C00">key</span>的节点，以及<span style="color:#FF8C00">key</span>下一节点）信息，将该节点移动到队尾；

##### 3、双链表 + 哈希表实现（内存消耗多，时间少）

模拟LRU Cache机制；

```cpp
struct ListNode{
    int key;
    int value;
    ListNode * pre;
    ListNode * next;
    ListNode(int tmpKey, int tmpValue):key(tmpKey),value(tmpValue),next(nullptr){}
};   // 链表节点结构
ListNode * head;  // 链表哨兵头节点
ListNode * tail;  // 始终指向链表的尾部
unordered_map<int, ListNode *> map; // 存放<键，键对应节点>  , 无排序关系，选择unordered_map
```

- <code>get(key)</code>

  复杂度： **O(n) = 1**

  从<span style="color:blue">map</span>，获取对应<span style="color:#FF8C00">key</span>节点 map->second</span>;

  - 当对应<span style="color:#FF8C00">key</span>的节点不为<span style="color:blue">tail</span>，将该节点移动到队尾，返回**value**；
  - 当对应<span style="color:#FF8C00">key</span>的节点不存在，返回 **-1**;

- <code>put(key, value)</code>

  复杂度： **O(n)=1 **

  从<span style="color:blue">map</span>, 获取对应<span style="color:#FF8C00">key</span>节点是否存在；

  - 当节点<span style="color:#FF8C00">key</span>不存在时, 在链尾加入新节点（更新<span style="color:blue">map</span>),若容量超额，删除首节点<span style="color:blue">head</span>(更新<span style="color:blue">map</span>)，；
  - 当对应<span style="color:#FF8C00">key</span>节点存在，且不为<span style="color:blue">tail</span>，将该节点移动到队尾；



