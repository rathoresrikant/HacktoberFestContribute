 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 #define Node ListNode
 #define val data
 int compareList(Node *A, Node *B)
 {
     Node *curr1=A, *curr2=B;
     while(curr1!=NULL&&curr2!=NULL)
     {
         if(curr1->val!=curr2->val)
         return 0;
         
         curr1=curr1->next;
         curr2=curr2->next;
     }
     if(curr1==NULL && curr2==NULL)
     return true;
     
     return false;
 }
 
 Node *reverse(Node *A)
 {
     if(A==NULL)
     return NULL;
     
     Node *curr=A, *prev=NULL, *next;
     while(curr!=NULL)
     {
         next=curr->next;
         curr->next=prev;
         prev=curr;
         curr=next;
     }
     A=prev;
     return A;
 }
 
int Solution::lPalin(ListNode* A) {
    
    if(A==NULL||A->next==NULL)
    return 1;
    
    Node *fast,*prev_slow_ptr=NULL, *slow;
    slow=A;
    fast=A;
    
    while(fast&&fast->next)
    {
        prev_slow_ptr=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    
    Node *midnode=NULL;
    
    if(fast!=NULL)
    {
        midnode=slow;
        slow=slow->next;
    }
    
    prev_slow_ptr->next=NULL;
    Node *second_half=slow;
    
    second_half=reverse(second_half);
    int ans=compareList(A, second_half);
    
    if(midnode)
    {
        prev_slow_ptr->next=midnode;
        midnode->next=second_half;
    }
    else
    prev_slow_ptr->next=second_half;
    return ans;
    

    
}
