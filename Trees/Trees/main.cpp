#include <stdlib.h>

#include <QDebug>

#include "BinaryTree.h"

int main(int /*argc*/, char */*argv*/[])
{
    qDebug() << rand() % 9 + 1;
    BinaryTree tree;
    for (int i = 0; i < 20; ++i) {
        tree.addNode(rand() % 100);
    }
    tree.printHorizontal();
    return 0;
}