#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

template <class T>
class node
{
public:
    T val;
    bool valid;
    node *back;
    node *front;
    node(T val, bool valid=true, node *back=nullptr, node *front=nullptr):val(val),valid(valid),back(back),front(front){}
    bool operator<(const node& obj)
    {
        return this->val < obj.val;
    }
};

template<class T>
class Compare
{
public:
    bool operator() (const node<T>* obj1, const node<T>* obj2)
    {
        return obj1->val > obj2->val;
    }
};

void testCase()
{
    int n,c;
    cin>>n>>c;
    node<int> *start=nullptr;
    priority_queue<node<int>*, vector<node<int>*>, Compare<int>> pq;
    vector<int> locs(n);
    for(int i=0;i<n;i++)
    {
        cin>>locs[i];
    }
    sort(locs.begin(),locs.end());
    for(int i=n-1;i>0;i--)
    {
        node<int> *tempNode = new node(locs[i]-locs[i-1]);
        pq.push(tempNode);
        if(start==nullptr)
        {
            start = tempNode;
        }
        else
        {
            tempNode->front = start;
            start->back = tempNode;
            start = tempNode;
        }
    }

    vector<node<int>*> removedNodes;
    for(int i=0;i<(n-c);i++)
    {
        node<int> *tempNode = pq.top();
        pq.pop();
        while(tempNode->valid==false)
        {
            tempNode = pq.top();
            pq.pop();
        }
        if(tempNode->back==nullptr || (tempNode->front!=nullptr && tempNode->back->val > tempNode->front->val))
        {
            tempNode->front->valid=false;
            tempNode->val += tempNode->front->val;
            removedNodes.push_back(tempNode->front);
            tempNode->front = tempNode->front->front;
            if(tempNode->front)tempNode->front->back = tempNode;
            pq.push(tempNode);
        }
        else
        {
            tempNode->back->valid=false;
            tempNode->val += tempNode->back->val;
            removedNodes.push_back(tempNode->back);
            tempNode->back = tempNode->back->back;
            if(tempNode->back)tempNode->back->front = tempNode;
            pq.push(tempNode);
        }
    }
    while(pq.top()->valid==false)
    {
        pq.pop();
    }
    int ans = pq.top()->val;
    cout<<ans<<'\n';
    for(auto it:removedNodes)
    {
        delete it;
    }
    start = pq.top();
    while(start->back!=nullptr)
    {
        start = start->back;
    }
    while(start)
    {
        node<int> *temp = start;
        start = start->front;
        delete temp;
    }
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        testCase();
    }
}