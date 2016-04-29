#include "Binary_tree.h"
#include <iostream>
#include "Element.h"

using namespace std;

// Constructor creates root, sets root color as black
Binary_tree::Binary_tree()
{
    Element* n_element = new Element;
    root=n_element;
    root->color = 'b';
    cout<<"Set ROOT value: ";
    cin>>root->value;
}

void Binary_tree::add(int value){
    Element* new_element = new Element;
    new_element->set_value(value);
    Element* pointer = root;
    while(pointer!=NULL){
        if(new_element->value < pointer->value){
                if(pointer->left!=NULL){
                    pointer = pointer->left;
                }
                else{
                    new_element->parent = pointer;
                    pointer->left = new_element;
                    break;
                }
        }
        else if(new_element->value > pointer->value){
                if(pointer->right!=NULL){
                    pointer = pointer->right;
                }
                else{
                    new_element->parent = pointer;
                    pointer->right = new_element;
                    break;
                }
        }
    }
}

void Binary_tree::find(Element* target){

}

void Binary_tree::moving_pre_order(Element* start_element){
    cout<<start_element->value<<endl;
    if(start_element->left!=NULL){
        moving_pre_order(start_element->left);
    }
    if(start_element->right!=NULL){
        moving_pre_order(start_element->right);
    }
}

void Binary_tree::show_tree(){
    moving_pre_order(root);
}

void Binary_tree::check_black_red_properties1(Element* just_added){
    if(just_added->parent->color=='r'){
            //Pierwszy przypadek z odbiciem lustranym
            if(just_added->parent->parent->left==just_added->parent){
                if(just_added->parent->parent->right->color=='r'){
                    if(just_added->parent->parent!=root){
                        just_added->parent->parent->color='r';
                    }
                    just_added->parent->parent->right->color='b';
                    just_added->parent->color='b';
                }
            }
            else if(just_added->parent->parent->right==just_added->parent){
                if(just_added->parent->parent->left->color=='r'){
                    if(just_added->parent->parent!=root){
                        just_added->parent->parent->color='r';
                    }
                    just_added->parent->parent->left->color='b';
                    just_added->parent->color='b';
                }
            }
    }
}
void Binary_tree::check_black_red_properties2(Element* just_added){
    if(just_added->parent->color=='r'){
            //Drugi przypadek z odbiciem lustrzanym
                // Jeœli dodany: ma ojca ktory jest lewy i sam jest prawym synem, brat ojca jest czarny
            if(just_added->parent->parent->right!=just_added->parent){
                    if(just_added->parent->parent->right->color=='b'){
                        // Rotate left
                        if(just_added->parent->right==just_added){
                            Element* grandparent = just_added->parent->parent;
                            Element* parent = just_added->parent;
                            grandparent->left = just_added;
                            just_added->parent = grandparent;
                            parent->parent = just_added;
                            just_added->left = parent;
                        }
                    }
            }
                // Jeœli dodany: ma ojca ktory jest prawy i sam jest lewym synem, lewy brat ojca jest czarny
            else if(just_added->parent->parent->right==just_added->parent){
                    if(just_added->parent->parent->left->color=='b'){
                        // Rotate right
                        if(just_added->parent->left==just_added){
                            Element* grandparent = just_added->parent->parent;
                            Element* parent = just_added->parent;
                            grandparent->right = just_added;
                            just_added->parent = grandparent;
                            parent->parent = just_added;
                            just_added->right = parent;
                        }
                }
            }
    }
}
void Binary_tree::check_black_red_properties3(Element* just_added){
    if(just_added->parent->color=='r'){
        // Trzeci przypadek
        // Jeœli jestesmy synem lewego ojca i jestesmy lewi a prawy brato ojca jest czarny
        if(just_added->parent->parent->left==just_added->parent){
            if(just_added->parent->left==just_added){
                if(just_added->parent->parent->right=='b'){
                    Element* grandparent = just_added->parent->parent;
                    Element* parent = just_added->parent;
                    if(just_added->parent->parent->parent!=NULL){
                        Element* grandgrandparent = just_added->parent->parent->parent;
                        if(grandgrandparent->left == just_added->parent->parent){
                            grandgrandparent->left = parent;
                        }
                        else{
                            grandgrandparent->right = parent;
                        }
                        parent->right = grandparent;
                        grandparent->parent = parent;
                        grandparent->left = NULL;

                    }


                }
            }
        }
    }
}
