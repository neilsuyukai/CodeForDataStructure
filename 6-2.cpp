#include <math.h>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class TreeNode {
public:
    friend class BinTree;
    TreeNode(int a) {
        data = a;
        leftChild = rightChild = 0;
    };

private:
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;
};

class BinTree
{
private:
    TreeNode* root=0;
public:
    void BuildTree(vector<int> data, int n)
    {
        TreeNode* r = new TreeNode(data[0]);
        root = r;
        TreeNode* temp;
        for (int i = 1; i < n; i++)
        {
            TreeNode* current = new TreeNode(data[i]);
            temp = r;
            while (r != 0)
            {
                if (data[i] > temp->data) {
                    if (temp->rightChild != 0)temp = temp->rightChild;
                    else {
                        temp->rightChild = current; break;
                    }
                }
                else {
                    if (temp->leftChild != 0)temp = temp->leftChild;
                    else {
                        temp->leftChild = current; break;
                    }
                }
            }

        }

    }
    void Plot();
};

void BinTree::Plot() {
    int MAX_HEIGHT = 7, CHAR_SPACE = 2;
    int capacity = pow(2, MAX_HEIGHT);
    vector<int> arr(capacity);
    queue<TreeNode*> q;
    queue<int> index_q;
    q.push(root);
    index_q.push(1);
    TreeNode* currentNode;
    int currentIndex, tail = 0;
    while (!q.empty()) {
        currentNode = q.front();
        q.pop();
        currentIndex = index_q.front();
        index_q.pop();
        arr[currentIndex] = currentNode->data;
        if (tail < currentIndex)
            tail = currentIndex;
        if (currentNode->leftChild) {
            q.push(currentNode->leftChild);
            index_q.push(currentIndex * 2);
        }
        if (currentNode->rightChild) {
            q.push(currentNode->rightChild);
            index_q.push(currentIndex * 2 + 1);
        }
    }
    int i, sps;
    int max_level = log(tail) / log(2) + 1;
    for (int lv = 1; lv <= max_level; lv++) {
        sps = pow(2, max_level - lv) * CHAR_SPACE;
        i = pow(2, lv - 1);
        cout << setw(sps);
        if (arr[i])
            cout << arr[i];
        else
            cout << " ";
        sps *= 2;
        for (i++; i <= pow(2, lv) - 1; i++) {
            cout << setw(sps);
            if (arr[i])
                cout << arr[i];
            else
                cout << " ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
    BinTree tree1;
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++)
        cin >> data[i];
    tree1.BuildTree(data, n);
    tree1.Plot();
}