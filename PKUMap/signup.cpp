#include "signup.h"
#include "ui_signup.h"
#include "mainwindow.h"

Signup::Signup(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Signup)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Window);  // 添加标准窗口标题栏
    this->setWindowTitle("Sign up");

    //设置图片
    QPixmap *pix = new QPixmap("://recource_image/tower.jpg");
    QSize sz = ui->label_image->size();
    ui->label_image->setPixmap(pix->scaled(sz));
}

Signup::~Signup()
{
    delete ui;
}


void Signup::on_btn_return_clicked()
{
    MainWindow *w = new MainWindow;
    w->show();
    this->close();
}

void Signup::on_pushButton_clicked()
{
    sqlite_Init();
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_passwd->text();
    QString surepass = ui->lineEdit_surepasswd->text();

    // 判断密码是否一致
    if (password == surepass) {
        QString sql = QString("insert into user(username, password) values('%1', '%2');")
        .arg(username).arg(password);

        QSqlQuery query;
        if (!query.exec(sql)) {
            qDebug() << "insert into error";

            // 自定义失败消息框
            QMessageBox msgBox;
            msgBox.setWindowTitle("注册认证");
            msgBox.setText("注册失败，请重试！");
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setStyleSheet(
                "QMessageBox { background-color: #F0F0F0; }"
                "QLabel { color: #FF0000; font-weight: bold; }"  // 红色错误提示
                "QPushButton { min-width: 80px; }"
                );
            msgBox.exec();
        } else {
            qDebug() << "insert into success";

            // 自定义成功消息框
            QMessageBox msgBox;
            msgBox.setWindowTitle("注册认证");
            msgBox.setText("注册成功！");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setStyleSheet(
                "QMessageBox { background-color: #F0F0F0; }"
                "QLabel { color: #009900; font-weight: bold; }"  // 绿色成功提示
                "QPushButton { min-width: 80px; }"
                );
            msgBox.exec();

            // 跳转到主窗口
            MainWindow *w = new MainWindow;
            w->show();
            this->close();
        }
    } else {
        // 密码不一致提示
        QMessageBox msgBox;
        msgBox.setWindowTitle("注册认证");
        msgBox.setText("两次密码输入不一致！");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet(
            "QMessageBox { background-color: #F0F0F0; }"
            "QLabel { color: #FF8C00; font-weight: bold; }"  // 橙色警告提示
            "QPushButton { min-width: 80px; }"
            );
        msgBox.exec();
    }
}

