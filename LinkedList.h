#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

#include "Node.h"

template <class T>
class LinkedList
{
public: // DO NOT CHANGE THIS PART.
    LinkedList();
    LinkedList(const LinkedList<T> &rhs);
    ~LinkedList();

    LinkedList<T> &operator=(const LinkedList<T> &rhs);

    int getSize() const;
    bool isEmpty() const;
    bool containsNode(Node<T> *node) const;
    int getIndex(Node<T> *node) const;

    Node<T> *getFirstNode() const;
    Node<T> *getLastNode() const;
    Node<T> *getNode(const T &data) const;
    Node<T> *getNodeAtIndex(int index) const;

    void append(const T &data);
    void prepend(const T &data);
    void insertAfterNode(const T &data, Node<T> *node);
    void insertAtIndex(const T &data, int index);
    void moveToIndex(int currentIndex, int newIndex);
    void mergeNodes(int sourceIndex, int destIndex);

    void removeNode(Node<T> *node);
    void removeNode(const T &data);
    void removeNodeAtIndex(int index);
    void removeAllNodes();

    void print() const;

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.

private: // DO NOT CHANGE THIS PART.
    Node<T> *head;
    int size;
};

template<class T>
LinkedList<T>::LinkedList()
{
    head = new Node<T>(T());
    size = 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &rhs)
{   
    Node<T> *temp;
    Node<T> *current;
    temp=rhs.getFirstNode();
    
    head = new Node<T>(T());
    size = 0;
    
    if (temp){
        
        
        head->next = new Node<T>(temp->data);
        head->next->prev=head;
        size++;
        
        while(temp->next!=NULL){
            temp=temp->next;
            current=this->getLastNode();
            
            current->next=new Node<T>(temp->data);
            current->next->prev=current;
            size++;
        }
    }
}

template<class T>
LinkedList<T>::~LinkedList()
{   
    Node<T>* curr = head->next;
    Node<T>* temp;
    
    while (curr!=NULL) {
        temp = curr;
        curr = curr->next;
        delete temp;
    }
    size = 0;
    delete head;
}

template<class T> 
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs)
{
    Node<T> *temp;      
    Node<T> *current;            
    Node<T> *n;                           

    
                               
    if (!rhs.isEmpty() && &rhs!=this) {
        this->removeAllNodes();
        
        temp = rhs.getFirstNode();
        
        n=new Node<T>(temp->data);
        head->next = n;
        n->prev=head;
        size++;

        while (temp->next != NULL) {     
            temp = temp->next;
            current = this->getLastNode();
            
            n = new Node<T>(temp->data);
            current->next = n;
            current->next->prev = current;
            size++;
        }
    }


    return *this;
}


template<class T> 
int LinkedList<T>::getSize() const
{
   return size;
}

template<class T>
bool LinkedList<T>::isEmpty() const
{
    if (head->next==NULL){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
bool LinkedList<T>::containsNode(Node<T> *node) const
{
    int i=0;
    Node<T> *temp;
    temp = head->next;
    
    if (temp==NULL){
        return false;
    }
    
    while(temp!=NULL){
        if (node==temp){
            i=1;
        }
        temp=temp->next;
    }
    
    if(i){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
Node<T> *LinkedList<T>::getFirstNode() const
{
    return head->next;
}

template<class T>
Node<T> *LinkedList<T>::getLastNode() const
{
    Node<T> *temp;
    temp=head->next;
    if (temp==NULL){
        return NULL;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        return temp;
    }
}

template<class T>
Node<T> *LinkedList<T>::getNode(const T &data) const
{
    Node<T> *temp;
    temp=head->next;
    
    while(temp!=NULL){
        if(temp->data == data){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

template<class T>
Node<T> *LinkedList<T>::getNodeAtIndex(int index) const
{   
    Node<T> *temp;
    if(index<size){ 
        
        temp=head->next;
        
        for(int i=0;i<index;i++){
            temp=temp->next;
            
        }
        return temp;
    }
    else{
        return NULL;
    }
}

template<class T>
void LinkedList<T>::append(const T &data)
{   
    
    Node<T> *temp;
    Node<T> *n;
    n=new Node<T>(data);
    
    if(head->next==NULL){
        head->next=n;
        n->prev=head;
    }
    else{
        temp=this->getLastNode();
        
        temp->next=n;
        n->prev=temp;
        
        
    }
    this->size++;
}

template<class T>
void LinkedList<T>::prepend(const T &data)
{
    Node<T> *temp;
    Node<T> *alfa;
    temp=head->next;
    
    alfa=new Node<T>(data);
    
    if (temp==NULL){
        head->next=alfa;
        alfa->prev=head;
    }
    else{
        head->next=alfa;
        alfa->prev=head;
        alfa->next=temp;
        temp->prev=alfa;
    }
    size++;
}

template<class T>
void LinkedList<T>::insertAfterNode(const T &data, Node<T> *node)
{
    Node<T> *n;
    
    if (this->containsNode(node)){
        n = new Node<T>(data);
        
        if(node->next==NULL){
            node->next=n;
            n->prev=node;
        }
        else{
            n->prev=node;
            n->next=node->next;
            node->next=n;
            n->next->prev=n;
        }
        size++;
    }
    
}

template<class T>
void LinkedList<T>::insertAtIndex(const T &data, int index)
{
    
    Node<T> *current;
    Node<T> *n;
    
    if(index<size){
        
        n=new Node<T>(data);
        
        if (index==0){
            current=head->next;
            
            head->next=n;
            n->prev=head;
            
            n->next=current;
            current->prev=n;
        }
        else{
            current=this->getNodeAtIndex(index);
            n->next=current;
            n->prev=current->prev;
            current->prev->next=n;
            current->prev=n;
        }
    }
    this->size++;
}

template<class T>
int LinkedList<T>::getIndex(Node<T> *node) const
{

    int i=0;
    int flag=1;
    Node<T> *temp;
    
    temp=head->next;
    
    if(this->containsNode(node)){
        
        while(flag){
            if(node == temp){
                flag=0;
            }
            else{
                temp=temp->next;
                i++;
            }
        }
    }
    else{
        return -1;
    }
    
    return i;
}

template<class T>
void LinkedList<T>::moveToIndex(int currentIndex, int newIndex)
{
    Node<T> *current;
    Node<T> *target;
    if (currentIndex != newIndex && currentIndex < size)
    {

        
        if(newIndex >= size){
            newIndex=size-1;
        }
        current = getNodeAtIndex(currentIndex);
    
        //kopardık
        if(current->next!=NULL){//ara eleman
            current->prev->next=current->next;
            current->next->prev=current->prev;
        }
        else{//son
            current->prev->next=NULL;
        }
        current->next=NULL;
        current->prev=NULL;
    
        if (newIndex == 0)
        {
         
            current->prev = head;
            current->next = head->next;
            head->next = current;
            current->next->prev = current;
        }
        else
        {
           
            target = getNodeAtIndex(newIndex - 1);
            current->prev = target;
            current->next = target->next;
            target->next = current;
            if (current->next!=NULL)
            {
                current->next->prev = current;
            }
        }
    
    }
}





template<class T>
void LinkedList<T>::mergeNodes(int sourceIndex, int destIndex)
{
    Node<T> *source;
    Node<T> *dest;
    
    source=this->getNodeAtIndex(sourceIndex);
    dest=this->getNodeAtIndex(destIndex);
    
    dest->data=dest->data + source->data;
    
    this->removeNodeAtIndex(sourceIndex);
}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node)
{
    if(this->containsNode(node)){
        this->removeNodeAtIndex(this->getIndex(node));
    }
}

template<class T>
void LinkedList<T>::removeNode(const T &data)
{   
 
    Node<T>* node;
    int flag=1;
    
    while(flag){ 
        node=this->getNode(data);
        if(node==NULL){
            flag=0;
        }
        else{
            this->removeNode(node);
        }
    }
}

template<class T>
void LinkedList<T>::removeNodeAtIndex(int index)
{

    Node<T>* node;
    
    if(index<size && index > -1){
        node=this->getNodeAtIndex(index);
    
    
        if(index==size-1){
            node->prev->next=NULL;
            delete node;
            size--;
        }
        else{
            node->prev->next=node->next;
            node->next->prev=node->prev;
            delete node;
            size--;
        }
    }
    
}

template<class T>
void LinkedList<T>::removeAllNodes()
{   
    Node<T>* current = head->next;
    Node<T>* temp;
    while (current!=NULL) {
        temp = current;
        current = current->next;
        delete temp;
    }
    head->next=NULL;
    size = 0;
}


template<class T>
void LinkedList<T>::print() const
{
    if (this->isEmpty()) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    Node<T> *node = this->getFirstNode();

    while(node)
    {
        std::cout << *node << std::endl;
        node = node->next;
    }

}

#endif //LINKEDLIST_H