#include <iostream>
#include "Header.h"


std::vector<int> vecdel;
bool used[1000];
std::vector<int> vecbfs{};

int kol_A = 0, kol_N = 0, vsize = 0;
std::string print = "";

void NewGraph(std::vector<int> graph[1000]) {
    
    for (int i = 0; i < vsize; i++)
    {
        graph[i].clear();
        graph[i].shrink_to_fit();
    }

    kol_A = 0;
    vsize = 0;
    kol_N = 0;

    vecdel.clear();
    vecdel.shrink_to_fit();
    vecbfs.clear();
    vecbfs.shrink_to_fit();
    
}

void AddNode(std::vector<int> graph[1000], int x) {
    vsize = vsize + x;
    kol_N = kol_N + x;
}

void PrintGraph(std::vector<int> graph[1000]) {
    print = "{";
    for (int i = 0; i < vsize; i++) {
        print += "{";
        if (find(vecdel.begin(), vecdel.end(), i) == vecdel.end()) {

            for (int j = 0; j < graph[i].size(); j++) {
                print += std::to_string(graph[i][j] + 1);
                if (j != graph[i].size() - 1) {
                    print += ",";
                }
            }
        }
        else { print += "X"; }
        if (i == vsize - 1) {
            print += "}";
        }
        else {
            print += "},";
        }
    }

    print += "}";
    std::cout << print << std::endl;
}

void DelNode(std::vector<int> graph[1000], int x) {
    x--;
    if (x >= 0 && x < vsize) {
        if (find(vecdel.begin(), vecdel.end(), x) == vecdel.end()) {

            for (int i = 0; i < vsize; i++) {
                if (find(graph[i].begin(), graph[i].end(), x) != graph[i].end()) {
                    kol_A--;
                    std::vector<int>::iterator it = std::find(graph[i].begin(), graph[i].end(), x);
                    int index = distance(graph[i].begin(), it);
                    graph[i].erase(graph[i].begin() + index);
                   
                }
            }
            kol_A = kol_A - graph[x].size();
            graph[x].clear();
            graph[x].shrink_to_fit();
            
            vecdel.push_back(x);
            kol_N--;

        }
        else std::cout << "Node " << x + 1 << " is not exist\n";
    }
    else  std::cout << "Error! Going beyond what is possible\n"; 
}
  

void AddArc(std::vector<int> graph[1000], int u, int v) {
    u--, v--;
    
    if (u >= 0 && v >= 0 && u < vsize && v < vsize) {
        
        if (find(vecdel.begin(), vecdel.end(), u) == vecdel.end()) {

            if (find(vecdel.begin(), vecdel.end(), v) == vecdel.end()) {

                if (find(graph[u].begin(), graph[u].end(), v) == graph[u].end()) {

                    kol_A++;
                    graph[u].push_back(v);
                }
                else std::cout << "Arc " << u+1 << " -> " << v+1<< " is exist\n";
            }
            else std::cout << "Node " << v + 1 << " is not exist\n";
        }
        else std::cout << "Node " << u + 1 << " is not exist\n";
    }
    else  std::cout << "Error! Going beyond what is possible\n";
}

void DelArc(std::vector<int> graph[1000], int u, int v) {
    u--; v--;

    if (u >= 0 && v >= 0 && u < vsize && v < vsize) {
        if (find(vecdel.begin(), vecdel.end(), u) == vecdel.end()) {

            if (find(vecdel.begin(), vecdel.end(), v) == vecdel.end()) {

                if (find(graph[u].begin(), graph[u].end(), v) != graph[u].end()) {

                    std::vector<int>::iterator it = std::find(graph[u].begin(), graph[u].end(), v);
                    int index = distance(graph[u].begin(), it);
                    graph[u].erase(graph[u].begin() + index);
                    kol_A--;
                }
                else std::cout << "Arc " << u + 1 << " -> " << v + 1 << " is not exist\n";
            
            }
            else std::cout << "Node " << v + 1 << " is not exist\n";
        }
        else std::cout << "Node " << u + 1 << " is not exist\n";
    }
    else std::cout << "Error! Going beyond what is possible\n";

    
}



void BFS(std::vector<int> graph[1000], int x) {
    x--;
    std::queue<int> q;
    if (x >= 0 && x < vsize) {
        q.push(x);
        used[x] = true;

        std::cout << "BFS from " << x + 1 << " :\nSTART -> ";
        if (find(vecdel.begin(), vecdel.end(), x) == vecdel.end()) {

            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                std::cout << cur + 1 << " -> ";
                vecbfs.push_back(cur + 1);
                for (int neighbor : graph[cur]) {
                    if (!used[neighbor]) {
                        q.push(neighbor);
                        used[neighbor] = true;
                    }
                }
            }
            std::cout << "FINISH\n";


            q.push(x);
            used[x] = false;

            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int neighbor : graph[cur]) {
                    if (used[neighbor]) {
                        q.push(neighbor);
                        used[neighbor] = false;
                    }
                }
            }
        }
        else { std::cout << "Error! Node " << x + 1 << " is not exist!\n"; }
    }
    else { std::cout << "Error! Going beyond what is possible\n"; }
}
