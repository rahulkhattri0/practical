class Node:
    def __init__(self,val:int) -> None:
        self.val = val
        self.next = None

class LL:
    def __init__(self) -> None:
        self.head = None
        self.tail = None
    def append(self,val:int)->None:
        if(self.head==None and self.tail==None):
            self.head = Node(val)
            self.tail = Node(val)
        else:
            temp = self.head
            while(temp.next!=None):
                temp = temp.next
            node = Node(val)
            temp.next = node
            self.tail = node

    def dislpay(self):
        print("Element at tail:",self.tail.val,end="")
        print()
        temp = self.head
        while(temp!=None):
            print(temp.val,end="->")
            temp = temp.next
LinkedList = LL()
LinkedList.append(1)
LinkedList.append(2)
LinkedList.append(3)
LinkedList.dislpay()

