#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->plainTextEdit);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    ui->plainTextEdit->clear();
    ui->statusBar->showMessage("");
    m_filename.clear();
}


void MainWindow::on_actionOpen_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, "open file");
    QFile file(path);


    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::critical(this, "err", file.errorString());
        return;
    }
    QTextStream stream(&file);
    ui->plainTextEdit->setPlainText(stream.readAll());
    file.close();

    ui->statusBar->showMessage(path);
    m_filename = path;
}


void MainWindow::on_actionSave_triggered()
{
    QString path = QFileDialog::getSaveFileName(this, "save file");
    QFile file(path);


    if(!file.open(QIODevice::WriteOnly)){
        QMessageBox::critical(this, "err", file.errorString());
        return;
    }
    QTextStream stream(&file);
    stream << ui->plainTextEdit->toPlainText();
    file.close();

    ui->statusBar->showMessage(path);
    m_filename = path;
}


void MainWindow::on_actionCut_triggered()
{
     ui->plainTextEdit->cut();
}


void MainWindow::on_actionSelectAll_triggered()
{
     ui->plainTextEdit->selectAll();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->plainTextEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
     ui->plainTextEdit->paste();
}

