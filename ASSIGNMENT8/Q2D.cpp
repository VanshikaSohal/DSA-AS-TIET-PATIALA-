void inorder(node*root,int key)
{
	vector<int>result;
	if(root==NULL)
	return;
		inorder(root->left);
		result.push_back(root->data);
		inorder(root->right);
}
int n=result.size();
void successor(int n,int key)
{
	for(int i=0;i<n;i++)
	{
		if(result[i]==key)
		{
			cout<<"Successor of "<<result[i]<<" is "<<result[i+1];
		}
	}
}

