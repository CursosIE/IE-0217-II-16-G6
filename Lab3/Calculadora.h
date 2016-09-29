#ifndef CALCULADORA_H
#define CALCULADORA_H


template <typename data>

class Calculadora {
    
public:
    
    Calculadora(){}; 
    Calculadora(const Calculadora& orig){};
    virtual ~Calculadora(){};
    
    data add(data &d1,  const data &d2){
        
        return(d1 + d2);

    }

    data sub(data &d1, const data &d2){

        return (d1 - d2);

    }

    data mul(data &d1, const data &d2){

        return (d1 * d2);

    }

    data div(data &d1, const data &d2){

        return (d1 / d2);

    }

    void print(data &d){
        ~d;        
    }
};


#endif 
