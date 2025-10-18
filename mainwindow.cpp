#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>

#include <QPixmap>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QTimer>
#include <QMessageBox>
#include <QBrush>   // pour la couleur du surlignage
#include <QColor>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsOpacityEffect *effet = new QGraphicsOpacityEffect(this);
    ui->labelWelcome->setGraphicsEffect(effet);
    QPropertyAnimation *anim = new QPropertyAnimation(effet, "opacity");
    anim->setDuration(3000);
    anim->setStartValue(1.0);
    anim->setEndValue(0.0);
    anim->setEasingCurve(QEasingCurve::InOutQuad);

    QTimer::singleShot(1000, anim, SLOT(start()));
    connect(anim, &QPropertyAnimation::finished, [=]() {
        ui->labelWelcome->hide();
    });
}



MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_candidat_clicked()
{


    ui->tabWidget->setCurrentIndex(2);

}


void MainWindow::on_vehicule_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
}


void MainWindow::on_employee_clicked()
{
    ui->tabWidget->setCurrentIndex(4);
}


void MainWindow::on_seance_clicked()
{
    ui->tabWidget->setCurrentIndex(5);
}


void MainWindow::on_examen_clicked()
{
    ui->tabWidget->setCurrentIndex(6);
}


void MainWindow::on_candidat_2_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}



void MainWindow::on_vehicule_2_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
}


void MainWindow::on_employee_2_clicked()
{
    ui->tabWidget->setCurrentIndex(4);
}


void MainWindow::on_seance_2_clicked()
{
    ui->tabWidget->setCurrentIndex(5);
}


void MainWindow::on_examen_2_clicked()
{
    ui->tabWidget->setCurrentIndex(6);
}


void MainWindow::on_candidat_3_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}


void MainWindow::on_vehicule_3_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
}


void MainWindow::on_employee_3_clicked()
{
    ui->tabWidget->setCurrentIndex(4);
}


void MainWindow::on_seance_3_clicked()
{
    ui->tabWidget->setCurrentIndex(5);
}


void MainWindow::on_examen_3_clicked()
{
    ui->tabWidget->setCurrentIndex(6);
}


void MainWindow::on_candidat_4_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}


void MainWindow::on_vehicule_4_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
}


void MainWindow::on_employee_6_clicked()
{
    ui->tabWidget->setCurrentIndex(4);
}


void MainWindow::on_seance_6_clicked()
{
    ui->tabWidget->setCurrentIndex(5);
}


void MainWindow::on_examen_4_clicked()
{
    ui->tabWidget->setCurrentIndex(6);
}


void MainWindow::on_candidat_5_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}


void MainWindow::on_vehicule_5_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
}


void MainWindow::on_employee_5_clicked()
{
    ui->tabWidget->setCurrentIndex(4);
}


void MainWindow::on_seance_5_clicked()
{
    ui->tabWidget->setCurrentIndex(5);
}


void MainWindow::on_examen_5_clicked()
{
    ui->tabWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_Ajouter_clicked()
{


    QString matricule = ui->matricule->text();
    QString type = ui->comboBox_TypeVehicule->currentText();
    QString etat = ui->radioButton_EnPanne->isChecked() ? "En panne" : "Fonctionnelle";
    QString dispo = ui->comboBox_dipo->currentText();
    QString km = ui->lineEdit_Kilometrage->text();
    QString date = ui->dateEdit_Maintenance->text();
    QString assurance;
    QString Date = ui->date_assurance->text();

    if (ui->radioButton_TousRisque->isChecked())
        assurance = "Tous Risque";
    else if (ui->radioButton_Intermediaire->isChecked())
        assurance = "Intermédiaire";
    else
        assurance = "Responsabilité civile RC";

    bool existe = false;
    for (int i = 0; i < ui->tableWidget_Vehicule->rowCount(); ++i) {
        QTableWidgetItem *item = ui->tableWidget_Vehicule->item(i, 0);
        if (item && item->text() == matricule) {
            existe = true;
            break;
        }
    }

    if (existe) {
        QMessageBox::warning(this, "error 404", "Un vehicule avec ce matricule existe deja ");
        return;
    }

    int row = ui->tableWidget_Vehicule->rowCount();
    ui->tableWidget_Vehicule->insertRow(row);
    ui->tableWidget_Vehicule->setItem(row, 0, new QTableWidgetItem(matricule));
    ui->tableWidget_Vehicule->setItem(row, 1, new QTableWidgetItem(type));
    ui->tableWidget_Vehicule->setItem(row, 2, new QTableWidgetItem(etat));
    ui->tableWidget_Vehicule->setItem(row, 3, new QTableWidgetItem(km));
    ui->tableWidget_Vehicule->setItem(row, 4, new QTableWidgetItem(date));
    ui->tableWidget_Vehicule->setItem(row, 5, new QTableWidgetItem(assurance));
    ui->tableWidget_Vehicule->setItem(row, 6, new QTableWidgetItem(dispo));
    ui->tableWidget_Vehicule->setItem(row, 7, new QTableWidgetItem(Date));

    ui->lineEdit_Kilometrage->clear();
    ui->matricule ->clear();

}


void MainWindow::on_pushButton_supprimer_clicked()
{
    QString matriculeASupprimer = ui->lineEdit_supprimer->text().trimmed();
    bool trouve = false;


    for (int row = 0; row < ui->tableWidget_Vehicule->rowCount(); ++row)
    {
        QTableWidgetItem *item = ui->tableWidget_Vehicule->item(row, 0);

        if (item && item->text() == matriculeASupprimer)
        {
            ui->tableWidget_Vehicule->removeRow(row);
            trouve = true;
            break;
        }
    }
    ui->lineEdit_supprimer->clear();

}



void MainWindow::on_pushButton_54_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}


void MainWindow::on_btnStats_clicked()
{
    int total = ui->tableWidget_Vehicule->rowCount();
    if (total == 0) {
        QMessageBox::information(this, "Statistiques", "🚗 Aucun véhicule trouvé !");
        return;
    }

    int fonctionnelles = 0;
    int enPanne = 0;

    // Supposons que la colonne 'Etat' = colonne 2 (adapt si nécessaire)
    int colEtat = 2;

    for (int i = 0; i < total; ++i) {
        QString etat = ui->tableWidget_Vehicule->item(i, colEtat)->text().trimmed();
        if (etat.compare("Fonctionnelle", Qt::CaseInsensitive) == 0)
            fonctionnelles++;
        else if (etat.compare("En Panne", Qt::CaseInsensitive) == 0)
            enPanne++;
    }

    double pourcentage = (fonctionnelles * 100.0) / total;

    QString message = QString("📊 **Statistiques Véhicules**\n\n""🚗 Total : %1\n""✅ Fonctionnelles : %2\n""❌ En Panne : %3\n""💯 Pourcentage Fonctionnelles : %4%").arg(total).arg(fonctionnelles).arg(enPanne).arg(QString::number(pourcentage, 'f', 1));

    QMessageBox::information(this, "Statistiques", message);
}


void MainWindow::on_pushButton_Rechercher_clicked()
{
    QString searchMatricule = ui->lineEdit_Recherche->text().trimmed();
    bool found = false;
    for (int i = 0; i < ui->tableWidget_Vehicule->rowCount(); ++i)
    {
        QTableWidgetItem *item = ui->tableWidget_Vehicule->item(i, 0);

        if (item)
        {


            if (item->text().compare(searchMatricule, Qt::CaseInsensitive) == 0)
            {
                found = true;

                for (int j = 0; j < ui->tableWidget_Vehicule->columnCount(); ++j)
                {
                    ui->tableWidget_Vehicule->item(i, j)->setBackground(QBrush(QColor("green")));
                }
                ui->tableWidget_Vehicule->scrollToItem(item);

                QTimer::singleShot(20000, [this, i]() {
                    for (int j = 0; j < ui->tableWidget_Vehicule->columnCount(); ++j)
                    {
                        ui->tableWidget_Vehicule->item(i, j)->setBackground(Qt::red);
                    }
                });

                break;
            }
        }
    }

    if (!found)
    {
        QMessageBox::information(this, "error 404", "Aucun véhicule trouvé avec ce matricule !");
    }
    ui->lineEdit_Recherche->clear();
}
