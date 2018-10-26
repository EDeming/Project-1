//Ethan Deming
//Oct. 24, 2018
//Based in part on List.cpp by Tom Bailey, Ethan Deming

#include "List.h"

linkedList::linkedList() //initializes a link list with one node whose value is NULL
{
    min = NULL;
    max = 0;

    first_ = NULL;
}

bool linkedList::empty() const //checks if the list is empty
{
    return first_ == NULL;
}

int linkedList::getSize() const //checks the number of nodes in the list
{
    int size = 0;

    Node * ptr = first_;

    if(!empty())
    {
        while(ptr != NULL)
        {
            ptr = ptr->next_;
            size++;
        }
    }

    return size;
}

float linkedList::sum() const //returns the sum of all nodes
{
    float sum = 0;

    Node * ptr = first_;

    if(!empty())
    {
        while(ptr != NULL)
        {
            sum = sum + ptr->entry_;
            ptr = ptr->next_;
        }
    }

    return sum;
}

void linkedList::insertAsLast(float input) //inserts input as the last node in the list
{
    if(input > 0)
    {
        if(!empty())
        {
            Node * ptr = first_;

            Node * tmp;

            while(ptr != NULL)
            {
                tmp = ptr;
                ptr = ptr->next_;
            }

            tmp->next_ = new Node(input);
        }
        else
        {
            first_ = new Node(input, first_);
        }

        if(min == NULL || input < min)
        {
            min = input;
        }

        if(input > max)
        {
            max = input;
        }
    }
}

float linkedList::getMin() //returns the smallest value in the list
{
    return min;
}

float linkedList::getMax() //returns the largest value in the list
{
    return max;
}
