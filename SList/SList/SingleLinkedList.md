



# 顺序表和链表学习笔记

## 一、线性表基础
- **定义**：由 `n` 个相同数据元素构成的有限序列，逻辑上呈线性结构。
- **物理存储形式**：
  - **顺序表**：基于数组，物理地址连续。
  - **链表**：链式结构，物理存储离散，通过指针连接。

---

## 二、顺序表详解
### 1. 结构与概念
- **定义**：用物理连续的存储单元存数据，分静态和动态。
- **动态顺序表结构（C语言示例）**：
  ```c
  typedef struct SeqList {
      int* array;    // 动态数组指针
      size_t size;   // 有效数据个数
      size_t capacity; // 总容量
  } SeqList;
  ```

### 2. 核心操作与典型例题
#### （1）删除有序数组中的重复项（LeetCode 26）
- **思路**：双指针法，`dst` 记录不重复元素位置，`src` 遍历数组。
- **代码实现**：
  ```c
  int removeDuplicates(int* nums, int numsSize) {
      if (numsSize == 0) return 0;
      int dst = 1, src = 1;
      while (src < numsSize) {
          if (nums[src] != nums[dst - 1]) {
              nums[dst++] = nums[src];
          }
          src++;
      }
      return dst;
  }
  ```
- **示意图**：
  - 输入：`[0,0,1,1,1,2,2,3,3,4]`
  - 处理：`dst` 从前覆盖存储不重复值，最终得 `[0,1,2,3,4]`，返回长度 `5`。

#### （2）合并两个有序数组（LeetCode 88）
- **思路**：双指针逆序比较，从后往前填充。
- **代码实现**：
  ```c
  void merge(int* nums1, int m, int* nums2, int n) {
      int i = m - 1, j = n - 1, end = m + n - 1;
      while (i >= 0 && j >= 0) {
          nums1[end--] = (nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
      }
      while (j >= 0) {
          nums1[end--] = nums2[j--];
      }
  }
  ```
- **示意图**：
  - `nums1: [1,2,3,0,0,0]`，`nums2: [2,5,6]`
  - 逆序合并后：`[1,2,2,3,5,6]`。

### 3. 顺序表的局限性
- **插入/删除效率**：中间或头部操作需移动数据，时间复杂度 O(N)。
- **扩容问题**：
  - 扩容有性能消耗，且可能浪费空间（如扩容 200 仅用 120，浪费 80）。
  - 扩容策略难平衡，过大浪费，过小则频繁扩容。

---

## 三、链表详解
### 1. 结构与概念
- **定义**：物理存储离散，通过指针实现逻辑顺序。
- **单链表结构（C语言示例）**：
  ```c
  struct ListNode {
      int val;
      struct ListNode* next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  ```
- **逻辑与物理结构**：
  - **逻辑**：`1 → 2 → 3 → NULL`。
  - **物理**：节点地址随机，通过指针链接。

### 2. 核心操作实现
#### （1）单链表尾插
- **代码实现**：
  ```c
  void SLTPushBack(ListNode** pphead, int x) {
      ListNode* newnode = new ListNode(x);
      if (*pphead == NULL) {
          *pphead = newnode;
      } else {
          ListNode* tail = *pphead;
          while (tail->next != NULL) {
              tail = tail->next;
          }
          tail->next = newnode;
      }
  }
  ```
- **示意图**：
  - 空链表：`NULL → [newnode:1]`。
  - 非空链表：找到尾节点，修改 `tail->next` 指向新节点。

#### （2）链表遍历
- **代码实现**：
  ```c
  void SLTPrint(ListNode* phead) {
      ListNode* cur = phead;
      while (cur != NULL) {
          printf("%d ", cur->val);
          cur = cur->next;
      }
      printf("\n");
  }
  ```

### 3. 链表操作注意事项
- **尾插易错点**：
  - 错误写法：未正确修改原链表指针。
  - 正确逻辑：需通过指针操作修改链表结构，避免局部变量丢失指针。

---

## 四、顺序表与链表对比
| **特性**       | **顺序表**                | **链表**                |
|----------------|---------------------------|-------------------------|
| **存储方式**   | 物理地址连续              | 物理存储离散            |
| **访问效率**   | 随机访问 O(1)             | 顺序访问 O(N)           |
| **插入/删除**  | 中间操作 O(N)（需移动）   | 任意位置 O(1)（改指针） |
| **空间管理**   | 预分配，可能浪费          | 按需分配，无浪费        |
| **缓存友好**   | 高（局部性原理）          | 低                      |
| **典型场景**   | 频繁访问，少增删          | 频繁增删，数据动态变化  |
