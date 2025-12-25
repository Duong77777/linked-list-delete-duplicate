#include <iostream>
using namespace std;

struct Node { //khai báo cấu trúc Node 
    int data;   // khai báo kiểu dữ liệu trong đó data chưa thoong tin của kiểu dữ liệu 
    Node *next; // dấu * là con trỏ, trỏ đến phần tử kế tiếp
};

Node* createNode(int x){ // hàm khởi tạo con trởtrở
    Node* p = new Node();// trong đó Node* là kiểu dữ liệu con trỏ, p là tên con trỏ, new là toán tử tạo nên con trỏ mới sẽ cấp phát bộ nhớ trên heap 
    p->data = x;
    p->next = nullptr;
    return p;
   
}
 void AddNodeHead (Node* &head, int x){ //them node vao danh sach 
    Node* p =  createNode(x);
    p->next = head;
    head = p;
}
int main() {
    Node* head = nullptr;
    AddNodeHead(head, 3);
    AddNodeHead(head, 3);
    AddNodeHead(head, 2);
    AddNodeHead(head, 1);
    AddNodeHead(head, 1);
    AddNodeHead(head, 1);
    return 0;
     
}

 void Browselist (Node* head){
    Node* p = head;
    while (p != nullptr)
    {
        cout << p->data <<"\t";
        p = p->next;
    }
    cout << p->data;
 }
 void removeDuplicate (Node* head){
    if (head == nullptr) 
    return;
    Node* p = head;
    while (p->next != nullptr)
    if (p->data == p->next->data){
        Node* temp = p->next;
        p->next = temp->next;
    }
    else {
        p = p->next;
    }
 }
 void freeList(Node* &head){
    while (head != nullptr){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
 }