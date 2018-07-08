#ifndef __arrayStackClassH__
#define __arrayStackClassH__

#include <assert.h>

template <class Elem>
class ArrayStack
{
  public:
    ArrayStack(int maxSize=500);
    ArrayStack(const ArrayStack<Elem> &OtherStack);
    ~ArrayStack(void);

    inline void Push(const Elem &Item);
    inline Elem Pop(void);
    inline const Elem &Peek(int Depth) const;

  protected:
    Elem *Data;
    int  CurrElemNum;
    const int MAX_NUM;
};

template <class Elem>
ArrayStack<Elem>::ArrayStack(int MaxSize) :
    MAX_NUM( MaxSize )
{
    Data = new Elem[MAX_NUM];
    CurrElemNum = 0;
}

template <class Elem>
ArrayStack<Elem>::~ArrayStack(void)
{
    delete[] Data;
}

template <class Elem>
inline void ArrayStack<Elem>::Push(const Elem &Item)
{
    assert(CurrElemNum < MAX_NUM);
    Data[CurrElemNum++] = Item;
}

template <class Elem>
inline Elem ArrayStack<Elem>::Pop(void)
{
    assert(CurrElemNum > 0);
    return Data[--CurrElemNum];
}

template <class Elem>
inline const Elem &ArrayStack<Elem>::Peek(int Depth) const
{
    assert(Depth < CurrElemNum);
    return Data[ CurrElemNum - (Depth + 1) ];
}

#endif /*__arrayStackClassH__*/

