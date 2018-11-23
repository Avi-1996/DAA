SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    struct SinglyLinkedListNode *temp1,*temp;
    temp1 = (struct SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    temp->data = data;
    temp1->next = NULL;
    if(head == NULL){
        head = temp1;
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next = temp1;
    }
    return head;
}
