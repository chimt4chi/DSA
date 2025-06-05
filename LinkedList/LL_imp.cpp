#include <bits/stdc++.h>
using namespace std;

struct List {
  int data;
  List* next;
  List(){};
  List(int val){
    data = val;
    next = nullptr;
  }
  
};

void print(List* root) {
  while(root){
    cout << root->data << " ";
    root = root->next;
  }
}

List* insert(List* root, int val){
  List* newNode = new List(val);
  if(!root) return newNode;
  
  List* temp = root;
  while(temp->next){
    temp = temp->next;
  }
  temp->next = newNode;
  return root;
}

List* insertAtFront(List* root, int val){
  List* newNode = new List(val);
  if(!root) return newNode;
  
  newNode->next = root;
  root = newNode; // can skip this 
  return root; // return newNode
}

// List* rotate(List* head, int k) {
//     if (!head || k == 0) return head;

//     // Step 1: Find the length and tail
//     List* tail = head;
//     int len = 1;
//     while (tail->next) {
//         tail = tail->next;
//         len++;
//     }

//     // Step 2: Make the list circular
//     tail->next = head;

//     // Step 3: Find the new tail: (len - k % len - 1)th node
//     k = k % len;
//     int stepsToNewTail = len - k;
//     List* newTail = head;
//     for (int i = 1; i < stepsToNewTail; i++) {
//         newTail = newTail->next;
//     }

//     // Step 4: Set new head and break the loop
//     List* newHead = newTail->next;
//     newTail->next = nullptr;

//     return newHead;
// }

// List* rotate(List* head, int k) {
  //   if(!head && k == 0) return nullptr;

  //       List* tailPointer = head;
  //       while(k > 1){
  //           while(tailPointer->next){
  //               tailPointer  = tailPointer->next;
  //           }
  //           head->next = head;
  //           head = tailPointer;
  //           k--;
  //       }
  //   return head;
  // }
  
  List* rotate(List* head, int k) {
    if (!head || !head->next || k == 0) return head;

    int length = 0;
    List* temp = head;
    while (temp) {
        length++;
        temp = temp->next;
    }

    k = k % length;
    if (k == 0) return head;

    for (int i = 0; i < k; ++i) {
        List* prev = nullptr;
        List* curr = head;

        // Move to the last node
        while (curr->next) {
            prev = curr;
            curr = curr->next;
        }

        // Move the last node to the front
        prev->next = nullptr;
        curr->next = head;
        head = curr;
    }

    return head;
}

List* getMiddle(List* head) {
    if (!head) return head;
    List* slow = head;
    List* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    cout << slow->data;
    return slow;
}

List* deleteByValue(List* head, int val){
  if(!head) return nullptr;
  
  if(head->data == val){
    List* temp = head;
    head = head->next;
    delete temp;
    return head;
  }
  
  List* temp = head;
  while(temp->next && temp->next->data != val){
    temp = temp->next;
  }
  
  if (temp->next && temp->next->data == val) {
      List* toDelete = temp->next;
      temp->next = temp->next->next;
      delete toDelete;
  }
  return head;
}

List* deleteByPos(List* head, int pos) {
    if (!head) return nullptr;

    List dummy;
    dummy.next = head;
    List* first = &dummy;
    List* second = &dummy;

    // Move first 'pos' steps ahead
    for (int i = 0; i < pos; ++i) {
        if (!first->next) return head; // pos > length of list
        first = first->next;
    }

    // Move both pointers until first reaches the end
    while (first->next) {
        first = first->next;
        second = second->next;
    }

    // Delete the target node
    List* toDelete = second->next;
    if (toDelete) {
        second->next = toDelete->next;
        delete toDelete;
    }

    return dummy.next;
}

List* deleteHead(List* head){
  if(!head) return nullptr;
  
  List* temp = head;
  head = head->next;
  delete temp;
  return head;
}

List* detectCycle(List* head){
  if(!head || !head->next) return nullptr;
  
  List* fast = head;
  List* slow = head;
  
  while(fast && fast->next){
    fast = fast->next->next;
    slow = slow->next;
        if (slow == fast) {  // Cycle detected
            // Now find the start of the cycle
            List* cycleStart = head;
            while (cycleStart != slow) {
                cycleStart = cycleStart->next;
                slow = slow->next;
            }
            return cycleStart;  // Return the node where the cycle starts
        }
  }
  return nullptr;
}

void printCycleStartNode(List* head) {
    List* cycleStart = detectCycle(head);
    if (cycleStart) {
        cout << "Cycle detected starting at node with data: " << cycleStart->data << endl;
    } else {
        cout << "No cycle detected." << endl;
    }
}


int main () {
  // method 1
  /* 
    List* head = new List(5);
    head->next = new List(10);
  */
  
  // Method 2
  // /*
    List* head = nullptr;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);
    // head = insertAtFront(head, 4);
    // head = insertAtFront(head, 3);
    // head = insertAtFront(head, 1);
    // head = insertAtFront(head, 2);
  // */
  // head = rotate(head, 1);
  // head = deleteByPos(head, 2);
  // print(head); // Output: 5 10 15
  // head = deleteHead(head);
  // cout << endl;
  // print(head); // Output: 5 10 15
  // head = detectCycle(head);
  // cout << endl;
  printCycleStartNode(head);
  // cout << endl;
  
  // head = deleteByValue(head, 25);
  
  // print(head); // Output: 5 10 15
  // getMiddle(head);
  return 0;
}
    head = insert(head, 3);

