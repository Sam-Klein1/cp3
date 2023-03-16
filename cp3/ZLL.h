template <typename T>
class Node{

    public:
    
    Node(const T &thing);
    T item;
    Node<T> *next;
    Node<T> *prev;

};
template <typename T>
class ZLL{

    public:

    ZLL<T>();
    ~ZLL<T>();
    bool front(const T &thing);
    bool back(const T &thing);
    bool join(ZLL &other);
    ZLL<T> &operator+=(const ZLL<T> &other);
    ZLL<T> &operator-=(const ZLL<T> &other);
    int removeZany();
    int removeNonZany();
    bool promoteZany();
    bool start();
    bool done();
    T getNext();
    void print(); //helper function

    private:

    Node<T> *head;
    Node<T> *tail;
    Node<T> *ptr;


};

#include "ZLL.cpp"