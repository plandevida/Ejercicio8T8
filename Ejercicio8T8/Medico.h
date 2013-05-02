//
//  Medico.h
//  Ejercicio8T8
//
//  Created by Dani on 02/05/13.
//  Copyright (c) 2013 EDA. All rights reserved.
//

#ifndef Ejercicio8T8_Medico_h
#define Ejercicio8T8_Medico_h

#include <cmath>

class Medico {
    
public:
    
    Medico() : nombre(new char[MAX_NOMBRE]) {}
    
    inline unsigned int hash() {
        
        unsigned int hash = 0;
        
        for( int i = 0; i < strlen(nombre); i++) {
            hash += ((int)nombre[i])*pow(2, i);
        }
        
        return hash;
    }
    
    bool operator==(const Medico &medico) const {
        
        return ( strcmp(nombre, medico.nombre) );
    }
    
private:
    char *nombre;
    
    int MAX_NOMBRE = 20;
};

#endif
