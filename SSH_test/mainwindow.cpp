#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
using std::string;

#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->SSH_Btn, SIGNAL(clicked(bool)),this,SLOT(ssh_connect()));
    connect(ui->Test_btn, SIGNAL(clicked(bool)),this,SLOT(ssh_connect_test()));
    connect(ui->Test1_btn, SIGNAL(clicked(bool)),this,SLOT(test_1()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ssh_connect()
{
    string destination; //putty -ssh -P 22 demo@test.org -pw password
    destination = "Putty.exe -ssh " + (ui->UserName->text()).toStdString() +
                                "@" + (ui->ServerIP->text().toStdString()) +
                                " -P " + (ui->ServerPort->text().toStdString()) +
                                " -pw " + (ui->UserPassword->text().toStdString());
    char *cstr = new char[destination.length() + 1];
    strcpy(cstr, destination.c_str());
    system(cstr);
    delete [] cstr;
}

void MainWindow::ssh_connect_test()
{
    string destination = "putty -ssh -P 22 kairbek@linux-desktop.cc.tut.fi -pw ywKmXqnrtZu22m3sxw";
    char *cstr = new char[destination.length() + 1];
    strcpy(cstr, destination.c_str());
    system(cstr);
    delete [] cstr;
}

//Test 1 (20 small files)

void MainWindow::test_1()
{
    /*
    QString path = "C:\\Program Files (x86)\\PuTTY\\putty.exe";
    QStringList arguments;
    arguments << "+ssh" << ""
              << "+P" << "22"
              << "+" << "kairbek@linux-desktop.cc.tut.fi"
              << "+pw" << "ywKmXqnrtZu22m3sxw";
    */
    QString command = "Putty.exe -ssh " + (ui->UserName->text()) +
                                "@" + (ui->ServerIP->text()) +
                                " -P " + (ui->ServerPort->text()) +
                                " -pw " + (ui->UserPassword->text());
    QProcess process;
    qint64 pid;
    process.startDetached(command);
    pid = process.processId();
    ui->cmd->setText((QString)(int)pid);
}

//Test 2 (1 big file)

//Draw graph

//Show results (ping, latency, avg speed)
