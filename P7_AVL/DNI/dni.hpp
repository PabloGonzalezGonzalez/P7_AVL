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
    
    void write(void) const;
};


/* */


dni_t :: dni_t():
num_(0),
let_(' '),
key_(-1)
{}



dni_t :: dni_t(long int n, char l):
num_(n),
let_(l)
{
    
    long int aux = (unsigned long)let_;
    key_ = aux + num_;
}



dni_t :: dni_t(const dni_t& dni):
num_(dni.num_),
let_(dni.let_),
key_(dni.key_)
{}



dni_t :: ~dni_t(){
    
    num_ = 0;
}



/* */




bool dni_t :: operator== (const dni_t& dni) const{
    
    if(this->key_ == dni.key_){
        
        return true;
    }
    
    return false;
}



bool dni_t :: operator!= (const dni_t& dni) const{
    
    if(this->key_ == dni.key_){
        
        return true;
    }
    
    return false;
}



bool dni_t :: operator< (const dni_t& dni) const{
    
    if(this->key_ < dni.key_){
        
        return true;
    }
    
    return false;
}



bool dni_t :: operator> (const dni_t& dni) const{
    
    if(this->key_ > dni.key_){
        
        return true;
    }
    
    return false;
}



dni_t& dni_t :: operator= (const dni_t& dni){
    
    this->num_ = dni.num_;
    this->let_ = dni.let_;
    this->key_ = dni.key_;
    
    return *this;
}


/* */



void dni_t :: write(void) const{
    
    std::cout << "Número: " << num_ << std::endl;
    std::cout << "Letra: " << let_ << std::endl;
    std::cout << "Clave: " << key_ << std::endl;
}



/* */


#endif /* dni_hpp */
