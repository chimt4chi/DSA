struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    // calculate length
    int length = 0;
    ListNode *curr = head;
    while (curr != nullptr)
    {
      length++;
      curr = curr->next;
    }

    int target = length - n + 1; // calculate target

    // if the target is head
    if (target == 1)
    {
      ListNode *temp = head;
      head = head->next;
      delete temp;
      return head;
    }

    curr = head; // reset curr to head.
    for (int i = 1; i < target - 1; i++)
    {
      curr = curr->next;
    }

    ListNode *toDelete = curr->next;
    curr->next = curr->next->next;
    delete toDelete;
    return head;
  }
};