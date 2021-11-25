#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

template <typename T>

class DoubleLinkedList
{
public:
    struct Node
    {
        T Data;
        Node* Prev = nullptr;
        Node* Next = nullptr;
    };

    void insert_front(const T& d)
    {
        Node* node = new Node();
        node->Data = d;
        node->Prev = nullptr;
        if (size == 0)
        {
            Head = node;
            Tail = node;
            node->Next = nullptr;
        }
        else
        {
            Head->Prev = node;
            node->Next = Head;
            Head = node;
        }
        size++;
    }
    void insert_back(const T& d)
    {
        Node* node = new Node();
        node->Data = d;
        node->Next = nullptr;
        if (size == 0)
        {
            Head = node;
            Tail = node;
            node->Prev = nullptr;
        }
        else
        {
            Tail->Next = node;
            node->Prev = Tail;
            Tail = node;
        }
        size++;
    }
    void print()
    {
        int i = 0;
        Node* current = Head;
        if (size == 0)
        {
            cout << "There's nothing to print" << endl;
        }
        while (current != nullptr)
        {
            if (size > 0)
            {
                cout << "No. " << i << " data: " << setw(5) << current->Data << " Current: " << setw(15) << current << " Next: " << setw(15) << current->Next << " Previous: " << setw(15) << current->Prev << endl;
            }

            current = current->Next;
            i++;
        }
    }
    void print_given_index(int index)
    {
        int i = 0;
        Node* current = Head;
        if (size < index)
        {
            cout << "There's such index" << endl;
        }
        else
            while (current != NULL)
            {
                if (index == i)
                {
                    cout << "No. " << index << " data: " << setw(5) << current->Data << " Current: " << setw(15) << current << " Next: " << setw(15) << current->Next << " Previous: " << setw(15) << current->Prev << endl;
                    break;
                }
                else
                {
                    cout << "There's no such index" << endl;
                }
                current = current->Next;
                i++;
            }
    }
    void del_first_node()
    {
        if (size == 0)
        {
            cout << "There's nothing to delete" << endl;

        }
        else
            if (Head->Next == nullptr)
            {
                delete Head;
                size--;
            }
            else
            {
                Head = Head->Next;
                delete Head->Prev;
                Head->Prev = nullptr;
                size--;
            }
    }
    void del_last_node()
    {
        if (size == 0)
        {
            cout << "There's nothing to delete" << endl;

        }
        else
            if (Head->Next = NULL)
            {
                delete Head;
                size--;
            }
            else
            {
                Tail = Tail->Prev;
                delete Tail->Next;
                Tail->Next = nullptr;
                size--;
            }
    }
    void clear_list()
    {
        Node* current = Head;
        if (size == 0)
        {
            cout << "There's no elements to be cleared" << endl;
        }
        else
            while (current != nullptr)
            {
                current = Head->Next;
                del_first_node();
            }
        cout << size << endl;
        cout << "All nodes are deleted successfully.\n" << endl;
    }
    void Append_after_index(const T& d, int index)
    {
        Node* current = Head;
        Node* new_node = new Node;
        new_node->Data = d;
        int i = 0;
        if (size == 0)
        {
            cout << "There's no element to put behind" << endl;
        }
        else
            if (index < 0 || size < index)
            {
                cout << "Mistake, There's no element to be shown" << endl;
            }
            else
                while (current != nullptr)
                {
                    if (index == i)
                    {
                        Node* next_node = current->Next;
                        current->Next = new_node;
                        new_node->Prev = current;
                        new_node->Next = next_node;
                        next_node->Prev = new_node;
                    }

                    current = current->Next;
                    i++;
                }
        size++;
    }
    void swap_data_at_GivenIndex(const T& d, int index)
    {
        Node* current = Head;
        int pos = 0;
        if (size == 0)
        {
            cout << "There's nothing to swap" << endl;
        }
        else if (index < 0 || size - 1 < index)
        {
            cout << "There's no index to be swapped" << endl;
        }
        else
            while (current != nullptr)
            {
                if (pos == index)
                {
                    current->Data = d;
                    return;
                }
                else
                    if (current->Next != nullptr)
                    {
                        current = current->Next;
                    }
                pos++;
            }
    }
   
    void delete_given_index(int index)
    {
        int i = 0;
        Node* current = Head;
        if (size == 0)
        {
            cout << "There's nothing to delete" << endl;
        }
        else
            if (size < index)
            {
                cout << "There's no such index" << endl;
            }
            else if (index < 0)
            {
                cout << "There's no such element, You've put negative index which is not possible." << endl;
            }
            else
             
                    while (current != NULL)
                    {
                        if (index == 0)
                        {
                            del_first_node();
                            break;
                        }
                        else if (index-1 == i)
                            {
                                Node* next  = current->Next->Next;
                                free(current->Next);
                                current->Next = next;
                                break;
                            }
                        else if (current->Next == nullptr)
                             {
                                del_last_node();
                                break;
                             }

                        current = current->Next;
                        i++;
                    }
    }
private:
    Node* Head;
    Node* Tail;
    int size = 0;
};
struct some_object
{
    int field_1;
    char field_2;
    bool operator <(const some_object& d)const
    {
        return field_1 < d.field_1 || field_1 == d.field_1 && field_2 < d.field_2;
    }
};
int main()
{
    int t = 1;
    DoubleLinkedList<int>* podwojnalista = new DoubleLinkedList<int>();
    podwojnalista->del_first_node();
    podwojnalista->del_last_node();
    some_object* Komparator = new some_object;

    clock_t t1 = clock();
    podwojnalista->insert_front(23);
    podwojnalista->print();
    clock_t t2 = clock();

   
    cout << endl;
    
    

    cout << (t2-t1);
}