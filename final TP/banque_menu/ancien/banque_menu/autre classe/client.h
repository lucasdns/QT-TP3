#ifndef CLIENT_H
#define CLIENT_H

#endif // CLIENT_H
#include <QString>


class client
{

public:
    client();
    ~client();
    client(int id_client, float cin, float tel, int mdp, QString nom, QString prenom);

private:
    int m_id_client;
    int m_cin;
    int m_tel;
    int m_mdp;
    QString m_nom;
    QString m_prenom;
};
