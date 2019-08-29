

## 构造与析构

向量结构在内部维护了一个元素类型为T的私有数组_elem[]：容量由私有变量_capacity指示；有效元素的向量即向量的规模，由_size指示。且我们约定

向量的**构造**与**析构**，将围绕这些**私有变量和数据区**的**初始化**和**销毁**之间展开。

### 默认构造方法

```C++
 Vector (int c = DEFAULT_CAPACITY, int s = 0, T v = 0){ //容量为c、规模为s、所有元素初始为v
                 _elem = new T[_capacity = c];
                 for(_size = 0; _size < s; _elem[_size++] = v);         
}
```

默认构造方法的时间复杂度是O(1)

### 基于复制的构造方法

基于复制的构造方法可以由一个数组，或者一个向量复制而来，最核心的代码时下面这一部分

```C++
template <typename T> //元素类型
void Vector<T>::copyFrom ( T const* A, Rank lo, Rank hi ) { //以数组区间A[lo, hi)为蓝本复制向量
   _elem = new T[_capacity = 2 * ( hi - lo ) ]; _size = 0; //分配空间，规模清零
   while ( lo < hi ) //A[lo, hi)内的元素逐一
      _elem[_size++] = A[lo++]; //复制至_elem[0, hi - lo)
}
```

### 析构方法

