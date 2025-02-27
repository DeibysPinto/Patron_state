#include <iostream>

class State {
public:
    virtual ~State() {}
    virtual void handle() = 0;
};

class Semaforo {
private:
    State* estadoActual;

public:
    Semaforo(State* estado) : estadoActual(estado) {}

    void setEstado(State* nuevoEstado) {
        estadoActual = nuevoEstado;
    }

    void cambiar() {
        estadoActual->handle();
    }
};

class EstadoRojo : public State {
public:
    void handle() override {
        std::cout << "El semáforo está en ROJO. Detenerse!" << std::endl;
    }
};

class EstadoAmarillo : public State {
public:
    void handle() override {
        std::cout << "El semáforo está en AMARILLO. Precaución!" << std::endl;
    }
};

class EstadoVerde : public State {
public:
    void handle() override {
        std::cout << "El semáforo está en VERDE. Avanzar!" << std::endl;
    }
};

int main() {
	
    EstadoRojo rojo;
    EstadoAmarillo amarillo;
    EstadoVerde verde;

    Semaforo semaforo(&rojo);

    semaforo.cambiar();

    semaforo.setEstado(&verde);
    semaforo.cambiar(); 

    semaforo.setEstado(&amarillo);
    semaforo.cambiar(); 

    semaforo.setEstado(&rojo);
    semaforo.cambiar(); 

    return 0;
}
