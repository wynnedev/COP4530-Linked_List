template <typename T>
TList<T>::TList()
{
    std::cout << "TList()\n";
    Init();
}

template <typename T>
TList<T>::TList(T val, int num)
{
    while(num--)
    {
        Insert(GetIteratorEnd(), val);
    }
}

template <typename T>
TList<T>::~TList()
{
    Clear();
    delete first;
    delete last;
}

template <typename T>
TList<T>::TList(const TList& L)
{
    Init();
    bool copyData;
    while(copyData)
    {
        os << itr.GetData() << delim;

        if(itr.HasNext()){
            itr.Next();
        }

        else
        {
            copyData = false;
        }
    }

}

template <typename T>
TList<T>& TList<T>::operator=(const TList& L)
{
    TList<T> copy = L
    std::swap(*this, copy);
    return *this;
}

template <typename T>
TList<T>::TList<T>(TList&& L)
{
    size = L.size;
    first = L.first;
    last = L.last;

    L.size = 0;
    L.first = nullptr;
    L.last = nullptr;
}

template <typename T>
TList<T>& TList<T>::operator=(TList&& L)
{
    std::swap(size, L.size);
    std::swap(first, L.first);
    std::swap(last, L.last);
}

template <typename T>
void TList<T>::Init()
{
    std::cout << "Init()\n";
    first = new Node<T>;
    last = new Node<T>;
    first->next = last;
    last->prev = first;
    size = 0;
}

template <typename T>
bool TList<T>::IsEmpty() const
{
    if(size == 0)
    {
        return true;
    }

    return false;
}

template <typename T>
void TList<T>::Clear()
{
   int sz = size;

   while(size--)
   {
       RemoveFront();
   }
}

template <typename T>
int TList<T>::GetSize() const
{
    return size;
}

template <typename T>
void TList<T>::InsertFront(const T& d)
{
    Insert(GetInterator(), d);
}

template <typename T>
void TList<T>::InsertBack( const T& d)
{
    Insert(GetIteratorEnd(), d);
}

template <typename T>
void TList<T>::RemoveFront()
{
    Remove(GetIterator());
}

template <typename T>
void TList<T>::RemoveBack()
{
    Remove(GetIteratorEnd());
}

template <typename T>
T& TList<T>::GetFirst() const
{
    return GetIterator().GetData();
}

template <typename T>
T& TList<T>::GetLast() const
{
    return GetIteratorEnd().GetData();
}

template <typename T>
TListIterator<T> TList<T>::GetIterator() const
{
    return TListIterator<T> itr.ptr = first->next;
}

template <typename T>
TListIterator<T> TList<T>::GetIteratorEnd() const
{
    return TListIterator<T> itr.ptr = last->prev;
}

template <typename T>
void TList<T>::Insert(TListIterator<T> pos, const T& d)
{
    Node<T> *ptr(d);

    ptr->prev = pos.ptr->prev;
    ptr->next = pos.ptr;
    pos.ptr->prev->next = ptr;
    pos.ptr->prev = ptr;
    ++size;
}

template <typename T>
TListIterator<T> Remove(TListIterator<T> pos)
{
    Node<T> *ptr = pos.ptr;
    TListIterator<T> itr(ptr->next);
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    delete ptr;
    --size;

    return itr;
}

template <typename T>
void TList<T>::Print(std::ostream& os, char delim = ' ') const
{
    TListIterator<T> itr = GetIterator();
    bool printData = true;
    while(printData)
    {
        os << itr.GetData() << delim;

        if(itr.HasNext()){
            itr.Next();
        }

        else
        {
            printData = false;
        }
    }
}

template <typename T>
TList<T> operator+(const TList<T>& t1, const TList<T>& t2)
{
    ///TODO concatenate list
}

template <typename T>
TListIterator<T>::TListIterator()
{
    ptr = nullptr;
}

template <typename T>
bool TListIterator<T>::HasNext() const
{
    if(ptr->next != nullptr)
    {
        return true;
    }

    return false;
}

template <typename T>
bool TListIterator<T>::HasPrevious() const
{
    if(ptr->prev != nullptr)
    {
        return true;
    }

    return false;
}

template <typename T>
TListIterator<T> TListIterator<T>::Next()
{
    ptr = ptr->next;
}

template <typename T>
TListIterator<T> TListIterator<T>::Previous()
{
    ptr = ptr->prev;
}

template <typename T>
T& TListIterator<T>::GetData() const
{
    return ptr->data;
}


