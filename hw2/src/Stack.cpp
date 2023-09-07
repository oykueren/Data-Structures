//--- 2022-2023 Fall YZV201E Assignment 2 ---//
//--------------------------//
//---Name & Surname: Öykü Eren
//---Student Number: 150200326
//--------------------------//

#include <iostream>  // For input/output operations
//#include <stack.h>
#include "../include/stack.h"

using namespace std;

//-------------stack Methods-------------//

//Add a new node to the stack
void stack::push(int newvalue){
    Node *newnode = new Node;
    //to assign new value to new node
    newnode->value = newvalue;
    //to make new node top node
    newnode->next = top;
    top = newnode;
}

//Remove the topmost node from the stack
void stack::pop(){
    //while make the next value as top, delete the previous top
    Node *temp;
    temp = top;
    top = top->next;
    delete temp;
}

//Return the topmost node of the stack. (itself not value of it)
Node* stack::peek(){
    return top;

}

//Return number of nodes in the stack
int stack::size(){
    //while temp is jumping next one, calculate the number of total by counting number of jumping
    Node *temp;
    temp = top;
    int count;
    count = 0; 
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;

}

//Print values of all nodes in the stack
void stack::print_all(){
    if(top == NULL){
    return;
    }
    /*if top is not return, create a temp node. 
    While the traverse node is jumping the next one from top node to end, values are printing. */
    Node *temp;
    temp = top;
    int i;
    i=1;
    while(temp){
        cout << i << "." <<temp->value<< endl;
        i++;
        temp = temp->next;
    }
}

//Return whether stack is empty or not
bool stack::is_empty(){
    //if the stack or top of the stack empty, return true, if not, return false.
    bool empty = false;
    if(top == NULL){
        empty = true;
    }
    return empty;
}

//Return whether nodes are sorted from smallest to biggest. (from top to bottom)
bool stack::is_descending(){
    //if the stack is descending, return false
    bool descend = false;
    Node *temp;
    temp = top;
    
    //for all nodes, check if the next one is smaller than the previous one or not.
    //if it is smaller, return true.
    if(temp){
        while(temp->next){
            if (temp->value > temp->next->value){
                descend = true;
                return descend;
            }
            else{
                temp = temp->next;
            }   
        }
        return descend;
    }
    //if the temp is null, return false
    else{
        return descend;
    }
        
}

//For every two nodes next to each other, check whether their difference is 1. remove second one if it is not
void stack::sequentilized(){
    Node *temp;
    //if top is empty, do not do anything
    if (!top)
        return ;
    temp = top;
    Node *oper;
    while(temp->next){
        // if the next one is not 1 more than the temp, after this element, nextb elemnts should be deleted. 
        if((temp->next->value) - (temp->value) != 1){
            //while temp is mooving forward, assign the temp value to oper, and delete oper. Until temp->next is empty, continue.
            oper = temp->next;
            temp->next = oper->next;
            delete oper;
        }
        else{
            temp = temp->next;
        }
    }
}

// Get another basket’s nodes and add them to the basket without breaking the order of the nodes.    
void stack::merge_basket(stack &second){
    //if the second stack is empty, we should get firat basket directly.
    if(second.top == nullptr){
        return ;
    }
    //if the first stack is empty, our second stack should be assgned to first one, and the second one should be empty.
    if(top == nullptr){
        top = second.top;
        second.top = nullptr;
        return;
    }

    Node *head1;
    Node *head2;
    Node *head3;
    Node *temp3;

    head1 = top;
    head2 = second.top;
    head3 = nullptr;

    //to pick smallest one from stacks
    if(head1->value <= head2->value){
        head3 = head1;
        //to cotinue to compare with other elements if the top is smallest.
        head1 = head1->next;
    }
    else{
        head3 = head2;
        //to cotinue to compare with other elements if the top of second stack is smallest.
        head2 = head2->next;
    }
    
    //continue to compare other all elements
    //to add new elements to new linked list
    temp3 = head3;
    while(head1 && head2){
        Node *add = nullptr;
        //find smallets one, assign to node add, and jump the next one.
        if(head1->value <= head2->value){
            add = head1;
            head1 = head1->next;
        }
        else{
            add = head2;
            head2 = head2->next;
        }
        
        //to make connected the nodes
        temp3->next = add;
        temp3 = temp3->next;
    }

    //if the second stack is over, but the first one is here still, next elements of new linked list shoul be remaining elements of the first list. 
    if(head1){
        //to connect remaining elements
        temp3->next = head1;
        head1 = nullptr;
    } 
    //if the first stack is over, but the second one is here still, next elements of new linked list shoul be remaining elements of the second list. 
    else if(head2){
        //to connect remaining elements
        temp3->next = head2;
        head2 = nullptr;
    }


    //assign new linked list to first stack
    top = head3;
    head3 = nullptr;
    //delete the second stack
    second.top = nullptr;
}
