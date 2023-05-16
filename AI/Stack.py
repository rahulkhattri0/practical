class Stack:
    S=[]
    top=None
    def isEmpty(stk):
        if(stk==[]):
            return True
        else:
            return False
    def push(stk,item):
         stk.append(item)
         top=len(stk)-1
    def pop_s(stk):
        if(stk==[]):
            return ('underflow')
        else:
            i=stk.pop()
            # i=stk.pop()
            # if(len(stk)==0):
            #     top=None
            # else:
            #     top=top-1
        return i
    push(S,1)
    push(S,4)
    push(S,8)
    push(S,10)
    print(isEmpty(S))
    print(S)
    print("Popped :", pop_s(S))
    print(S)
    print("Popped :" , pop_s(S))
    print(S)