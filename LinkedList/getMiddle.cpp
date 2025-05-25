List *getMiddle(List *head)
{
  if (!head)
    return head;
  List *slow = head;
  List *fast = head->next;

  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}