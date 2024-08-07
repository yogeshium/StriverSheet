  //Approach 1: 
    /*
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* temp = head;
        int len=0;
        while(temp){
            len++;
            temp=temp->next;
        }

        int mid = (len/2)+1;
        temp=head;
        while(--mid){
            temp=temp->next;
        }

        return temp;
    }
    */

    //Approach 2: 
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* sp=head, *fp=head;
        while(fp && fp->next){
            sp=sp->next;
            fp=fp->next->next;
        }

        return sp;
    }
