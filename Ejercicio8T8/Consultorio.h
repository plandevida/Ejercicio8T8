//
//  Consultorio.h
//  Ejercicio8T8
//
//  Created by Dani on 02/05/13.
//  Copyright (c) 2013 EDA. All rights reserved.
//

#ifndef Ejercicio8T8_Consultorio_h
#define Ejercicio8T8_Consultorio_h

#include "Medico.h";
#include "Paciente.h";

class Consultorio {
  
public:
    Consultorio() {
        
    }
    
private:
    
    Lista<Medico> medicos;
    
    Lista<Paciente> pacientes;
};

#endif
