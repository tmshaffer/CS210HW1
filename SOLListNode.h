#pragma once
template<class DT> class SOLList;

template <class DT>
class SOLListNode
{
    friend class SOLList<DT>;

public:

    explicit SOLListNode(const DT& newData)
    {
        data = newData;
        next = nullptr;
    }

    DT getData() const { return data; }

private:
    DT data;
    SOLListNode<DT>* next;
};