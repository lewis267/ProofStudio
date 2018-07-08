#ifndef __stackClassH__
#define __stackClassH__

#include <assert.h>

template <class snT>
struct sNode {
    snT *value;
    sNode *next;
};

template <class Elem>
class Stack
{
  public:
    Stack();
    Stack(const Stack<Elem> &OtherStack);
    ~Stack(void);

    inline void Push(Elem *Item);
    inline Elem* Pop(void);
    inline Elem* Peek(int Depth) const;

    int Size;

  protected:
    sNode<Elem>* head;
};

template <class Elem>
Stack<Elem>::Stack()
{
    Size = 0;
}

template <class Elem>
Stack<Elem>::~Stack(void)
{
    while(Size)
        Pop();
}

template <class Elem>
inline void Stack<Elem>::Push(Elem *Item)
{
    // static constructor
    sNode<Elem>* newNode = new sNode<Elem>();

    // assign value
    newNode->value = Item;

    // push the previous node down
    newNode->next = head;

    // increment the size
    Size++;

    // update the head reference
    head = newNode;
}

template <class Elem>
inline Elem* Stack<Elem>::Pop(void)
{
    sNode<Elem>* old = head;
    if (old != nullptr) 
    {
        Elem* top = head->value;
        head = head->next;
    
        delete old;
        Size--;

        return top;
    }
    else return nullptr;
}

template <class Elem>
inline Elem* Stack<Elem>::Peek(int Depth) const
{
    assert(Depth < Size);

    sNode<Elem>* toSend = head;
    while (Depth-- > 0) {
        toSend = toSend->next;
    }

    return toSend->value;
}

#endif /*__stackClassH__*/

