#include<iostream> 
//#include<SinglyLinkedList.cpp>
using namespace std; 

class SNode
{
    public:
    int data;
    SNode* next;

    SNode(int x)
    {
        data=x;
        next=NULL;
    }
};

class SinglyLinkedList
{
    SNode* head; //Stores the head of the List can be NULL too
    SNode* tail; //Optional but improves performance
    int size;


    public: 
    SinglyLinkedList()
    {
        head=NULL;
        tail=head;
        size=0;
    }

    void insertAtEnd(int d)
    {
        SNode* newNode = new SNode(d);
        if(head==NULL)
        {
            head = newNode;
            return;
        }    

        SNode* dummy = head;
        while(dummy->next!=NULL)
        {
            dummy=dummy->next; //Skipping all body            
        }
        
        dummy->next = newNode;
        tail = newNode;
        size++;
    }

    SNode* getHead()
    {
        return head;
    }

    void printList()
    {
        SNode* dummy=head;
        while(dummy!=NULL)
        {
            cout<<dummy->data<<" ";
            dummy=dummy->next;
        }
        cout<<endl;    
    }
};

bool checkWave(SNode* head){
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return true;
    SNode* curr = head;
    while(curr->next->next != nullptr){
        if(curr->data < curr->next->data && curr->next->data < curr->next->next->data) return false;
        if(curr->data > curr->next->data && curr->next->data > curr->next->next->data) return false;
        if(curr->data == curr->next->data && curr->next->data == curr->next->next->data) return false;
        curr = curr->next;
    }
    return true;
}

bool checkWaveSom(SNode* head){    
    int valid=0; 
    SNode* dummy = head;
    while(dummy->next!=NULL )
    {
        if(dummy->data > dummy->next->data) valid++;
        if(dummy->data < dummy->next->data) valid--;

        if(valid>1 || valid<-1) return false;

        dummy=dummy->next;
    }
    return true;
}

int main()
{
    SinglyLinkedList sll;
    sll.insertAtEnd(2);
    sll.insertAtEnd(2);
    sll.insertAtEnd(2);
    sll.insertAtEnd(1);
    sll.insertAtEnd(3);
    sll.insertAtEnd(1);
    sll.printList();
    cout<<"Has Wave(Rohit) : "<<checkWave(sll.getHead())<<endl;
    cout<<"Has Wave(Som) : "<<checkWaveSom(sll.getHead())<<endl;
}