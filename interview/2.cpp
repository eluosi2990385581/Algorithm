/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ismt=0;
        int temp,temp1;
        int length1=0,length2=0;
        ListNode* temp2;
        for(temp2=l1;temp2!=NULL;temp2=temp2->next)
            length1++;
        for(temp2=l2;temp2!=NULL;temp2=temp2->next)
            length2++;
        if(length1>length2)
            {
                temp2=l2;
                while(temp2->next!=NULL)temp2=temp2->next;
                for(int i=0;i<length1-length2;i++)
                    {
                        temp2->next=new ListNode(0);
                        temp2=temp2->next;
                    }
            }
        if(length2>length1)
            {
                temp2=l1;
                while(temp2->next!=NULL)temp2=temp2->next;
                for(int i=0;i<length2-length1;i++)
                    {
                        temp2->next=new ListNode(0);
                        temp2=temp2->next;
                    }
            }

        temp=l1->val+l2->val;


        if(temp>=10)
        {
            temp=temp-10;
            ismt=1;
        }
        ListNode* l=new ListNode(temp);
        l1=l1->next;l2=l2->next;
        ListNode* h=l;
        while(l1 && l2)
        {
            temp1=ismt+l1->val+l2->val;
            ismt=0;
            temp=temp1;
            if(temp>=10)
            {
                temp=temp-10;
                ismt=1;
            }

            l->next=new ListNode(temp);
            l=l->next;
            l1=l1->next;l2=l2->next;

        }
        if(l1==NULL && l2==NULL && ismt==1)
            l->next=new ListNode(1);
        else if(l1==NULL && l2==NULL)
            return h;

        return h;
    }
};
