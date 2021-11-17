#include <iostream>
using namespace std;

class Polyn
{
public:
    struct Item {
        float coef; // 系数
        int expn;   // 项数
        Item* next;

        // constructor
        // c 为系数， e 为项数
        Item(float c, int e)
        {
            coef = c;
            expn = e;
            next = nullptr;
        }
    };

private:
    // head item
    Item* head;
    int size;

// funcs
public:
    Polyn()
    {
        head = new Item(-1, -1);
        size = 0;
    }

    Item* hasExpn(int ex)
    {
        Item* it = head->next;
        return findExpn(it, ex);
    }

    Item* findExpn(Item* temp, int ex)
    {
        // cout << "findEx" << endl;
        if (!temp || temp->expn == ex)
        { 
            // cout << "found item" << endl;
            return temp;
        }
        return findExpn(temp->next, ex);
    }

    void findFrontItem(Item* &temp, int ex)
    {
        cout << endl << "finding frontItem" << endl;
        if (!temp->next || temp->next->expn > ex) { return; }
        temp = temp->next;
        findFrontItem(temp, ex);
    }

    void addItem(int co, int ex)
    {
        // cout << endl << "Adding item" << endl;
        Item* it = hasExpn(ex);
        if (it)
        {
            // cout << "has this ex" << endl;
            it->coef += co;
        }
        else
        {
            it = new Item(co, ex);
            Item* frontItem = this->head;
            findFrontItem(frontItem, ex);
            it->next = frontItem->next;
            frontItem->next = it;
            cout << frontItem->expn << endl;
        }

        size += 1;
    }

    int getSum(int x)
    {
        int sum = 0;
        Item* it = head->next;
        for (int i = 0; i < size; i++ )
        {
            int itemSum = 1;
            for (int ii = 0; ii < it->expn; ii++)
            {
                itemSum *= x;
            }
            sum += itemSum* it->coef;
            cout << "it_expn is: " << it->expn << endl;
            cout << "itemSum is: " << itemSum << endl;
            cout << "Sum is: " << sum << endl;
            it = it->next;
        }
        return sum;
    }
};

int main()
{
    Polyn* p = new Polyn();
    p->addItem(3, 0);
    p->addItem(3, 1);
    p->addItem(3, 2);
    cout << p->getSum(2) << endl;
    
    return 0;
}