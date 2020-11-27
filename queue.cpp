# include <iostream>


struct qNode {
    int data;
    qNode *next;
    qNode (int value);
};


qNode::qNode(int value) {
    data = value;
    next = NULL;
}


class queueList {
    qNode* head;
    qNode* tail;
public:
    queueList();
    ~queueList();
    void enqueue(int value);
    void dequeue();
};


queueList::queueList() {
    head = NULL;
    tail = NULL;
}


queueList::~queueList() {
    qNode* temp;
    while (head != NULL) {
        temp = head->next;
        delete head;
        head = temp;
    }
    delete tail;
}


void queueList::enqueue(int value) {
    qNode* temp = new qNode(value); 
  
    if (tail == NULL) {
        head = temp;
        tail = temp;
    }
  
    tail->next = temp;
    tail = temp;
    std::cout << "Enqueue " << tail->data << std::endl;
}


void queueList::dequeue() {
    assert(head != NULL);

    qNode* temp = head;
    head = head->next;

    if (head == NULL) {
        tail = NULL;
    }

    std::cout << "Dequeue " << temp->data << std::endl; 
    delete temp;
}


int main() {
    queueList X;
    X.enqueue(10);
    X.enqueue(20);
    X.dequeue();
    X.dequeue();   
    return 0;
}