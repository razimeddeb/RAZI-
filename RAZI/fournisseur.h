#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Fournisseur
{
public:
    Fournisseur();
   Fournisseur(int,QString,QString);
    QString get_nom();
    QString get_prenom();
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool rech(int);
    bool modifier(int,QString,QString);
    QSqlQueryModel *Rechercher(long id);
    QSqlQueryModel * trie(int);
    QSqlQueryModel * trie1(QString);





private:
    QString nom,prenom;
    int id;
};



#endif // FOURNISSEUR_H
