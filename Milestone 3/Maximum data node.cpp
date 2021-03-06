//WAP to return the node with maximum data in a generic tree using recursion.

#include<vector>
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Tree{
	public:
		T data;
		vector<Tree<T>*>child;
		
		Tree(T data)
		{
			this->data=data;
		}
};

Tree<int>*input()
{
	int value;
	cout<<"Enter root : ";
	cin>>value;
	Tree<int>*root=new Tree<int>(value);
	queue<Tree<int>*>q;
	
	q.push(root);
	
	while(!q.empty())
	{
		Tree<int>*temp=q.front();
		q.pop()	;
		int n;
		cout<<"Enter number of children of "<<temp->data<<" = ";
		cin>>n;	
		
		for(int i=1;i<=n;i++)
		{
			int v;
			cout<<"Enter data of "<<i<<"th child of "<<temp->data<<" = ";
			cin>>v;
			Tree<int>*t=new Tree<int>(v);
			temp->child.push_back(t);
			q.push(t);	
		}
	}
	return root;		
}

Tree<int>*max(Tree<int>*root)
{
	if(root==NULL)
		return NULL;

	Tree<int>*ans=root;
	Tree<int>*cm;
	
	for(int i=0;i<root->child.size();i++)
	{
		cm=max(root->child[i]);
		if(cm->data>ans->data)
			ans=cm;
	}
	return ans;
}

int main()
{
	Tree<int>*root=input();
	cout<<"Maximum root = "<<max(root)->data;
	return 0;
}

/*
Enter root : 8
Enter number of children of 4 = 3
Enter data of 1th child of 4 = 9
Enter data of 2th child of 4 = 4
Enter data of 3th child of 4 = 5
Enter number of children of 9 = 2
Enter data of 1th child of 9 = 7
Enter data of 2nd child of 9 = 6
Enter number of children of 4 = 2
Enter data of 1th child of 4 = 2
Enter data of 2th child of 4 = 3
Enter number of children of 5 = 0
Enter number of children of 7 = 0
Enter number of children of 6 = 0
Enter number of children of 2 = 0
Enter number of children of 3 = 0
Maximum root = 9
*/