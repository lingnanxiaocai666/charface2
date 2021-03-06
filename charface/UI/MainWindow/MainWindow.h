#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSharedPointer>

#include "UI/MainWindow/DocumentListView/DocumentListView.h"
#include "cfplugininterface.h"
#include "Models/PageZoneModel.h"

class DocumentModel;
class PageGraphicsScene;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    explicit MainWindow(DocumentModel *document, QWidget *parent = 0);
    ~MainWindow();

    void show();

    PageGraphicsScene *pageView() { return mPageView; }

private slots:
    void onPlugins();
    void onLoadDir();
    void onLoadFile();
    bool onBatchNew();
    bool onBatchOpen();
    bool onBatchSaveAs();
    void onEditImage(bool down);

    void updateUI();
    void updatePluginDepent();
    void updatePagesListWidget();

    void onPluginImportAction();
    void onPluginAction();
    void onPluginEditImageChanged(int index);

    void onPageListSelectionChanged(int index);
    void onPageViewChangedPage();

    void onZoom();
    void onSelectTypeChanged();
    void onMouseModeChanged();

    void onPageListDelete();
    void onPageListMove();

    void onRead();
    void onReadAll();

    void onAnalyze();
    void onAnalyzeAll();

private:
    void initialize();
    void updateToolbar();
    void updateImageEditPluginsStackWidget();
    void updateSelectType(ZoneType zoneType);
    void updateStatusBar();

    //
    void addBatchActions();
    void addImportActions();
    void addEditImageActions();
    void addAnalyzeActions();
    void addReadActions();
    void addExportActions();
    void addPuginsActions();
    void setupStatusBar();

    void setupDropDownPluginsMenu(PluginType pluginType, QMenu *menu);

    //
    void execPluginActionImport(CFPluginInterface *plugin);

    //
    bool askToSaveBatchIsOk();

    //
    void showPluginsDialog();

    //
    Ui::MainWindow *ui;

    //
    QSharedPointer<DocumentModel> mDocument;

    //
    void setPageScale(qreal scale);
    PageGraphicsScene *mPageView;

    //
    DocumentListView *mItemsListView;

    //
    QLabel *mLabelBatchInfo;
    QLabel *mLabelPageInfo;

    //toobar buttons
    QAction *defaultReadAction;
    QMenu *menuAnalyze;

    QAction *defaultAnalyzeAction;
    QMenu *menuRead;
};

#endif // MAINWINDOW_H
