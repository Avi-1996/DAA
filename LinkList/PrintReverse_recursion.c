void reversePrint(SinglyLinkedListNode* head) {
  if (head->next != NULL) {
    reversePrint(head->next);
  }
  printf("%d\n", head->data);
}
