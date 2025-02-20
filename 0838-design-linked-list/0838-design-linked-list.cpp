class MyLinkedList {
public:

    struct Node{
        int val;
        Node * next;
        Node(int x){
            val = x;
            next = nullptr;
        }
    };

    Node * head;
    int size;

    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size) return -1;
        Node * temp = head;
        int i = 0;
        while(temp){
            if(i == index) return temp -> val;
            else {
                temp = temp -> next;
                i += 1;
            }
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node * newNode = new Node(val);
        if(head == NULL) head = newNode;
        else{
            newNode -> next = head;
            head = newNode;
        }
        size += 1;
    }
    
    void addAtTail(int val) {
        Node * newNode = new Node(val);
        if(head == NULL) head = newNode;
        else{
            Node * temp = head;
            while(temp -> next){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
        size += 1;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) return;
        if(index == 0) addAtHead(val);
        
        else{
            Node * newNode = new Node(val);
            Node * temp = head;
            for(int i = 0; i < index - 1; i++){
                temp = temp -> next;
            }
            newNode -> next = temp -> next;
            temp -> next = newNode;
        }
        size+=1;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;
        else if(index == 0){
            Node * temp;
            temp = head;
            head = head -> next;
            temp -> next = NULL;
        }
        else{
            Node * temp = head;
            for(int i = 0 ; i < index - 1; i++){
                temp = temp -> next;
            }
            temp -> next = temp -> next -> next;
        }
        size -= 1;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */