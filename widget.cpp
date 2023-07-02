#include "widget.h"
#include "./ui_widget.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,"filePath","choose file");
    if (!filePath.isEmpty()) {
        ui->source->setText(filePath);
    }
}


void Widget::on_pushButton_2_clicked()
{
    QFile file(sourcePath);
    if (!file.exists()) {
        QMessageBox::information(this, "error", "file does not exist");
        return;
    }
    file.open(QIODevice::ReadOnly);
    if (!file.isOpen()) {
        QMessageBox::information(this, "error" , "file open file");
        return;
    }
    QFile fileToWrite(ui->dest->text());
    fileToWrite.open(QIODevice::WriteOnly);
    if(!file.isOpen()) {

    }
    QByteArray arrHead = file.read(1);
    int bitIdx = arrHead[0]  & 0x07;
    int byteInterval = int(((arrHead[0] & 0x38) >> 3) + 2);

    file.seek(0);
    while (!file.atEnd()) {
        QByteArray arr = file.read(300);

    }

}

