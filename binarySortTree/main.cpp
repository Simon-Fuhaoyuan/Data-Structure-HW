#include <iostream>

using namespace std;

struct node
{
	int data;
	node *left;
    node *right;
	node(const int &x, node *l = NULL, node *r = NULL) { data = x; left = l; right = r; }
	node() :left(NULL), right(NULL) {}
	~node() {}
};

int main()
{
    node *root;
    root = new node(-1);

    node *tmpFather, *tmpChild;

    int cnt, tmp;
    cin >> cnt;
    for (int i = 0; i < cnt; ++i)
    {
        cin >> tmp;
        tmpChild = root;
        if (i == 0)
        {
            root->data = tmp;
            cout << -1 << endl;
            continue;
        }

        while(tmpChild != NULL)
        {
            tmpFather = tmpChild;
            if (tmpFather->data > tmp) tmpChild = tmpFather->left;
            else tmpChild = tmpFather->right;
        }
        cout << tmpFather->data << endl;
        if (tmpFather->data > tmp) tmpFather->left = new node(tmp);
        else tmpFather->right = new node(tmp);
    }
    
    return 0;
}