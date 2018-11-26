def insertNodeAtHead(head, data):
    # Write your code here
    temp = SinglyLinkedList()
    temp.data = data
    temp.next =None
    if head == None:
        head = temp
    else:
        temp.next = head
        head = temp
    return head
