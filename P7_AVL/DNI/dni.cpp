//
//  dni.cpp
//  P4_Hash
//
//  Created by Pablo González González on 5/4/18.
//  Copyright © 2018 Pablo González González. All rights reserved.
//

#include "dni.hpp"


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



dni_t :: operator long int(void) const{
    
    return this->key_;
}



/* */



void dni_t :: write(void) const{
    
    cout << "Número: " << num_ << endl;
    cout << "Letra: " << let_ << endl;
    cout << "Clave: " << key_ << endl;
}



/* */
