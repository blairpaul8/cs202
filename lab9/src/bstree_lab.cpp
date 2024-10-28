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
  return rv;
}
    
BSTree::BSTree(const BSTree &t) {
  (void) t;
}

BSTree& BSTree::operator= (const BSTree &t) {
  (void) t;
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
                            size_t num_indices) const
{
  (void) sorted_keys;
  (void) vals;
  (void) first_index;
  (void) num_indices;
  return NULL;
}
