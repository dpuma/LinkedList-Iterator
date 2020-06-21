template<typename T>
class LinkedList
{
    int size;
    Node<T>* head;
public:
    LinkedList();
    LinkedList(LinkedList &);
    ~LinkedList();
    Iterator<T> begin();
    Iterator<T> end();
    void insert(T);
    void remove(T);
    void print();
    void printIterator(); // print con interator
};
