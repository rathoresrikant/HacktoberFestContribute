class Node:
    def __init__(self,key):
        self.val=key
        self.left=None
        self.right=None
#print function
def oddLevelPrint(root):
    temp=[root]
    temp2=[];anstemp=[];ans=[];cnt=0
    while len(temp)>0:
        while len(temp)>0:
            cur=temp.pop()
            if cnt%2==0:
                anstemp.append(cur.val)
            if cur.left:
                temp2.append(cur.left)
            if cur.right:
                temp2.append(cur.right)
        temp=temp2
        if not cnt%2:ans.append(anstemp)
        cnt+=1
        temp2=[];anstemp=[]
    return ans
#inititalization of tree
if __name__ == "__main__":
        start=Node(10)
        start.left=Node(20)
        start.right=Node(30)
        start.right.right=Node(25)
        start.right.left=Node(45)
        start.left.right=Node(59)
        start.left.left=Node(21)
        start.left.left.right=Node(15)
        start.left.left.right.left=Node(33)
        # print(*oddLevelPrint(start),end="\n")
        cnt=1
        for elements in oddLevelPrint(start):
            print("Level {0} elements are ".format(cnt));[print(i,end=" ") for i in elements]
            print()
            cnt+=1
        
        

