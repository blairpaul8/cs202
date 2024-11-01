#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include "bstree.hpp"
using namespace std;
using CS140::BSTree;
using CS140::BSTNode;

/* ---------------------------------------------- */
/* You'll write all of these as part of your lab. */

int BSTree::Depth(const string &key) const {
  int depth = 0;
  BSTNode *n;
  n = sentinel->right;
  while (true) {
		if (n == sentinel) {
			break;
		}
    if (key == n->key) {
      return depth;
    }
    if (key < n->key) {
      depth++;
      n = n->left;
    }
    else {
      depth++;
      n = n->right;

    }
  }
  return -1;
}
           
int BSTree::Height() const {
  BSTNode *n;
  n = sentinel->right;
  int height = recursive_find_height(n);
  if (height >= 0) {
    return height;
  }
  return -1;
}

vector <string> BSTree::Ordered_Keys() const {
  vector <string> rv;
  make_key_vector(sentinel->right, rv);
  return rv;
}
    
BSTree::BSTree(const BSTree &t) {
	sentinel = new BSTNode;
	sentinel->left = NULL;
	sentinel->right = sentinel;
	sentinel->parent = NULL;
	sentinel->key = "---SENTINEL---";
	sentinel->val = NULL;
	size = 0;
	*this = t;
}

BSTree& BSTree::operator= (const BSTree &t) {
	Clear();
	vector<string> keys = t.Ordered_Keys();
	vector<void *> vals = t.Ordered_Vals();
	sentinel->right = make_balanced_tree(keys, vals, 0, vals.size());
	sentinel->right->parent = sentinel;
  size = vals.size();
  return *this;
}

int BSTree::recursive_find_height(const BSTNode *n) const {
  if (n == sentinel) {
    return 0;
  }

  int h_left = recursive_find_height(n->left) + 1;
  int h_right = recursive_find_height(n->right) + 1;

  if (h_left >= h_right) {
    return h_left;
  }
  else {
    return h_right;
  }
  return -1;
}

void BSTree::make_key_vector(const BSTNode *n, vector<string> &v) const {
  if (n == sentinel) {
	  return;
  }
  make_key_vector(n->left, v);
  v.push_back(n->key);
  make_key_vector(n->right, v);
}

BSTNode *BSTree::make_balanced_tree(const vector<string> &sorted_keys, 
                            const vector<void *> &vals,
                            size_t first_index,
                            size_t num_indices) const {
  if (num_indices == 0) {
    return sentinel;
  }
  //This finds the middle of the vector to make the balanced tree 
  size_t mid = first_index + num_indices / 2;
  BSTNode *n = new BSTNode;
  
  //Recursively make balanced tree for the left and right side of the vector.
  n->left = make_balanced_tree(sorted_keys, vals, first_index, num_indices / 2);
  n->right = make_balanced_tree(sorted_keys, vals, mid + 1, (num_indices - 1) / 2); 
  
  //set the values of the node;
  n->key = sorted_keys[mid];
  n->val = vals[mid];
	
  if (num_indices == 1) {
    return n;
  }

  //If this is not a leaf node the nodes parent needs to be set
	if (n->left != sentinel) {
		n->left->parent = n;
	}
	if (n->right != sentinel) {
		n->right->parent = n;
	}
  
  return n;
}
