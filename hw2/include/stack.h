//--- 2022-2023 Fall YZV201E Assignment 2 ---//
//--------------------------//
//---Name & Surname: Öykü Eren
//---Student Number: 150200326
//--------------------------//


#include <string>  // For string operations

class Node{
public:
    int value;
    Node *next;
};


class stack{
public:
    Node *top;

    //Add a new node to the stack
    void push(int);
    //Remove the topmost node from the stack
    void pop();
    //Return the topmost node of the stack. (itself not value of it)
    Node* peek();
    //Return number of nodes in the stack.
    int size();
    //Print values of all nodes in the stack.
    void print_all();
    //Return whether stack is empty or not.
    bool is_empty();
    //Return whether nodes are sorted from smallest to biggest. (from top to bottom)
    bool is_descending();
    //For every two nodes next to each other, check whether their difference is 1. remove second one if it is not
    void sequentilized();
    // Get another basket’s nodes and add them to the basket without breaking the order of the nodes.
    void merge_basket(stack &second);
};