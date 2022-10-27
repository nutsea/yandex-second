#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

void showTree(node *array){
    if (array != NULL){
        showTree(array -> left);
        cout << char(array -> data) << " ";
        showTree(array -> right);
    }
}

struct node * addNode(int x, node *array){
    if (array == NULL){
        array = new node;
        array -> data = x;
        array -> left = NULL;
        array -> right = NULL;
    }
    else
        if (x < array -> data)
        array -> left = addNode(x, array -> left);
        else
        array -> right = addNode(x, array -> right);
        return(array);
}

int main(){
    struct node *array = 0;
    char thisNode;
    int elementsAmount;
    cout << "Amount of elements: ";
    cin >> elementsAmount;
    cout << "Enter elements: ";
    for (int i = 0; i < elementsAmount; i++){
        cin >> thisNode;
        array = addNode(int(thisNode), array);
    }
    cout << "\nResult: ";
    showTree(array);
    cout << endl;
    return 0;
}