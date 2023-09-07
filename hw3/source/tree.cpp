/* @Author
* Student Name: <Öykü Eren>
* Student ID : <150200326>
*/

#include <iostream>  // For input/output operations
#include <fstream>
#include <sstream>
#include "../include/tree.h"


using namespace std;

//read from file the map into array
int **MapTree::readfile(){
    //create array
    int **arrof_l = new int*[7];
    
    for (int i = 0; i < 7; i++)
        arrof_l[i] = new int[4];

    //read from file
    int i=0;
    string line;
    string file_name = "map.txt";
    ifstream myFile(file_name);
    if(myFile.is_open()) {
        while(!myFile.eof())
        {
            getline(myFile, line);
            
            string arr[4];
            int a = 0;
            //split the line by ' ' and assign the elements to arr
            stringstream ssin(line);
            while (ssin.good() && a < 4){
                ssin >> arr[a];
                ++a;
            }

            //assign the arrays of lines to arrof_l as subarray
            for(int m = 0; m<4; m++){
                arrof_l[i][m] = stoi(arr[m]);
            }
            i++;
        }
        myFile.close();
    }
    //if the system couldn't reach the file
    else{
        cout<<"Couldn't open the file\n";   
    }
    return arrof_l;
}
    
//for body part of that we create tree and define root
void MapTree::create_tree(int **arr){
    //assign the root from array
    //find the array with island id is 1
    int r = 0;
    while(arr[r][0]!= 1){
        r++;
    }

    //to assign characteristics of the island to node
    Node *newnode = new Node;
    //ID of the island
    newnode->ID = arr[r][0];
    //Fish count of the island
    newnode->FC = arr[r][1];
    //ID of the island which on the southwest of the island
    newnode->SW = arr[r][2];
    //ID of the island which on the southeast of the island
    newnode->SE = arr[r][3];

    root = newnode;
    root->left = nullptr;
    root->right =nullptr;

    //create other nodes of tree
    rec_insert(arr, root);
}


//as recersive, create rest of tree
void MapTree::rec_insert(int **arr, Node *p){    
    //to finish recursive, if the any of nodes will not have child
    if (!p->SW && !p->SE)
        return;

    //to add left child
    if(!p->left && p->SW != 0){
        int r=0;
        while(arr[r][0]!= p->SW){
            r++;
        }


        //to assign characteristics of the island to node
        Node *leftnode = new Node;
        //ID of the island
        leftnode->ID = arr[r][0];
        //Fish count of the island
        leftnode->FC = arr[r][1];
        //ID of the island which on the southwest of the island
        leftnode->SW = arr[r][2];
        //ID of the island which on the southeast of the island
        leftnode->SE = arr[r][3];

        p->left = leftnode;
        p->left->left = nullptr;
        p->left->right = nullptr; 
    }

    //to add right
    if(!p->right && p->SE != 0){
        int r = 0;
        while(arr[r][0]!= p->SE){
            r++;
        }

        //to assign characteristics of the island to node
        Node *rightnode = new Node;
        //Fish count of the island
        rightnode->ID = arr[r][0];
        //Fish count of the island
        rightnode->FC = arr[r][1];
        //ID of the island which on the southwest of the island
        rightnode->SW = arr[r][2];
        //ID of the island which on the southeast of the island
        rightnode->SE = arr[r][3];

        p->right = rightnode;
        p->right->left = nullptr;
        p->right->right = nullptr; 
    }

    //call the recersive to add nodes for children which we assign above
    //for the left child
    if (p->SW)
        rec_insert(arr, p->left);
    //for the right child
    if (p->SE)
        rec_insert(arr, p->right);
    
}

//from tree, print the map in order
void MapTree::print_map_inorder(Node *parent){
    if(parent){
        //firstly, print left one.
        print_map_inorder(parent->left);
        //secondly, print parent.
        cout<<parent->ID<<" "<<parent->FC<<" "<<parent->SW<<" "<<parent->SE<<endl;
        //lastly, print right one.
        print_map_inorder(parent->right);
    }
}

//find the maximum number of fish that the fisherman can catch
int MapTree::find_maxfish(Node *parent){
    //if there is no any node, the fish will be catch is 0
    if (!parent){
        return 0;
    }

    //if there is no child of the parent, number of fish will be just parent's fish count
    if (!(parent->left) && !(parent->right)){
        return parent->FC;
    }

    //for left children, call recersive and find max number of fish
    int left_c = find_maxfish(parent->left);
    //for left children, call recersive and find max number of fish
    int right_c = find_maxfish(parent->right);

    //after finding max number for right and child, compare them, and add the number to account with parent's fish count
    int max_fc = max(left_c,right_c) + parent->FC;

    //return the maximum number of fish that the fisherman can catch 
    return max_fc;
}

//delete nodes of tree
void MapTree::deletree(Node *parent){
    if(parent){
        //delete the left child
        if(parent->left != nullptr){
            deletree(parent->left);
            parent->left = nullptr;
        }
        //delete the right child
        if(parent->right != nullptr){
            deletree(parent->right);
            parent->right = nullptr;
        }
        //delete the parent
        delete parent;
    }
}