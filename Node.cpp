//Ethan Deming
//Oct. 24 2018
//Based on Node.cpp by Tom Bailey

#include "Node.h"

Node::Node(float entry) //Takes an entry and assigns it to a new node with a NULL value as the nodes pointer
{
        entry_ = entry;
        next_ = NULL;
}

Node::Node(float entry, Node * next) //Takes an entry and assigns it to a new node with a pointer to a given
{                                    //next node as the nodes pointer value
        entry_ = entry;
        next_ = next;
}
