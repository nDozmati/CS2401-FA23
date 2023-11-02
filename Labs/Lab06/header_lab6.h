#include <cstdlib>
#include <iostream>

struct node{
     int data;
     node* next;
};

// remove all repeats inside of the list
void remove_repeats(node*& head) {
    node *cursor = head; // iterator
    node *target; // data in question
    node *duplicate; // repeated value

    // select elements one by one while the link exists
    while(cursor != nullptr && cursor -> next != nullptr){
        // start from 1st item (since cursor = head)
        target = cursor;

        // compare the target value to the rest of the list
        while(target -> next != nullptr){

            // if the cursor and the next item, target, equal, delete the duplicate
            if(cursor -> data == target -> next -> data){
                // we found a duplicate
                duplicate = target -> next;
                // iterate target past the duplicate value
                target -> next = target -> next -> next;
                // remove the duplicate value
                delete (duplicate);
            // if we don't find any duplicates
            } else {
                // iterate target (while loop)
                target = target -> next;
            }

        }
        // iterate cursor (while loop)
        cursor = cursor -> next;
    }
}

// split the list at a value present in the list
void split_list(const node* original, node*& lesser, node*& greater, int split_value) {
    // iterators so we don't change head
    node *cursor_lesser, *cursor_greater;
    // counters so we iterate the new nodes correct for our first pass
    int lesser_counter = 0, greater_counter = 0;

    const node *cursor_original = original; // original is head, and we do not want to change head
    // go through the entire linked list through an iterator
    while(cursor_original != nullptr){
        // adding to lesser list
        if(cursor_original -> data < split_value){
            // iterate correctly for a first pass
            if(lesser_counter == 0) {
                lesser = new node;
                lesser -> data = cursor_original -> data;
                lesser -> next = nullptr;
                lesser_counter++;
            // after we set up our list, do this for the rest
            } else {
                // set cursor to head of list
                cursor_lesser = lesser;
                // find the end of the list using the cursor
                while(cursor_lesser -> next != nullptr) {
                    cursor_lesser = cursor_lesser -> next;
                }
                // add data to new node inserted at end of list
                cursor_lesser -> next = new node;
                cursor_lesser = cursor_lesser -> next;
                cursor_lesser -> data = cursor_original -> data;
                cursor_lesser -> next = nullptr;
            }
        }
        // same stuff but for values greater than the split value
        if(cursor_original -> data > split_value){

            if(greater_counter == 0) {
                greater = new node;
                greater -> data = cursor_original -> data;
                greater -> next = nullptr;
                greater_counter++;

            } else {

                cursor_greater = greater;

                while(cursor_greater -> next != nullptr) {
                    cursor_greater = cursor_greater -> next;
             }
            
                cursor_greater -> next = new node;
                cursor_greater = cursor_greater -> next;
                cursor_greater -> data = cursor_original -> data;
                cursor_greater -> next = nullptr;
            }
        }
        // iterate cursor for while loop, not head (we don't move head unless we are removing it)
        cursor_original = cursor_original -> next;
    }
}

// builds a linked list of 2000 random integers, all in the range 1 - 500
void build_list(node*& head){
     node* cursor;

     head = new node;
     head -> data = std::rand() % 500 + 1;

     cursor = head;
     for(int i = 0; i < 2000; ++i){
		cursor -> next = new node;
        cursor = cursor -> next;
        cursor -> data = std::rand() % 500 + 1;
     }
     cursor -> next = NULL;
}

// outputs the contents of a linked list to the screen
void show_list(const node* head){
     const node* cursor = head;

     while(cursor !=  NULL){
		std::cout << cursor -> data << "  ";
		cursor = cursor -> next;
	 }
	 std::cout << std::endl;
}

// returns the number of nodes in a linked list
int size(const node* head){
	const node* cursor = head;
	int count = 0;
	while(cursor != NULL){
  	    count++;
	    cursor = cursor -> next;
	}
	return count;
}