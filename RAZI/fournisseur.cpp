#include "fournisseur.h"
#include <QDebug>
Fournisseur::Fournisseur()
{
id=0;
nom="";
prenom="";
}
Fournisseur::Fournisseur(int id,QString nom,QString prenom)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
}

QString Fournisseur::get_nom(){return  nom;}
QString Fournisseur::get_prenom(){return prenom;}
int Fournisseur::get_id(){return  id;}

bool Fournisseur::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO fournisseur (ID, NOM, PRENOM) "
                    "VALUES (:id, :nom, :prenom)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);

return    query.exec();
}

QSqlQueryModel * Fournisseur::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from fournisseur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    return model;
}

bool Fournisseur::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from fournisseur where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool Fournisseur::rech(int x){
    QSqlQuery query;
    QString res= QString::number(x);

    query.prepare("select * from fournisseur where ID = :id");
    query.bindValue(":id", res);
    return query.exec();
}
bool Fournisseur::modifier(int a,QString b,QString c){
    QSqlQuery query;
    query.prepare("update fournisseur set nom=:nom ,prenom=:prenom   where id = :id");
    query.bindValue(":id", a);
    query.bindValue(":nom", b);
    query.bindValue(":prenom", c);

    return query.exec();
}
QSqlQueryModel * Fournisseur::Rechercher(long id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString::number(id);
    model->setQuery("select * from fournisseur where (id LIKE '"+res+"%' ) ");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));


            return  model;
}
QSqlQueryModel * Fournisseur::trie(int)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from fournisseur order by id");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    return model;
}
QSqlQueryModel * Fournisseur::trie1(QString)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from fournisseur order by nom");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    return model;
}
