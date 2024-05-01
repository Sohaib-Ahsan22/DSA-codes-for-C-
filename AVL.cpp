#include <iostream>
using namespace std;
struct BSTNode
{
  int value;
  int HeightFromLeft;
  int HeightFromRight;
  BSTNode *LeftChild;
  BSTNode *RightChild;
};

int MaximumHeight(int a, int b)
{
  if (a>b)
  {
    return a;
  }
  return b;
}

BSTNode *shiftLeft(BSTNode *UBNode)
{
  BSTNode *CurrNode = UBNode->RightChild;
  BSTNode *Temp = CurrNode->LeftChild;
  CurrNode->LeftChild = UBNode;
  UBNode->RightChild = Temp;
  if (Temp == NULL)
  {
    UBNode->HeightFromRight = 0;
  }
  else
  {
    UBNode->HeightFromRight = MaximumHeight(Temp->HeightFromLeft, Temp->HeightFromRight) + 1;
  }
  CurrNode->HeightFromLeft = MaximumHeight(UBNode->HeightFromLeft, UBNode->HeightFromRight) + 1;
  return CurrNode;
}

BSTNode *shiftRight(BSTNode *UBNode)
{
  BSTNode *CurrNode = UBNode->LeftChild;
  BSTNode *Temp = CurrNode->RightChild;
  CurrNode->RightChild = UBNode;
  UBNode->LeftChild = Temp;
  if (Temp == NULL)
  {
    UBNode->HeightFromLeft = 0;
  }
  else
  {
    UBNode->HeightFromLeft = MaximumHeight(Temp->HeightFromLeft, Temp->HeightFromRight) + 1;
  }
  CurrNode->HeightFromRight = MaximumHeight(UBNode->HeightFromLeft, UBNode->HeightFromRight) + 1;
  return CurrNode;
}

BSTNode *insert(BSTNode *root, int value)
{
  if (root == NULL)
  {
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    node->value = value;
    node->HeightFromLeft = node->HeightFromRight = 0;
    node->LeftChild = node->RightChild = NULL;
    return node;
  }
  
  if (value > root->value)
  {
    root->RightChild = insert(root->RightChild, value);
    root->HeightFromRight = MaximumHeight(root->RightChild->HeightFromLeft, root->RightChild->HeightFromRight) + 1;
  }
  else if (value < root->value)
  {
    root->LeftChild = insert(root->LeftChild, value);
    root->HeightFromLeft = MaximumHeight(root->LeftChild->HeightFromLeft, root->LeftChild->HeightFromRight) + 1;
  }
  int balanceFactor = root->HeightFromLeft - root->HeightFromRight;
  
if (balanceFactor > 1)
  {
    if (value < root->LeftChild->value)
    {
      root = shiftRight(root);
    }
    else    // double shifting
    {
      root->LeftChild = shiftLeft(root->LeftChild);
      root = shiftRight(root);
    }
  }
else if (balanceFactor < -1)
  {
    if (value > root->RightChild->value)
    {
      root = shiftLeft(root);
    }
    else
    {
      root->RightChild = shiftRight(root->RightChild);
      root = shiftLeft(root);
    }
  }
  return root;
}

bool search(BSTNode *root, int toSearch)
{
  if (root == NULL)
  {
    return false;
  }
  if (toSearch == root->value)
  {
    return true;
  }
  if (toSearch < root->value)
  {
    search(root->LeftChild, toSearch);
  }
  else if (toSearch > root->value)
  {
    search(root->RightChild, toSearch);
  }
}

void inOrderTraversial(BSTNode *root)
{
  if (root == NULL)
  {
    return;
  }
  inOrderTraversial(root->LeftChild);
  cout << root->value << " ";
  inOrderTraversial(root->RightChild);
}


int main()
{
  BSTNode *root = NULL;
  int a;
  do
  {
    cout << "Enter 1 to Insert a value" << endl
         << "Enter 2 to Search a value" << endl
         << "enter 3 to print In Order Traversial" << endl
         << "Enter 4 to End the program " << endl;
    cin >> a;
    if (a == 1)
    {
      int value;
      cout << "Enter a value to Insert : ";
      cin >> value;
      root = insert(root, value);
    }
    else if (a == 2)
    {
      int toSearch;
      cout << "Enter a value to Search  : ";
      cin >> toSearch;
      bool isAvailable = search(root, toSearch);
      isAvailable ? cout << "Value found  " << endl : cout << "Value not Found " << endl;
    }
    else if (a == 3)
    {
      inOrderTraversial(root);
      cout << endl;
    }
    
    else if (a == 4)
    {
      cout << "Good Bye" << endl;
    }
    else
    {
      cout << "please enter a valid number" << endl;
    }
  } while (a != 4);
}