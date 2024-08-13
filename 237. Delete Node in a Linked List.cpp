  void deleteNode(ListNode* node) 
    {
       node->val = node->next->val;
       ListNode* d = node->next;
       node->next=node->next->next;
       d->next=NULL;
       delete d;
    }
