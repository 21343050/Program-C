void storeSorted(Node *root, int arr[], int &i)
{
    if (root != NULL)
    {
        storeSorted(root->left, arr, i);
        arr[i++] = root->key;
        storeSorted(root->right, arr, i);
    }
}

void treeSort(int arr[], int n)
{
    struct Node *root = NULL;
  
    // Construct the BST
    root = insert(root, arr[0]);
    for (int i=1; i<n; i++)
        root = insert(root, arr[i]);
  
    // Store inorder traversal of the BST
    // in arr[]
    int i = 0;
    storeSorted(root, arr, i);
}