#include <stdio.h>

class Node {
    public:
        int Data;
        Node *Next;
        Node *Back;
    public:
        Node(int data = 0) : Data(data), Next(NULL), Back(NULL) {}
} ;

class DoubleLinkedList : Node {
    private:
        Node *head;
    public:
        DoubleLinkedList() : head(NULL) {}
        void AddNode() ;
        void InsertNode() ;
        void DeleteNode() ;
        void ShowFront() ;
        void ShowBack() ;
} ;

int main() {
    DoubleLinkedList A, B;
    A.AddNode(); A.AddNode(); A.ShowFront();
    A.InsertNode(); A.InsertNode(); A.ShowFront();
    A.DeleteNode(); A.DeleteNode(); A.ShowFront();
    printf( "---\n" ) ;
    B.AddNode() ; B.AddNode() ; B.AddNode() ; B.ShowBack() ;
    return 0;
}

void DoubleLinkedList :: ShowBack() {
    Node* temp = this->head;
    
    while (temp != NULL && temp->Next != NULL) {
        temp = temp->Next;
    }
    while ( temp != NULL ) {
        printf( "%d " , temp->Data ) ;
        temp = temp->Back ;
    }
    printf("\n") ;
}

void DoubleLinkedList :: ShowFront() {
    Node* temp = this->head;
    while ( temp != NULL ) {
        printf( "%d " , temp->Data ) ;
        temp = temp->Next ;
    }
    printf("\n") ;
    
}

void DoubleLinkedList :: DeleteNode() {
    int pos = 0 ;
    //printf( "Delete (pos) :" ) ; 
    scanf( "%d", &pos ) ;
    Node** walk = &this->head;
    Node* temp = *walk;
    int now = 1 ;
    if ( pos == 1 ) {
        *walk = temp->Next;
        delete temp;
    } else {
        while ( temp != NULL && now < pos - 1) {
            temp = temp->Next;
            now++;
            //printf( "%d\n" , now ) ;
        }
        if (temp->Next != NULL) {
            Node* nodeToDelete= temp->Next;      // ชี้ไปที่โหนดที่จะลบ
            temp->Next = nodeToDelete->Next;  // เชื่อมโหนดก่อนหน้าไปยังโหนดถัดไป
            delete nodeToDelete;    
        }
    }
}

void DoubleLinkedList :: InsertNode() {
    int data = 0 , pos = 0 ;
    //printf( "InsertNode(data pos) " ) ;
    scanf( "%d %d" , &data , &pos ) ;
    Node** walk = &this->head;
    Node* newNode = new Node(data);
    int now = 1 ;
    if( pos == 1 ) {
        newNode->Next = *walk ;
        if( *walk != NULL ) {
            (*walk)->Back = newNode ;
            
        }
        *walk = newNode ;
    }else {
        while ( *walk != NULL && now < pos - 1 ) {
            walk = &((*walk)->Next);
            now ++ ;
        }
        if (*walk == NULL) {
            *walk = newNode ;
        } else {
            newNode->Next = (*walk)->Next;
            newNode->Back = *walk;
        }
        if ((*walk)->Next != NULL) { // ตรวจสอบว่ามีโหนดถัดไปหรือไม่
            (*walk)->Next->Back = newNode;
        }
        (*walk)->Next = newNode;
    }
}

void DoubleLinkedList :: AddNode() {
    int data = 0 ;
    //printf( "Add node " ) ;
    scanf( "%d" , &data ) ;
    struct Node **walk ;  
    walk  = &(this->head) ;
    struct Node *temp = NULL ;
    
    while ( *walk != NULL)  {
        temp = *walk ;
        walk = &(*walk)->Next ;
    }
    
    *walk  = new struct Node ;
    (*walk)->Data = data ;
    (*walk)->Next = NULL ;
    (*walk)->Back = temp ;
}
