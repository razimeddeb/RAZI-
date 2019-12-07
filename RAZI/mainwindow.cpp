#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseur.h"
#include "materiel.h"
#include <QMessageBox>
#include "smtp.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
ui->lineEdit_id->setValidator( new QRegExpValidator( QRegExp("[0-9]{5,5}"), this ) );
ui->lineEdit_nom->setValidator(new QRegExpValidator( QRegExp("[A-Za-z]{0,32}"), this ));
ui->lineEdit_prenom->setValidator(new QRegExpValidator( QRegExp("[A-Za-z]{0,32}"), this ));
ui->tabfournisseur->setModel(tmpfournisseur.afficher());
ui->tabmateriel->setModel(tmpmateriel.afficher());
ui->tabrechfournisseur->setModel(tmpfournisseur.afficher());
ui->tabfournisseurtrier->setModel(tmpfournisseur.afficher());
ui->tabrechmateriel->setModel(tmpmateriel.afficher());
ui->tabmaterieltrier->setModel(tmpmateriel.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_fournisseur_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
  Fournisseur e(id,nom,prenom);
  bool test=e.ajouter();
  if(test)
{ui->tabfournisseur->setModel(tmpfournisseur.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter fournisseur"),
                  QObject::tr("Fournisseur ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_fournisseur_clicked()
{
int id = ui->lineEdit_id_2->text().toInt();
bool test=tmpfournisseur.supprimer(id);
if(test)
{ui->tabfournisseur->setModel(tmpfournisseur.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseur"),
                QObject::tr("Fournisseur supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseur"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
void MainWindow::on_pb_ajouter_materiel_clicked()
{
    int ref = ui->lineEdit_ref->text().toInt();
    QString nom= ui->lineEdit_nom_2->text();
    int quantite= ui->lineEdit_quantite->text().toInt();
  Materiel e(ref,nom,quantite);
  bool test=e.ajouter();
  if(test)
{ui->tabmateriel->setModel(tmpmateriel.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter materiel"),
                  QObject::tr("materiel ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter materiel"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_materiel_clicked()
{
int ref = ui->lineEdit_ref_2->text().toInt();
bool test=tmpmateriel.supprimer(ref);
if(test)
{ui->tabmateriel->setModel(tmpmateriel.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer materiel"),
                QObject::tr("materiel supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer materiel"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
void MainWindow::on_pb_modifier_fournisseur_clicked()
{
    int id = ui->lineEdit_id_3->text().toInt();
    QString nom = ui->lineEdit_nom_3->text();
    QString prenom = ui->lineEdit_prenom_2->text();

    Fournisseur v;
    if(v.rech(id)){

        bool test = v.modifier(id,nom,prenom);
        if(test){
            ui->tabfournisseur->setModel(tmpfournisseur.afficher());
            QMessageBox::information(nullptr,QObject::tr("fournisseur modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
        }
    }
}
void MainWindow::on_pb_lineEdit_rech_textChanged(const QString &arg1)
{

        long id=ui->pb_lineEdit_rech->text().toLong();
        ui->tabrechfournisseur->setModel(tmpfournisseur.Rechercher(id));

}
void MainWindow::on_pushButton_trie_clicked()
{
    int id = ui->pushButton_trie->text().toInt();


    ui->tabfournisseurtrier->setModel(tmpfournisseur.trie(id));//refresh
}
void MainWindow::on_pushButton_trie1_clicked()
{
    QString nom = ui->pushButton_trie1->text();


    ui->tabfournisseurtrier->setModel(tmpfournisseur.trie1(nom));//refresh
}

void MainWindow::on_pb_modifier_materiel_clicked()
{
    int ref = ui->lineEdit_ref_3->text().toInt();
    QString nom = ui->lineEdit_nom_4->text();
    int quantite = ui->lineEdit_quantite_2->text().toInt();

    Materiel m;
    if(m.rech2(ref)){

        bool test = m.modifier2(ref,nom,quantite);
        if(test){
            ui->tabmateriel->setModel(tmpmateriel.afficher());
            QMessageBox::information(nullptr,QObject::tr("materiel modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
        }
    }
}
void MainWindow::on_pb_lineEdit_rech2_textChanged(const QString &arg1)
{

        long ref=ui->pb_lineEdit_rech2->text().toLong();
        ui->tabrechmateriel->setModel(tmpmateriel.Rechercher(ref));

}
void MainWindow::on_pushButton_trie_2_clicked()
{
    int ref = ui->pushButton_trie_2->text().toInt();


    ui->tabmaterieltrier->setModel(tmpmateriel.trie2(ref));//refresh
}
void MainWindow::on_pushButton_trie_3_clicked()
{
    QString nom = ui->pushButton_trie_3->text();


    ui->tabmaterieltrier->setModel(tmpmateriel.trie3(nom));//refresh
}
void MainWindow::on_pushButton_trie_4_clicked()
{
    int quantite = ui->pushButton_trie_4->text().toInt();


    ui->tabmaterieltrier->setModel(tmpmateriel.trie4(quantite));//refresh
}
void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

