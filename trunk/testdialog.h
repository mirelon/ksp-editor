#ifndef TESTDIALOG_H
#define TESTDIALOG_H

#include <QDialog>
#include <QDebug>
#include <vector>
#include <string>
#include "testovac/testovac.h"
#include "settings.h"

namespace Ui {
    class TestDialog;
}

class TestDialog : public QDialog {
    Q_OBJECT
public:
	TestDialog(Settings* settings, QWidget *parent = 0);
    ~TestDialog();

	QString program;
	std::vector<std::string> fromQStringList(QStringList s);
	QStringList toQStringList(std::vector<std::string> s);

public slots:
	void show();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::TestDialog *ui;
	Settings* s;
	CompileSettings compile_settings;
	TestSettings test_settings;


private slots:
	void on_pushButton_clicked();
};

#endif // TESTDIALOG_H