#include <iostream>
using namespace std;

template<class T> class List {
    public:
    //  清空线性表
    virtual void clear()=0;
    //  判断是否为空，表空返回true，非空返回false
    virtual bool empty()=0;
    //  求线性表的长度
    virtual int size()=0;
    //  在线性表中位序为i处插入元素value
    virtual void insert(int i, const T& value)=0;
    //  在线性表中删除位序为i的元素
    virtual void remove(int i)=0;
    //  在线性表中查找值为value的元素第一次出现的位序
    virtual int search(const T& value)=0;
    //  在线性表中，查找位序为i的元素并返回其值
    virtual T visit(int i)=0;
    //  历遍
    virtual void traverse()=0;
    //  逆置
    virtual void inverse()=0;
};

/* 自定义异常处理类 */

class out_of_range1 : public std::exception {   //用于检查范围的有效性
public:
    const char* what() const throw() {
        return "ERROR! OUT OF RANGE.\n";
    }
};

class bad_size1 : public std::exception {     //用于检查长度有效性
public:
    const char *what() const throw() {
        return "ERROR! BAD SIZE.\n";
    }
};


