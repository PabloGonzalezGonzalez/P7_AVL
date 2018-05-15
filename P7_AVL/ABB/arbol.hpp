//
//  arbol.hpp
//  P6_ABB
//
//  Created by Pablo González González on 3/5/18.
//  Copyright © 2018 Pablo González González. All rights reserved.
//

#ifndef arbol_hpp
#define arbol_hpp

#include "node.hpp"
#include "cola.hpp"

using namespace std;

template<class TDato>

class ABB{
    
private:
    node<TDato>* raiz_;
    
public:
    ABB();
    virtual ~ABB();
    
    node<TDato>*& buscar(const TDato& clave);
    void buscar_nodo(TDato& clave);
    void insertar(const TDato& clave);
    void eliminar(const TDato& clave);
    
    ostream& write(ostream& os);
    
private:
    void podar(node<TDato>*& raiz);
    bool empty() const;
    
    node<TDato>*& buscar_rama(node<TDato>*& nodo, const TDato& clave);
    void insertar_rama(node<TDato>*& nodo, const TDato& clave, node<TDato>*& prev);
    void eliminar_rama(node<TDato>*& nodo, const TDato& clave);
    void sustituye(node<TDato>*& eliminado, node<TDato>*& sust);
    
    bool igual (const TDato& a, const TDato& b) const;
    bool menor (const TDato& a, const TDato& b) const;
    bool mayor (const TDato& a, const TDato& b) const;

    ostream& write(ostream& os, node<TDato>*& nodo);
};


/* */


template<class TDato>
ABB<TDato> :: ABB():
    raiz_(NULL)
{}


template<class TDato>
ABB<TDato> :: ~ABB(){
    
    this->podar(raiz_);
}


template<class TDato>
void ABB<TDato> :: podar(node<TDato>*& raiz){
    
    if(raiz != NULL){
        
        podar(raiz->get_izq());
        podar(raiz->get_der());
        
        delete raiz;
        raiz = NULL;
    }
}

/* */


template<class TDato>
bool ABB<TDato> :: empty(void) const{
    
    if(this->raiz_ == NULL){
        return true;
    }
    
    else{
        return false;
    }
}


/* */


template<class TDato>
void ABB<TDato> :: buscar_nodo(TDato& clave){
    
    node<TDato>*& aux = buscar_rama(this->raiz_, clave);
    
    if(aux == NULL){
        cout << endl << "NO EXISTE LA CLAVE " << endl << endl;
    }
    
    else{
        
        aux->write(cout);
    }
}


template<class TDato>
node<TDato>*& ABB<TDato> :: buscar(const TDato& clave){
    
    return(this->buscar_rama(this->raiz_, clave));
}


template<class TDato>
node<TDato>*& ABB<TDato> :: buscar_rama(node<TDato>*& nodo, const TDato& clave){
    
    if(nodo == NULL){
        
        return nodo;
    }
    
    else{
        
        if(this->igual(nodo->get_dato(), clave)){
            
            return nodo;
        }
        
        else{
            
            if(this->menor(nodo->get_dato(), clave)){
                
                return (buscar_rama(nodo->get_der(), clave));
            }
            
            else{
                
                return (buscar_rama(nodo->get_izq(), clave));
            }
        }
    }
}


/* */


template<class TDato>
void ABB<TDato> :: insertar(const TDato& clave){
    
    node<TDato>* prev = this->raiz_;
    
    this->insertar_rama(this->raiz_, clave, prev);
    
}


template<class TDato>
void ABB<TDato> :: insertar_rama(node<TDato>*& nodo, const TDato& clave, node<TDato>*& prev){
    
    if(nodo == NULL){
        
        nodo = new node<TDato>(clave);
        
        if(prev == NULL){
            nodo->set_pad(nodo);
        }
        
        else{
            nodo->set_pad(prev);
        }
        
        nodo->aumentar_cont();
    }
    
    else{
        
        if(menor(clave, nodo->get_dato())){
            
            insertar_rama(nodo->get_izq(), clave, nodo);
        }
        
        else{
            
            if(mayor(clave, nodo->get_dato())){
                
                insertar_rama(nodo->get_der(), clave, nodo);
            }
            
            else{
                
                // cout << endl << "CLAVE YA INSERTADA" << endl;
                nodo->aumentar_cont();
            }
        }
    }
}


/* */


template<class TDato>
void ABB<TDato> :: eliminar(const TDato& clave){
    
    eliminar_rama(this->raiz_, clave);
}


template<class TDato>
void ABB<TDato> :: eliminar_rama(node<TDato>*& nodo, const TDato& clave){
    
    if(nodo == NULL){
        
        cout << endl << "LA CLAVE NO EXISTE" << endl;
    }
    
    if(clave < nodo->get_dato()){
            
        eliminar_rama(nodo->get_izq(), clave);
    }
        
    else if(clave > nodo->get_dato()){
                
        eliminar_rama(nodo->get_der(), clave);
    }
                
    else{
        
        if(nodo->get_cont() > 1){
            
            nodo->disminuir_cont();
        }
        
        else{
            
            node<TDato>* eliminado = nodo;
            
            if(nodo->get_der() == NULL){
                
                nodo = nodo->get_izq();
            }
            
            else if(nodo->get_izq() == NULL){
                
                nodo = nodo->get_der();
            }
            
            else{
                
                sustituye(eliminado, nodo->get_izq());
            }
            
            delete eliminado;
        }
    }
}


template<class TDato>
void ABB<TDato> :: sustituye(node<TDato>*& eliminado, node<TDato>*& sust){
    
    if(sust->get_der() != NULL){
        
        sustituye(eliminado, sust->get_der());
    }
    
    else{
        
        eliminado->set_dato(sust->get_dato());
        eliminado = sust;
        
        sust = sust->get_izq();
    }
}


/* */


template<class TDato>
bool ABB<TDato> :: igual(const TDato& a, const TDato& b) const{
    
    if(a == b){
        return true;
    }
    
    else{
        return false;
    }
}


template<class TDato>
bool ABB<TDato> :: mayor(const TDato& a, const TDato& b) const{
    
    if(a > b){
        return true;
    }
    
    else{
        return false;
    }
}


template<class TDato>
bool ABB<TDato> :: menor(const TDato& a, const TDato& b) const{
    
    if(a < b){
        return true;
    }
    
    else{
        return false;
    }
}


/* */


template<class TDato>
ostream& ABB<TDato> :: write(ostream& os){
    
    write(os, this->raiz_);
    
    return os;
}


template<class TDato>
ostream& ABB<TDato> :: write(ostream& os, node<TDato>*& nodo){
    
    cola<node<TDato>* > impr;
    node<TDato>* aux;
    
    int nivel = 0, act = 0;
    
    impr.push_dato(nodo, nivel);
    
    os << nivel << " nivel: ";
    
    while(!impr.empty()){
        
        aux = impr.pop_dato(nivel);
        
        if(nivel > act){
            
            act = nivel;
            os << endl << nivel << " nivel: ";
        }
        
        if(aux != NULL){
            
            os << "[" << aux->get_dato() << "]";
            
            impr.push_dato(aux->get_izq(), nivel+1);
            impr.push_dato(aux->get_der(), nivel+1);
        }
        
        else{
            
            os << "[.]";
        }
    }
    
    return os;
}



/* */

#endif /* arbol_hpp */
