# 数据结构学习开始

## 一、线性表概述
- **定义**：由 `n` 个相同类型元素构成的有限序列，逻辑上属于线性结构。
- **存储表示形式**：
  - **顺序表**：物理地址连续，通常使用数组存储。
  - **链表**：链式存储结构，数据存储离散，通过指针相连。

---

## 顺序表

### 1. 结构定义
- **定义**：顺序表是用一段物理地址连续的存储单元依次存储数据元素，分为静态和动态。
- **动态顺序表结构C语言表示**：
```c
typedef struct SeqList 
{
    int* array;    // 动态数组指针
    size_t size;   // 有效数据个数
    size_t capacity; // 容量
} SeqList;
```

### 2. 经典算法实现
#### （1）删除有序数组中的重复项（LeetCode 26）
- **思路**：双指针法，`dst` 记录不重复元素位置，`src` 遍历数组。
- **代码实现**：
```c
int removeDuplicates(int* nums, int numsSize) 
{
    if (numsSize == 0) return 0;
    int dst = 1, src = 1;
    while (src < numsSize) 
    {
        if (nums[src] != nums[dst - 1]) 
        {
            nums[dst++] = nums[src];
        }
        src++;
    }
    return dst;
}
```
- **示例图**：
  - 输入：`[0,0,1,1,1,2,2,3,3,4]`
  - 输出：`dst` 之前存储的是不重复值的数组 `[0,1,2,3,4]`，返回长度 `5`。

#### （2）合并两个有序数组（LeetCode 88）
- **思路**：双指针比较，从后往前插入。
- **代码实现**：
```c
void merge(int* nums1, int m, int* nums2, int n) 
{
    int i = m - 1, j = n - 1, end = m + n - 1;
    while (i >= 0 && j >= 0) 
    {
        nums1[end--] = (nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
    }
    while (j >= 0) 
    {
        nums1[end--] = nums2[j--];
    }
}
```
- **示例图**：
  - `nums1: [1,2,3,0,0,0]`，`nums2: [2,5,6]`
  - 合并后结果为 `[1,2,2,3,5,6]`。

### 3. 顺序表的优缺点
- **插入/删除效率**：中间和头部插入删除需要移动数据，时间复杂度 O(N)。
- **优点**：
  - 支持随机访问，访问效率 O(1)。
  - 缓存命中率高，局部性原理。
- **缺点**：
  - 需要预先分配空间，可能存在空间浪费（如申请 200 个，只用 120 个，浪费 80 个）。
  - 数据量不稳定时，扩容频繁，且扩容可能导致内存碎片。

---

## 单链表

### 1. 结构定义
- **定义**：链式存储离散的数据，通过指针实现逻辑上的顺序。
- **单链表结构C语言表示**：
```c
struct ListNode 
{
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
```
- **逻辑存储结构**：
  - **逻辑**：`1 -> 2 -> 3 -> NULL`
  - **实际**：节点地址离散，通过指针相连。

### 2. 常见操作实现

#### （1）尾插操作
- **代码实现**：
```c
void SLTPushBack(ListNode** pphead, int x) 
{
    ListNode* newnode = new ListNode(x);
    if (*pphead == NULL) 
    {
        *pphead = newnode;
    } else 
    {
        ListNode* tail = *pphead;
        while (tail->next != NULL) 
        {
            tail = tail->next;
        }
        tail->next = newnode;
    }
}
```
- **示例图**：
  - 初始状态 `NULL -> [newnode:1]`
  - 找到尾节点，修改 `tail->next` 指向新节点。

#### （2）打印链表
- **代码实现**：
```c
void SLTPrint(ListNode* phead) 
{
    ListNode* cur = phead;
    while (cur != NULL) 
    {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}
```

#### （3）头插操作
- **思路**：创建新节点，将新节点的 `next` 指向原头节点，更新头指针。
- **代码实现**：
```c
void SLTPushFront(ListNode** pphead, int x) 
{
    ListNode* newnode = new ListNode(x);
    newnode->next = *pphead;
    *pphead = newnode;
}
```

#### （4）头删操作
- **思路**：保存原头节点的下一个节点，释放原头节点，更新头指针。
- **代码实现**：
```c
void SLTPopFront(ListNode** pphead) 
{
    if (*pphead == NULL) return;
    ListNode* next = (*pphead)->next;
    delete *pphead;
    *pphead = next;
}
```

#### （5）尾删操作
- **思路**：找到尾节点的前一个节点，释放尾节点，将前一个节点的 `next` 置为 `NULL`。
- **代码实现**：
```c
void SLTPopBack(ListNode** pphead) 
{
    if (*pphead == NULL) return;
    if ((*pphead)->next == NULL) 
    {
        delete *pphead;
        *pphead = NULL;
    } else {
        ListNode* prev = NULL;
        ListNode* tail = *pphead;
        while (tail->next != NULL) 
        {
            prev = tail;
            tail = tail->next;
        }
        delete tail;
        prev->next = NULL;
    }
}
```

### 3. 单链表操作注意事项
- **空指针问题**：在访问节点指针之前，务必检查指针是否为 `NULL`，避免空指针异常。
- **头指针更新**：涉及头节点的操作（如头插、头删），需要通过二级指针更新头指针，确保修改能反映到原链表。
- **内存管理**：插入节点时要正确分配内存，删除节点时要及时释放内存，防止内存泄漏。

### 4. 单链表的优缺点
- **优点**：
  - 插入和删除操作效率高，在已知位置的情况下，时间复杂度为 O(1)（仅需修改指针）。
  - 动态分配内存，无需预先分配大量空间，不会造成空间浪费。
- **缺点**：
  - 不支持随机访问，查找元素需要从头节点开始遍历，时间复杂度为 O(N)。
  - 每个节点需要额外的指针域，增加了空间开销。

---

## 三、顺序表与单链表对比
| **对比项**       | **顺序表**                | **单链表**                |
|----------------|---------------------------|-------------------------|
| **存储形式**   | 物理地址连续              | 链式存储离散            |
| **访问效率**   | 随机访问 O(1)             | 顺序访问 O(N)           |
| **插入/删除**  | 中间和头部 O(N)（需移动数据） | 已知位置 O(1)（仅改指针） |
| **空间占用**   | 预先分配，可能浪费空间    | 按需分配，无空间浪费    |
| **缓存友好**   | 高，局部性原理            | 低                      |
| **适用场景**   | 数据量稳定，频繁访问      | 数据量动态变化，频繁插入删除  |