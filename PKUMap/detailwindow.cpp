// detailwindow.cpp
#include "detailwindow.h"

DetailWindow::DetailWindow(const QString &content, QWidget *parent)
    : QDialog(parent) {
    // 设置窗口属性
    setWindowTitle("景点详情");
    setWindowFlags(windowFlags() | Qt::WindowMaximizeButtonHint); // 允许最大化

    // 主布局
    QVBoxLayout *layout = new QVBoxLayout(this);

    // 使用 QTextEdit 显示可滚动文本
    m_textEdit = new QTextEdit(this);
    m_textEdit->setPlainText(content);
    m_textEdit->setReadOnly(true); // 只读模式
    m_textEdit->setWordWrapMode(QTextOption::WordWrap); // 自动换行

    // 添加关闭按钮
    QPushButton *closeButton = new QPushButton("关闭", this);
    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);

    // 布局设置
    layout->addWidget(m_textEdit);
    layout->addWidget(closeButton);

    // 窗口大小设置
    setMinimumSize(400, 300); // 最小大小
    resize(600, 400); // 初始大小
}
