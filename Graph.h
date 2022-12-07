#pragma once
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <cstdlib>


// #include <opencv2/opencv.hpp>
using namespace std;
// id = [gender] [hair color/bald] [skin color] [hair type] [facial hair]
// [bangs] [lips] [nose] [glasses] [young/old]

class Graph {

    struct Node {
        unordered_map<char, vector<pair<string, string>>> graph; // id, image name
        Node *first;
        Node *second;
        Node *third;
        Node *fourth;
        Node *fifth;
        Node *sixth;
        char c;
        Node() { // root
            this->first = nullptr;
            this->second = nullptr;
            this->third = nullptr;
            this->fourth = nullptr;
            this->fifth = nullptr;
            this->sixth = nullptr;
        }
        Node(char characteristic) { // root
            this->first = nullptr;
            this->second = nullptr;
            this->third = nullptr;
            this->fourth = nullptr;
            this->fifth = nullptr;
            this->sixth = nullptr;
            this->c = characteristic;
        }

    };

    Node *root = nullptr;

    Node *helperCon(int index, Node *node) {
        if (index == 0 || index == 2 ||index == 5 || index == 6 || index == 7 || index == 8 ) { // node = root
            node->first = new Node();
            node->second = new Node();
            node->first = helperCon(index + 1, node->first);
            node->second = helperCon(index + 1, node->second);
        } else if (index == 1) { // node = root
            node->first = new Node();
            node->second = new Node();
            node->third = new Node();
            node->fourth = new Node();
            node->fifth = new Node();
            node->sixth = new Node();
            node->first = helperCon(index + 1, node->first);
            node->second = helperCon(index + 1, node->second);
            node->third = helperCon(index + 1, node->third);
            node->fourth = helperCon(index + 1, node->fourth);
            node->fifth = helperCon(index + 1, node->fifth);
            node->sixth = helperCon(index + 1, node->sixth);
        } else if (index == 3) { // node = root
            node->first = new Node();
            node->second = new Node();
            node->third = new Node();
            node->first = helperCon(index + 1, node->first);
            node->second = helperCon(index + 1, node->second);
            node->third = helperCon(index + 1, node->third);
        } else if (index == 4) { // node = root
            node->first = new Node();
            node->second = new Node();
            node->third = new Node();
            node->fourth = new Node();
            node->first = helperCon(index + 1, node->first);
            node->second = helperCon(index + 1, node->second);
            node->third = helperCon(index + 1, node->third);
            node->fourth = helperCon(index + 1, node->fourth);
        } else if (index == 9) {
            node->first = new Node();
            node->second = new Node();
        } else
            cout << "oop something not working" << endl;

        return node;
    }

    // void insert (string id, int index) {

    Node *helperInsert(string id, int index, string image, Node *node) {
        // cout << "index " << index << " working" << endl;
        // make_pair(id, image)
        if (index == 0) {
            if (id.at(index) == 'm') {
                root->first = helperInsert(id, index + 1, image, root->first);
                root->graph['m'].push_back(make_pair(id, image));
            } else { // index = f
                root->second = helperInsert(id, index + 1, image, root->second);
                root->graph['f'].push_back(make_pair(id, image));
            }
        } else if (index == 1) {
            if (id.at(index) == 'o') {
                cout << "id: " << id << endl;
                node->first = helperInsert(id, index + 1, image, node->first);
                node->graph['o'].push_back(make_pair(id, image));
            } else if (id.at(index) == 'b') {
                node->second = helperInsert(id, index + 1, image, node->second);
                node->graph['b'].push_back(make_pair(id, image));
            } else if (id.at(index) == 'y') {
                node->third = helperInsert(id, index + 1, image, node->third);
                node->graph['y'].push_back(make_pair(id, image));
            } else if (id.at(index) == 'r') {
                node->fourth = helperInsert(id, index + 1, image, node->fourth);
                node->graph['r'].push_back(make_pair(id, image));
            } else if (id.at(index) == 'g') {
                node->fifth = helperInsert(id, index + 1, image, node->fifth);
                node->graph['g'].push_back(make_pair(id, image));
            } else if (id.at(index) == 'x') {
                node->sixth = helperInsert(id, index + 1, image, node->sixth);
                node->graph['x'].push_back(make_pair(id, image));
            }
        } else if (index == 2) {
            if (id.at(index) == 'p') {
                node->first = helperInsert(id, index + 1, image, node->first);
                node->graph['p'].push_back(make_pair(id, image));
            } else if (id.at(index) == 'c') {
                node->second = helperInsert(id, index + 1, image, node->second);
                node->graph['c'].push_back(make_pair(id, image));
            }
        } else if (index == 3) {
            if (id.at(index) == 's') {
                node->first = helperInsert(id, index + 1, image, node->first);
                node->graph['s'].push_back(make_pair(id, image));
            } else if (id.at(index) == 'w') {
                node->second = helperInsert(id, index + 1, image, node->second);
                node->graph['w'].push_back(make_pair(id, image));
            } else if (id.at(index) == 'z') {
                node->third = helperInsert(id, index + 1, image, node->third);
                node->graph['z'].push_back(make_pair(id, image));
            }
        } else if (index == 4) { // m n t z
            if (id.at(index == 'm')) {
                node->first = helperInsert(id, index + 1, image, node->first);
                node->graph['m'].push_back(make_pair(id, image));
            } else if (id.at(index == 'n')) {
                node->second = helperInsert(id, index + 1, image, node->second);
                node->graph['n'].push_back(make_pair(id, image));
            } else if (id.at(index == 't')) {
                node->third = helperInsert(id, index + 1, image, node->third);
                node->graph['t'].push_back(make_pair(id, image));
            } else if (id.at(index == 'z')) {
                node->fourth = helperInsert(id, index + 1, image, node->fourth);
                node->graph['z'].push_back(make_pair(id, image));
            }
        }
            //  n e y else: z
        else if (index == 5) {
            if (id.at(index == 'b')) {
                node->first = helperInsert(id, index + 1, image, node->first);
                node->graph['b'].push_back(make_pair(id, image));
            } else if (id.at(index == 'z')) {
                node->second = helperInsert(id, index + 1, image, node->second);
                node->graph['z'].push_back(make_pair(id, image));
            }
        }

        else if (index == 6) {
            if (id.at(index == 'l')) {
                node->first = helperInsert(id, index + 1, image, node->first);
                node->graph['l'].push_back(make_pair(id, image));
            } else if (id.at(index == 'z')) {
                node->second = helperInsert(id, index + 1, image, node->second);
                node->graph['z'].push_back(make_pair(id, image));
            }
        } else if (index == 7) {
            if (id.at(index == 'n')) {
                node->first = helperInsert(id, index + 1, image, node->first);
                node->graph['n'].push_back(make_pair(id, image));
            } else if (id.at(index == 'z')) {
                node->second = helperInsert(id, index + 1, image, node->second);
                node->graph['z'].push_back(make_pair(id, image));
            }
        } else if (index == 8) {
            if (id.at(index == 'e')) {
                node->first = helperInsert(id, index + 1, image, node->first);
                node->graph['e'].push_back(make_pair(id, image));
            } else if (id.at(index == 'z')) {
                node->second = helperInsert(id, index + 1, image, node->second);
                node->graph['z'].push_back(make_pair(id, image));
            }
        } else if (index == 9) {
            if (id.at(index == 'y')) {
                node->graph['y'].push_back(make_pair(id, image));
            } else if (id.at(index == 'z')) {
                node->graph['z'].push_back(make_pair(id, image));
            }
        } else {
            // cout << "done" << endl;
        }
        // cout << "index " << index << " and graph size " << node->graph.size() << endl;
        return node;
    }



    string printInorder(Node* node, string id, int index) {
        // cout << index << " for graph size: " << node->graph.size() << endl;
        if (index == 9) {
            // cout << "node in DFS: " << node << endl;
            // cout << "graph size inside 9: " << node->graph.size() << endl;
            if (node->graph.size() != 0) {
                int c = 0;
                vector<string> images;
                auto it = node->graph.begin();
                for (; it != node->graph.end(); it++) {
                    for (int i = 0; i < it->second.size(); i++) {
                        if (it->second.at(i).first == id) {
                            // cout << "id " << id << endl;
                            // cout << "matching s: " << it->second[i].first << endl;
                            cout << "matching image: " << it->second[i].second << endl;
                            images.push_back(it->second[i].second);
                            c++;
                        }
                    }
                    if (images.size() != 0) {
                        srand(time(0));
                        return images.at(rand() % images.size() - 1);
                    }
                }
            }

            return "";
        }

        else {

            string s = "";
            // call first child
            s += printInorder(node->first, id, index + 1);
            // cout << "s1 for index " << index << ": " << s << endl;
            if (s != "") {
                return s;
            }

            // then call second child
            s += printInorder(node->second, id, index + 1);
            // cout << "s2 for index " << index << ": " << s << endl;

            if (s != "") {
                return s;
            }

            if (node->third != nullptr) {
                s += printInorder(node->third, id, index + 1);
                // cout << "s3 for index " << index << ": " << s << endl;
                if (s != "") {
                    return s;
                }
            }

            if (node->fourth != nullptr) {
                s += printInorder(node->fourth, id, index + 1);
                // cout << "s4 for index " << index << ": " << s << endl;
                if (s != "") {
                    return s;
                }
            }

            if (node->fifth != nullptr) {
                s += printInorder(node->fifth, id, index + 1);
                // cout << "s5 for index " << index << ": " << s << endl;
                if (s != "") {
                    return s;
                }
            }

            if (node->sixth != nullptr) {
                s += printInorder(node->sixth, id, index + 1);
                cout << "s6 for index " << index << ": " << s << endl;
                if (s != "") {
                    return s;
                }
            }
        }
        return "";
    }

public:
    Graph() { // constructor
        cout << "constructing" << endl;
        this->root = new Node();
        this->root = helperCon(0, this->root);
    }
    void insert(string id, string image) {
        // cout << "this is working" << endl;
        this->root = helperInsert(id, 0, image, this->root);
    }

    void printgender() {
        cout << "da men: " << endl;
        cout << "size: " << root->graph['m'].size() << endl;
        for (int i = 0; i < root->graph['m'].size(); i++) {
            cout << root->graph['m'].at(i).first << " ";
            cout << root->graph['m'].at(i).second << endl;
        }
        cout << "da women: " << endl;
        cout << "size: " << root->graph['f'].size() << endl;
        for (int i = 0; i < root->graph['f'].size(); i++) {
            cout << root->graph['f'].at(i).first << " ";
            cout << root->graph['f'].at(i).second << endl;
        }
    }

    vector<string> BFSTraversal() {
        cout << "entered BFS" << endl;
        queue<Node *> q;
        q.push(this->root);
        auto iter = q.front()->graph.begin();
        cout << "reached" << endl;
        cout << iter->first << endl;
        vector <string> jpg_nums;

        while (!q.empty()) {
            cout << "entering queue" << endl;
            if (q.size() != 0) {
                cout << "breaks here " << endl;
                cout << "graph.size(): "  << q.front()->graph.size() << endl;
                if (q.front()->graph.size() == 0)
                    break;

                auto iter = q.front()->graph.begin();
                jpg_nums.push_back(iter->second[0].second);
            }

            if (q.front()->first != nullptr) {
                q.push(q.front()->first);
                cout << "breaks here 1" << endl;
            }
            if (q.front()->second != nullptr) {
                q.push(q.front()->second);
                cout << "breaks here 2 "<< endl;
            }
            if (q.front()->third != nullptr) {
                q.push(q.front()->third);
                cout << "breaks here 3 "<< endl;
            }
            if (q.front()->fourth != nullptr) {
                q.push(q.front()->fourth);
                cout << "breaks here 4" << endl;
            }
            if (q.front()->fifth != nullptr) {
                q.push(q.front()->fifth);
                cout << "breaks here 5 "<< endl;
            }
            if (q.front()->sixth != nullptr) {
                q.push(q.front()->sixth);
                cout << "breaks here 6" << endl;
            }
            q.pop();
        }
        return jpg_nums;
    }

    void DFSsearch(string ID) {
        set<Node*> visited;
        stack<Node*> s;

        Node* temp = this->root;
        visited.insert(this->root);
        s.push(this->root);
        string possible_id = "";

        while(!s.empty()) {
            temp = s.top();
            auto iter = temp->graph.begin();
            possible_id += iter->first;
            s.pop();

            vector <Node*> neighbors;
            neighbors.push_back(temp);
            for(Node* node:neighbors) {
                if (visited.count(temp) == 0) {
                    visited.insert(temp);
                    s.push(temp);
                }
            }
            if(possible_id.length() == 10) {
                if(ID == possible_id) {
                    cout << "found id: " << possible_id << endl;
                }
                else {
                    // c
                }
            }
        }


    }
    string publicBFS () {
        BFSTraversal();
        return "temp";
    }

    string publicDFS (string id) {
        cout << "looking for " << id << endl;
        string k = printInorder(this->root, id, 0);
        cout << "final k: " << k << endl;
        return k;
    }












    Node *getRoot() { return this->root; }
};
