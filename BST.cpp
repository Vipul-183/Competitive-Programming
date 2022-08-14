#include <bits/stdc++.h>

using namespace std;

// struct Node
// {
//     int data;
//     Node *left;
//     Node *right;
// };

// Node* create_Node(int data){
//     Node* root = new Node;
//     root->data = data;
//     root->left = NULL;
//     root->right = NULL;
// }

// Node* insert(int data, Node* root){
//     if (root == NULL){
//         return create_Node(data);
//     }
//     if(root->data>data){
//         root->left = insert(data, root->left);
//     }
//     else{
//         root->right = insert(data, root->right);
//     }
//     return root;
// }

// void search(int data, Node* &parent, Node* &cur){
//     while(cur!=NULL && cur->data != data){
//         parent = cur;
//         if(cur->data>data){
//             cur = cur->left;
//         }
//         else
//             cur = cur->right;
//     }
// }
const int N = 20005;
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        set<pair<int,pair<int,int>>> st;
        for(int i=0;i<k;i++){
            st.insert({KSortedArray[i][0],{i,0}});
        }
        int ans = (*st.rbegin()).first - (*st.begin()).first;
        pair<int, int> req = {(*st.begin()).first, (*st.rbegin()).first};
        while(true){
            pair<int, pair<int, int>> temp = *st.begin();
            if(temp.second.second == n-1)
                break;
            st.erase(temp);
            st.insert({KSortedArray[temp.second.first][temp.second.second + 1], {temp.second.first, temp.second.second + 1}});
            if(ans>(*st.rbegin()).first - (*st.begin()).first){
                ans = (*st.rbegin()).first - (*st.begin()).first;
                req = {(*st.begin()).first, (*st.rbegin()).first};
            }
        }
        return req;
    }
};



int main(){

    return 0;
}


