#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QFileSystemModel>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <Zip.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class DrawnWindow : public QMainWindow
{
    Q_OBJECT

public:

    DrawnWindow(QWidget *parent = nullptr);
    ~DrawnWindow();

private slots:

    void on_pushButton_3_clicked();

    void on_treeView_2_clicked(const QModelIndex &index);



    void on_pushButton_2_clicked();
    void DecompressDir(QString ZipFile, QString Directory);


    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QStringListModel *model;
    QStringListModel *model_2;

    QString filename;
    QString path;
    ZIP zFile;
    QFileSystemModel *modelUn;
    QFileSystemModel * dir;
    QFileSystemModel * file;
};
#endif // MAINWINDOW_H
