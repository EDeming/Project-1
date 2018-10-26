//Ethan Deming
//Oct. 24, 2018
//Based on Node.h by Tom Bailey

#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <iostream>

using std::cout;
using std::endl;

class Node
{
public:
    float entry_;
    Node * next_;

public:
    Node(float entry);
    Node(float entry, Node * next);
};

#endif // NODE_H_INCLUDED
