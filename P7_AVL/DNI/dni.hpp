//
//  dni.hpp
//  P4_Hash
//
//  Created by Pablo González González on 5/4/18.
//  Copyright © 2018 Pablo González González. All rights reserved.
//

#ifndef dni_hpp
#define dni_hpp

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

class dni_t{
    
private:
    long int key_;
    long int num_;
    char let_;
    
public:
    dni_t();
    dni_t(long int n, char l);
    dni_t(const dni_t& dni);
    ~dni_t();
    
    bool operator== (const dni_t& dni) const;
    bool operator!= (const dni_t& dni) const;
    bool operator< (const dni_t& dni) const;
    bool operator> (const dni_t& dni) const;
    
    dni_t& operator=(const dni_t& dni);
    dni_t& operator=(const long int& dni);
    
    operator long int(void) const;
    
    void write(void) const;
};

#endif /* dni_hpp */
