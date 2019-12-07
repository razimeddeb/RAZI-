#include "materiel.h"

#include <QDebug>
Materiel::Materiel()
{
ref=0;
nom="";
quantite=0;
}
Materiel::Materiel(int ref,QString nom,int quantite)
{
  this->ref=ref;
  this->nom=nom;
  this->quantite=quantite;
}
int Materiel::get_ref(){return  ref;}
QString Materiel::get_nom(){return  nom;}
int Materiel::get_quantite(){return quantite;}


bool Materiel::ajouter()
{
QSqlQuery query;
QString res= QString::number(ref);
QString res1= QString::number(quantite);

query.prepare("INSERT INTO materiel (REF, NOM, QUANTITE) "
                    "VALUES (:ref, :nom, :quantite)");
query.bindValue(":ref", res);
query.bindValue(":nom", nom);
query.bindValue(":quantite", res1);

return    query.exec();
}

QSqlQueryModel * Materiel::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from materiel");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
    return model;
}

bool Materiel::supprimer(int reff)
{
QSqlQuery query;
QString res= QString::number(reff);
query.prepare("Delete from materiel where ref = :ref ");
query.bindValue(":ref", res);
return    query.exec();
}
bool Materiel::rech2(int x){
    QSqlQuery query;
    QString res2= QString::number(x);

    query.prepare("select * from materiel where ref = :ref");
    query.bindValue(":ref", res2);
    return query.exec();
}
bool Materiel::modifier2(int a1,QString b1,int c1){
    QSqlQuery query;
    query.prepare("update materiel set nom=:nom ,quantite=:quantite   where ref = :ref");
    query.bindValue(":ref", a1);
    query.bindValue(":nom", b1);
    query.bindValue(":quantite", c1);

    return query.exec();
}
QSqlQueryModel * Materiel::Rechercher(long ref)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString::number(ref);
    model->setQuery("select * from materiel where (ref LIKE '"+res+"%' ) ");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));


            return  model;
}
QSqlQueryModel * Materiel::trie2(int)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from materiel order by ref");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
    return model;
}
QSqlQueryModel * Materiel::trie3(QString)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from materiel order by nom");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
    return model;
}
QSqlQueryModel * Materiel::trie4(int)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from materiel order by quantite");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
    return model;
}
