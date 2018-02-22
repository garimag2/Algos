#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct node {
    int data;
    node* next;
};
struct node* addEdge(node* head,int n){
    node* temp1 = new node();
    
    temp1->data = n;
    temp1->next= head;

    return temp1;
}
void print_n(int d,node* temp){
    node* p = temp;
    while(p!=NULL){
        cout << d << "-->" << p->data << " ";
        p=p->next;
    }
    cout << endl;
}
void print_node(int temp[],int x, int nodes, int n){
    for(int i=1;i<=nodes;i++){
        if(i==n){
            continue;
        }
        if(temp[i] <= -1){
            cout << temp[i] << " ";
        }
        else{
            int m= temp[i]*6;
            cout << m <<" ";
        }
    }
    cout << endl;
}
void breadthfirstsearch(int levels[], node* tree[], int n, int nodes){
    node* temp = new node();
    int flag=1;
    int les=0;
    levels[n] =les;
    while(flag){
        flag=0;
        for(int i=1;i<=nodes;i++){
            if(levels[i] == les){
                flag=1;
                temp= tree[i];
                while(temp!=NULL){
                    if(levels[temp->data]!=-1){
                        temp= temp->next;
                        continue;
                    }
                    levels[temp->data] = les+1;
                    temp=temp->next;
                }
            }
        }
        ++les;
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a;
    cin >> a;
    
    for(int i=0;i<a;i++){
        int nodes,edges;
        cin >> nodes >> edges;
        node* tree[nodes+1];
        int levels[nodes+1];
        for(int i=1;i<=nodes;i++){
            tree[i] = NULL;
            levels[i]=-1;
        }
        
        for(int j=1;j<=edges;j++){
           int n,m;
           cin >> n >>m;
           //cout << n << " " << m << endl;
           tree[n] = addEdge(tree[n],m);
           tree[m] = addEdge(tree[m],n);
        }
        int n;
        cin >> n;
        /*for(int d=1;d<=nodes;d++){
            print_n(d,tree[d]);
        }*/
        breadthfirstsearch(levels,tree,n,nodes);
        print_node(levels,6,nodes,n);
    }
    return 0;
}
