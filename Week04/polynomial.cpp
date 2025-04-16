#include <bits/stdc++.h>
using namespace std;

struct DONTHUC
{
    int somu;
    double heso;

    DONTHUC(double _heso = 0, int _somu = 0)
    {
        heso = _heso;
        somu = _somu;
    }

    DONTHUC &operator=(const DONTHUC &rhs)
    {
        if (this == &rhs)
            return *this;
        this->heso = rhs.heso;
        this->somu = rhs.somu;
        return *this;
    }
};

struct Node
{
    DONTHUC *data;
    Node *next;

    Node(DONTHUC *_data = nullptr)
    {
        this->data = _data;
        this->next = nullptr;
    }

    ~Node()
    {
        delete data;
    }
};

struct DATHUC
{
    Node *head;
    Node *tail;
    DATHUC()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    ~DATHUC()
    {
        Node *cur = head;
        while (cur)
        {
            Node *temp = cur;
            cur = cur->next;
            delete temp;
        }
    }
};

void Nhap(DATHUC &B, double heso, int somu)
{
    if (heso == 0)
        return;

    DONTHUC *newTerm = new DONTHUC(heso, somu);
    Node *newNode = new Node(newTerm);

    if (!B.head)
    {
        B.head = B.tail = newNode;
        return;
    }

    if (B.head->data->somu < somu)
    {
        newNode->next = B.head;
        B.head = newNode;
        return;
    }

    Node *cur = B.head;
    Node *prev = nullptr;

    while (cur && cur->data->somu > somu)
    {
        prev = cur;
        cur = cur->next;
    }

    if (cur && cur->data->somu == somu)
    {
        cur->data->heso += heso;
        delete newNode;
        return;
    }

    newNode->next = cur;
    if (prev)
        prev->next = newNode;

    if (!cur)
        B.tail = newNode;
}

void OutputTerm(const DONTHUC *m, bool isFirst)
{
    if (m->heso == 0)
        return;

    if (!isFirst)
        cout << (m->heso < 0 ? "-" : "+");
    else if (m->heso < 0)
        cout << "-";

    double absHeso = fabs(m->heso);
    if (absHeso != 1 || m->somu == 0)
        cout << absHeso;

    if (m->somu > 0)
    {
        cout << "x";
        if (m->somu > 1)
            cout << "^" << m->somu;
    }
}

void Xuat(DATHUC &B)
{
    Node *curNode = B.head;
    bool first = true;
    while (curNode)
    {
        if (curNode->data->heso != 0)
        {
            OutputTerm(curNode->data, first);
            first = false;
        }
        curNode = curNode->next;
    }
    if (first)
        cout << "0";
}

double TinhDaThuc(DATHUC &B, double x)
{
    double sum = 0.0;
    Node *curNode = B.head;
    while (curNode)
    {
        DONTHUC *curMono = curNode->data;
        sum += curMono->heso * pow(x, curMono->somu);
        curNode = curNode->next;
    }
    return sum;
}

int main()
{
    DATHUC B;
    int N;

    cin >> N;
    for (int test = 0; test < N; test++)
    {
        double heso;
        int somu;
        cin >> heso >> somu;
        Nhap(B, heso, somu);
    }

    cout << "Da thuc vua nhap la: ";
    Xuat(B);

    double x;
    cin >> x;

    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << fixed << setprecision(2) << TinhDaThuc(B, x);
    return 0;
}
