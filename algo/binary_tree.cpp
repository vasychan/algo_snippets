/*
 * =====================================================================================
 *
 *       Filename:  binary_tree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20.12.2016 17:39:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <string>
#include <vector>
#include <iostream>

struct node;

struct  node
{
    public:
    node* m_left;
    node* m_rigth;

    int m_key;
    std::string m_value;
    
    node (int key, const std::string& value) 
            : m_key(key), 
              m_value(value) 
    {
        m_left = nullptr;
        m_rigth = nullptr;
    }
};

struct binary_tree
{
    std::vector<node*> tree;
    node* root_node = nullptr;

    binary_tree() {};

    void add(int key, const std::string& value)
    {
        // create first element 
        node*  new_node = new node(key, value);
        if ( root_node == nullptr )
            {
            tree.push_back(new_node);
            root_node = new_node; 
            return;
            }
        // add element
        else
            {
            node* x = root_node;
            node* pr_node = nullptr;
            while ( x != nullptr )
                {
                // check to found place
                pr_node = x;
                if  ( key < x->m_key )
                    {
                    x = x->m_left;
                    if ( x == nullptr )
                        { 
                        pr_node->m_left = new_node;
                        new_node->m_rigth = pr_node;
                        break;
                        }
                    if ( x->m_key < key < pr_node->m_key )
                        {
                        pr_node->m_left = new_node;
                        x->m_rigth = new_node;

                        new_node->m_rigth = pr_node;
                        new_node->m_left = x;
                        break;
                        }
                    }
                else if  ( key > x->m_key )
                    {
                    x = x->m_rigth;
                    if ( x == nullptr )
                        { 
                        pr_node->m_rigth = new_node;
                        new_node->m_left = pr_node;
                        break;
                        }

                    if ( x->m_key > key > pr_node->m_key )
                        {
                        pr_node->m_rigth = new_node;
                        x->m_left = new_node;


                        new_node->m_left = pr_node;
                        new_node->m_rigth = x;
                        break;
                        }
                    }
                else if  ( key == x->m_key )
                    {
                    delete new_node;
                    return;
                    }
                }
            tree.push_back(new_node);
            }
    };
    
    void print(node* root, int level = 0)
    {
        std::cout << " <<<<  next node >>>> " << "\n";
        if ( root == nullptr ) 
            return ;
        std::cout << "  " << root->m_key << "  " << "\n";
        std::cout << " / " <<  "\\ " << "\n";
        //std::cout << current->m_left->m_key << "    " << current->m_rigth->m_key << "\n";
        if ( root->m_left != nullptr )
        {
            std::cout << root->m_left->m_key ;
        }
        std::cout << "   ";
        if ( root->m_rigth != nullptr )
        {
            std::cout << root->m_rigth->m_key ;
        }
        std::cout << "\n";
        
        if ( root->m_left == nullptr && root->m_rigth != nullptr)
            print(root);
        if ( root->m_left != nullptr )
        {
            std::cout << " go left  <<<<<< " << "\n";
            print(root->m_left);
        }
        else if ( root->m_rigth != nullptr )
        {
            std::cout << " go rigth >>>>>> " << "\n";
            print(root->m_rigth);
        }
        return; 
    }

    node* search(int key)
    {
        int count = 0;
        node* x = root_node;
        while (x != nullptr)
        {
            std::cout << x->m_key << " ->\n";
            count++;
            if ( x->m_key == key )
            {
                break;
            }
            else if ( x->m_key > key )
            {
                x = x->m_left;    
            }
            else if ( x->m_key < key )
            {
                x = x->m_rigth;    
            }
        }
        std::cout << " search make " << count << " iterations, max count of tree eq "<< tree.size() << "\n";
        return x;
    };

    void remove(const int node_id)
    {

    };

    void min()
    {

    };

    void max()
    {

    };
    node* invert(node* root)
    {
       if ( root == nullptr )
           return nullptr;
        if ( root->m_left != nullptr )
        {
            node* leftchild = invert(root->m_left);
            if ( leftchild != nullptr )
            leftchild->m_rigth = root;
        }
        if ( root->m_rigth != nullptr )
        {
            node* rigthchild = invert(root->m_rigth);
            if ( rigthchild != nullptr )
            rigthchild->m_left = root;
        }
        root->m_left = nullptr; 
        root->m_rigth = nullptr; 
        return root;
    };
};


int main()
{
binary_tree* bt = new binary_tree();

/*
for ( int i = 0; i < 10 ; i++)
{
    int random = rand() % 100; 
    bt->add(random, "test" + std::to_string(random));
}
*/
    bt->add(5, "test10" );
    bt->add(2, "test2");
    bt->add(1, "test2");
    bt->add(3, "test3");
    bt->add(7, "test7");
    bt->add(6, "test7");
    bt->add(9, "test7");
std::cout << " ============= binary tree ================= \n" ;
bt->print(bt->root_node);

//std::cout << " ============= invert binary tree ================= \n" ;
//bt->invert(bt->root_node);
//bt->print(bt->root_node);
int a;
std::cout << " key = ";
std::cin>>a;

node* n = bt->search(a);
if ( n != nullptr)
    std::cout << " ====== " << n->m_value << " ========== " << "\n";
return 0;
}
