template<typename T>
class Iterator
{
    Node<T>* posicion;
    template<typename> friend class LinkedList;
public:
    Iterator();
    bool operator==(const Iterator&);
    void nextPosicion();
    T getValue();
};
