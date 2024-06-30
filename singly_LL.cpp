// c++ program for creation,insertion,deletion and traversal of a singly linked list.

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    void create_List();
    void insert_Front();
    void insert_Mid();
    void insert_End();
    void delete_Front();
    void delete_Mid();
    void delete_End();
    void show_List();

} *newnode, *head = NULL, *temp;

void Node::create_List()
{
    int choice;
    // head = NULL;
    while (choice != 0)
    {
        newnode = new Node;
        cout << "Enter data to be inserted: ";
        cin >> newnode->data;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        cout << "Press 1 for creating another node, otherwise press 0: ";
        cin >> choice;
    }
}
void Node::insert_Front()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        newnode = new Node;
        cout << "Enter data to be inserted at front: ";
        cin >> newnode->data;
        newnode->next = head;
        head = newnode;
    }
}

void Node::insert_Mid()
{
    int pos, i = 1;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        newnode = new Node;
        temp = head;
        cout << "Enter position: ";
        cin >> pos;
        cout << "Enter data to be inserted: ";
        cin >> newnode->data;

        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void Node::insert_End()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        temp = head;
        newnode = new Node;
        cout << "Enter data to be inserted at the end: ";
        cin >> newnode->data;
        newnode->next = NULL;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void Node::delete_Front()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        temp = head;
        int del = temp->data;
        head = head->next;
        delete (temp);
        cout << "Node deleted which contains " << del << " data" << endl;
    }
}

void Node::delete_Mid()
{
    int pos;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }

    else
    {
        cout << "Enter position of the node which do you want to be deleted: ";
        cin >> pos;

        Node *prev;
        temp = head;
        int i = 1;
        while (i < pos)
        {
            prev = temp;
            temp = temp->next;
            i++;
        }
        int del = temp->data;
        prev->next = temp->next;
        delete (temp);
        cout << "Node deleted which contains " << del << " data" << endl;
    }
}

void Node::delete_End()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        temp = head;
        Node *prev;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        int del = temp->data;
        delete (temp);
        cout << "Node deleted which contains " << del << " data" << endl;

        prev->next = NULL;
    }
}

void Node::show_List()
{
    temp = head;
    if (head == NULL)
    {
        cout << "\t\tList is empty" << endl;
    }
    while (temp != NULL)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
}

int main()
{
    Node sll;
    int choice;
    while (choice != 9)
    {
        cout << "\n\t\tOPERATIONS  ON SINGLY LINKED LIST" << endl;
        cout << "1.Create List\n2.Insert At Front\n3.Insert At Middle\n4.Insert At End\n5.Delete From Front\n6.Delete From Middle\n7.Delete From End\n8.Display List\n9.Exit\n  Enter the choice(1-9): " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            sll.create_List();
            break;
        case 2:
            sll.insert_Front();
            break;
        case 3:
            sll.insert_Mid();
            break;
        case 4:
            sll.insert_End();
            break;
        case 5:
            sll.delete_Front();
            break;
        case 6:
            sll.delete_Mid();
            break;
        case 7:
            sll.delete_End();
            break;
        case 8:
            sll.show_List();
            break;
        case 9:
            exit(0);
            break;
        default:
            cout << "Invalid choice, enter between 1-9." << endl;
        }
    }

    return 0;
}
