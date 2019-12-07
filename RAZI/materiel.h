#ifndef MATERIEL_H
#define MATERIEL_H
#include <QObject>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Materiel
{public:
    Materiel();
    Materiel(int,QString,int);
    QString get_nom();
    int get_quantite();
    int get_ref();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool rech2(int);
    bool modifier2(int,QString,int);
    QSqlQueryModel *Rechercher(long ref);
    QSqlQueryModel * trie2(int);
    QSqlQueryModel * trie3(QString);
    QSqlQueryModel * trie4(int);
private:
    QString nom;
    int ref,quantite;
};

#endif // MATERIEL_H
