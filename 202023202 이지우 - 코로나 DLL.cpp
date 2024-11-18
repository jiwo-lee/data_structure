#include <iostream>

using namespace std;

class corona_nation
{
public:
    corona_nation(string name = "empty", int num_of_confirmed_p = 0, int num_of_death_p = 0);
    void print_info();


    string m_name;
    int m_num_of_confirmed_p;
    int m_num_of_death_p;
    double m_death_rate;
};

template<class T>
class DLLNode
{
public:
    DLLNode()
    {
        next = prev = NULL;
    }
    DLLNode(const T& el, DLLNode* n = NULL, DLLNode* p = NULL) {
        info = el;
        next = n;
        prev = p;
    }

    T info;
    DLLNode* next, * prev;
};

template<class T>
class DLL
{
public:
    DLL()
    {
        head = NULL;
    }

    ~DLL()
    {
        for (DLLNode<T>* p = head; p != NULL; )
        {
            p = head->next;
            delete head;
            head = p;
        }
    }

    void AddtoDLLSorted(const T& el);
    void deleteDLLSorted(const string& name);
    void printtDLLSorted();

private:
    DLLNode<T>* head;
};

template<class T>
void DLL<T>::AddtoDLLSorted(const T& el) 
{
    for (DLLNode<T>* pt = head; ; ) {
        if (head == NULL) {
            head = new DLLNode<T>(el, NULL, NULL);
            break;
        }
        else {
            if (pt->info.m_name < el.m_name) {
                if (pt->next == NULL) {
                    pt->next = new DLLNode<T>(el, NULL, pt);
                    break;
                }
                else pt = pt->next;
            }
            else if (pt->info.m_name > el.m_name) {
                if (pt == head) {
                    head = new DLLNode<T>(el, head, NULL);
                    head->next->prev = head;
                    break;
                }
                else {
                    pt->prev->next = new DLLNode<T>(el, pt, pt->prev);
                    pt->prev = pt->prev->next;
                    break;
                }
            }
        }
    }
}

template<class T>
void DLL<T>::deleteDLLSorted(const string& name)
{
    for (DLLNode<T>* pt = head; pt != NULL; ) {
        if (pt->info.m_name == name) {
            if (pt == head) {
                head = pt->next;
                delete pt;
                break;
            }
            else if (pt->next == NULL) {
                delete pt;
                break;
            }
            else {
                pt->prev->next = pt->next;
                pt->next->prev = pt->prev;
                delete pt;
                break;
            }
        }
        pt = pt->next;
    }
}

template<class T>
void DLL<T>::printtDLLSorted()
{
    for (DLLNode<T>* pt = head; pt != NULL; ) {
        pt->info.print_info();
        pt = pt->next;
    }
}


corona_nation::corona_nation(string name, int num_of_confirmed_p, int num_of_death_p)
{
    m_name = name;
    m_num_of_confirmed_p = num_of_confirmed_p;
    m_num_of_death_p = num_of_death_p;
    m_death_rate = ((double)m_num_of_death_p / m_num_of_confirmed_p) * 100;
}

void corona_nation::print_info()
{
    cout.width(10);
    cout << m_name;
    cout.width(10);
    cout << m_num_of_confirmed_p;
    cout.width(10);
    cout << m_num_of_death_p;
    cout.width(10);
    cout << m_death_rate << endl;
}


int main()
{
    DLL<corona_nation> DLLdata;


    DLLdata.AddtoDLLSorted(corona_nation("USA", 387547, 12291));
    DLLdata.AddtoDLLSorted(corona_nation("Spain", 140510, 13798));
    DLLdata.AddtoDLLSorted(corona_nation("Italy", 135586, 17127));
    DLLdata.AddtoDLLSorted(corona_nation("Germany", 107591, 2012));
    DLLdata.AddtoDLLSorted(corona_nation("China", 81802, 3333));
    DLLdata.AddtoDLLSorted(corona_nation("France", 78167, 10328));
    DLLdata.AddtoDLLSorted(corona_nation("Iran", 62589, 3872));
    DLLdata.AddtoDLLSorted(corona_nation("U.K", 55242, 6159));

    DLLdata.printtDLLSorted();

    cout << "삭제하고 싶은 나라 이름을 입력하세요:" << endl;

    string temp;

    cin >> temp;

    DLLdata.deleteDLLSorted(temp);

    DLLdata.printtDLLSorted();
}