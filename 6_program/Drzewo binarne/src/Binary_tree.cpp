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
    check_black_red_properties(new_element);
}

void Binary_tree::find(Element* target){

}

void Binary_tree::moving_pre_order(Element* start_element){
    cout<<start_element->value<<" - "<<start_element->color<<endl;
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

Element* Binary_tree::check_black_red_properties_met_1(Element* just_added){
                //Pierwszy przypadek z odbiciem lustranym
                if(just_added->parent->parent->left==just_added->parent){
                        if(just_added->parent->parent->right!=NULL){
                            if(just_added->parent->parent->right->color=='r'){
                                if(just_added->parent->parent!=root){
                                    just_added->parent->parent->color='r';
                                }
                                just_added->parent->parent->right->color='b';
                                just_added->parent->color='b';
                                return(just_added->parent->parent);
                            }
                        }
                }
                else if(just_added->parent->parent->right==just_added->parent){
                         if(just_added->parent->parent->left!=NULL){
                            if(just_added->parent->parent->left->color=='r'){
                                if(just_added->parent->parent!=root){
                                    just_added->parent->parent->color='r';
                                }
                                just_added->parent->parent->left->color='b';
                                just_added->parent->color='b';
                                return(just_added->parent->parent);
                            }
                        }
                }
        root->color='b';
        return(just_added->parent->parent);
}

Element* Binary_tree::check_black_red_properties_met_2(Element* just_added){
                //Drugi przypadek z odbiciem lustrzanym
                // Jeœli dodany: ma ojca ktory jest lewy i sam jest prawym synem, brat ojca jest czarny
                if(just_added->parent->parent->right!=just_added->parent){
                        if(just_added->parent->parent->right==NULL){
                            // Rotate left
                            if(just_added->parent->right==just_added){
                                Element* grandparent = just_added->parent->parent;
                                Element* parent = just_added->parent;
                                Element* help = just_added->left;
                                grandparent->left = just_added;
                                just_added->parent = grandparent;
                                parent->parent = just_added;
                                just_added->left = parent;
                                parent->right = help;
                                check_black_red_properties_met_3(just_added->left);
                            }
                        }
                        else if(just_added->parent->parent->right!=NULL){
                            if(just_added->parent->parent->right->color=='b'){
                                // Rotate left
                                    if(just_added->parent->right==just_added){
                                        Element* grandparent = just_added->parent->parent;
                                        Element* parent = just_added->parent;
                                        Element* help = just_added->left;
                                        grandparent->left = just_added;
                                        just_added->parent = grandparent;
                                        parent->parent = just_added;
                                        just_added->left = parent;
                                        parent->right = help;
                                        check_black_red_properties_met_3(just_added->left);
                                    }
                            }
                        }
                }
                    // Jeœli dodany: ma ojca ktory jest prawy i sam jest lewym synem, lewy brat ojca jest czarny
                else if(just_added->parent->parent->right==just_added->parent){
                        if(just_added->parent->parent->left==NULL){
                            // Rotate right
                            if(just_added->parent->left==just_added){
                                Element* grandparent = just_added->parent->parent;
                                Element* parent = just_added->parent;
                                Element* help = just_added->right;
                                grandparent->right = just_added;
                                just_added->parent = grandparent;
                                parent->parent = just_added;
                                just_added->right = parent;
                                parent->right = help;
                                check_black_red_properties_met_3(just_added->right);
                            }
                        }
                        else if(just_added->parent->parent->left!=NULL){
                            if(just_added->parent->parent->left->color=='b'){
                                // Rotate right
                                if(just_added->parent->left==just_added){
                                    Element* grandparent = just_added->parent->parent;
                                    Element* parent = just_added->parent;
                                    Element* help = just_added->right;
                                    grandparent->right = just_added;
                                    just_added->parent = grandparent;
                                    parent->parent = just_added;
                                    just_added->right = parent;
                                    parent->right = help;
                                    check_black_red_properties_met_3(just_added->right);
                                }
                            }
                        }
                }
    return(just_added->parent);
}

Element* Binary_tree::check_black_red_properties_met_3(Element* just_added){
            // Trzeci przypadek
            // Jeœli jestesmy synem lewego ojca i jestesmy lewi a prawy brato ojca jest czarny
            if(just_added->parent->parent!=root){
            if(just_added->parent->parent->left==just_added->parent){
                if(just_added->parent->left==just_added){
                    if((just_added->parent->parent->right->color=='b')||(just_added->parent->parent->right==NULL)){
                        Element* grandparent = just_added->parent->parent;
                        Element* parent = just_added->parent;
                        if(just_added->parent->parent->parent!=NULL){
                            Element* oldgrandparent = just_added->parent->parent->parent;
                            if(oldgrandparent->left == just_added->parent->parent){
                                oldgrandparent->left = parent;
                            }
                            else{
                                oldgrandparent->right = parent;
                            }
                            parent->parent = oldgrandparent;
                        }
                        Element* help = just_added->parent->right;
                        parent->right = grandparent;
                        grandparent->parent = parent;
                        grandparent->left = help;

                    }
                }
            }
            // Jesli jestesmy synem prawego ojca i jestesmy prawi
            if(just_added->parent->parent->right==just_added->parent){
                if(just_added->parent->right==just_added){
                    if((just_added->parent->parent->left->color=='b')||(just_added->parent->parent->left==NULL)){
                        Element* grandparent = just_added->parent->parent;
                        Element* parent = just_added->parent;
                        if(just_added->parent->parent->parent!=NULL){
                            Element* oldgrandparent = just_added->parent->parent->parent;
                            if(oldgrandparent->right == just_added->parent->parent){
                                oldgrandparent->right = parent;
                            }
                            else{
                                oldgrandparent->left = parent;
                            }
                            parent->parent = oldgrandparent;
                        }
                        Element* help = just_added->parent->left;
                        parent->left = grandparent;
                        grandparent->parent = parent;
                        grandparent->right = help;

                    }
                }
            }
            }
        return(just_added->parent);
}

void Binary_tree::check_black_red_properties(Element* just_added){
    while(1){
            int i=2;
            if((just_added!=root) && (just_added->parent != root) && (just_added->parent->color == 'r')&&(i!=0)){
                i=0;
                    Element* grandparent;
                    if((just_added->parent->parent->right!=NULL)&&(i!=1)){
                            if((just_added->parent->parent->right->color=='r')&&((just_added->parent->parent->right->right!=just_added)&&(just_added->parent->parent->right->left!=just_added))){
                                grandparent = check_black_red_properties_met_1(just_added);
                                check_black_red_properties(grandparent);
                                i=1;
                            }
                    }
                    if(i!=1){
                    if((just_added->parent->parent->left!=NULL)&&(i!=1)){
                            if((just_added->parent->parent->left->color=='r')&&((just_added->parent->parent->left->right!=just_added)&&(just_added->parent->parent->left->left!=just_added))){
                                grandparent = check_black_red_properties_met_1(just_added);
                                check_black_red_properties(grandparent);
                                i=1;
                            }
                    }}
                    //przypadek 2
                    if(i!=1){
                    if((just_added->parent->parent->left==just_added->parent)&&((just_added->parent->parent->right != NULL))&&(just_added->parent->right==just_added)&&(i!=1)){
                        if(just_added->parent->parent->right->color=='b'){
                            grandparent = check_black_red_properties_met_2(just_added);
                            check_black_red_properties(grandparent);
                            i=1;
                        }
                    }}
                    if(i!=1){
                    if((just_added->parent->parent->left==just_added->parent)&&((just_added->parent->parent->right == NULL))&&(just_added->parent->right==just_added)&&(i!=1)){
                        grandparent = check_black_red_properties_met_2(just_added);
                        check_black_red_properties(grandparent);
                        i=1;
                    }}
                    //odbicie lustrzane przypadku 2
                    if(i!=1){
                    if((just_added->parent->parent->right==just_added->parent)&&((just_added->parent->parent->left != NULL))&&(just_added->parent->left==just_added)){
                        if(just_added->parent->parent->left->color=='b'){
                            grandparent = check_black_red_properties_met_2(just_added);
                            check_black_red_properties(grandparent);
                            i=1;
                        }
                    }}
                    if(i!=1){
                    if((just_added->parent->parent->right==just_added->parent)&&((just_added->parent->parent->left == NULL))&&(just_added->parent->left==just_added)&&(i!=1)){
                        grandparent = check_black_red_properties_met_2(just_added);
                        check_black_red_properties(grandparent);
                        i=1;
                    }}
                    // przypadek 3
                    if(i!=1){
                    if((just_added->parent->parent->left==just_added->parent)&&(just_added->parent->left==just_added)&&(just_added->parent->parent->right!=NULL)&&(just_added->parent->parent != root)&&(i!=1)){
                        if(just_added->parent->parent->right->color=='b'){
                            grandparent = check_black_red_properties_met_3(just_added);
                            check_black_red_properties(grandparent);
                            i=1;
                        }
                    }}
                    if(i!=1){
                    if((just_added->parent->parent->left==just_added->parent)&&(just_added->parent->left==just_added)&&(just_added->parent->parent->right==NULL)&&(just_added->parent->parent != root)&&(i!=1)){
                        grandparent = check_black_red_properties_met_3(just_added);
                        check_black_red_properties(grandparent);
                        i=1;
                    }}
                    // przpadek 3 odbicie lustrzane
                    if(i!=1){
                    if((just_added->parent->parent->right==just_added->parent)&&(just_added->parent->right==just_added)&&(just_added->parent->parent->left!=NULL)&&(just_added->parent->parent != root)&&(i!=1)){
                        if(just_added->parent->parent->left->color=='b'){
                            grandparent = check_black_red_properties_met_3(just_added);
                            check_black_red_properties(grandparent);
                            i=1;
                        }
                    }}
                    if(i!=1){
                    if((just_added->parent->parent->right==just_added->parent)&&(just_added->parent->right==just_added)&&(just_added->parent->parent->left==NULL)&&(just_added->parent->parent != root)&&(i!=1)){
                        grandparent = check_black_red_properties_met_3(just_added);
                        check_black_red_properties(grandparent);
                        i=1;
                    }}

                }
            else
                break;
        }
}
