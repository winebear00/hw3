#include "llrec.h"
//#include <iostream>
//using namespace std; 

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
/*void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
	if (head==NULL)
    {
        smaller=NULL;
        larger=NULL;
        return; 
    }
    else if (head->val>pivot)
    {
        larger=head;
        head=head->next;
        llpivot(head, smaller, larger->next, pivot);   
    }
    else
    {
        smaller=head;
        head=head->next;
        llpivot(head, smaller->next, larger, pivot); 
    }
}*/

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    if (head==NULL)
    {
        smaller=NULL;
        larger=NULL;
        return; 
    }
    else 
    {
        llpivot(head->next, smaller, larger, pivot);
        if (head->val>pivot)
        {
            head->next=larger;
            larger=head; 
        }
        else 
        {
            head->next=smaller;
            smaller=head; 
        }
        head=NULL;    
    }
}

