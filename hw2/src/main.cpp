/* * * * * * * * * * * * * * * * * * * * *
* ONLY INDICATED PARTS SHOULD BE CHANGED *
* * * * * * * * * * * * * * * * * * * * */

/* @Author
* Student Name: <Öykü Eren>
* Student ID : <150200326>
*/

/* Necessary header files */
#include <iostream>
#include <cstdlib>
#include <limits>
#include "../include/stack.h"  // TODO: Do not forget to implement

using namespace std;



/* Declaration of the non-member functions */
void print_intro();
void print_basket_info(int);
bool check_end_game();
int get_random_number();
bool get_action();
bool apply_joker();
void empty_baskets();

/* Global stack variables which can be reached anywhere in main.cpp */
stack basket1, basket2, basket3;

int main(){
    /* Random number generator seed */
    srand(time(NULL));
    srand(42); // uncomment this and comment above line out while testing with Calico

    /* Print game intro to the console */
    print_intro();

    /* Variables to store total points and turn number */
    int points = 0, turn = 0;

    /* Initialize stack variables which is declared before */
    basket1.top = nullptr;
    basket2.top = nullptr;
    basket3.top = nullptr; 

    /* Boolean variable for end game condition */
    bool end_game = false;

    /* Main loop of the program */
    while (!end_game) {                     // while end game condition is NOT met

        system("clear");                    // clear console output

        print_basket_info(turn);            // print info of all baskets

        if (!get_action()) {                // users make their move
            points -= 10;                   // if users make an illegal move, reduce points
            continue;
        }                      

        end_game = check_end_game();        // check for end game condition

        /* If game does not end, give user 10 more points */
        if (!end_game){
            points += 10;
        }

        turn++;                             // go to the next turn
     }
    
    /* When game ends, print final basket info */
    print_basket_info(turn);                

    /* Print total points */
    cout << endl;
    cout << "GAME OVER." << endl;
    cout << "Total points: " << points << endl;

    /* Give all allocated memory back */
    empty_baskets();

    return 0;
}

/* Print game intro to the console */
void print_intro(){
    cout << " ____________________  " << endl;
    cout << "|                    | " << endl; 
    cout << "|    Hanoi Baskets   | " << endl;         
    cout << "|____________________| " << endl;      
    cout << " \\/\\/\\/\\/\\/\\/\\/\\/\\/\\/  " << endl;       
    cout << "  \\/\\/\\/\\/\\/\\/\\/\\/\\/   " << endl;       
    cout << "   \\/\\/\\/\\/\\/\\/\\/\\/    " << endl;         
    cout << "    \\/\\/\\/\\/\\/\\/\\/     " << endl;          
    cout << "     \\/\\/\\/\\/\\/\\/      " << endl;            
    cout << "      \\/\\/\\/\\/\\/       " << endl;          
    cout << "       \\/\\/\\/\\/        " << endl;
    cout << endl;
    cout << "Please put incoming numbers to one of three baskets with the goal of obtaining three baskets filled with numbers from highest (at the bottom) to the lowest (at the top)." << endl;
    cout << endl;
    cout << "Press enter to continue.." << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');      // Wait for enter key

    /* If we use cin.get() and user presses other than enter with 
    more than one character, we will end up with an endless loop. 
    So, we need to force stream to ignore the bad input. */
}

/* Print info of all baskets */
void print_basket_info(int turn){
    cout << endl;
    cout << "Turn " << turn << ": Baskets look like this:" << endl;

    //print elements at baskets by using stack function.
    cout << "Basket 1:" << endl;;
    basket1.print_all();

    cout << "Basket 2:" << endl;;
    basket2.print_all();

    cout << "Basket 3:" << endl;;
    basket3.print_all();       

    cout << endl;
}

/* Check for end game condition */
bool check_end_game(){
    /* TODO */
    bool result = false;
    /*if these baskets are not descended, the game should end. If the basket are not descended, is_descending function returns true. 
    So, if one of if conditions is true at least, result will be true and game will end*/
    if(basket1.is_descending() || basket2.is_descending() || basket3.is_descending()){
        result = true;
    }

    return result;
    /* TODO */
}


/* Get a random number between 0-10 */ 
int get_random_number(){

    int random = rand() % 10;
    cout << "Incoming number: " << random << endl;

    return random;
}

/* Users make their move */
bool get_action(){

    int number = get_random_number();   // get a random number between 0-10

    cout << endl;
    cout << "Press 0 to see jokers." << endl;
    cout << "Where to put the incoming number: ";
    int index;  
    cin >> index;                       // get input from the user for the next move
    
    /* If given input is not integer (illegal move), error will occur.
    Clean stream buffer and ignore the bad input. */
    if (cin.fail()) {
        cin.clear();    
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        index = -1;
    }

    /* TODO */
    // to put the incoming number to stack which is chosen by user.
    if(index == 1){
        basket1.push(number);
    } else if(index == 2){
        basket2.push(number);
    } else if(index == 3){
        basket3.push(number);
    } else if(index == 0){
        apply_joker();
        return false;
    //if it is invalid
    } else {
        std::cout << "Enter a valid move \n" << std::endl;
        return false;
    }

    /* TODO */

    return true;
}

/* User chooses to use a joker */
bool apply_joker(){
    cout << endl;
    cout << "Choose a joker: " << endl;
    cout << "1. Merge baskets: move elements from second basket to the first basket without breaking the order of the elements. (highest at the bottom, lowest at the top)" << endl;
    cout << "2. Sequentialize basket: remove elements which break consecutiveness from a basket." << endl;
    cout << endl;
    int index;  
    cin >> index;

    /* If given input is not integer (illegal move), error will occur.
    Clean stream buffer and ignore the bad input. */
    if (cin.fail()) {
        cin.clear();    
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        index = -1;
    }

    /* TODO */
    //if the joker merge baskets is choosen
    if(index == 1){
        //to get input for the first basket
        cout << "Choose first basket:"<< " ";
        int first;
        cin >> first;
        
        if (cin.fail()) {
        cin.clear();    
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        first = -1;
        }
        
        //to get input for the second basket
        cout << "Choose second basket:"<< " ";
        int second;
        cin >> second;

        if (cin.fail()) {
        cin.clear();    
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        second = -1;
        }

        //to call merge_basket function according to first basket and second basket choosen by user
        if(first == 1){
            if(second == 2){
                basket1.merge_basket(basket2);
            } else if(second == 3){
                basket1.merge_basket(basket3);
            }
        
        } else if(first == 2){
            if(second == 1){
                basket2.merge_basket(basket1);
            } else if(second == 3){
                basket2.merge_basket(basket3);
            }
        
        } else if(first == 3){
            if(second == 1){
                basket3.merge_basket(basket1);
            } else if(second == 2){
                basket3.merge_basket(basket2);
            }
        }
    
    //if the joker sequentilized baskets is choosen
    } else if(index == 2){
        //to get input to make sequentilized the basket is choosen
        cout << "Which basket should be sequentilized::"<< " ";
        int seq;
        cin >> seq;
        
        if (cin.fail()) {
        cin.clear();    
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        seq = -1;
        }

        //to call sequentilized function according to basket choosen by user
        if(seq == 1){
            basket1.sequentilized();
        } else if(seq == 2){
            basket2.sequentilized();
        } else if(seq == 3){
            basket3.sequentilized();
        }
    //if there is invalid input
    } else {
        std::cout << "Enter a valid move \n" << std::endl;
        return false;
    }
    /* TODO */

    return true;
}

/* Empty all baskets */
void empty_baskets(){

    /* TODO */
    //by uisnp pop funtion, delete all elements of baskets.
    while (basket1.top)
        basket1.pop();
    while (basket2.top)
        basket2.pop();
    while (basket3.top)
        basket3.pop();
    /* TODO */
}