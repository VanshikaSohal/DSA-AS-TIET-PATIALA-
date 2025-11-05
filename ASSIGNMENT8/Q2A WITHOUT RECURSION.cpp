int searchelement(node*root,int key)
{
	if(!root)
	return -1;
	if(root->data==key)
	return root->data;
	if(root->data<key)
	{
		return searchelement(root->right,key);
	}
	else if(root->data>key)
	{
		return searchelement(root->left,key);
	}
	return -1;
}
