#include "SettingsDialog.h"
#include "ui_SettingsDialog.h"
#include <QFileDialog>
#include <QFile>

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    settings_.beginGroup("SettingsDialog");

    connect (this, &QDialog::accepted, this, &SettingsDialog::saveSettings);
    connect (this, &QDialog::rejected, [this]{setApplicationSetings(applicationSetings_);});
    connect (ui->browseDataBaseBtn, &QToolButton::clicked, this, &SettingsDialog::browseDataBaseFile);
    connect (ui->dataBasePathTxt, &QLineEdit::textChanged, this, &SettingsDialog::validateDataBasePath);

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

void SettingsDialog::browseDataBaseFile()
{
    const QString &fileName = QFileDialog::getSaveFileName(this, tr("Choose database file"), ui->dataBasePathTxt->text());
    if (fileName.isNull()) {
        return;
    }

    ui->dataBasePathTxt->setText(fileName);
}

void SettingsDialog::validateDataBasePath(const QString &fileName) const
{

    ui->dataBasePathTxt->setStyleSheet(QFile::exists(fileName) ?
                                           QString() :
                                       QStringLiteral("color: red"));
}

ApplicationSettings SettingsDialog::applicationSetings() const
{
    return applicationSetings_;
}

void SettingsDialog::setApplicationSetings(const ApplicationSettings &applicationSetings)
{
    applicationSetings_ = applicationSetings;
}
