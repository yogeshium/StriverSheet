//Approach 1: 
    /*
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* temp=head;
        while(temp){
            len++;
            temp=temp->next;
        }
        if(len==n) return head->next;
        int pos=len-n-1;
        temp=head;
        while(pos--){
            temp=temp->next;
        }
        ListNode* del=temp->next;
        temp->next=del->next;
        del->next=NULL;
        delete del;

        return head;
    }

//Approach 2:
    */
    ListNode* solve(ListNode* head, int& n){
        if(!head) return NULL;
        ListNode* temp = solve(head->next,n);
        n--;
        if(n){
            head->next=temp;
            return head;
        }
        head->next=NULL; delete head;
        return temp;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return solve(head,n);
    }

//Approach 3: 
    ListNode* removeNthFromEnd(ListNode* head, int n){
        if(!head->next) return NULL;
        ListNode *p1=head, *p2=head;
        while(n--){
            p2=p2->next;
        }
        if(!p2) return head->next;
        while(p2->next){
            p1=p1->next;
            p2=p2->next;
        }
        // cout<<p1->val<<endl;
        ListNode* del = p1->next;
        p1->next=del->next;
        del->next=NULL;
        delete del;

        return head;
    }
