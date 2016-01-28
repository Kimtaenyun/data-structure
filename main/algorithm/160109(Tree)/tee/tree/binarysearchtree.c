#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"
#include "binarysearchtree.h"

// 이진 탐색 트리의 생성 및 초기화
void BSTMakeAndInit(BTreeNode ** pRoot){
    pRoot = (BTreeNode**)malloc(sizeof(BTreeNode*));
    (*pRoot) = NULL;
}

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode * bst){
    return bst->data;
}

// 이진 탐색 트리를 대상으로 데이터 저장(노드의 생성과정 포함)
void BSTInsert(BTreeNode ** pRoot, BSTData data){

    BTreeNode* *p = *pRoot;

    if(*pRoot == NULL){
        *pRoot =  MakeBTreeNode();
        (*pRoot)->data = data;
        (*pRoot)->left = NULL;
        (*pRoot)->right = NULL;
        return;
    }

    if((*pRoot)->data < data){
        BSTInsert(&(*pRoot)->right, data);
    }else{
        BSTInsert(&(*pRoot)->left, data);
    }

}

// 이진 탐색 트리를 대상으로 데이터 탐색
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target){
    if(bst->data == target){
        return bst;
    }else if(bst->data == NULL){
        return NULL;
    }

    if(bst->data < target){
        return BSTSearch(bst->left, target);
    }else{
        return BSTSearch(bst->right, target);
    }
}
