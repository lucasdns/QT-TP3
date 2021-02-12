#include "client.h"

client::client()
{

}

client::~client()
{

}

client::client(int id_client, float cin, float tel, int mdp, QString nom, QString prenom)
{
    this->m_id_client = id_client;
    this->m_cin = cin;
    this->m_tel = tel;
    this->m_mdp = mdp;
    this->m_nom = nom;
    this->m_prenom = prenom;
}
