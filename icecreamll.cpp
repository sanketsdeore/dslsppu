#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert(Node *&head, int val)
{
    Node *new_node = new Node(val);
    if (head == NULL)
    {
        head = new_node;
    }

    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void unions(Node *&result, Node *set1, Node *set2)
{
    Node *t1 = set1;
    Node *t2 = set2;

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->val < t2->val)
        {
            insert(result, t1->val);
            t1 = t1->next;
        }
        else if (t1->val > t2->val)
        {
            insert(result, t2->val);
            t2 = t2->next;
        }
        else
        {
            insert(result, t1->val);
            t1 = t1->next;
            t2 = t2->next;
        }
    }
    while (t1 != NULL)
    {
        insert(result, t1->val);
        t1 = t1->next;
    }
    while (t2 != NULL)
    {
        insert(result, t2->val);
        t2 = t2->next;
    }
}

void intersection(Node *&result, Node *set1, Node *set2)
{
    Node *t1 = set1;
    while (t1 != NULL)
    {
        Node *t2 = set2;
        while (t2 != NULL)
        {
            if (t1->val == t2->val)
            {
                insert(result, t1->val);
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
}

void diff(Node *&result, Node *set1, Node *set2)
{
    Node *t1 = set1;
    while (t1 != NULL)
    {
        Node *t2 = set2;
        int found = 0;
        while (t2 != NULL)
        {
            if (t1->val == t2->val)
            {
                found = 1;
                break;
            }
            t2 = t2->next;
        }
        if (found != 1)
        {
            insert(result, t1->val);
        }
        t1 = t1->next;
    }
}

void sym_diff(Node *&result, Node *set1, Node *set2)
{
    Node *t1=set1;
    Node *t2=set2;
    Node *result_diff1 = NULL;
    Node *result_diff2 = NULL;
    diff(result_diff1, t1, t2);
    diff(result_diff2, t2, t1);
    unions(result, result_diff1, result_diff2);
}

int main()
{
    Node *SE = NULL;
    Node *A = NULL;
    Node *B = NULL;

    insert(SE, 1);
    insert(SE, 2);
    insert(SE, 3);
    insert(SE, 4);
    insert(SE, 5);
    insert(SE, 6);
    insert(SE, 7);
    insert(SE, 8);
    insert(SE, 9);
    insert(SE, 10);

    insert(A, 1);
    insert(A, 5);
    insert(A, 10);
    insert(A, 9);

    cout << "Students who like Vanilla: ";
    display(A);

    insert(B, 1);
    insert(B, 3);
    insert(B, 5);
    insert(B, 6);
    insert(B, 9);
    cout << "Students who like Butterscotch: ";
    display(B);

    Node *result_union_list = NULL;
    unions(result_union_list, A, B);
    cout << "Students who like both Vanilla & Butterscotch: ";
    display(result_union_list);

    Node *result_symdiff_list = NULL;
    sym_diff(result_symdiff_list, A, B);
    cout << "Students who like either Vanilla or Butterscotch (not both): ";
    display(result_symdiff_list);

    Node *result_nothing_list = NULL;
    diff(result_nothing_list, SE, result_union_list);

    cout << "Students who neither like Vanilla nor Butterscotch: ";
    display(result_nothing_list);

    return 0;
}
