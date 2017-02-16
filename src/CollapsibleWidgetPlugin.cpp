#include "CollapsibleWidget.h"
#include "CollapsibleWidgetPlugin.h"

#include <QtPlugin>

CollapsibleWidgetPlugin::CollapsibleWidgetPlugin(QObject *parent):
	QObject(parent),
	_initialized(false)
{
}

void CollapsibleWidgetPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
	if (_initialized)
	{
		return;
	}

	_initialized = true;
}

bool CollapsibleWidgetPlugin::isInitialized() const
{
	return _initialized;
}

QWidget* CollapsibleWidgetPlugin::createWidget(QWidget *parent)
{
	return new CollapsibleWidget(parent);
}

QString CollapsibleWidgetPlugin::name() const
{
	return "CollapsibleWidget";
}

QString CollapsibleWidgetPlugin::group() const
{
	return "senseFly";
}

QIcon CollapsibleWidgetPlugin::icon() const
{
	return QIcon();
}

QString CollapsibleWidgetPlugin::toolTip() const
{
	return "A widget with a title and collapsible content.";
}

QString CollapsibleWidgetPlugin::whatsThis() const
{
	return "A custom widget with a title and collapsible content.";
}

bool CollapsibleWidgetPlugin::isContainer() const
{
	return true;
}

QString CollapsibleWidgetPlugin::domXml() const
{
	return "<ui language=\"c++\">\n"
		   " <widget class=\"Collapsible Widget\" name=\"collapsibleWidget\">\n"
		   "  <property name=\"title\">\n"
		   "   <string>Title</string>\n"
		   "  </property>\n"
		   " </widget>\n"
		   "</ui>\n";
}

QString CollapsibleWidgetPlugin::includeFile() const
{
	return "CollapsibleWidget.h";
}
