#include <stdio.h>

struct Node {
    int Data;
    struct Node *Next;
    struct Node *Back;
} typedef N;

void AddNode( N **, int *Data);
void InsertNode( N **, int *Data, int *pos);
void DeleteNode( N **, int *pos ) ;
void SwapNode( N **, int *pos1, int *pos2 );
void ShowFront (N **);
void ShowBack( N **);
 
int main() {
    N *start = NULL;
    int data = 0, pos1 = 0, pos2 = 0 ; 

    AddNode( &start, &data ); AddNode(&start, &data); AddNode(&start, &data);
    ShowFront(&start);
    ShowBack(&start);

    InsertNode(&start, &data, &pos1); InsertNode(&start, &data, &pos1); InsertNode(&start, &data, &pos1);
    ShowFront(&start);

    DeleteNode(&start, &pos1); DeleteNode(&start, &pos1);
    ShowFront(&start);

    SwapNode(&start, &pos1, &pos2); ShowFront(&start);
    return 0;
}

void AddNode( N **Walk, int *Data) {
    //printf( "Add (data) :" ) ; 
    scanf( "%d", Data ) ;
    N *temp = NULL ;
    while ( *Walk != NULL ) {
        temp = *Walk ;
        Walk = &(*Walk)->Next ;
    }
    *Walk = new N ;
    (*Walk)->Data = *Data ;
    (*Walk)->Next = NULL ;
    (*Walk)->Back = temp ;
}

void ShowFront( N **Walk) {
    N *walk = *Walk;
    printf( "Show Front : " ) ;
    while (walk != NULL) {
        printf("%d ", walk->Data); 
        walk = walk->Next; 
    }
    printf("\n");
}

void ShowBack( N **Walk) {
    printf( "Show Back : " ) ;
    N *walk = *Walk;
    while (walk != NULL && walk->Next != NULL) {
        walk = walk->Next;
    }
    while (walk != NULL) {
        printf("%d ", walk->Data); 
        walk = walk->Back;
    }
    printf("\n");
}  

void InsertNode( N **Walk, int *Data, int *position) {
    //printf( "Insert (data, pos) :" ) ; 
    scanf( "%d %d", Data , position ) ;
    int now = 1 ;
    N *newNode = new N();  // สร้างโหนดใหม่
    newNode->Data = *Data; // กำหนดค่าข้อมูล
    newNode->Next = NULL;
    newNode->Back = NULL;
    N **temp = Walk;
    
    if ( *position == 1 ) {
         newNode->Next = *Walk;
        if (*Walk != NULL) {
           (*Walk)->Back = newNode;
        }
        *Walk = newNode; 
        return ;
    }
    while ( *temp != NULL && now < *position - 1 ) {
            temp = &((*temp)->Next);
            now ++ ;
        } 
    if (*temp == NULL) {
        *temp = newNode ;
         return ;
    }
        newNode->Next = (*temp)->Next;
        newNode->Back = *temp;
    
    if ((*temp)->Next != NULL) { // ตรวจสอบว่ามีโหนดถัดไปหรือไม่
        (*temp)->Next->Back = newNode;
    }
    (*temp)->Next = newNode;
    
}

void DeleteNode( N **Walk, int *position) {
    //printf( "Delete (pos) :" ) ; 
    scanf( "%d", position ) ;
    N *temp = *Walk;
    int now = 1 ;
    if ( *position == 1 ) {
        *Walk = temp->Next;
        delete temp;
    } else {
        while (temp != NULL && now < *position - 1) {
            temp = temp->Next;
            now++;
            //printf( "%d\n" , now ) ;
        }
        if (temp->Next != NULL) {
            N *nodeToDelete = temp->Next;      // ชี้ไปที่โหนดที่จะลบ
            temp->Next = nodeToDelete->Next;  // เชื่อมโหนดก่อนหน้าไปยังโหนดถัดไป
            delete nodeToDelete;    
        }
        
    }
}

void SwapNode(N **Walk, int *position1, int *position2) {
    //printf( "SwapNode( position1 , position2 )" ) ;
    scanf( "%d %d" , position1 , position2 ) ;
    N *temp = *Walk;
    N *pos1 = NULL;
    N *pos2 = NULL;
    int now = 0 , now2 = 0 , posss1 = 0 , posss2 = 0 ;
    while ( temp != NULL ) {
        if ( *position1 - 1 == now ) {
            pos1 = temp;
            posss1 = now + 1;
        }
        if ( *position2 - 1 == now ) {
            pos2 = temp;
            posss2 = now + 1;
        }
        temp = temp->Next;
        now++ ;
    }
    int tempData = pos1->Data;
    pos1->Data = pos2->Data;
    pos2->Data = tempData;
}
