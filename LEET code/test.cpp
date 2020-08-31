#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define s(x, n) memset(x, n, sizeof(x));
#define pb(x) push_back(x)
struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;
    Node(int x)
    {
        this->data = x;
        next = NULL;
        bottom = NULL;
    }
    bool operator <(const Node* j) const{
        cout<<"this->data: "<<this->data<<" and j->data: "<<j->data<<endl;
        return ((this->data) < (j->data));
    }
};

int main()
{
#ifdef WIN32
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

#ifndef WIN32
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

    set<Node*> v;
    Node* temp = new Node(5000);
    v.insert(temp);
    Node* temp1 = new Node(4000);
    v.insert(temp1);
    temp1=new Node(1000);
    v.insert(temp1);
    auto it = v.begin();
    cout<< ((*it)->data);
    return 0;
}