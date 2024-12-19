//Nguyen Kim Linh
//20233495
//               ..╱ | 、 ♡
//               (˚ˎ 。7      ⋆
//                | 、˜〵
//                じしˍ, )ノ
               
#include <iostream>
#include<vector>
#include<string>
using namespace std;

#define TVALUE string

struct Node {
    TVALUE info;
    int page;
    vector<Node*> childs;

    Node(string info, int page) : info(info), page(page) {}

    void add_child(Node* child) {
        this->childs.push_back(child);
    }
};

int countChapters(Node* root) {
    if (!root) return 0;
    return root->childs.size();
}

int calculateTotalPages(Node* root) {
    if (!root) return 0;
    int total = root->page;

    for (auto child : root->childs)
        total = max(total, calculateTotalPages(child));

    return total;
}

// Tim chuong dai nhat
Node* findLongestChapter(Node* root) {
    if (!root || root->childs.empty()) return NULL;

    Node* longest = NULL;
    int maxPages = 0;

    for (auto child : root->childs) {
        int currentPages = calculateTotalPages(child) - child->page;
        if (currentPages > maxPages) {
            longest = child;
            maxPages = currentPages;
        }
    }
    return longest;
}


bool deleteNode(Node*& root, const string target) {
    if (!root) return false;
    
    //Phần cập nhật trang em nghĩ mãi không làm được, nên em bỏ cuộc :((

    for (auto it = root->childs.begin(); it != root->childs.end(); ++it) {
        if ((*it)->info == target) {

            delete* it;                 
            root->childs.erase(it);      
            return true;
        }
        if (deleteNode(*it, target)) {
            return true;
        }
    }
    return false;

    
}


void printBook(Node* root, int level = 0) {
    if (!root) return;
    cout << string(level * 4, ' ') << root->info << " (" << root->page << ')' << endl;

    for (auto child : root->childs) 
        printBook(child, level + 1);
}

int main()
{
    Node* root = new Node("Table of Contents", 0);

    Node* chapter1 = new Node("Chapter 1: Introduction to Programming", 1);
    Node* chapter2 = new Node("Chapter 2: Data Structures", 24);
    Node* chapter3 = new Node("Chapter 3: Algorithms", 50);

    root->add_child(chapter1);
    root->add_child(chapter2);
    root->add_child(chapter3);

    Node* section1_1 = new Node("Section 1.1: History of Programming", 2);
    Node* section1_2 = new Node("Section 1.2: Basics of Programming", 5);

    chapter1->add_child(section1_1);
    chapter1->add_child(section1_2);

    Node* subsection1_2_1 = new Node("Subsection 1.2.1: Variables", 6);
    Node* subsection1_2_2 = new Node("Subsection 1.2.2: Data Types", 8);
    Node* subsection1_2_3 = new Node("Subsection 1.2.3: Control Flow", 10);

    section1_2->add_child(subsection1_2_1);
    section1_2->add_child(subsection1_2_2);
    section1_2->add_child(subsection1_2_3);

    Node* subsubsection1_2_3_1 = new Node("Subsubsection 1.2.3.1: If-Else Statements", 11);
    Node* subsubsection1_2_3_2 = new Node("Subsubsection 1.2.3.2: Loops", 13);

    subsection1_2_3->add_child(subsubsection1_2_3_1);
    subsection1_2_3->add_child(subsubsection1_2_3_2);

    Node* section2_1 = new Node("Section 2.1: Arrays and Lists", 25);
    Node* section2_2 = new Node("Section 2.2: Trees and Graphs", 32);

    chapter2->add_child(section2_1);
    chapter2->add_child(section2_2);

    Node* subsection2_2_1 = new Node("Subsection 2.2.1: Binary Trees", 33);
    Node* subsection2_2_2 = new Node("Subsection 2.2.2: Graph Traversal", 37);

    section2_2->add_child(subsection2_2_1);
    section2_2->add_child(subsection2_2_2);

    Node* section3_1 = new Node("Section 3.1: Sorting Algorithms", 51);
    Node* section3_2 = new Node("Section 3.2: Searching Algorithms", 60);

    chapter3->add_child(section3_1);
    chapter3->add_child(section3_2);

    cout << "Tong so chuong: " << countChapters(root) << endl;

    Node* longestChapter = findLongestChapter(root);
    if (longestChapter) 
        cout << "Chuong dai nhat: " << longestChapter->info << endl;

    cout << "Tong trang cua cuon sach: " << calculateTotalPages(root) << endl;

    string target = "Subsection 1.2.2: Data Types";
    if (deleteNode(root, target)) 
        cout << "Xoa muc: " << target << endl;
    else 
        cout << "Khong tim thay muc do: " << target << endl;

    cout << "Tong trang cua cuon sach: " << calculateTotalPages(root) << endl;

    cout << "Book:" << endl;
    printBook(root);

    delete root;
    return 0;
}


