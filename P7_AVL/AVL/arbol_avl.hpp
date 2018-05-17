//
//  arbol_avl.hpp
//  P7_AVL
//
//  Created by Pablo González González on 17/5/18.
//  Copyright © 2018 Pablo González González. All rights reserved.
//

#ifndef arbol_avl_hpp
#define arbol_avl_hpp

#include "arbol.hpp"

template<class TDato>
class AVL : public ABB<TDato> {
    
public:
    
    AVL();
    ~AVL();
    
    void podar(node<TDato>*& nodo);
    node<TDato>* get_raiz(void);
    
    void rotacion_II(node<TDato>*& nodo);
    void rotacion_DD(node<TDato>*& nodo);
    void rotacion_ID(node<TDato>*& nodo);
    void rotacion_DI(node<TDato>*& nodo);
    
    virtual void insertar(const TDato& clave);
    void insertar_bal(node<TDato>*& nodo, node<TDato>*& nuevo, bool& grow);
    void insertar_re_balan_izq(node<TDato>*& nodo, bool& grow);
    void insertar_re_balan_der(node<TDato>*& nodo, bool& grow);
    
    virtual void eliminar(const TDato& clave);
    void eliminar_bal(node<TDato>*& nodo, const TDato& clave, bool& degrow);
    void sustituye(node<TDato>*& eliminado, node<TDato>*& sust, bool& degrow);
    void eliminar_re_bal_I(node<TDato>*& nodo, bool& degrow);
    void eliminar_re_bal_D(node<TDato>*& node, bool& degrow);

};

/* */


template<class TDato>
AVL<TDato> :: AVL(){
    
    this->raiz_ = NULL;
}


template<class TDato>
AVL<TDato> :: ~AVL(){
    
    podar(this->raiz_);
}


/* */


template<class TDato>
void AVL<TDato> :: podar(node<TDato>*& nodo){
    
    if(nodo != NULL){
        
        podar(nodo->get_der());
        podar(nodo->get_izq());
        delete nodo;
        nodo = NULL;
    }
}


template<class TDato>
node<TDato>* AVL<TDato> :: get_raiz(void){
    
    return (this->raiz_);
}


/* */


template<class TDato>
void AVL<TDato> :: rotacion_II(node<TDato>*& nodo){
    
    node<TDato>* aux = nodo->get_izq();
    nodo->get_izq() = aux->get_der();
    aux->get_der() = nodo;
    
    if(aux->get_bal() == 1){
        
        nodo->set_bal(0);
        aux->set_bal(0);
    }
    
    else{
        
        nodo->set_bal(1);
        aux->set_bal(-1);
    }
    
    nodo = aux;
}


template<class TDato>
void AVL<TDato> :: rotacion_DD(node<TDato>*& nodo){
    
    node<TDato>* aux = nodo->get_der();
    nodo->get_der() = aux->get_izq();
    aux->get_izq() = nodo;
    
    if(aux->get_bal() == -1){
        
        nodo->set_bal(0);
        aux->set_bal(0);
    }
    
    else{
        
        nodo->set_bal(-1);
        aux->set_bal(1);
    }
    
    nodo = aux;
}


template<class TDato>
void AVL<TDato> :: rotacion_ID(node<TDato>*& nodo){
    
    node<TDato>* aux = nodo->get_izq();
    node<TDato>* tmp = aux->get_der();
    
    nodo->get_izq() = tmp->get_der();
    tmp->get_der() = nodo;
    aux->get_der() = tmp->get_izq();
    tmp->get_izq() = aux;
    
    
    if(tmp->get_bal() == -1){
        
        aux->set_bal(1);
    }
    
    else{
        
        aux->set_bal(0);
    }
    
    if(tmp->get_bal() == 1){
        
        nodo->set_bal(-1);
    }
    
    else{
        
        nodo->set_bal(0);
    }
    
    tmp->set_bal(0);
    nodo = tmp;
}


/* */


template<class TDato>
void AVL<TDato> :: rotacion_DI(node<TDato>*& nodo){
    
    node<TDato>* aux = nodo->get_der();
    node<TDato>* tmp = aux->get_izq();
    
    nodo->get_der() = tmp->get_izq();
    tmp->get_izq() = nodo;
    aux->get_izq() = tmp->get_der();
    tmp->get_der() = aux;
    
    if(tmp->get_bal() == 1){
        
        aux->set_bal(-1);
    }
    
    else{
        
        aux->set_bal(0);
    }
    
    if(tmp->get_bal() == -1){
        
        nodo->set_bal(1);
    }
        
    else{
    
        nodo->set_bal(0);
    }
    
    tmp->set_bal(0);
    nodo = tmp;
}

/* */


template<class TDato>
void AVL<TDato> :: insertar(const TDato& clave){
    
    node<TDato>* aux = new node<TDato>(clave);
    aux->set_bal(0);
    
    bool grow = false;
    insertar_bal(this->raiz_, aux, grow);
}


template<class TDato>
void AVL<TDato> :: insertar_bal(node<TDato>*& nodo, node<TDato>*& nuevo, bool& grow){
    
    if(nodo == NULL){
        
        nodo = nuevo;
        grow = true;
    }
    
    else{
        
        if(nuevo->get_dato() == nodo->get_dato()){
            
            cout << endl << "YA SE HA INSERTADO ESTA CLAVE" << endl;
        }
        
        else if(nuevo->get_dato() < nodo->get_dato()){
            
            insertar_bal(nodo->get_izq(), nuevo, grow);
            
            if(grow){
                
                insertar_re_balan_izq(nodo, grow);
            }
        }
        
        else if(nuevo->get_dato() > nodo->get_dato()){
            
            insertar_bal(nodo->get_der(), nuevo, grow);
            
            if(grow){
                
                insertar_re_balan_der(nodo, grow);
            }
        }
    }
}


template<class TDato>
void AVL<TDato> :: insertar_re_balan_izq(node<TDato>*& nodo, bool& grow){
    
    switch(nodo->get_bal()) {
            
        case -1:{
            
            nodo->set_bal(0);
            grow = false;
            
            break;}
            
        case 0:{
            
            nodo->set_bal(1);
            
            break;}
            
        case 1:{
            
            node<TDato>* aux = nodo->get_izq();
            
            if(aux->get_bal() == 1){
            
                rotacion_II(nodo);
            }
            
            else{
                
                rotacion_ID(nodo);
            }
            
            grow = false;
            
            break;}
    }
}



template<class TDato>
void AVL<TDato> :: insertar_re_balan_der(node<TDato>*& nodo, bool& grow){
    
    switch(nodo->get_bal()) {
            
        case -1:{
            
            node<TDato>* aux = nodo->get_der();
            
            if(aux->get_bal()== -1){
                
                rotacion_DD(nodo);
            }
            
            else{
                
                rotacion_DI(nodo);
            }
            
            grow = false;
            
            break;}
            
        case 0:{
            
            nodo->set_bal(-1);
            
            break;}
            
        case 1:{
            
            nodo->set_bal(0);
            grow = false;
            
            break;}
    }
}


/* */


template<class TDato>
void AVL<TDato> :: eliminar(const TDato& clave){
    
    bool degrow = false;
    eliminar_bal(this->raiz_, clave, degrow);
}


template<class TDato>
void AVL<TDato> :: eliminar_bal(node<TDato>*& nodo, const TDato& clave, bool& degrow){
    
    if(nodo == NULL) {
        
        cout << endl << "El nodo a eliminar no esta en el arbol!" << endl;
        return;
    }
    
    if(clave < nodo->get_dato()) {
        
        eliminar_bal(nodo->get_izq(), clave, degrow);
        
        if(degrow){
            
            eliminar_re_bal_I(nodo, degrow);
        }
        
    }
    
    else if(clave > nodo->get_dato()){
        
        eliminar_bal(nodo->get_der(), clave, degrow);
        
        if(degrow){
            
            eliminar_re_bal_D(nodo, degrow);
        }
            
    }
    
    else{
        
        node<TDato>* eliminado = nodo;
        
        if(!nodo->get_izq()){
            
            nodo = nodo->get_der();
            degrow = true;
        }
        
        else if(!nodo->get_der()){
            
            nodo = nodo->get_izq();
            degrow = true;
        }
        
        else{
            sustituye(eliminado, nodo->get_izq(), degrow);
            
            if(degrow){
                eliminar_re_bal_I(nodo, degrow);
            }
        }
        delete eliminado;
    }
}


template<class TDato>
void AVL<TDato> :: sustituye(node<TDato>*& eliminado, node<TDato>*& sust, bool& degrow){
    
    if(sust->get_der()){
        
        sustituye(eliminado, sust->get_der(), degrow);
        
        if(degrow){
            
            eliminar_re_bal_D(sust, degrow);
        }
    }
    
    else{
        
        eliminado->set_dato(sust->get_dato());
        eliminado = sust;
        sust = sust->get_izq();
        degrow = true;
    }
}


template<class TDato>
void AVL<TDato> :: eliminar_re_bal_I(node<TDato>*& nodo, bool& degrow){
    
    node<TDato>* aux = nodo->get_der();
    
    switch(nodo->get_bal()) {
        case -1:{
            if(aux->get_bal() > 0){
    
                rotacion_DI(nodo);
            }
            
            else{
                
                if(aux->get_bal() == 0){
                    
                    degrow = false;
                }
                
                rotacion_DD(nodo);
            }
            
            break;}
            
        case 0:{
            
            nodo->set_bal(-1);
            degrow = false;
            break;}
            
        case 1:{
            
            nodo->set_bal(0);
            break;}
    }
}


template<class TDato>
void AVL<TDato> :: eliminar_re_bal_D(node<TDato>*& nodo, bool& degrow){
    
    node<TDato>* aux = nodo->get_izq();
    
    switch(nodo->get_bal()) {
            
        case 1:{
            
            if(aux->get_bal() < 0){
                
                rotacion_ID(nodo);
            }
            
            else {
                
                if(aux->get_bal() == 0){
                    degrow = false;
                }
                
                rotacion_II(nodo);
            }
            
            break;}
            
        case 0:{
            
            nodo->set_bal(1);
            degrow = false;
            
            break;}
            
        case -1:{
            
            nodo->set_bal(0);
            break;}
    }
}

/* */

#endif /* arbol_avl_hpp */
