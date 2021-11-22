//WAP to print a generic tree in Post order.

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
 void traverse(Tree<int>*root, vector<int> &ans) {
        if(!root) return;
    
            for(int i=0; i<root->child.size();i++){
            	  traverse(root->child[i], ans);
           
        }
        ans.push_back(root->data);
    }
    
    vector<int> postorder(Tree<int>*root) {
        vector<int> ans;
        if(!root) return ans;
        stack<Tree<int>*> s;
        s.push(root);
        
        while(!s.empty()) {
            Tree<int>*curr = s.top();
            s.pop();
            ans.push_back(curr->data);
    
            for(int i=0; i<curr->child.size(); i++) {
                if(curr->child[i])
                    s.push(curr->child[i]);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
Tree<int>*inputData()
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

int main()
{
	Tree<int>*root=inputData();
	vector<int>vector=postorder(root);
    cout<<"Postorder traversal: ";
  for(int i = 0; i < vector.size(); i++) {
        cout<<vector[i]<<" ";
    }
    cout << endl;
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
Postorder traversal: 7 6 9 2 3 4 5 8
*/