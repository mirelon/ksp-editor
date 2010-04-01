#ifndef SHOPDIALOG_H
#define SHOPDIALOG_H

#include <QDialog>
#include <QCheckBox>
#include "settings.h"

namespace Ui {
    class ShopDialog;
}

class ShopDialog : public QDialog {
    Q_OBJECT
public:
	ShopDialog(Settings* settings,QWidget *parent = 0);
    ~ShopDialog();

public slots:
	void show();
	void reload();
	void accept();

protected:
    void changeEvent(QEvent *e);
	void checkAvailability();
	void reset();
	QCheckBox* propNameToCheckBox(QString propName);
	QString checkBoxToPropName(QCheckBox* checkBox);

private:
    Ui::ShopDialog *ui;
	Settings* s;
	int credits;
	QMap<QString,QCheckBox*> checkBoxes;
	QMap<QString,int> prices;
};

#endif // SHOPDIALOG_H
