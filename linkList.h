#include "list.h"
using namespace std;

template <class elemType> class linkList : public List<elemType> {
    struct Node {
        elemType data;
        Node *next;
        //两个构造函数
        Node(const elemType value, Node *p = NULL) {
            data = value;
            next = p;
        }
        Node(Node *p = NULL) {
            next = p;
        }
    };

    //单链表的头指针
    Node *head;
    //单链表的尾指针
    Node *tail;
    //单链表的当前长度
    int curLength;

public:
    linkList();
    ~linkList();
    //清空单链表，使其成为空表
    void clear();
    //带头结点的单链表，判空
    bool empty() {return head->next == NULL;}
    //返回单链表的当前实际长度
    int size() {return curLength;}
    //在位序i处插入值为value的节点，表长增1
    void insert(int i, const elemType& value);
    //删除位序为i处的节点，表长减1
    void remove(int i);
    //查找值为value的节点的位序
    int search(const elemType& value);
    //访问位序为i的节点的值，0定位到首元结点
    elemType visit(int i);
    //遍历单链表
    void traverse();
    //头插法创建单链表
    void headCreate();
    //尾插法创建单链表
    void tailCreate();
    //逆置单链表
    void inverse();
    //返回指向位序为i的节点的指针
    Node *getPosition(int i);
    //  合并
    bool Union(linkList<elemType> *lb);
    //题目所用
    void create(int m);
    //同上题目所用
    void operate(int s, int n);
    //另一种删除
    int dd(Node *p);
    //清理重复数据
    int clean();
};

template <class elemType> linkList<elemType>::linkList() {
    head = tail = new Node();
    curLength = 0;
}

template <class elemType> linkList<elemType>::~linkList() {
    clear();
    delete head;
}

template <class elemType> void linkList<elemType>::clear() {
    Node *p, *tmp;
    if (head != tail) {
        p = head->next;
        while (p != NULL) {
            tmp = p;
            p = p->next;
            //delete tmp;
        }
        head->next = NULL;
        tail = head;
        curLength = 0;
    }
}

template <class elemType> void linkList<elemType>::traverse() {
    Node *p = head->next;
    cout << "traverse:";
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

template <class elemType>
typename linkList<elemType>::Node *linkList<elemType>::getPosition(int i) {
    if (i < -1 || i > curLength)
        return NULL;
    Node *p = head;
    int count = 0;
    while(count <= i) {
        p = p->next;
        count++;
    }
    return p;
}

template <class elemType>
int linkList<elemType>::search(const elemType& value) {
    Node *p = head->next;
    int count = 0;
    while (p != NULL && p->data != value) {
        p = p->next;
        count++;
    }
    if (p == NULL)
        return -1;
    else
        return count;
}

template <class elemType>
void linkList<elemType>::insert(int i, const elemType& value) {
    Node *p, *q;
    if (i < 0 || i > curLength)
        throw out_of_range1();
    p = getPosition(i - 1);
    q = new Node(value, p->next);
    p->next = q;
    if (p == tail)
        tail = q;
    curLength++;
}

template <class elemType> void linkList<elemType>::remove(int i) {
    //p是待删节点，pre是其前驱
    Node *p, *pre;
    if (i < 0 || i >= curLength)
        throw out_of_range1();
    pre = getPosition(i - 1);
    p = pre->next;
    if (p == tail) {
        tail = pre;
        pre->next = NULL;
        delete p;
    }
    else {
        pre->next = p->next;
        delete p;
    }
}

template<class elemType> void linkList<elemType>::headCreate() {
    Node *p;
    elemType value, flag;
    cout << "input elements, ended with:";
    cin >> flag;
    while(cin >> value, value != flag) {
        //p->data == value, p->next = head->next
        p = new Node(value, head->next);
        head->next = p;
        //原链表为空，新节点p成为尾节点
        if (head == tail)
            tail = p;
        curLength++;
    }
}

template<class elemType> void linkList<elemType>::tailCreate() {
    Node *p;
    elemType value, flag;
    cout << "input elements, ended with:";
    cin >> flag;
    while(cin >> value, value != flag) {
        p = new Node(value, NULL);
        tail->next = p;
        tail = p;
        curLength++;
    }
}

//  整体思路是把所操作的节点逐个接在head的后面

template<class elemType> void linkList<elemType>::inverse() {
    Node *p, *tmp;
    //p为工作指针，指向首元结点
    p = head->next;
    //头结点的指针域置空，构成空链表
    head->next = NULL;
    //逆置后首元结点将成为尾节点
    if (p != NULL)
        tail = p;
    while (p != NULL) {
        //暂存p的后继
        tmp = p->next;
        //把head后面的链接到p的后面
        p->next = head->next;
        //把p插在head的后面
        head->next = p;
        //继续处理下一个节点
        p = tmp;
    }
}

template <class elemType>
bool linkList<elemType>::Union(linkList<elemType> *lb)
{
    Node *pa, *pb, *pc;
    pc = head;
    
    pa = head->next;
    
    pb = (lb->head)->next;

    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    if (pa) {
        pc->next = pa;
    } else {
        pc->next = pb;
        tail = lb->tail;
    }
    curLength += lb->curLength;
    return true;
}

template <class elemType> elemType linkList<elemType>::visit(int i) {
    if (i < 0 || i >= curLength)
        throw out_of_range1();
    Node *p = head->next;
    int count = 0;
    while (p != NULL && count < i) {
        p = p->next;
        count++;
    }
    return p->data;
}

template <class elemType> void linkList<elemType>::create(int m) {
    Node *p;
    int value = m;

    while (value > 0) {
        //p->data == value, p->next = head->next
        p = new Node(value, head->next);
        head->next = p;
        //原链表为空，新节点p成为尾节点
        if (head == tail)
            tail = p;
        curLength++;
        value--;
    }

    tail->next = head->next;
}

template <class elemType>
void linkList<elemType>::operate(int s, int n) {
    Node *p = getPosition(s - 1);
    int count = 1;
    while (curLength > 0) {
        while (count < n) {
            p = p->next;
            count++;
        }
        cout << p->data << " ";
        //记录删除的节点
        Node *tobeDel = p;
        //p从下一节点开始
        p = p->next;
        //删除
        dd(tobeDel);
        //将count复位
        count = 1;
    }
}

template <class elemType> int linkList<elemType>::dd(Node *p) {
    Node *tmp = head;
    
    if (head->next == p) {
        //注意这是一个环，删去第一个借点时尾巴要接到前面来
        tail->next = p->next;
        head->next = p->next;
        curLength--;
        
        if (tail == p) {
            tail = head;
        }
        
        delete p;
        return 0;
    }
    while (tmp->next != p) {
        tmp = tmp->next;
    }
    
    tmp->next = p->next;
    
    curLength--;
    
    if (tail == p)
        tail = tmp;
    
    delete p;
    return 0;
}

template <class elemType> int linkList<elemType>::clean() {
    if (head == tail || curLength == 1)
        return -1;
    Node *p = head->next;
    while (p != tail) {
        if (p->data == p->next->data) {
            if (p->next->next == NULL) {
                delete p->next;
                p->next = NULL;
                tail = p;
                return 0;
            } else {
                p->next = p->next->next;
            }
        }
        p = p->next;
    }
    return 0;
}
