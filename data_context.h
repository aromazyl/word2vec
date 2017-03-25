/*
 * data_context.h
 * Copyright (C) 2017 zhangyule <zyl2336709@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef DATA_CONTEXT_H
#define DATA_CONTEXT_H

namespace context {
class DataContext {
  public:
    DataContext(const std::string& filename);
    ~DataContext();

    // get next string, return false if failure
    bool GetNext(char*, int);

    // reflush stream
    void Reflush();

};

}

#endif /* !DATA_CONTEXT_H */
