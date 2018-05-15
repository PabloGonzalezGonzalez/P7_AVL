//
//  node.hpp
//  P6_ABB
//
//  Created by Pablo González González on 2/5/18.
//  Copyright © 2018 Pablo González González. All rights reserved.
//

#ifndef node_hpp
#define node_hpp

#include <iostream>
#include <cstdio>

using namespace std;

template<class TDato>
class node{
    
private:
    node<TDato>* izq_;
    node<TDato>* der_;
    node<TDato>* pad_;
    TDato dato_;
    
    int cont_;
    
public:
    node();
    node(const TDato& t);
    virtual ~node();
    
    void set_izq(node<TDato>* a);
    void set_der(node<TDato>* a);
    void set_pad(node<TDato>* a);
    void set_dato(const TDato& a);
    
    node<TDato>*& get_izq(void);
    node<TDato>*& get_der(void);
    node<TDato>*& get_pad(void);
    node<TDato>* get_izq(void) const;
    node<TDato>* get_der(void) const;
    node<TDato>* get_pad(void) const;
    TDato get_dato(void) const;
    
    void aumentar_cont(void);
    void disminuir_cont(void);
    int get_cont(void);
    
    node<TDato>& operator=(const node<TDato>& n);
    
    ostream& write(ostream& os);
};


/* */


template<class TDato>
node<TDato> :: node():
    izq_(NULL),
    der_(NULL),
    pad_(NULL),
    dato_(),
    cont_(0)
{}


template<class TDato>
node<TDato> :: node(const TDato& t):
    izq_(NULL),
    der_(NULL),
    pad_(NULL),
    dato_(t),
    cont_(0)
{}


template<class TDato>
node<TDato> :: ~node(){
    
    izq_ = NULL;
    der_ = NULL;
    pad_ = NULL;
}


/* */


template<class TDato>
void node<TDato> :: set_izq(node<TDato>* a){
    
    this-> izq_ = a;
}


template<class TDato>
void node<TDato> :: set_der(node<TDato>* a){
    
    this-> der_ = a;
}


template<class TDato>
void node<TDato> :: set_pad(node<TDato>* a){
    
    this-> pad_ = a;
}


template<class TDato>
void node<TDato> :: set_dato(const TDato& a){
    
    this-> dato_ = a;
}


/* */


template<class TDato>
node<TDato>*& node<TDato> :: get_izq(void){
    
    return (this->izq_);
}


template<class TDato>
node<TDato>*& node<TDato> :: get_der(void){
    
    return (this->der_);
}


template<class TDato>
node<TDato>*& node<TDato> :: get_pad(void){
    
    return (this->pad_);
}

template<class TDato>
node<TDato>* node<TDato> :: get_izq(void) const{
    
    return (this->izq_);
}


template<class TDato>
node<TDato>* node<TDato> :: get_der(void) const{
    
    return (this->der_);
}


template<class TDato>
node<TDato>* node<TDato> :: get_pad(void) const{
    
    return (this->pad_);
}

template<class TDato>
TDato node<TDato> :: get_dato(void) const{
    
    return (this->dato_);
}


/* */


template<class TDato>
node<TDato>& node<TDato> :: operator= (const node<TDato>& n){
    
    this->der_ = n->der_;
    this->izq_ = n->izq_;
    this->pad_ = n->pad_;
    
    this->dato_ = n->dato_;
    
    return (*this);
}

template<class TDato>
ostream& node<TDato> :: write(ostream& os){
    
    os << "· Padre: " << this->pad_ << endl;
    os << "· Dato: " << this->dato_ << endl;
    
    if(this->izq_ != NULL){
        os << "· Hijo izq: " << this->izq_ << endl;
    }
    else{
        os << "· Hijo izq: NULL" << endl;
    }
    
    if(this->der_ != NULL){
        os << "· Hijo der: " << this->der_ << endl;
    }
    else{
        os << "· Hijo izq: NULL" << endl;
    }
}

/* */


template<class TDato>
void node<TDato> :: aumentar_cont(void){
    
    this->cont_ ++;
}


template<class TDato>
void node<TDato> :: disminuir_cont(void){
    
    this->cont_ --;
}


template<class TDato>
int node<TDato> :: get_cont(void){
    
    return (this->cont_);
}




/* */


#endif /* node_hpp */
