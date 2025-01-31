#include <stdio.h>

struct Node {
    int Data;
    struct Node *Next;
} typedef N;

void AddNode(N **, int Data);
void InsertNode(N **, int Data, int position);
void DeleteNode(N **, int position);
void ShowNode(N **);

int main() {
    N *start = NULL;
    int data = 0, pos = 0 ;
    printf( "Add (data) :" ) ; scanf( "%d", &data ) ; AddNode(&start, data);
    printf( "Add (data) :" ) ; scanf( "%d", &data ) ; AddNode(&start, data);
    printf( "Add (data) :" ) ; scanf( "%d", &data ) ; AddNode(&start, data);
    ShowNode( &start ) ; 

    printf( "Insert (data, pos) :" ) ; scanf( "%d %d", &data, &pos ) ; InsertNode(&start, data, pos );
    printf( "Insert (data, pos) :" ) ; scanf( "%d %d", &data, &pos ) ; InsertNode(&start, data, pos );
    printf( "Insert (data, pos) :" ) ; scanf( "%d %d", &data, &pos ) ; InsertNode(&start, data, pos) ;
    ShowNode(&start);

    printf( "Delete (pos) :" ) ; scanf( "%d", &pos ) ; DeleteNode(&start, pos);
    printf( "Delete (pos) :" ) ; scanf( "%d", &pos ) ; DeleteNode(&start, pos);
    printf( "Delete (pos) :" ) ; scanf( "%d", &pos ) ; DeleteNode(&start, pos);
    ShowNode(&start);

    return 0;
}

void AddNode( N **Walk, int Data) {
    while ( *Walk != NULL ) {
        Walk = &(*Walk)->Next ;
    }
    *Walk = new N ;
    (*Walk)->Data = Data ;
    (*Walk)->Next = NULL ;
}


void ShowNode(N **Walk) {
    N *walk = *Walk;
    while (walk != NULL) {
        printf("%d ", walk->Data); 
        walk = walk->Next;
    }
    printf("\n");
}


void InsertNode( N **Walk, int Data, int position) {
    int now = 0 ;
    N *newNode = new N ;
    newNode->Data = Data;    
    if ( position == 0 ) {
        newNode->Next = *Walk;  // โนดใหม่ชี้ไปที่โนดแรก
        *Walk = newNode ;  
    } else {
        while ( now != position - 1 ) {
            Walk = &(*Walk)->Next ;
            now ++ ;
            //printf( "(%d)" , now ) ;
        }
        newNode->Next = *Walk;  // โนดใหม่ชี้ไปที่โนดแรก
        *Walk = newNode ; 
    }
}

void DeleteNode( N **Walk, int position) {
    int now = 0 ;
    N *temp = *Walk;
    if ( position == 0 ) {
        *Walk = temp->Next;    // ให้หัวลิสต์ชี้ไปที่โนดถัดไป
        delete temp;
    } else {
        while ( now != position - 1 ) { //ไล่เดินโง่ๆแม่ง
            temp = temp->Next;
            now++;
        }
            if (temp->Next != NULL) {
            N *nodeToDelete = temp->Next;      // ชี้ไปที่โหนดที่จะลบ
            temp->Next = nodeToDelete->Next;  // เชื่อมโหนดก่อนหน้าไปยังโหนดถัดไป
            delete nodeToDelete;    
        }
    }
}
