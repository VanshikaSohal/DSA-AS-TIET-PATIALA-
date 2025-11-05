int searchelement(node*root,int key)
{
	if(!root)
	return -1;
	while(root){
	if(root->data==key)
	return root->data;
	if(root->data<key)
	{
		root=root->right;
	}
	else if(root->data>key)
	{
		root=root->left;
	}
    }
	return -1;
}
