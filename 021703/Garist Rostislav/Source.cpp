#include "Header.h"
#include <iostream>


void add_all(que** b, que** e, int in, int prty, int col)
{
    if (*b == 0 && *e == 0)
    {
        que* t = new que;
        t->info = in;
        t->priority = prty;
        t->next = t->prev = 0;
        *b = *e = t;
        return;
    }

    que* a = new que;
    a->info = in;
    a->priority = prty;

    if (col == 2)
    {
        if ((*b = *e) && (*e)->priority > a->priority)
        {
            que* l = *b;
            a->next = l;
            a->prev = 0;
            l->prev = a;
            l->next = 0;
            *b = a;
            *e = l;
            return;
        }
        if ((*b = *e) && (*e)->priority < a->priority)
        {
            que* p = *e;
            a->next = 0;
            a->prev = p;
            (p)->next = a;
            p->prev = 0;
            *b = p;
            *e = a;
            return;
        }
    }

    if (col > 2)
    {
        que* y = *b;
        while (y != 0)
        {
            if (a->priority < y->priority)
            {
                a->next = y;
                a->prev = y->prev;
                if (y->prev != NULL)
                    (y->prev)->next = a;
                else  *b = a;

                y->prev = a;
                return;
            }
            y = y->next;
        }
        a->next = 0;
        a->prev = *e;
        (*e)->next = a;
        *e = a;
    }

}

void take_el(que** b, que** e, int elem)
{
    que* u = *b, * key = NULL, * temp = NULL;
    while (u != 0)
    {
        if (u->info == elem)
        {
            key = u;
            std::cout << "Элемент удален" << std::endl;
            if (*b == key && key != *e)
            {
                que* temp = *b;
                *b = (*b)->next;
                (*b)->prev = 0;
                delete temp;
                return;
            }
            else if (*e == key && *b != key)
            {
                que* temp = *e;
                *e = (*e)->prev;
                (*e)->next = 0;
                delete temp;
                return;
            }
            else if (*e == *b && *b == key)
            {
                *b = *e = 0;
                delete key;
                return;
            }
            else if (*e != key && *b != key)
            {
                (key->next)->prev = key->prev;
                (key->prev)->next = key->next;
                delete key;
                return;
            }
        }
        u = u->next;
    }
    if (u == 0)
    {
        std::cout << "Такой элемент отсутствует" << std::endl;
    }
}

void view_all(que* b)
{
    que* t = b;
    while (t != 0)
    {
        std::cout << t->info << ";" << t->priority << " ";
        t = t->next;
    }
    std::cout << std::endl;
}