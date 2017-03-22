/*
 * haffman.h
 * Copyright (C) 2017 zhangyule <zyl2336709@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef HAFFMAN_H
#define HAFFMAN_H

#include <vector>
#include <string>

class Haffman {
  public:
    Haffman(int len) : kLen (len) {}
    void AddWord(const std::string& word);
    void Build();

    void GetCode(const std::string& str, std::vector<int>* code) const;

  private:
    // 哈夫曼编码长度
    const int kLen;
    std::unordered_map<std::string, int> count_;
    std::unordered_map<std::string, std::vector<int>> dicts_;

  private:
    struct Node {
      std::string word;
      int count;
      Node* left;
      Node* right;
    };

  private:
    void WordBuildHelper(std::vector<int>& code, Node* root);

};

#endif /* !HAFFMAN_H */
