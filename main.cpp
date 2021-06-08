#include<bits/stdc++.h>
using namespace std;

// A Binomial Tree node.
struct Node
{
    int data, degree;
    Node *child, *sibling, *parent;
};

Node* newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->degree = 0;
    temp->child = temp->parent = temp->sibling = NULL;
    return temp;
}

// This function merge two Binomial Trees.
Node* mergeBinomialTrees(Node *b1, Node *b2)
{
    // Make sure b1 is smaller
    if (b1->data > b2->data)
        swap(b1, b2);

    // We basically make larger valued tree
    // a child of smaller valued tree
    b2->parent = b1;
    b2->sibling = b1->child;
    b1->child = b2;
    b1->degree++;

    return b1;
}

Node * addNode(Node * head, Node * temp){

    return mergeBinomialTrees(head , temp);

}
// removing minimum key element from binomial heap
// this function take Binomial Tree as input and return
// binomial heap after
// removing head of that tree i.e. minimum element
Node * removeMinFromTreeReturnBHeap(Node *tree)
{

    Node *temp = tree->child;
    Node * head= NULL;
    Node *lo;

    // making a binomial heap from Binomial Tree
    while (temp)
    {
        lo = temp;
        temp = temp->sibling;
        lo->sibling = NULL;

        if(head==NULL)
            head=lo;
        else
         head= addNode(head, lo);

    }


    return head;
}



// print function for Binomial Tree
void printTree(Node *h)
{
    while (h)
    {
        cout << h->data << " ";
        printTree(h->child);
        h = h->sibling;
    }
    cout<<endl;
}


// Driver program to test above functions
int main()
{
    int ch,key;
    list<Node*> _heap;
    Node * head= newNode(1);

    Node * a= newNode(2);
    head= addNode(head,a);


    printTree(head);
    head=removeMinFromTreeReturnBHeap(head);
    printTree(head);

    return 0;
}

