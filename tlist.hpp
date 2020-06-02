template <typename T>
TList<T>::TList()
{
    Init();
}

template <typename T>
TList<T>::TList(T val, int num)
{
    Init();
    while(num--){
        InsertFront(val);
    }
}

template <typename T>
TList<T>::TList(const TList& L)
{
    Init();
    TListIterator<T> itr = L.GetIterator();

    while(itr.HasNext())
    {
        this->InsertBack(itr.GetData());
        itr.Next();
    }
}

template <typename T>
TList<T>& TList<T>::operator=(const TList<T>& L)
{   
    Init();
        Init();
    TListIterator<T> itr = L.GetIterator();

    while(itr.HasNext())
    {
        this->InsertBack(itr.GetData());
        itr.Next();
    }

    return *this;
}

template <typename T>
TList<T>::TList(TList<T> &&L) : size(L.size), first(L.first), last(L.last){
    L.Init();
}

template <typename T>
TList<T>& TList<T>::operator=( TList<T>&& L)
{   
    Init();
        Init();
    TListIterator<T> itr = L.GetIterator();

    while(itr.HasNext())
    {
        this->InsertBack(itr.GetData());
        itr.Next();
    }

    return *this;
}

template <typename T>
TList<T>::~TList()
{
    Clear();
    delete first;
    delete last;
}

template <typename T>
void TList<T>::Init()
{
    first = new Node<T>();
    last = new Node<T>();
    first->next = last;
    last->prev = first;
    
    size = 0;
}

template <typename T>
bool TList<T>::IsEmpty() const
{   
    if(size  == 0)
    {
        return true;
    }

    return false;
}

template <typename T>
void TList<T>::Clear()
{
    while(!IsEmpty())
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
    Insert(GetIterator(), d);
}

template <typename T>
void TList<T>::InsertBack(const T& d)
{
    Insert(GetIteratorEnd(), d);
}

template <typename T>
TListIterator<T> TList<T>::GetIterator() const
{   
    TListIterator<T> begin;
    begin.ptr = first->next;
    return begin;
}

template <typename T>
void TList<T>::RemoveFront()
{
    Remove(GetIterator());
}

template <typename T>
void TList<T>::RemoveBack()
{
    TListIterator<T> itr = GetIteratorEnd();
    Remove(itr.Previous());
}

template <typename T>
T& TList<T>::GetFirst() const
{
    TListIterator<T> begin;
    begin.ptr = first->next;
    return begin.GetData(); 
}

template <typename T>
T& TList<T>::GetLast() const
{
    TListIterator<T> end;
    end.ptr = last->prev;
    return end.GetData(); 
}

template <typename T>
TListIterator<T> TList<T>::GetIteratorEnd() const
{
    TListIterator<T> end;
    end.ptr = last;
    return end;
}

template <typename T>
void TList<T>::Insert(TListIterator<T> pos, const T& d)
{
    Node<T> *current = pos.ptr;
    ++size;
    current->prev = current->prev->next = new Node<T>(d, current->prev, current);
}

template <typename T>
TListIterator<T> TList<T>::Remove(TListIterator<T> pos)
{
    Node<T> *current = pos.ptr;
    TListIterator<T> returnItr; 
    returnItr.ptr = current->next;

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    --size; 
    return returnItr;
}

template <typename T>
void TList<T>::Print(std::ostream& os, char delim) const
{
    TListIterator<T> current = this->GetIterator();

    while(current.HasNext())
    {
        os << current.GetData() << delim;
        current.Next();
    }

    std::cout << std::endl;
}
/*************** ITERATORS ******************/
template <typename T>
TListIterator<T>::TListIterator() : ptr(nullptr) {}

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
    return *this;
}

template <typename T>
TListIterator<T> TListIterator<T>::Previous()
{
    ptr = ptr->prev;
    return *this;
}

template <typename T>
T& TListIterator<T>::GetData() const
{
    return this->ptr->data;
}

/*************************************************************/