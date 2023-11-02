#include <iostream>
#include <string>

struct Node{
    std::string data;
    Node *next;
};

class Lilist{
    public:
        Lilist(){head = NULL;}
        void add(std::string item);
        void show();
        Node* search(std::string target);
        void move_front_to_back();

    private:
        Node *head; // start ptr
        Node *cursor; // iterator ptr
};

void Lilist::add(std::string item){
    Node *tmp; //unused

    if(head == NULL){
        head = new Node;
        head -> data = item;
        head -> next = NULL;
    } else {
        for(tmp = head; tmp -> next != NULL; tmp = tmp -> next)
            ;// this loop simply advances the pointer to the last node in the list
        tmp -> next = new Node;
        tmp = tmp -> next;
        tmp -> data = item;
        tmp -> next = NULL;
    
    }
}

void Lilist::show(){
    for(Node *tmp = head; tmp != NULL; tmp = tmp -> next){
        std::cout << tmp -> data << "  ";
    }
}

Node* Lilist::search(std::string target){ 
    cursor = head;
    while(cursor != NULL){
        if(cursor -> data == target){
            return cursor;
        }
        cursor = cursor -> next;
    }
    return NULL;
}

void Lilist::move_front_to_back(){
    Node *tmp = head;
    while(tmp -> next != NULL){
        tmp = tmp -> next;
    }
    tmp -> next = head;
    head = head -> next;
    tmp -> next -> next = NULL; 
}