template<typename T>
class Node
{
    T elem;
    Node* next = nullptr;
public:
    Node(T);
    Node(Node &);
    T getElem();
    void setElem(T);
    Node*getNext();
    void setNext(Node*);
};
