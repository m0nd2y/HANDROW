#include "exit.h"
#include <QVBoxLayout>
#include "D:/Qt Project/LIBRARY/Material/components/qtmaterialdialog.h"

#pragma comment(lib, "D:/Qt Project/LIBRARY/Material/components/release/components.lib")

Exit::Exit(QWidget *parent)
	: QWidget(parent),
	m_exitButton(new QtMaterialFlatButton)
{
	QVBoxLayout *layout = new QVBoxLayout();
	this->setLayout(layout);

	layout->addWidget(m_exitButton);
	layout->setAlignment(m_exitButton, Qt::AlignCenter | Qt::AlignBottom);

	m_exitButton->setText(tr("Exit"));
	m_exitButton->setMinimumWidth(150);
	m_exitButton->setMaximumWidth(150);
	m_exitButton->setRole(Material::Secondary);
	m_exitButton->setRippleStyle(Material::PositionedRipple);
	m_exitButton->setOverlayStyle(Material::TintedOverlay);

	//QtMaterialDialog *dialog = new QtMaterialDialog(this);
	//dialog->setParent(parent);
	//dialog->setMaximumSize(500, 500);
	//layout->addWidget(dialog);
	connect(m_exitButton, SIGNAL(clicked()), parent, SLOT(close()));
	//connect(m_exitButton, SIGNAL(pressed()), dialog, SLOT(showDialog()));
}


Exit::~Exit()
{
}
