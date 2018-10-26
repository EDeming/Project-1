//Ethan Deming
//Oct. 24, 2018
//Based in part on LinkedList.h by Tom Bailey, Ethan Deming

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "Node.h"

class linkedList
{
public:
    float max;

    float min;

public:
    linkedList();

    bool empty() const;

    int getSize() const;

    float sum() const;

    void insertAsLast(float input);

    float getMin();

    float getMax();

private:
    Node * first_;

};

#endif // LIST_H_INCLUDED
