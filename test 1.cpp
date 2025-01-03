//#include "AVLNode.hpp"
///****************************************************************************************/
///*                                 AVLTree Prototype                                    */
///****************************************************************************************/
//
//
//template <typename ITEM>
//class AVLTree : public BinarySearchTree<AVLNode<ITEM>,ITEM>
//{
//private:
//    AVLNode <ITEM>* updateHeightAndEvaluateBalance(AVLNode <ITEM>* n);
//    void rotateWithLeftChild(AVLNode <ITEM>* p);
//    void rotateWithRightChild(AVLNode <ITEM>* p);
//    void doubleRotateWithLeftChild(AVLNode <ITEM>* p);
//    void doubleRotateWithRightChild(AVLNode <ITEM>* p);
//    int calcHeight(AVLNode <ITEM>* n);
//    bool isBalanced(AVLNode <ITEM>* n);
//public:
//    AVLTree();
//    AVLNode <ITEM>* insert(const ITEM& item);
//    int calcHeight();  // This is needed for the isBalanaced
//    bool remove(const ITEM& item);
//    void traverse(AVLNode <ITEM>* n = NULL, int depth = 0);
//    bool isBalanced();
//    ~AVLTree();
//};
//
///*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
///*                               AVLTree Implementation                                 */
///*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//
//
////UPDATE & EVALUATE METHOD 
//template <typename ITEM>  AVLNode <ITEM>* AVLTree<ITEM>::updateHeightAndEvaluateBalance(AVLNode <ITEM>* n)
//{
//    n->setHeight(calcHeight(n)+1);//updating height
//    int bf = calcHeight(n->getLeft()) - calcHeight(n->getLeft());
//    if (bf > 1 or bf < -1) {//evaluating
//        cout << "Evaluating balance: not balanced" << endl;
//        return n;
//    }
//    else {
//        cout << "Evaluating balance: balanced" << endl;
//    }
//    return NULL;
//}
//
////LL RL
//template <typename ITEM> void AVLTree<ITEM>::rotateWithLeftChild(AVLNode <ITEM>* p)
//{
//    AVLNode<ITEM>* x = p->getLeft();
//    AVLNode<ITEM>* temp = x->getRight();
//    x->setRight(p);
//    p->setLeft(temp);
//    
//}
//
////RR LR
//template <typename ITEM> void AVLTree<ITEM>::rotateWithRightChild(AVLNode <ITEM>* p)
//{
//    AVLNode<ITEM>* x = p->getLeft();
//    AVLNode<ITEM>* temp = x->getRight();
//    x->setLeft(p);
//    p->setRight(temp);
//    
//}   
//
////LRLR RL
//template <typename ITEM> void AVLTree<ITEM>::doubleRotateWithLeftChild(AVLNode <ITEM>* p)
//{
//    p->setLeft(rotateWithLeftChild(p->getLeft())) ;
//     rotateWithRightChild(p);
//}
//
////RLRL LR
//template <typename ITEM> void AVLTree<ITEM>::doubleRotateWithRightChild(AVLNode <ITEM>* p)
//{
//    p->setRight(rotateWithRightChild(p->getRight()));
//    rotateWithLeftChild(p)
//}
//
////CALCULATING HEIGHT
//template <typename ITEM> int AVLTree<ITEM>::calcHeight(AVLNode <ITEM>* n)
//{
//    if (n == NULL) return -1;
//    int lheight = calcHeight(n->getLeft());
//    int rheight = calcHeight(n->getRight());
//    if (lheight > rheight){
//        return (lheight + 1);
//    }
//    else {
//        return (rheight + 1);
//    }
//    return 0;
//}
//
////CHECKING BALANCE 
//template <typename ITEM> bool AVLTree<ITEM>::isBalanced(AVLNode <ITEM>* n)
//{
//    if (n == NULL) {
//        return true;
//    }
//    int lheight = calcHeight(n->getLeft());
//    int rheight = calcHeight(n->getRight());
//    int bf = lheight - rheight;//getting balance factor 
//    if (bf > 1 or bf < -1) {
//        return false;
//    }
//
//    bool ltreecheck = isBalanced(n->getLeft());
//    bool rtreecheck = isBalanced(n->getRight());
//
//    if (ltreecheck == false or rtreecheck == false) {
//        return false;
//    }
//    return true;
//}
//
////CONSTRUCTOR 
//template <typename ITEM> AVLTree<ITEM>::AVLTree() :BinarySearchTree<AVLNode<ITEM>,ITEM>() {}
//
////INSERT METHOD
//template <typename ITEM> AVLNode <ITEM>* AVLTree<ITEM>::insert(const ITEM& item) {
//    this->insert1(item);
//    return NULL;
//}
//
//
////HEIGHT OF TREE
//template <typename ITEM> int AVLTree<ITEM>::calcHeight()
//{
//    return calcHeight(this->root);
//}
//
////IF TREE IS BALANCED 
//template <typename ITEM> bool AVLTree<ITEM>::isBalanced()
//{
//    return isBalanced(this->root);
//}
//
//
////REMOVE METHOD 
//template <typename ITEM> bool AVLTree<ITEM>::remove(const ITEM& item) {
//    if (this->contains(item) == true) {//checking if item we want to remove is in the tree
//        this->remove1(item);//called this method from parent class we inherited from
//        return true;
//    }
//    else {
//        return false;
//    }
//    
//}
//
//
//
////TRAVERSE METHOD MADE IT ASC BY DEFAULT 
//template <typename ITEM> void AVLTree<ITEM>::traverse(AVLNode <ITEM>* n , int depth ) {
//    this->traverseASC();
//
//}
//
//
////DESTRUCTOR
//template <typename ITEM> AVLTree<ITEM>::~AVLTree() {}
//
//
////TESTINT THE CODE
//int main() {
//    AVLTree<int> t;
//    //***TESTING THE ISBALANCED WITH ONLY ONE NODE IN TREE CASE***//
//    //t.insert(6);
//    //cout << "isbalanced: " << t.isBalanced() << endl;//1 BCS ITS BALANCED
//    //t.traverse();
//    //cout << "height of tree:" << t.calcHeight() << endl;//0 BCS LEAVES ALWAYS AT HEIGHT 0
//
//
//    //***TESTING THE ISBALANCED WITH AN IMBALANCED CASE***//
//    t.insert(6);
//    t.insert(3);
//    t.insert(4);
//    t.insert(2);
//    t.insert(7);
//    t.insert(9);
//    t.insert(8);
//    cout << "isbalanced: " << t.isBalanced() << endl;//0 BCS ITS IMBALANCED 
//    t.traverse();
//    cout<<"height of tree:"<<t.calcHeight()<<endl;//3 (BASE 0)
//
//    //TESTING THE REMOVE FUNCTION WITH LEAF NODE 
//    cout << "**REMOVING LEAF NODE 8**" << endl;
//    t.remove(8);
//    cout << "isbalanced: " << t.isBalanced() << endl;//1 BCS NOW ITS BALANCED 
//    t.traverse();
//    cout << "height of tree:" << t.calcHeight() << endl;//2 (BASE 0)
//
//    //TESTING THE REMOVE FUNCTION WITH INTERNAL NODE (3)
//    cout << "**REMOVING INTERNAL NODE 3**" << endl;
//    t.remove(3);
//    cout << "isbalanced: " << t.isBalanced() << endl;//1 BCS STILL BALANCED 
//    t.traverse();
//    cout << "height of tree:" << t.calcHeight() << endl;//2 (BASE 0)
//
//    //TESTING THE REMOVE FUNCTION WITH ROOT NODE (3)
//    cout << "**REMOVING ROOT NODE 6**" << endl;
//    t.remove(6);
//    cout << "isbalanced: " << t.isBalanced() << endl;//1 BCS STILL BALANCED 
//    t.traverse();
//    cout << "height of tree:" << t.calcHeight() << endl;//2 (BASE 0)
//
//
//
//    //***TESTING THE ISBALANCED WITH A BALANCED CASE***//
//    //t.insert(2);
//    //t.insert(1);
//    //t.insert(3);
//    //cout << "isbalanced: " << t.isBalanced() << endl;//1 BCS ITS BALANCED 
//    //t.traverse();
//    //cout<<"height of tree:"<<t.calcHeight()<<endl;//1 (BASE 0)
//    
//    /* AVLTree <int> avlTree;
//srand(time(NULL));
//for (int i = 0; i < 1000000; i++)
//    avlTree.insert(rand());
//cout << "Printing " << endl;
//avlTree.traverseDESC();
//cout << "Checking Balance ....." << endl;
//cout << "Balanaced? " << avlTree.isBalanced() << endl;
//return 0;*/
//   
//
//    
//}
