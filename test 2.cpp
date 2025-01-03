//TEST 2 WERE TESTING THE WORKING TEST 1 TO FIX THE UPDATEHEIGHTANDEVALBALANCE AND THE INSERT AND 
////REMOVE FUNCTIONS THAT SHOULD AUTOMATICALLY BALANCE THE TREE UPON INSERTION/REMOVAL
//
//
//#include "AVLNode.hpp"
///****************************************************************************************/
///*                                 AVLTree Prototype                                    */
///****************************************************************************************/
//
//
//template <typename ITEM>
//class AVLTree : public BinarySearchTree<AVLNode<ITEM>, ITEM>
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
////CALCULATING HEIGHT
//template <typename ITEM> int AVLTree<ITEM>::calcHeight(AVLNode <ITEM>* n)
//{
//    if (n == NULL) return -1;
//    int lheight = calcHeight(n->getLeft());//gettng height of left subtree till last node
//    int rheight = calcHeight(n->getRight());//getting height of right subtree till last node
//    if (lheight > rheight) {//checking which subtree has higher height
//        return (lheight + 1);
//    }
//    else {
//        return (rheight + 1);//returning that height +1 since if theres no left/right 
//        //meaning its a leaf then in this case only base case will execute and since that returns -1 and leaves are 
//        // always at height zero we will add 1 to the -1 and since the base case will execute 
//        //at the end of either subtracting from height we also add 1 to make the height correct
//    }
//    return 0;
//}
//
////UPDATE & EVALUATE METHOD 
//template <typename ITEM>  AVLNode <ITEM>* AVLTree<ITEM>::updateHeightAndEvaluateBalance(AVLNode <ITEM>* n)
//{
//    int leftHeight; 
//    int rightHeight;
//
//    if (n->getLeft() != NULL) {//storing the height of left subtree if it exists 
//        leftHeight = n->getLeft()->getHeight();
//    }
//    else {
//        leftHeight = -1;//-1 if it doesnt exist meaning might be a leaf
//    }
//    if (n->getRight() != NULL) {//storing height of right subtree if it exists
//        rightHeight = n->getRight()->getHeight(); 
//    }
//    else {
//        rightHeight = -1; //if it doesnt meaning might be a leaf
//    }
//    if (leftHeight > rightHeight) { //pick out of the two heights of the left and right subtree which is bigger and setting the height of current node to that
//        n->setHeight(leftHeight + 1);
//    }
//    else { 
//        n->setHeight(rightHeight + 1);
//    }
//
//    int bf = calcHeight(n->getLeft()) - calcHeight(n->getLeft());
//    if (bf > 1 or bf < -1) {//returning the node with the imbalance
//        return n;
//    }
//    else {
//        return NULL;
//    }
//   
//}
//
////ACTS AS A RIGHT ROTATION 
//template <typename ITEM> void AVLTree<ITEM>::rotateWithLeftChild(AVLNode <ITEM>* p)
//{
//    AVLNode<ITEM>* x = p->getLeft();
//    AVLNode<ITEM>* temp = NULL;
//    x->setRight(p);
//    p->setLeft(temp);
//    p->setParent(x);
//    /*if (x->getRight() != NULL) {
//        p->getRight()->setParent(p);
//    }*/
//    
//    
//}
//
////ACTS AS A LEFT ROTATION 
//template <typename ITEM> void AVLTree<ITEM>::rotateWithRightChild(AVLNode <ITEM>* p)
//{
//    AVLNode<ITEM>* x = p->getRight();
//    AVLNode<ITEM>* temp = NULL;
//    x->setLeft(p);
//    p->setRight(temp);
//    p->setParent(x);
//    /*if (p->getLeft() != NULL) {
//        p->getLeft()->setParent(p);
//    }*/
//    
//}
//
//// ACTS AS A RIGHT ROTATION FOLLOWED BY A LEFT ROTATION 
//template <typename ITEM> void AVLTree<ITEM>::doubleRotateWithLeftChild(AVLNode <ITEM>* p)
//{
//    rotateWithLeftChild(p->getRight());
//    p->setRight(p->getRight()->getParent())
//    return rotateWithRightChild(p);
//}
//
////ACTS AS A LEFT ROTATION FOLLOWED BY A RIGHT ROTATION 
//template <typename ITEM> void AVLTree<ITEM>::doubleRotateWithRightChild(AVLNode <ITEM>* p)
//{
//    rotateWithRightChild(p->getLeft());
//    p->setLeft(p->getLeft()->getParent());
//    return rotateWithLeftChild(p);
//}
//
//
//
////CHECKING BALANCE 
//template <typename ITEM> bool AVLTree<ITEM>::isBalanced(AVLNode <ITEM>* n)
//{
//    if (n == NULL) {//case tree is empty
//        return true;
//    }
//    int lheight = calcHeight(n->getLeft());//getting height of left subtree
//    int rheight = calcHeight(n->getRight());//getting height of right subtree
//    int bf = lheight - rheight;//getting balance factor for root
//    if (bf > 1 or bf < -1) {
//        return false;//if root is unbalanced then tree is automatically unbalanced 
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
//template <typename ITEM> AVLTree<ITEM>::AVLTree() :BinarySearchTree<AVLNode<ITEM>, ITEM>() {}
//
////INSERT METHOD
//template <typename ITEM> AVLNode <ITEM>* AVLTree<ITEM>::insert(const ITEM& item) {
//    this->insert1(item);
//    AVLNode <ITEM>* node= updateHeightAndEvaluateBalance(this->root);//updating the heights 
//    //and storing the return of this function in "node" which is the node with an imbalance
//    if (!isBalanced(this->root)) {//if after insertion tree not balanced 
//        int bf = calcHeight(node->getLeft()) - calcHeight(node->getRight());//calculating bf of node returned by evaluate balance function
//        //(node with an imbalance
//        if (bf > 1 and (calcHeight(node->getLeft()->getLeft())>calcHeight(node->getLeft()->getRight()))) {//meaning that both nodes are on the left,node left left height =0 and node left right height =-1
//             rotateWithLeftChild(node);//passing the node with imbalance to the functions to fix it 
//        }
//        else if (bf<-1 and (calcHeight(node->getRight()->getRight()) > calcHeight(node->getRight()->getLeft()))) {//both nodes are on the right so node right right height =0 and node right left =-1
//             rotateWithRightChild(node);
//        }
//        else if (bf > 1 and (calcHeight(node->getLeft()->getLeft()) < calcHeight(node->getLeft()->getRight()))) {//node left left height =-1 node left right height =0
//             doubleRotateWithRightChild(node);
//        }
//        else {
//             doubleRotateWithLeftChild(node);
//            
//        }
//        return node;
//    }
//    else {
//        return NULL;//if insert successfully
//    }
//    
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
//        AVLNode <ITEM>* node= updateHeightAndEvaluateBalance(this->root);//updating the heights 
//    //and storing the return of this function in "node" which is the node with an imbalance
//    if (!isBalanced(this->root)) {//if after insertion tree not balanced 
//        int bf = calcHeight(node->getLeft()) - calcHeight(node->getRight());//calculating bf of node returned by evaluate balance function
//        //(node with an imbalance
//        if (bf > 1 and (calcHeight(node->getLeft()->getLeft())>calcHeight(node->getLeft()->getRight()))) {//meaning that both nodes are on the left,node left left height =0 and node left right height =-1
//             rotateWithLeftChild(node);//passing the node with imbalance to the functions to fix it 
//        }
//        else if (bf<-1 and (calcHeight(node->getRight()->getRight()) > calcHeight(node->getRight()->getLeft()))) {//both nodes are on the right so node right right height =0 and node right left =-1
//             rotateWithRightChild(node);
//        }
//        else if (bf > 1 and (calcHeight(node->getLeft()->getLeft()) < calcHeight(node->getLeft()->getRight()))) {//node left left height =-1 node left right height =0
//             doubleRotateWithRightChild(node);
//        }
//        else {
//             doubleRotateWithLeftChild(node);
//            
//        }
//        return node;
//    }
//    else {
//        return NULL;//if insert successfully
//    }
//
//}
//
//
//
////TRAVERSE METHOD MADE IT ASC BY DEFAULT 
//template <typename ITEM> void AVLTree<ITEM>::traverse(AVLNode <ITEM>* n, int depth) {
//    this->traverseASC();
//
//}
//
//
////DESTRUCTOR
//template <typename ITEM> AVLTree<ITEM>::~AVLTree() {}
//
//
////TESTING THE CODE
//int main() {
//    AVLTree<int> t;
//    //***TESTING THE ISBALANCED WITH ONLY ONE NODE IN TREE CASE***//
//    //t.insert(6);
//    //cout << "isbalanced: " << t.isBalanced() << endl;//1 BCS ITS BALANCED
//    //t.traverse();
//    //cout << "height of tree:" << t.calcHeight() << endl;//0 BCS LEAVES ALWAYS AT HEIGHT 0
//
//    //***TESTING THE ISBALANCED WITH AN IMBALANCED CASE***//
//    t.insert(1);
//    t.insert(3);
//    t.insert(2);
//    //t.insert(3);
//    cout << "isbalanced: " << t.isBalanced() << endl;//0 BCS ITS IMBALANCED 
//    t.traverse();
//    cout << "height of tree:" << t.calcHeight() << endl;//3 (BASE 0)
//
////    ////TESTING THE REMOVE FUNCTION WITH LEAF NODE 
////    //cout << "**REMOVING LEAF NODE 8**" << endl;
////    //t.remove(8);
////    //cout << "isbalanced: " << t.isBalanced() << endl;//1 BCS NOW ITS BALANCED 
////    //t.traverse();
////    //cout << "height of tree:" << t.calcHeight() << endl;//2 (BASE 0)
////
////    ////TESTING THE REMOVE FUNCTION WITH INTERNAL NODE (3)
////    //cout << "**REMOVING INTERNAL NODE 3**" << endl;
////    //t.remove(3);
////    //cout << "isbalanced: " << t.isBalanced() << endl;//1 BCS STILL BALANCED 
////    //t.traverse();
////    //cout << "height of tree:" << t.calcHeight() << endl;//2 (BASE 0)
////
////    ////TESTING THE REMOVE FUNCTION WITH ROOT NODE (3)
////    //cout << "**REMOVING ROOT NODE 6**" << endl;
////    //t.remove(6);
////    //cout << "isbalanced: " << t.isBalanced() << endl;//1 BCS STILL BALANCED 
////    //t.traverse();
////    //cout << "height of tree:" << t.calcHeight() << endl;//2 (BASE 0)
////
////
////
////    //***TESTING THE ISBALANCED WITH A BALANCED CASE***//
////    //t.insert(2);
////    //t.insert(1);
////    //t.insert(3);
////    //cout << "isbalanced: " << t.isBalanced() << endl;//1 BCS ITS BALANCED 
////    //t.traverse();
////    //cout<<"height of tree:"<<t.calcHeight()<<endl;//1 (BASE 0)
////
////   
////
////
//}
