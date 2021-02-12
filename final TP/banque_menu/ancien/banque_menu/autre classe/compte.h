#ifndef COMPTE_H
#define COMPTE_H

#endif // COMPTE_H

class client;

class compte
{

public:
    compte();
    ~compte();
    compte(int numero, float solde);

private:
    int m_numero;
    float m_solde;
};
