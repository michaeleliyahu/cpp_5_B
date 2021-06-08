#include <iostream>
#include <set>
namespace ariel
{
    template <typename T>
    class BinaryTree
    {
    private:
        struct Node
        {
            T t_value;
            Node *t_right;
            Node *t_left;
            Node(const T &val) : t_value(val) {}
        };
        Node *pointer_to_node2;
        Node *t_first;
        bool exist;
        // set<T> keep;
        //all add function
    public:
        BinaryTree() : t_first(nullptr), exist(false) {}

        BinaryTree &add_root(const T &val)
        {
            t_first = new Node(val);
            return *this;
        }
        BinaryTree &add_left(const T &num_first, const T &num_sec)
        {
            pointer_to_node2 = t_first;
            exist = false;
            Node *temp = search(num_first, this->t_first);
            // temp->t_value;
            // if (pointer_to_node2->t_value != num_first)
            // {
            //     throw std::invalid_argument("value isnt exist");
            // }
            if (pointer_to_node2->t_left != nullptr)
            {
                pointer_to_node2->t_left->t_value = num_sec;
            }
            else
            {
                pointer_to_node2->t_left = new Node(num_sec);
            }
            return *this;
        }
        BinaryTree &add_right(const T &num_first, const T &num_sec) { return *this; }

        //node

        //operator for iterator
        //preorder
        class preorder_iterator
        {
        private:
            Node *pointer_to_node;

        public:
            preorder_iterator(Node *ptr = nullptr) : pointer_to_node(ptr) {}

            preorder_iterator &operator++() { return *this; }
            bool operator!=(const preorder_iterator &rhs) { return false; }
            T &operator*() { return pointer_to_node->t_value; }
            T *operator->() { return &(pointer_to_node->t_value); }
            bool operator==(const preorder_iterator &rhs)
            {
                return pointer_to_node == rhs.pointer_to_node;
            }
            preorder_iterator operator++(int dummy_flag_for_postfix_increment)
            {
                // Node *tmp = *this;
                // pointer_to_node = pointer_to_node->t_root;
                return *this;
            }
        };

        //inorder
        class inorder_iterator
        {
        private:
            Node *pointer_to_node;

        public:
            inorder_iterator(Node *ptr = nullptr) : pointer_to_node(ptr) {}

            bool operator!=(const inorder_iterator &rhs) { return false; }
            inorder_iterator &operator++() { return *this; }
            T &operator*() { return pointer_to_node->t_value; }
            T *operator->() { return &(pointer_to_node->t_value); }
            bool operator==(const inorder_iterator &rhs)
            {
                return pointer_to_node == rhs.pointer_to_node;
            }
            inorder_iterator operator++(int dummy_flag_for_postfix_increment)
            {
                // Node tmp = *this;
                // pointer_to_node = pointer_to_node->t_root;
                return *this;
            }
        };

        //postorder
        class postorder_iterator
        {
        private:
            Node *pointer_to_node;

        public:
            postorder_iterator(Node *ptr = nullptr) : pointer_to_node(ptr) {}

            bool operator!=(const postorder_iterator &rhs) { return false; }
            postorder_iterator &operator++() { return *this; }
            T &operator*() { return pointer_to_node->t_value; }
            T *operator->() { return &(pointer_to_node->t_value); }
            bool operator==(const postorder_iterator &rhs)
            {
                return pointer_to_node == rhs.pointer_to_node;
            }
            postorder_iterator operator++(int dummy_flag_for_postfix_increment)
            {
                // Node tmp = *this;
                // pointer_to_node = pointer_to_node->t_root;
                return *this;
            }
        };

        //begin/end for iterator
        preorder_iterator begin_preorder() { return preorder_iterator{t_first}; }
        preorder_iterator end_preorder() { return preorder_iterator{nullptr}; }

        inorder_iterator begin_inorder() { return inorder_iterator{t_first}; }
        inorder_iterator end_inorder() { return inorder_iterator{nullptr}; }

        postorder_iterator begin_postorder() { return postorder_iterator{t_first}; }
        postorder_iterator end_postorder() { return postorder_iterator{nullptr}; }

        inorder_iterator begin() { return inorder_iterator{t_first}; }
        inorder_iterator end() { return inorder_iterator{nullptr}; }

        friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &strm)
        {
            return os;
        }

        Node *search(const T &val, Node *pointer)
        {
            if (!exist)
            {
                // cout<<"ff"<<" ";
                if (pointer->t_value == val)
                {
                    pointer_to_node2 = pointer;
                    exist = true;
                    // cout << "here1 \n";
                    return pointer;
                }
                if (pointer->t_left != nullptr && !exist)
                {
                    // cout << "here2";
                    // pointer = pointer->t_left;
                    search(val, pointer->t_left);
                }

                if (pointer->t_right != nullptr && !exist)
                {
                    // cout << "here3";
                    // pointer = pointer->t_right;
                    search(val, pointer->t_right);
                }
            }

            return pointer;
        }
    };
}
