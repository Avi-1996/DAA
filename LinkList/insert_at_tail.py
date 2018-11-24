def insertNodeAtTail(head, data):
    temp = SinglyLinkedList()
    temp.data = data
    temp.next = None
    if head == None:
        head = temp
        return head
    else:
        temp1 = head
        while(temp1.next != None):
            temp1=temp1.next
        temp1.next = temp
        return head
