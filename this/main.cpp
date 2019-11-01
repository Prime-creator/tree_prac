#include <iostream>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<cmath>
#include<stack>
using namespace std;
class node{
public:
    node *left;
    node *right;
    node *next;
    int data;
    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
        next = NULL;

    }
};

node *buildTree(){
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    }
    else{
        node *n = new node(data);
        n->left  = buildTree();
        n->right = buildTree();
        return n;
    }
}
void PreOrder(node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void Inorder(node *root){
    if(root == NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
void PostOrder(node *root){
    if(root == NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}
int CountNudes(node *root){
    if(root == NULL){return 0;}
    return 1 + CountNudes(root->left) + CountNudes(root->right);
}
int height(node *root){
    if(root == NULL){
        return 0;
    }
    int left  = height(root->left);
    int right = height(root->right);
    return 1 + max(left, right);
}
void PrintMirror(node *root){
    if(root == NULL){
        return;
    }
    swap(root->left, root->right);
    PrintMirror(root->left);
    PrintMirror(root->right);
}
int Diameter(node *root){
    if(root == NULL){return 0;}
    int op1 = height(root->left) + height(root->right);
    int op2 = Diameter(root->left);
    int op3 = Diameter(root->right);
    return max(op1,max(op2,op3));
}
//8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
void InOrderLess(node *root){
    stack<node*> s;
    node *current = root;
    while(current != NULL || !s.empty()){
        while(current != NULL){
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout<<current->data<<" ";
        current = current->right;
    }
}
bool isBST(node *root , int k1=INT_MIN , int k2 = INT_MAX){
    if(root == NULL){
        return true;
    }
    if(root->data >= k1 && root->data <= k2 && isBST(root->left ,k1 , root->data) && isBST(root->right , root->data ,k2))
    {
        return true;
    }
    else{
        return false;
    }
}
int counter = 0;
//to understand recursion use this function;
/*void InorderSucessor(node *root, int *arr){
    if(root == NULL){return;}
    cout<<"return"<<endl;
    cout<<"above root->left root->"<<root->data<<endl;
    InorderSucessor(root->left,arr);
    cout<<"below root->left root-> "<<root->data<<endl;
    cout<<"the data of root is  = "<<root->data<<endl;
    cout<<"above root->right root->"<<root->data<<endl;
    InorderSucessor(root->right, arr);
    cout<<"below root->right root->"<<root->data<<endl;
}*/

//1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
int index = 0;
node *inpretree(int *in, int *pre, int s, int e){
    if(s > e){
        return NULL;
    }
    int data = pre[index];
    node *root = new node(data);
    index++;
    int k = -1;
    for(int i = s; i < e; i++){
        if(data == in[i]){
            k = i;
            break;
        }
    }
    root->left = inpretree(in, pre, s, k-1);
    root->right = inpretree(in, pre, k+1, e);
    return root;
}

int main(){
    int in[] = {1,2,3,4};
    cout<<&in;cout<<endl;
    cout<<in;
    cout<<".......";
    int i = 22;
    cout<<i<<endl;
    cout<<&i;

  /*  node *root = NULL;
    root = buildTree();
    cout<<"........................."<<endl;
    Inorder(root);
    cout<<endl;
    int arr[CountNudes(root)];
    InorderSucessor(root, arr);
    for(int i = 0 ; i < CountNudes(root) ; i++){
        cout<<arr[i]<<" ";
    }*/
    return 0;
}
