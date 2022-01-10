/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
class List;

class node{
    int data;
    
    public: 
    
    node* next;

    friend class List;
    //Constructor
    node(int d)
    {
        data = d;
        next = NULL;
    }
    int getData()
    {
        return data;
    }
    //Destructor
    // ~node()
    // {
    //     if(next != null)
    //     {
    //         delete next;
    //     }
    // }
};


class List
{
    node* head;
    node* tail;
    
    public:
    
    List()
    {
        head = NULL;
        tail = NULL;
    }
    
    // ~List()
    // {
    //     if(head != NULL)
    //     delete head;

    // }
    node* length()
    {
        return head;
    }
    
    void push_front(int data)
    {
        node* first = new node(data);
        
        if(head == NULL)
        {
            head = first;
            tail = first;
        }
        
        else
        {
            first->next = head;
            head = first;
        }
    }
    
    void push_back(int data)
    {
        node* last = new node(data);
        
        if(head == NULL)
        {
            push_front(data);
            return;
        }
        else
        {
            tail->next = last;
            tail = last;
        }
    }
    
    void insert(int data, int pos)
    {
        if(pos == 0)
        {
            push_front(data);
        }
        
        else
        {
            node* h = head;
            for(int jump = 1; jump <= pos - 1; jump++)
            {
                h = h->next;
            }
            
            node* inserted = new node(data);
            
            inserted->next = h->next;
            h->next = inserted;
        }
    }
    
    int search(int key)
    {
        node* temp = head;
        
        int i = 0;
        
        while(temp != NULL)
        {
            if(temp->data == key)
            return i;
            
            i++;
            
            temp = temp->next;
        }
        
        return -1;
    }
    
    int helper(node* head, int key)
    {
        if(head == NULL)
        return -1;
        
        if(head->data == key)
        return 0;
        
        int subrecidx = helper(head->next, key);
        
        if(subrecidx == -1)
        return -1;
        
        else
        return (subrecidx + 1);
    }
    
    
    int recsearch(int key)
    {
        int idx = helper(head, key);
        return idx;
    }
    
    void pop_front()
    {
        node* temp = head;
        head = head->next;
        temp->next = NULL; //important
        delete temp;
    }
    
    void pop_back()
    {
        if(head->next == NULL)
            head = NULL;
        else
        {
            
            node* temp;
            temp = head;
            
            while(temp->next->next != NULL) // to reach second last element
            {
                temp = temp->next;
            }
            
            node* last = temp->next;
            
            temp->next = NULL;
            
            //last->next = NULL; already null since it was last element
            
            delete last;
        }
        
    }
    void ndelete(int pos)
    {
        if(pos == 0)
        {
            pop_front();
            return;
        }
        
        node* temp = head;
        
        for(int jump = 1; jump <= pos - 1; jump++)
        {
            temp = temp->next;
        }
        
        if(temp == NULL)
        {
            cout << "out of bound";
            return;
        }
        
        if(temp->next->next == NULL)
        {
            pop_back();
            return;
        }
        
        node* todelete = temp->next;
        
        temp->next = temp->next->next;
        
        todelete->next = NULL; //important
        delete todelete;
    }
    
    void reverse(node* head)
    {
        // Initialize current, previous and
        // next pointers
        node* current = head;
        node *prev = NULL, *n = NULL;
 
        while (current != NULL) {
            // Store next
            n = current->next;
 
            // Reverse current node's pointer
            current->next = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }
};


int main()
{
    List l;
    
    l.push_front(1);
    l.push_front(0);
    l.push_back(15);
    l.insert(2, 2);
    l.insert(10, 0);
    l.push_back(4);
   // l.pop_front();
    //l.pop_back();
    //l.ndelete(4);
    node* head = l.length();
    l.reverse(head);
    node* h = l.length();
    while(h != NULL)
    {
        cout << h->getData() << "->";
        h = h->next;
    }
    
    //cout << endl << l.recsearch(1);

    return 0;
}
