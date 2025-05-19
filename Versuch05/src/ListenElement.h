//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#ifndef _LISTENELEMENT_H_
#define _LISTENELEMENT_H_

#include "Student.h"

class ListenElement
{
private:
    Student data;
    ListenElement *next;
    ListenElement *prev;

public:
    ListenElement(Student pData, ListenElement *pNext = nullptr, ListenElement *pPrev = nullptr);

    ListenElement *getPrev() const { return prev; }
    void setPrev(ListenElement *pPrev) { prev = pPrev; }
    void setData(Student pData);
    void setNext(ListenElement *pNext);

    Student getData() const;
    ListenElement *getNext() const;
};

#endif
