/* @Author
* Student Name: <Öykü Eren>
* Student ID : <150200326>
*/

#include <string>

//create class for nodes of tree
class Node{
public:
    int ID;
    int FC;
    int SW;
    int SE;

    //for bional tree 
    Node *right;
    Node *left;
};


class MapTree{
public:
    Node *root;

    //read from file the map into array
    int  **readfile();
    //for body part of that we create tree and define root
    void create_tree(int **arr);
    //as recersive, create rest of tree
    void rec_insert(int **arr, Node *root);
    //from tree, print the map in order
    void print_map_inorder(Node *parent);
    //find the maximum number of fish that the fisherman can catch
    int find_maxfish(Node *parent);
    //delete nodes of tree
    void deletree(Node *parent);
};