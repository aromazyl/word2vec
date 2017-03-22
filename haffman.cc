#include <queue>
#include <move>

#include "haffman.h"

void Haffman::AddWord(const std::string& word) {
  count_[word] += 1;
  if (!dicts_.count(word)) dicts_[word].resize(kLen);
}

void Haffman::WordBuildHelper(std::vector<int>& code, Node* root) {
  if (!root) return;
  if (!root->left && !root->right) {
    dicts_[root->word] = code;
    return;
  }
  code.push_back(0);
  WordBuildHelper(code, root->left);
  code.pop_back();
  code.push_back(1);
  WordBuildHelper(code, root->right);
  code.pop_back();
}

void Haffman::Build() {
  std::priority_queue<Node, [](const Node& a, const Node& b)->bool{
    return a.count > b.count;
  }> que;

  for (auto u = count_.begin(); u != count_.end(); ++u) {
    Node* tmp = new Node;
    tmp->word = u->first;
    tmp->count = u->second;
    tmp->left = NULL;
    tmp->right = NULL;
    que.push(tmp);
  }

  while (!que.empty() && que.size() != 1) {
    auto p = que.front();
    que.pop();
    auto q = que.front();
    que.pop();
    auto node = new Node;
    node->word = p->word + ":" + q->word;
    node->count = p->count + q->count;
    node->left = p;
    node->right = q;
    que.push(node);
  }

  auto root = que.front();
  std::vector<int> code;
  WordBuildHelper(code, root);
}
