#include <iostream>
#include <queue>

// 이진 트리 기본 구조 
struct node {
    std::string position;
    node* first;
    node* second;
};

struct org_tree {
    node* root;

    static org_tree create_org_structure(const std::string& pos) {
        org_tree tree;
        tree.root = new node{ pos, NULL, NULL };
        return tree;
    }

    static node* find(node* root, const std::string& value) {
        if (root == NULL)
            return NULL;

        if (root->position == value)
            return root;

        auto firstFound = org_tree::find(root->first, value);

        if (firstFound != NULL)
            return firstFound;

        return org_tree::find(root->second, value);
    }

    bool addSubordinate(const std::string& manager, const std::string& subordinate) {
        auto managerNode = org_tree::find(root, manager);

        if (!managerNode) {
            std::cout << manager.c_str() << "을(를) 찾을 수 없습니다: " << std::endl;
            return false;
        }

        if (managerNode->first && managerNode->second) {
            std::cout << manager.c_str() << " 아래에 " << subordinate.c_str() << "을(를) 추가할 수 없습니다. " << std::endl;
            return false;
        }

        if (!managerNode->first)
            managerNode->first = new node{ subordinate, NULL, NULL };
        else
            managerNode->second = new node{ subordinate, NULL, NULL };

        std::cout << manager.c_str() << " 아래에 " << subordinate.c_str() << "을(를) 추가했습니다. " << std::endl;

        return true;
    }

    static void levelOrder(node* start) {
        if (!start) return;
        std::queue<node*> q;
        q.push(start);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto current = q.front();
                q.pop();
                std::cout << current->position.c_str() << ", ";
                if (current->first)
                    q.push(current->first);
                if (current->second)
                    q.push(current->second);
            }
            std::cout << std::endl;
        }
    }
};

static void preOrder(node* start) {
    if (!start) return;
    std::cout << start->position.c_str() << ", ";
    preOrder(start->first);
    preOrder(start->second);
}


static void inOrder(node* start) {
    if (!start) return;
    inOrder(start->first);
    std::cout << start->position.c_str() << ", ";
    inOrder(start->second);
}

static void postOrder(node* start) {
    if (!start)return;
    postOrder(start->first);
    postOrder(start->second);
    std::cout << start->position.c_str() << ", ";
}

int main() {
    auto tree = org_tree::create_org_structure("CEO");
    tree.addSubordinate("CEO", "부사장");
    tree.addSubordinate("부사장", "IT부장");
    tree.addSubordinate("부사장", "마케팅부장");
    tree.addSubordinate("IT부장", "보안팀장");
    tree.addSubordinate("IT부장", "앱개발팀장");
    tree.addSubordinate("마케팅부장", "물류팀장");
    tree.addSubordinate("마케팅부장", "홍보팀장");
    tree.addSubordinate("부사장", "재무부장");

    preOrder(tree.root);// 전위 순회 
    std::cout << std::endl;
    inOrder(tree.root);// 중위 순회
    std::cout << std::endl;
    postOrder(tree.root); //후위 순회
    std::cout << std::endl;
    org_tree::levelOrder(tree.root); // 레벨 순서 순회
    return 0;
}

/* 출력 결과
CEO 아래에 부사장을(를) 추가했습니다.
부사장 아래에 IT부장을(를) 추가했습니다.
부사장 아래에 마케팅부장을(를) 추가했습니다.
IT부장 아래에 보안팀장을(를) 추가했습니다.
IT부장 아래에 앱개발팀장을(를) 추가했습니다.
마케팅부장 아래에 물류팀장을(를) 추가했습니다.
마케팅부장 아래에 홍보팀장을(를) 추가했습니다.
부사장 아래에 재무부장을(를) 추가할 수 없습니다.
CEO, 부사장, IT부장, 보안팀장, 앱개발팀장, 마케팅부장, 물류팀장, 홍보팀장,
보안팀장, IT부장, 앱개발팀장, 부사장, 물류팀장, 마케팅부장, 홍보팀장, CEO,
보안팀장, 앱개발팀장, IT부장, 물류팀장, 홍보팀장, 마케팅부장, 부사장, CEO,
CEO,
부사장,
IT부장, 마케팅부장,
보안팀장, 앱개발팀장, 물류팀장, 홍보팀장,
*/
