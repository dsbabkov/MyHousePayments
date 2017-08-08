#include "SettingsDialog.h"
#include "ui_SettingsDialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    settings_.beginGroup("SettingsDialog");

    connect (this, &QDialog::accepted, this, &SettingsDialog::saveSettings);

    loadSettings();
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void SettingsDialog::loadSettings()
{
    ui->dataBasePathTxt->setText(settings_.value("dataBasePath").toString());
}

void SettingsDialog::saveSettings()
{
    settings_.setValue("dataBasePath", ui->dataBasePathTxt->text());
}

ApplicationSettings SettingsDialog::applicationSetings() const
{
    return applicationSetings_;
}

void SettingsDialog::setApplicationSetings(const ApplicationSettings &applicationSetings)
{
    applicationSetings_ = applicationSetings;
}
