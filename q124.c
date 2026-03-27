#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        visited[0] = true;
        vector<int> stack;
        stack.push_back(0);
        
        while(!stack.empty()){
            int current = stack.back();
            stack.pop_back();
            
            for(int key : rooms[current]){
                if(!visited[key]){
                    visited[key] = true;
                    stack.push_back(key);
                }
            }
        }
        
        for(bool v : visited){
            if(!v) return false;
        }
        return true;
    }
};

int main() {
    printf("Solution for Keys and Rooms is implemented. Add test cases as needed.\n");
    return 0;
}