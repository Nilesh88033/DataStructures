#include <iostream>

class SinglyCircularLinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *head;
    Node *tail;
    int size;

public:
    SinglyCircularLinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void addToHead(int data)
    {
        Node *p = new Node;
        p->data = data;
        p->next = NULL;
        if (head == NULL)
        {
            head = tail = p;
            p->next = head;
        }
        else
        {
            p->next = head;
            head = p;    
            tail->next = head;
        }
        size++;
    }

    void addToTail(int data)
    {
        Node *p = new Node;
        p->data = data;
        p->next = NULL;
        if (head == NULL)
        {
            head = tail = p;
            p->next = head;
        }
        else
        {
            tail->next = p;
            tail = p;
            p->next = head;
        }
        size++;
    }

    void removeFromHead()
    {
        if (head == NULL)
        {
            std::cout << "List is Empty\n";
            return;
        }
        Node *p = head;
        if (head == tail) // this means there is only 1 element
        {
            head = tail = NULL;
        }
        else
        {
            head = head->next;
            tail->next = head;
        }
        delete p;
        size--;
    }

    void removeFromTail()
    {
        if (head == NULL)
        {
            std::cout << "List is Empty\n";
            return;
        }
        Node *p = head;
        if (head == tail) // means there is only 1 element
        {
            head = tail = NULL;
        }
        else
        {
            while (p->next != tail)
            {
                p = p->next;
            }
            Node *q = p;
            p = p->next;
            q->next = head;
            tail = q;
        }
        delete p;
        size--;
    }

    void insert(int index, int data) // zero based indexing
    {
        if ((index > size) || (index < 0))
        {
            std::cout << "Invalid Index\n";
            return;
        }
        if (index == size)
        {
            addToTail(data);
            return;
        }
        if (index == 0)
        {
            addToHead(data);
            return;
        }
        Node *p = head;
        for (int i = 1; i < index; i++)
        {
            p = p->next;
        }
        Node *q = p->next;
        Node *r = new Node;
        r->data = data;
        r->next = q;
        p->next = r;
        size++;
    }

    void remove(int index)
    {
        if ((index > size - 1) || (index < 0))
        {
            std::cout << "Invalid Index\n";
            return;
        }
        if (index == size - 1)
        {
            removeFromTail();
            return;
        }
        if (index == 0)
        {
            removeFromHead();
            return;
        }
        Node *p = head;
        for (int i = 1; i < index; i++)
        {
            p = p->next;
        }
        Node *q = p->next;
        Node *r = q->next;
        p->next = r;
        delete q;
        size--;
    }

    void display()
    {
        if (head == NULL)
        {
            std::cout << "List is Empty\n";
            return;
        }
        Node *p = head;
        std::cout << "Size: " << size << "\n";
        while (p->next != head)
        {
            std::cout << p->data << " -> ";
            p = p->next;
        }
        std::cout << p->data;
        std::cout << "\n";
    }

    Node *begin() const
    {
        return head;
    }

    SinglyCircularLinkedList operator+(SinglyCircularLinkedList const &obj)
    {
        SinglyCircularLinkedList result;
        Node *p = head;
        while (p != NULL)
        {
            result.addToTail(p->data);
            p = p->next;
        }
        p = obj.begin();
        while (p != NULL)
        {
            result.addToTail(p->data);
            p = p->next;
        }
        return result;
    }

    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }

    void reverse()
    {
        Node *p = head, *q = NULL, *r = NULL;
        while (p->next != head)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        r = q;
        q = p;
        p = p->next;
        q->next = r;
        tail = head;
        head = q;
        tail->next = head;
    }

    int search(int key)
    {
        Node *p = head;
        int i = 0;
        while (p != head || i == 0)
        {
            if (p->data == key)
                return i;
            p = p->next;
            i++;
        }
        return -1;
    }

    ~SinglyCircularLinkedList()
    {
        Node *p = head;
        Node *q = NULL;
        while (p->next != head)
        {
            q = p->next;
            delete p;
            p = q;
        }
        delete p;
        head = tail = NULL;
    }
};

int main()
{
    SinglyCircularLinkedList A;
    int option;
    while (option != 10)
    {
        std::cout << "MENU\n";
        std::cout << "Select option\n";
        std::cout << "1. PushBack(addtotail)\n";
        std::cout << "2. PushFront(addtohead)\n";
        std::cout << "3. RemoveFromHead\n";
        std::cout << "4. RemoveFromTail\n";
        std::cout << "5. Insert\n";
        std::cout << "6. Remove\n";
        std::cout << "7. Display\n";
        std::cout << "8. Reverse\n";
        std::cout << "9. Search\n";
        std::cout << "10. End\n";
        std::cout << "Enter your choice: ";
        std::cin >> option;
        switch (option)
        {
        case 1:
        {
            int x;
            std::cout << "Enter an integer value: ";
            std::cin >> x;
            A.addToTail(x);
        }
        break;

        case 2:
        {
            int x;
            std::cout << "Enter an integer value: ";
            std::cin >> x;
            A.addToHead(x);
        }
        break;

        case 3:
            A.removeFromHead();
            break;
        case 4:
            A.removeFromTail();
            break;
        case 5:
        {
            int pos, value;
            std::cout << "Enter position: ";
            std::cin >> pos;
            std::cout << "Enter an integer value: ";
            std::cin >> value;
            A.insert(pos - 1, value);
        }
        break;

        case 6:
        {
            int pos;
            std::cout << "Enter position: ";
            std::cin >> pos;
            A.remove(pos - 1);
        }
        break;

        case 7:
            A.display();
            break;

        case 8:
            A.reverse();
            break;

        case 9:
        {
            int key;
            std::cout << "Enter value you want to search: ";
            std::cin >> key;
            int searchResult = A.search(key);
            if (searchResult == -1)
                std::cout << "Element not found\n";
            else
                std::cout << "Element found at postion " << searchResult + 1 << "\n";
            break;
        }

        case 10:
            break;
        default:
            std::cout << "Incorrect option\n";
        }
        std::cin.get();
        std::cout << "Press Enter to ";
        option == 10 ? std::cout << "exit..." : std::cout << "continue...";
        std::cin.get();
        std::cout << "\n";
    }
    return 0;
}
