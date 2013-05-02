//
//  Consultorio.h
//  Ejercicio8T8
//
//  Created by Dani on 02/05/13.
//  Copyright (c) 2013 EDA. All rights reserved.
//

#ifndef Ejercicio8T8_Consultorio_h
#define Ejercicio8T8_Consultorio_h

#include "Medico.h"
#include "Paciente.h"
#include "Tabla.h"
#include "Cola.h"

class Consultorio {
  
public:
    Consultorio() {
        consultas = Tabla<Medico, Cola<Paciente>>();
        pacientes = Cola<Paciente>();
    }
    
    void nuevoMedico( const Medico &medicoNuevo) {
        
        if ( ! consultas.esta(medicoNuevo) ) {
            
            consultas.inserta( medicoNuevo, Cola<Paciente>() );
        }
    }
    
    void pideConsulta( const Paciente &paciente) {
        pacientes.ponDetras(paciente);
    }
    
    void siguientePaciente( const Medico &medico ) {
        
        if ( consultas.esta(medico) ) {
            
            Cola<Paciente> pacientesMedico = consultas.consulta(medico);
            pacientesMedico.ponDetras( pacientes.primero() );
            
            consultas.inserta(medico, pacientesMedico);
            
            pacientes.quitaPrim();
        }
    }
    
    void atiendeConsulta( const Medico &medico) {
        
        if ( consultas.esta(medico) ) {
            
            Cola<Paciente> pacientesMedico = consultas.consulta(medico);
            
            pacientesMedico.quitaPrim();
            
            consultas.inserta(medico, pacientesMedico);
        }
    }
    
    bool tienePacientes(const Medico &medico) {
        
        bool tiene = false;
        
        if ( consultas.esta(medico)) {
            if ( consultas.consulta(medico).numElems() ) {
                tiene = true;
            }
        }
        
        return tiene;
    }
    
private:
    
    Tabla<Medico, Cola<Paciente>> consultas;
    
    Cola<Paciente> pacientes;
};

#endif
