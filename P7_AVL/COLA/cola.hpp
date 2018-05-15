//
//  cola.hpp
//  P6_ABB
//
//  Created by Pablo González González on 2/5/18.
//  Copyright © 2018 Pablo González González. All rights reserved.
//

#ifndef cola_hpp
#define cola_hpp

#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

template<class TDato>
class cola{
    
private:
    queue<int> niveles_;
    queue<TDato> cola_;
    
public:
    cola();
    ~cola();
    
    void push_dato(TDato t, int n);
    TDato pop_dato(int& n);
    
    bool empty(void);
};


/* */


template<class TDato>
cola<TDato> :: cola():
    niveles_(),
    cola_()
{}


template<class TDato>
cola<TDato> :: ~cola() {}


/* */


template<class TDato>
void cola<TDato> :: push_dato(TDato t, int n){
    
    this->cola_.push(t);
    this->niveles_.push(n);
}


template<class TDato>
TDato cola<TDato> :: pop_dato(int& n){
    
    n = this->niveles_.front();
    this->niveles_.pop();
    
    TDato aux = this->cola_.front();
    this->cola_.pop();
    
    return aux;
}


/* */


template<class TDato>
bool cola<TDato> :: empty(void){
    
    if(this->cola_.empty() && this->niveles_.empty()){
        return true;
    }
    
    else{
        return false;
    }
}


/* */


#endif /* cola_hpp */
