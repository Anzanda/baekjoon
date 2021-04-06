#include <iostream>
#include <list>
#include <vector>
using namespace std;

typedef struct __node{
    int data;
    struct __node* next;
}Node;

void insert(Node* head, int data, int n){
    Node* cur = head;
    for(int i=0; i<n; i++){
        cur = cur->next;
    }
    Node* newnode= new Node;
    newnode->data = data;
    newnode->next = nullptr;

    if(cur->next != nullptr)
        newnode->next = cur->next;
    cur->next = newnode;
    
}

void printNode(Node* head){
    Node* cur = head->next;
    while(cur!= nullptr){
        cout << cur->data << ' ';
        cur=cur->next;
    }
    cout << endl;
}
int n;
int main(void){
    cin >> n;
    Node* head = new Node;
    head->data = -1;
    head->next = nullptr;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        v[i] = num;
    }

    for(auto iter=v.rbegin(); iter!=v.rend(); iter++,n--){
        insert(head,n,*iter);
    }
    printNode(head);

    return 0;
}