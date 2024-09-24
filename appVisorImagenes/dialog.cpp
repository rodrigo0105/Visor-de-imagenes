#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent) , ui(new Ui::Dialog) {
    ui->setupUi(this);
}

Dialog::~Dialog() {

    delete ui;

    ui -> setupUi(this);

    //UNIX`LIKE


    QImage imagen ("C:\\Users\aguil\\OneDrive\\Imágenes\\imagenes");

    ui->label->setPixmap(QPixmap::fromImage(imagen));
    ui->label->setScaledContents(true);

}

void Dialog::on_pushButton_clicked() {

    QFileDialog dialogo (this);

    dialogo.setNameFilter("Imagenes(.png.jpg.jpeg.bmp)");  //tipos de archivos, archivos tipo...
    dialogo.setViewMode(QFileDialog::Detail); //Como se visualiza

    QString nomarch = QFileDialog::getOpenFileName(this,
                                                   "Abrir imágenes",
                                                   "C:\\Users\\aguil\\OneDrive\\Imágenes\\imagenes"
                                                   "Archivos IMGS(¨.png.jpg.jpeg.bmp)");

    if(!nomarch.isEmpty()){
        QImage imagen(nomarch);
        ui->label->setPixmap(QPixmap::fromImage(imagen));
        ui->label->setScaledContents(true);
    }

}


















