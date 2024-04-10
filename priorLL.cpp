#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class node{
public:
    int data;
    node *link;
    node(int val){
        data = val;
        link = NULL;
    }
};
node *head=NULL;
void insert(int data) {
    if (head == NULL) {
        node *ptr = new node(data);
        ptr->link = head;
        head = ptr;
    } else {
        node *ptr = new node(data);
        node *temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = ptr;
        ptr->link = NULL;
    }
}
void display(){
    if(head==NULL) cout<<"Underflow";
    else{
        node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->link;
        }
        cout<<"NULL\n";
    }
}
void deletion(){
    if(head==NULL) cout<<"Empty"<<endl;
    node *max = head;
        node *temp = head; 
        while (temp != NULL) {
            if (temp->data > max->data)
                max = temp;
            temp = temp->link;
        }
        cout<<max->data<<" Deleted\n";
    swap(max->data,head->data);
    head=head->link;
}

int main(){
    insert(78);
    insert(12);
    insert(63);
    insert(6);
    insert(99);
    insert(29);
    display();
    deletion();
    display();
}