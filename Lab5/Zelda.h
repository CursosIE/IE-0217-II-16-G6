#ifndef ZELDA_H
#define ZELDA_H

class Zelda {
public:
    Zelda();
    Zelda(double dato, Zelda* siguiente);
    Zelda(const Zelda& orig);
    virtual ~Zelda();
    
    double dato;
    Zelda* siguiente;
    
    
    
    
private:

};

#endif /* ZELDA_H */

