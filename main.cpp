#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
    node* prev;
};
node* tail=NULL;
node* head=NULL;
class linkedList{
    public:
        void insert(node* root, int n);
        void show(node* root);
        node* travarse(node* root, int value);
        void deleteNode(node* root);
        void deleteNodeN(node* root, int value);
};
//type-1 (recomended)
void linkedList:: insert(node* root, int n){
    node* new_node=new node();
    new_node->data=n;
    new_node->next=head;
    new_node->prev=tail;
    
    if(tail==NULL){
        tail=new_node;
        head=new_node;
        return;
    }
    tail->next = new_node;
    head->prev=new_node;
    tail=new_node;
}
//type-2
/*
void linkedList:: insert(node* root, int n){
    node* NewNode = new node(); 
    NewNode->data = n; 
    NewNode->next = NewNode; 
    NewNode->prev = NewNode; 
     
    if(tail==NULL){
     tail=NewNode;
     head=NewNode;
     return; 
    } 
    (tail->next)->prev = NewNode; 
    NewNode->next = tail->next; 
    NewNode->prev = tail; 
    tail->next = NewNode;
    tail=NewNode;
}
*/
node* linkedList:: travarse(node* root, int value){
    if(root->data == value)
        return root;
    travarse(root->next, value);
}
//delete node from the start/end of the list.
void linkedList:: deleteNode(node* root){
    (root->next)->prev = head->prev;
    head=head->next;
    
    //to delete from the end
    
    /*(tail->prev)->next = tail->next;
    tail=tail->prev;*/
    
}
//delete node which have specific value
void linkedList:: deleteNodeN(node* root, int value){
    node* temp = travarse(root,value);
    
    (temp->prev)->next = temp->next;
    (temp->next)->prev = temp->prev;
}
void linkedList:: show(node* root){
    for(root; root<=tail; root=root->next){
        cout<<root->data<<" ";
        if(root==tail)
            break;
    }
}
int main(){
    inkedList ob1;
    
    ob1.insert(tail,75);
    ob1.insert(tail,76);
    ob1.insert(tail,77);
    ob1.insert(tail,78);
    
    ob1.show(head);
    
    ob1.deleteNodeN(head,77);
    
    ob1.show(head);
    
    return 0;
}
