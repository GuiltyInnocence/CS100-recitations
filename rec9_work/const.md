只有指针和引用有底层`const`的概念，其他都是顶层`const`
引用没有实体，也就没有顶层`const`

```c++
const int a=1; //顶层const，a本身不可变
const int *const ptr = &a;
// const int 是底层const，表示指向的const int不可变
// *const是顶层const，表示指针内容不可变
const int* const &p=ptr;
// 绑定同时带有顶层const和底层const的指针的引用
// i.e. 指向const int的常量指针的引用
```

### 例1：

```c++
typedef char *pchar;
const pchar ptr1 = NULL; //指向char的指针，带有顶层const
const char *ptr2; //指向const char的指针，带有底层const
```

### 例2：

```c++
const int i=233;
const int *const p = &i;
const int *const &p2 = p;
std::cout<<*p2; //233
```


### 例3：对于`auto`（抛弃顶层const和引用只保留底层const，记住就行了）

```c++
const int ci = i;
auto &cr = ci; // const int &
auto b = ci; // int (top-level const in ci is dropped)
auto c = cr; // int (cr is an alias for ci whose const is top-level)
auto d = &i; // int* (& of an int object is int*)
auto e = &ci; // const int* (& of a const object is low-level const
```

Bitwise const 跟 Logical const 是针对成员函数而言的

编译器只能检查 Bitwise const 就是很傻的看你成员变量值有没有变

所以有一种情况：成员变量有个指针，你把指向位置的内容（需要指向的不是成员变量）变了，编译器检查不出来，这时候需要自己负责检查并且决定写不写这个成员函数的const

### 小彩蛋

```c++
const int*const foo(const int*const& p)const;
```

