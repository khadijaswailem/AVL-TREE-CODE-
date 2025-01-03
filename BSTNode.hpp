#include <iostream>
using namespace std;


#define MAX(X,Y) ((X>Y) ? X : Y)
#define HEIGHT(n) (n == NULL? 0 : n->getHeight())
#define ISLEAF(n) (n->getLeft() == NULL && n->getRight() == NULL? true :false)

/****************************************************************************************/
/*                                 BSTNode Prototype                                    */
/****************************************************************************************/

template <typename ITEM>
class BSTNode
{
protected:
    ITEM item;
    BSTNode <ITEM>* left;
    BSTNode <ITEM>* right;
    BSTNode <ITEM>* parent;
public:
    BSTNode();
    BSTNode(ITEM p_item);
    void setLeft(BSTNode <ITEM>* l);
    void setRight(BSTNode <ITEM>* r);
    void setParent(BSTNode <ITEM>* p);
    BSTNode<ITEM>* getLeft();
    BSTNode<ITEM>* getRight();
    BSTNode<ITEM>* getParent();
    BSTNode<ITEM>* compareAndAdvance(const ITEM& p_item);
    ITEM& getItem();

    ~BSTNode();
};
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*                                 BSTNode Implementation                               */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


template <typename ITEM> BSTNode<ITEM>::BSTNode() { left = right = parent = NULL; }
template <typename ITEM> BSTNode<ITEM>::BSTNode(ITEM p_item) :BSTNode() { item = p_item; }
template <typename ITEM> void BSTNode<ITEM>::setLeft(BSTNode <ITEM>* l) { left = l; }
template <typename ITEM> void BSTNode<ITEM>::setRight(BSTNode <ITEM>* r) { right = r; }
template <typename ITEM> void BSTNode<ITEM>::setParent(BSTNode <ITEM>* p) { parent = p; }
template <typename ITEM> BSTNode<ITEM>* BSTNode<ITEM>::getLeft() { return left; }
template <typename ITEM> BSTNode<ITEM>* BSTNode<ITEM>::getRight() { return right; }
template <typename ITEM> BSTNode<ITEM>* BSTNode<ITEM>::getParent() { return parent; }
template <typename ITEM> BSTNode<ITEM>* BSTNode<ITEM>::compareAndAdvance(const ITEM& p_item)
{
    if (item > p_item)  return left;
    else if (item < p_item)  return right;
    else return this;
}
template <typename ITEM> ITEM& BSTNode<ITEM>::getItem() { return item; }
template <typename ITEM> BSTNode<ITEM>::~BSTNode()
{
    if (left != NULL) delete(left);
    if (right != NULL) delete(right);
}



