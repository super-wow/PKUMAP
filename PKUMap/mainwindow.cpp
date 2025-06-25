#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signup.h"
#include "map.h"
#include <QGraphicsDropShadowEffect>

void sqlite_Init()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user.db");
    if(!db.open())
    {
        qDebug()<<"open error";
    }
    //create excle
    QString createsql=QString("create table if not exists user(id integer primary key autoincrement,"
                                "username ntext unique not NULL,"
                                "password ntext not NULL)");
    QSqlQuery query;
    if(!query.exec(createsql)){
        qDebug()<<"table create error";
    }
    else{
        qDebug()<<"table create success";
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Sign in");

    //设置图片
    QPixmap *pix = new QPixmap("://recource_image/west.jpg");
    QSize sz = ui->label_image->size();
    ui->label_image->setPixmap(pix->scaled(sz));

    //设置图片阴影效果
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(-3, 0);
    shadow->setColor(QColor(255, 0, 0));
    shadow->setBlurRadius(30);
    ui->label_image->setGraphicsEffect(shadow);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_btn_signin_clicked()
{
    sqlite_Init();
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QString sql=QString("select * from user where username='%1' and password='%2'")
                      .arg(username).arg(password);
    //创建执行语句对象
    QSqlQuery query(sql);
    //判断执行结果
    if(!query.next())
    {
        qDebug()<<"Login error";
        //QMessageBox::information(this,"登录认证","登录失败,账户或者密码错误");
        // 自定义失败消息框样式
        QMessageBox msgBox;
        msgBox.setWindowTitle("登录认证");
        msgBox.setText("登录失败，账户或密码错误");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet(
            "QMessageBox { background-color: #F0F0F0; }"
            "QLabel { color: #FF0000; font-weight: bold; }"  // 红色文字 + 加粗
            "QPushButton { min-width: 80px; }"
            );
        msgBox.exec();
    }
    else
    {
        qDebug()<<"Login success";
        //QMessageBox::information(this,"登录认证","登录成功");
        // 自定义成功消息框样式
        QMessageBox msgBox;
        msgBox.setWindowTitle("登录认证");
        msgBox.setText("登录成功");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setStyleSheet(
            "QMessageBox { background-color: #F0F0F0; }"
            "QLabel { color: #009900; font-weight: bold; }"  // 绿色文字 + 加粗
            "QPushButton { min-width: 80px; }"
            );
        msgBox.exec();

        //登录成功后可以跳转到其他页面
        Map *mapWindow = new Map();
        mapWindow->show();
        this->close();
    }
}


void MainWindow::on_btn_signup_clicked()
{
    this->close();
    Signup *s = new Signup;
    s->show();
}

