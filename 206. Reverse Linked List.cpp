  //Approach 1:
    /* 
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *curr=head, *prev=NULL, *nxt=NULL;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }

        return prev;
    }
    */
    //Approach 2: 
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL) return head;

        ListNode* newHead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;

        return newHead;
    }
    ListNode* reverseList(ListNode* head) 
    {
        return reverse(head);
    }
