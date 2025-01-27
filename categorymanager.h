#ifndef CATEGORYMANAGER_H
#define CATEGORYMANAGER_H

#include <QVector>
#include <QString>
#include <QSqlDatabase>

struct Category {
    int categoryId;
    QString name;
    int parentId;
    int position;
    int depth;
    int projectId;
};

class CategoryManager {
public:
    CategoryManager(QSqlDatabase &db);

    bool createCategory(const QString &name, int parentId, int projectId);
    bool updateCategory(int categoryId, const QString &newName);
    bool deleteCategory(int categoryId, bool deleteAll);

    QVector<Category> getCategoriesByProject(int projectId) const;  // Получение списка категорий

private:
    QSqlDatabase &db;
};

#endif // CATEGORYMANAGER_H
