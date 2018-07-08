#ifndef __trieClassH__
#define __trieClassH__

#include <assert.h>

/**
 * A Trie node which contains a value and a 
 * pointer to the next array.
 */
template <typename TKeyPiece, typename TValue>
struct tNode {
    TValue *value;
    TKeyPiece *next;
};


/**
 * The main class for the Trie datastructure.
 */
template <typename TKey, typename TKeyPiece, typename TValue>
class Trie
{
  public:
    Trie();
    Trie(const Trie<TKey, TKeyPiece, TValue> &other);
    ~Trie(void);

    /**
     * Add a key and value pair to the Trie.
     */
    inline void Add(const TKey &key, TValue *value);

    /**
     * Remove a key and any associated value from the Trie.
     */
    inline TValue* Remove(const TKey &key);

    /**
     * Obtain the reference to a value if it exists at the given
     * Key.
     */
    inline TValue* Search(const TKey &key);

    /**
     * The number of values in the Trie.
     */
    int Size;

  protected:
    tNode<TKey,TKeyPiece,TValue>* head;
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

#endif /*__trieClassH__*/

