/* 2.For a given a Binary Tree of type integer, print it in a level order fashion where each level will be printed on a new line.
 Elements on every level will be printed in a linear fashion and a single space will separate them*/
 
 #include<iostream>
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Tree{
	
	public:
		T data;		
		Tree* left;
		Tree* right;
		
		Tree(T data)
		{
			this->data=data;
			left = NULL;
			right = NULL;
		}
		
		~Tree()
		{
			delete left;
			delete right;
		}
};

Tree<int>*input()
{
	int val;
	cout<<"Enter root data= ";
	cin>>val;
	Tree<int>*root=new Tree<int>(val);
	queue<Tree<int>*>q;
	
	q.push(root);
	
	while(!q.empty())
	{
		Tree<int>*temp=q.front();
		q.pop()	;
		
		cout<<"Enter left child of "<<temp->data<<" = ";
		int x;
		cin>>x;
		if(x!=-1)
		{
			Tree<int>*child=new Tree<int>(x);
			temp->left=child;
			q.push(child);	
		}
		
		cout<<"Enter right child of "<<temp->data<<" = ";
		int y;
		cin>>y;
		if(y!=-1)
		{
			Tree<int>*child2=new Tree<int>(y);
			temp->right=child2;
			q.push(child2);
		}
	}
	return root;		
}

void levelOrder(Tree<int>*root)
{
	queue<Tree<int>*>q;
	
	q.push(root);
	
	while(!q.empty())
	{
		int n=q.size();
		for(int i=0;i<n;i++)
		{
			Tree<int>*temp=q.front();
			q.pop();
			if(temp->left!=NULL)
			{
				q.push(temp->left);
			}
		
			if(temp->right!=NULL)
			{
				q.push(temp->right);
			}
			cout<<temp->data<<" ";
		}
		cout<<endl;
	}			
}

int main()
{
	Tree<int>*root=input();
	cout<<"Level Order Traversal of Binary Tree= "<<endl;
	levelOrder(root);	
	return 0;
}

