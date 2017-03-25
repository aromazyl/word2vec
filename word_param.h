/*
 * word_param.h
 * Copyright (C) 2017 zhangyule <zyl2336709@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef WORD_PARAM_H
#define WORD_PARAM_H

#include "./hierarcher.h"
#include "./negtive_sample.h"

namespace word2vec {
template <typename T>
struct Params;

template <int N>
struct WordVectors;


template <int N>
struct Param<WordVectors<N>> {
  std::unordered_map<std::string, std::vector<float>> word_vecs;
  enum { DIM = N };
  float eita;
};

template <int N>
struct Param<Hierarcher> : public Param<WordVectors<N>> {
  
};

template <int N>
struct Param<NegtiveSample> : public Param<WordVectors<N>> {
  
};

}

#endif /* !WORD_PARAM_H */
