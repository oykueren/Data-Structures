//--- 2022-2023 Fall YZV201E Assignment 1 ---//
//--------------------------//
//---Name & Surname:
//---Student Number:
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include <iostream>  // For input/output operations
//#include <WordList.h>
#include <WordList.h>

//-------------Word Methods-------------//

Word::Word() {
  word_ = "";
  edit_dist_ = 999;  // An arbitrary number to set the distance as infinite
  next_ = NULL;
}

Word::Word(std::string vocab_word) {
  word_ = vocab_word;
  edit_dist_ = 999;  // An arbitrary number to set the distance as infinite
  next_ = NULL;
}

//to comparce characters, and if these are different, the code returns 2; if these are same, the code returns 1
int Word::SubsCost(char c1, char c2)
{
  if (c1 == c2)
    return 0;
  return 2;
}

//for EditDist method. It finds minimum value.
int min(int a, int b, int c){
  if(a <= b && a <= c)
    return a;
  else if(b<=a && b<=c)
    return b;
  else
    return c;
} 
//edit distance for a node.
int Word::EditDist(std::string str){
  int srcl;
  int trgtl;
  
  //to determine dimensions of matrix.
  srcl = word_.length() + 1;
  trgtl = str.length() + 1;

  int dis[srcl][trgtl];
  
  // to define every cell of matrix.
  for(int s = 0; s < srcl; s++){
    for(int t = 0; t < trgtl; t++){
        //at the first row, values should been increased one by one.
        if(s == 0){
          dis[s][t] = t;
        }
        
        //at the first column, values should been increased one by one.  
        else if(t == 0){
          dis[s][t] = s;
        }

        //for others, the code should find the value which the lowest possible.
        else{
          int subc_;
          //it calls SubsCost function, and the result is taken in subc_ 
          subc_= SubsCost(word_[s - 1], str[t - 1]);
          //to find the lowest value possible by looking above, to the left, and diagonal of the cell.
          //(dis[s - 1][t] + 1) is for deletion cost, (dis[s][t - 1] + 1) is for insertion cost, 
          //and (dis[s - 1][t - 1] + subc_) is for substitution cost
          dis[s][t] = min((dis[s - 1][t] + 1), (dis[s][t - 1] + 1), (dis[s - 1][t - 1] + subc_));
        }

    }
  }
  //return the last value of matrix
  return dis[srcl-1][trgtl-1];
}

//-------------WordList Methods-------------//

// Add all words to the list
void WordList::AddWord(std::string word) {
  //to create new pointer
  Word *newnode;
  newnode = new Word;
  newnode->word_ = word;

  // if the list is empty
  if (head_ == NULL){
    //to assign head_ and tail_ pointers to node of new word
    head_ = newnode;
    tail_ = newnode;
  }
  // if the list is not empty
  else{
    //to connect new node to linked list
    tail_->next_ = newnode;
    //to change position of tail_
    tail_ = newnode;
  }
}


// Print first "n" words from the list
void WordList::PrintWords(int n){
  // to create new pointer to go through linked list
  Word *traverse;
  traverse = head_;
  
  // if the list is not empty
  if(traverse){
    int i = 0;
    while ((i < n) && (traverse != NULL)) {
      std::cout << traverse->word_ << std::endl;
      //to go next ones.
      traverse = traverse->next_;
      i++;
      }
    // if there is no enough word.
    if (i < n-1){
    std::cout << "There are just" << i << "words." << std::endl;
    }
  }
  // if the list is empty
  else
    std::cout << "The list is empty." << std::endl;
}

// Calculate edit distances for all words in the list
void WordList::CalcEditDists(std::string str)
{
  //define new node to go through linked list
  Word *traverse = head_;
  while(traverse){
    //for every node of the linked listt, apply EditDist function
    traverse->edit_dist_= traverse->EditDist(str);
    traverse = traverse->next_;
  }
}

// Calculate edit distances for all words in the list
void WordList::PrintEditDists(int i)
{
  Word *traverse;
  traverse = head_;
  
  // if the list is not empty
  if(traverse){
    int n = 0;
    // to go throw linked list
    while ((n < i) && (traverse != NULL)) {
      std::cout << n+1 << ". " << traverse->edit_dist_<< std::endl;
      traverse = traverse->next_;
      n++;
      }
    
    //if there is no enough word
    if (i < n-1){
    std::cout << "There are just" << n << "words." << std::endl;
    }
  }
  // if the list is empty
  else
    std::cout << "The list is empty." << std::endl;
}
// Print "n" words that has the lowest edit distance
void WordList::SuggestWords(int i)
{
  Word *traverse;
  traverse = head_;

  //create new pointer to delete nodes of word selected
  Word *ptr;

  int min_v;

  //to find n words 
  for(int n = 0; n < i; n++){
    //min_v is defined as edit distance of head_
    min_v = head_->edit_dist_;
    ptr = NULL;
    while(traverse->next_){
      //compare edit distances of words, and if the new one is lower, the min value is changed
      //the word which is compared is traverse->next
      if (traverse->next_->edit_dist_ < min_v){
        //to change min_v
        min_v = traverse->next_->edit_dist_;
        ptr = traverse;
      }
      //to visit all nodes.
      traverse = traverse->next_;
    }
    //if there is no other words has lower edit distance than head_
    if(ptr == NULL){
      //print the word has the lowest edit distance and its word
      std::cout <<head_->word_<< " " << head_->edit_dist_ << std::endl;
      //to delete node of head_, and assign head_ to second node
      head_ = head_->next_;
      }
    //if the lowest value is tail_
    else if(ptr->next_->next_ == NULL){
      //print the word has the lowest edit distance 
      std::cout <<tail_->word_<< std::endl;
      std::cout <<tail_->edit_dist_<< std::endl;
      //to remove node of tail_
      ptr->next_=NULL;
      //to assign tail_ to new last node 
      tail_=ptr;
      }

    //for others  
    else{
      //print the word has the lowest edit distance
      std::cout <<ptr->next_->word_<< " " << ptr->next_->edit_dist_ << std::endl;
      //to remove the node
      ptr->next_=ptr->next_->next_;
      }
    //for while loop, make the traverse head_ everytime
    traverse = head_;  
  }
}

WordList::WordList() {
  this -> head_ = NULL;
}

WordList::~WordList() {
  Word* traverse = head_;

  // To make sure that we clear the memory when the program ends.
  while (traverse != NULL) {
    Word* temp = traverse;
    traverse = traverse -> next_;
    delete temp;
  }
}
