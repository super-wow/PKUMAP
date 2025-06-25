#ifndef DETAILWINDOW_H
#define DETAILWINDOW_H
#pragma once
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

#include <QDialog>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>

class DetailWindow : public QDialog {
    Q_OBJECT
public:
    explicit DetailWindow(const QString &content, QWidget *parent = nullptr);

private:
    QTextEdit *m_textEdit;
};

#endif // DETAILWINDOW_H
