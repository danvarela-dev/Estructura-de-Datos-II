#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QLabel>
#include <QDialog>
#include <QFileDialog>
#include <fstream>
#include <string>
#include "JlCompress.h"

using namespace std;


DrawnWindow::DrawnWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString sPath  ="C:/";

//    dir = new QFileSystemModel(this);
//    dir->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
//    dir->setRootPath(sPath);

//    ui->treeView_2->setModel(dir);

//    file = new QFileSystemModel(this);
//    file->setFilter(QDir::NoDotAndDotDot | QDir::Files );
//    file->setRootPath(sPath);

//    ui->listView->setModel(file);
}

DrawnWindow::~DrawnWindow()
{
    delete ui;
}

void DrawnWindow::on_pushButton_3_clicked()
{
    filename = QFileDialog::getOpenFileName(this, tr("Browser"), "C://","All files(*.*);;Zip Files (*.zip)");


    zFile.openZip(filename.toStdString().c_str());


}

void DrawnWindow::on_treeView_2_clicked(const QModelIndex &index)
{
      QString sPath = dir->fileInfo(index).absolutePath();
      ui->listView->setRootIndex(file->setRootPath(sPath));
}

void DrawnWindow::DecompressDir(QString zipFile, QString Directory){

    QStringList list= JlCompress::extractDir(zipFile, Directory);


    modelUn = new QFileSystemModel(this);

    ui->treeView_2->setModel(modelUn);
    ui->treeView_2->setRootIndex(modelUn->setRootPath(Directory));



    QMessageBox::information(this, tr("Success"), tr("FILE UNCOMPRESSED SUCCESFULLY"));

}


void DrawnWindow::on_pushButton_2_clicked()
{

   model = new QStringListModel(this);

    QStringList List;

    int num1 = (int)zFile.CD_signature[2];
    int num2 = (int)zFile.CD_signature[3];


    QString nums= QString::number(num1)  +QString::number(num2);

    ui->label->setText("CENTRAL HEADER DIRECTORY");
    ui->label->show();

    zFile.CD_signature[2] = '\0';
    QString sig = QString::fromStdString("Signature: ") + zFile.CD_signature + nums;
    QString verMade = QString::fromStdString("Version Made: ") + QString::number(zFile.CD_versionMade);
    QString verNeed = QString::fromStdString("Version Needed: ") + QString::number(zFile.CD_versionNeeded);
    QString bit =QString::fromStdString("BitFlag: ") + QString::number(zFile.CD_bitFlag);
    QString compression =QString::fromStdString("Compression: ") + QString::number(zFile.CD_compression);
    QString time  =QString::fromStdString("Last Mod Time: ") + QString::number(zFile.CD_lastMod_Time);
    QString date  =QString::fromStdString("Last Mod Date: ") + QString::number(zFile.CD_lastMod_Date);
    QString compressedSz  =QString::fromStdString("Compressed Size: ") + QString::number(zFile.CD_compressed_size);
    QString uncompressedSz  =QString::fromStdString("Uncompressed Size: ") + QString::number(zFile.CD_uncompressed_size);
    zFile.filename[zFile.CD_fileName_Length] = '\0';
    QString fileName_Length = QString::fromStdString("Filename Length: ") + QString::number(zFile.CD_fileName_Length);
    QString extrafield_Length = QString::fromStdString("Extra Field Length: ") + QString::number(zFile.CD_extraField_Length);
    QString fileCommentLen = QString::fromStdString("File Comment Length: ")+ QString::number(zFile.CD_fileComment_Length);
    QString diskSt = QString::fromStdString("Disk Start") + QString::number(zFile.CD_diskStart);
    QString internalAttr = QString::fromStdString("Internal File Attributes: ") + QString::number(zFile.CD_interalFileAttributes);
    QString externalAttr = QString::fromStdString("External File Attributes: ") + QString::number(zFile.CD_externalFileAttributes);
    QString offset = QString::fromStdString("Offset Local File Header: ") + QString::number(zFile.CD_offsetLocalFileHeader);

    zFile.filename[zFile.fileName_Length] = '\0';

    zFile.extraField[zFile.extraField_Length] = '\0';


    QString fileName = QString::fromStdString("Filename: ") + zFile.filename;
    QString extrafield = QString::fromStdString("Extra Field: ") + zFile.extraField;


    List << sig  <<" "<<verMade<<" " << verNeed <<" "<<bit<<" " <<compression<<" " << time<<" " << date <<" "<< compressedSz <<" "<< uncompressedSz<<" " << fileName_Length<<" "
         << extrafield_Length <<" "<< fileCommentLen<< " " << diskSt << " " << internalAttr << " " << externalAttr << " " << offset << " "<< fileName<<" " << extrafield;

    model->setStringList(List);

    ui->listView_2->setModel(model);

    ui->listView_2->setEditTriggers(QAbstractItemView::AnyKeyPressed | QAbstractItemView::DoubleClicked);

    
}



void DrawnWindow::on_pushButton_clicked()
{
    size_t lastPos = filename.toStdString().find_last_of(".");
    string nameNoExt = filename.toStdString().substr(0, lastPos);

    DecompressDir(filename, QString::fromStdString(nameNoExt));


}
