//Given a generic tree, WAP to print the tree level wise.

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
    queue<Tree<int>*>q;
	Tree<int>*root=new Tree<int>(value);
	
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


void print(Tree<int>*root)
{
	queue<Tree<int>*>q;
	q.push(root);
	
	while(!q.empty())
	{
		Tree<int>*temp=q.front();
		cout<<temp->data<<endl;
		q.pop()	;		
		for(int i=0;i<temp->child.size();i++)
			q.push(temp->child[i]);
	}
}

int main()
{
	Tree<int>*root=input();
	cout<<"Generic Tree: "<<endl;
	print(root);	
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
Generic Tree:
8
9
4
5
7
6
2
3
*/