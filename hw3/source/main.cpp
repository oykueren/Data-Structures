/* @Author
* Student Name: <Öykü Eren>
* Student ID : <150200326>
*/

#include <iostream>
#include <string>
#include "../include/tree.h"

using namespace std;

//delete the array
void arr_deleter(int **arr)
{
    int i = 0;
    while (i != 7)
    {
        delete [] arr[i];
        i++;
    }
    delete [] arr;
}


int main(){
     
    MapTree *mapTree = new MapTree;

    //create array
    int **arr = mapTree->readfile();
    
    //create tree
    mapTree->create_tree(arr);

    cout<<"THE MAP FOR GROUP OF ISLANDS"<<endl;

    //print tree of islands'map in order
    mapTree->print_map_inorder(mapTree->root);

    //find the maximum number of fish that the fisherman can catch, and assign this to max_value
    int max_value = mapTree->find_maxfish(mapTree->root);

    //print the maximum number of fish that the fisherman can catch
    cout<<"THE MAXIMUM NUMBER OF FISH THAT FISHERMAN CAN CATH: "<<max_value<<endl;
    
    //delete nodes of tree
    mapTree->deletree(mapTree->root);

    //delete array
    arr_deleter(arr);
    
    //delete tree
    delete mapTree;

    return 0;
}