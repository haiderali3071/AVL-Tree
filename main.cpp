//
//  main.cpp
//  AVL Tree
//
//  Created by Haider Ali on 12/6/19.
//  Copyright © 2019 Haider Ali. All rights reserved.
//

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* l_child;
    Node* r_child;
    Node(int data){
        this->data = data;
        this->l_child = nullptr;
        this->r_child = nullptr;
    }
};

class AVLTree{

private:
    Node* root;

    Node* leftToRightShift(Node* x){
        Node* y = x->l_child;
        x->l_child = y->r_child;
        y->r_child = x;
        return y;
    }

    Node* rightToLeftShift(Node* x){
        Node* y = x->r_child;
        x->r_child = y->l_child;
        y->l_child = x;
        return y;
    }

    Node* leftToRightDoubleShift(Node* x){
        x->l_child = rightToLeftShift(x->l_child);
        return leftToRightShift(x);
    }

    Node* rightToleftDoubleShift(Node* x){
        x->r_child = leftToRightShift(x->r_child);
        return rightToLeftShift(x);
    }
    int height(Node *temp) {

           if (temp == nullptr) {
               return 0;
           }
           else{
                int h1 =1+ height(temp->l_child);
                int h2 =1+ height(temp->r_child);
               if (h1>h2) {
                   return (h1);
               }
               else return (h2);
           }
       }

    int difference(Node* x){
        int h1 = height(x->l_child)+1;
        int h2 = height(x->r_child)+1;
        return h1-h2;
    }

    Node* balance(Node *t){
        if (difference(t) > 1) {
            if (difference(t->l_child) > 0) {
                t = leftToRightShift(t);
            }
            else{
                t = leftToRightDoubleShift(t);
            }
        }
        else if (difference(t) < -1) {
            if (difference(t->r_child) < 0) {
                t = rightToLeftShift(t);
            }
            else{
                t = rightToleftDoubleShift(t);
            }
        }
        return t;
    }
    Node* insert(Node* node, int data){
        if (node == nullptr) {
            node = new Node(data);
            return node;
        }
        else if(data<node->data){
            node->l_child = insert(node->l_child, data);
            node = balance(node);
        }
        else {
            node->r_child = insert(node->r_child, data);
            node = balance(node);
        }
        return node;
    }
    void prefix(Node *temp) {
           
           if (temp == nullptr) {
               return;
           }
           else{
               cout<<temp->data<<" ";
               prefix(temp->l_child);
               prefix(temp->r_child);
           }
       }
       
       void infix(Node *temp) {
              
              if (temp == nullptr) {
                  return;
              }
              else{
                  prefix(temp->l_child);
                  cout<<temp->data<<" ";
                  prefix(temp->r_child);
              }
          }
       
       void postfix(Node *temp) {
              
              if (temp == nullptr) {
                  return;
              }
              else{
                  prefix(temp->l_child);
                  prefix(temp->r_child);
                  cout<<temp->data<<" ";
              }
          }
public:
    AVLTree(){
        root = nullptr;
    }
    void insert(int data){
        root = insert(root, data);
    }
    void prefix() {
        prefix(root);
        cout<<endl;
    }
          
    void postfix() {
        postfix(root);
        cout<<endl;
    }
          
    void infix() {
        infix(root);
        cout<<endl;
    }
};
int main(int argc, const char * argv[]) {
    AVLTree *a = new AVLTree();
    a->insert(1);
    a->insert(2);
    a->insert(3);
    a->insert(4);
    a->insert(5);
    a->insert(6);
    a->insert(7);
    a->insert(8);
    a->insert(9);
    a->insert(10);
    a->insert(11);
    a->insert(12);
    a->insert(13);
    a->insert(14);
    a->insert(15);
    a->insert(16);
    a->insert(17);
    a->insert(18);
    a->insert(19);
    a->insert(20);
    a->insert(21);
    a->insert(22);
    a->insert(23);
    a->insert(24);
    a->insert(25);
    a->insert(26);
    a->insert(27);
    a->insert(28);
    a->insert(29);
    a->insert(30);
    a->insert(31);
    a->insert(32);
    a->prefix();
}
