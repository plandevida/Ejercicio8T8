//
//  Paciente.h
//  Ejercicio8T8
//
//  Created by Dani on 02/05/13.
//  Copyright (c) 2013 EDA. All rights reserved.
//

#ifndef Ejercicio8T8_Paciente_h
#define Ejercicio8T8_Paciente_h

class Paciente {
    
public:
    
    Paciente() : nombre(new char[MAX_NOMBRE]) {}
    
    unsigned int hash() {
        
        unsigned int hash = 0;
        
        for( int i = 0; i < strlen(nombre); i++) {
            hash += ((int)nombre[i])*pow(2, i);
        }
        
        return hash;
    }
    
private:
    char *nombre;
    
    int MAX_NOMBRE = 20;
};

#endif
