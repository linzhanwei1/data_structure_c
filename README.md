# 数据结构C++语言实现 
## lesson14
### 线性表的本质和操作
- 将元素插入线性表
- 将元素从线性表删除
- 获取目标位置初元素的值
- 设置目标位置处元素的值
- 获取线性表的长度
- 清空线性表
#### 数据结构
```
template <typename T> class List : public Object {
public:
    virtual bool insert(int i, const T &e) = 0;
    virtual bool remove(int i)             = 0;
    virtual bool set(int i, const T &e)    = 0;
    virtual bool get(int i, T &e) const    = 0;
    virtual int  length() const            = 0;
    virtual void clear()                   = 0;
};
```
#### 小结
- 线性表是数据元素的有序并且有限的集合
- 线性表中的数据元素必须是类型相同的
- 线性表可用于描述排队关系的问题
- 线性表在程序中表现为一种特殊的数据类型
- 线性表在C++中表现为一个抽象类
## lesson15
### 线性表的顺序存储结构
## lesson16
### 顺序存储结构的抽象实现
#### 数据结构
```
template <typename T> class SeqList : public List<T> {
protected:
    T  *m_array;
    int m_length;

public:
    bool insert(int i, const T &e);
    bool remove(int i);
    bool set(int i, const T &e);
    bool get(int i, T &e) const;
    int length() const;
    void clear();
    // 顺序存储线性表的数组访问方式
    T &operator[](int i);
    T operator[](int i) const;
    // 顺序存储空间的容量
    virtual int capacity() const = 0;
```
## lesson17
### StaticList设计要点
- 使用原生数组作为顺序存储空间
- 使用模板参数决定数组大小
#### 数据结构
``` C++
namespace DTLib {
template <typename T, int N> class StaticList : public SeqList<T> {
protected:
    T m_space[ N ];

public:
    StaticList();
    int capacity() const;
};
```
