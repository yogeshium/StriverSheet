//Approach 1: 

    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2)
    {
        if(!h1) return h2;
        if(!h2) return h1;
        
        ListNode *curr=NULL;
        if(h1->val<=h2->val){
            curr=h1;
            h1=h1->next;
        }
        else{
            curr=h2;
            h2=h2->next;
        }
        ListNode* resHead=curr;
        while(h1 && h2){
            if(h1->val<=h2->val){
                curr->next=h1;
                curr=curr->next;
                h1=h1->next;
            }
            else{
                curr->next=h2;
                curr=curr->next;
                h2=h2->next;
            }
        }
        if(h1) curr->next=h1;
        if(h2) curr->next=h2;

        return resHead;
    }
