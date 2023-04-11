#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
};

void initList(node** h){
    *h = NULL;
}

int count(node** h){
    node* c = *h;
    int cont = 0;
    while (c != NULL)
    {
        cont++;
        c = c->next;
    }
    
    return cont;
}

void insertFront(node** h, int d){
    node* nNode = new node;
    nNode->data = d;
    nNode->next = *h;
    nNode->prev = NULL;

    *h = nNode;
}

void insertBack(node** h, int d){
    node* nNode = new node;
    nNode->data = d;
    nNode->next = NULL;

    if(*h == NULL){
        nNode->prev = NULL;
        *h = nNode;
        return;
    }

    node* last = *h;
    while(last->next != NULL){
        last = last->next;
    }

    nNode->prev = last;
    last->next = nNode;
}

void insertPosition(node** h, int d, int pos){
    int length = count(h);

    if(pos >= length){
        cout << "Node inexistent\n";
        return;
    }
    else if(pos == length-1){
        insertBack(h, d);
        return;
    }
    
    node* nNode = new node;
    nNode->data = d;
    node* copy = *h;

    for(int i = 0; i < pos-1; i++) copy = copy->next;

    nNode->next = copy->next;
    nNode->prev = copy;
    (copy->next)->prev = nNode;
    copy->next = nNode;
}

void showList(node** h){
    node* copy = *h;
    cout << "Showing: ";
    while(copy != NULL){
        cout << (copy->data) << " ";
        copy = copy->next;
    }
    cout << "\n";
}

void showInverse(node** h){
    node* copy = *h;
    cout << "Showing: ";
    if(copy == NULL){
        cout << "List empty\n";
        return;
    }
    while(copy->next != NULL) copy = copy->next;

    while (copy != NULL){
        cout << (copy->data) << " ";
        copy = copy->prev;
    }
    cout << "\n";
}

void deleteFirst(node** h){
    node* copy = *h;
    *h = (*h)->next;
    (*h)->prev = NULL;
    delete copy;
}

void destroyList(node** h){
    while(*h != NULL){
        node* dest = *h;
        *h = (*h)->next;
        delete dest;
    }
}

int main(){
    node* listF;
    node* listB;
    node* listA;
    node* listE;
    initList(&listF);
    initList(&listB);
    initList(&listA);
    initList(&listE);

    cout << "Inserting and showing F...\n";
    insertFront(&listF, 1);
    insertFront(&listF, 2);
    insertFront(&listF, 3);
    showList(&listF);

    cout << "\nInserting and showing B...\n";
    insertBack(&listB, 1);
    insertBack(&listB, 2);
    insertBack(&listB, 3);
    showList(&listB);

    cout << "\nPreparing A...\n";
    insertBack(&listA, 4);
    insertBack(&listA, 8);
    insertBack(&listA, 2);
    insertBack(&listA, 7);
    insertBack(&listA, 3);
    insertBack(&listA, 5);
    insertBack(&listA, 6);

    cout << "\nCounting A...\n" << count(&listA) << endl;
    cout << "Showing A...\n";
    showList(&listA);
    cout << "Inserting in position 4 in A...\n";
    insertPosition(&listA, 1, 4);
    showList(&listA);
    insertPosition(&listA, 10, 1);
    showList(&listA);
    insertPosition(&listA, 100, 0);
    showList(&listA);
    insertPosition(&listA, 1000, -1);
    showList(&listA);
    insertPosition(&listA, 69, 100);
    showList(&listA);

    cout << "Showing A in reverse...\n";
    showInverse(&listA);

    cout << "\nDeleting first node in A...\n";
    deleteFirst(&listA);
    showList(&listA);


    cout << "\nDestroyig A...\n";
    destroyList(&listA); 
    cout << "Counting A...\n" << count(&listA) << endl;
    showList(&listA);

    cout << "\nInserting in A...\n";
    insertBack(&listA, 4);
    insertBack(&listA, 8);
    showList(&listA);

    cout << "\nDeleting first node in A...\n";
    deleteFirst(&listA);
    showList(&listA);
    destroyList(&listA);
    showList(&listA);
    cout << "Terminated";

    return 0;
}