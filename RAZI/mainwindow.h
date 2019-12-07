#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fournisseur.h"
#include "materiel.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_fournisseur_clicked();
    void on_pb_ajouter_materiel_clicked();
    void on_pb_supprimer_materiel_clicked();
    void on_pb_supprimer_fournisseur_clicked();
    void on_pb_modifier_fournisseur_clicked();
    void on_pb_trierfournisseur_clicked();
    void on_pb_lineEdit_rech_textChanged(const QString &arg1);
    void on_pushButton_trie_clicked();
    void on_pushButton_trie1_clicked();
    void on_pb_modifier_materiel_clicked();
    void on_pb_lineEdit_rech2_textChanged(const QString &arg1);
    void on_pushButton_trie_2_clicked();
    void on_pushButton_trie_3_clicked();
    void on_pushButton_trie_4_clicked();
    void sendMail();
    void mailSent(QString);

private:
    Ui::MainWindow *ui;
    Fournisseur tmpfournisseur;
    Materiel tmpmateriel;
};

#endif // MAINWINDOW_H
