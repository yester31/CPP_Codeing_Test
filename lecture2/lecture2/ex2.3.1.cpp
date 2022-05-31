#include <iostream>
#include <queue>

// ���� Ʈ�� �⺻ ���� 
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
            std::cout << manager.c_str() << "��(��) ã�� �� �����ϴ�: " << std::endl;
            return false;
        }

        if (managerNode->first && managerNode->second) {
            std::cout << manager.c_str() << " �Ʒ��� " << subordinate.c_str() << "��(��) �߰��� �� �����ϴ�. " << std::endl;
            return false;
        }

        if (!managerNode->first)
            managerNode->first = new node{ subordinate, NULL, NULL };
        else
            managerNode->second = new node{ subordinate, NULL, NULL };

        std::cout << manager.c_str() << " �Ʒ��� " << subordinate.c_str() << "��(��) �߰��߽��ϴ�. " << std::endl;

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
    tree.addSubordinate("CEO", "�λ���");
    tree.addSubordinate("�λ���", "IT����");
    tree.addSubordinate("�λ���", "�����ú���");
    tree.addSubordinate("IT����", "��������");
    tree.addSubordinate("IT����", "�۰�������");
    tree.addSubordinate("�����ú���", "��������");
    tree.addSubordinate("�����ú���", "ȫ������");
    tree.addSubordinate("�λ���", "�繫����");

    preOrder(tree.root);// ���� ��ȸ 
    std::cout << std::endl;
    inOrder(tree.root);// ���� ��ȸ
    std::cout << std::endl;
    postOrder(tree.root); //���� ��ȸ
    std::cout << std::endl;
    org_tree::levelOrder(tree.root); // ���� ���� ��ȸ
    return 0;
}

/* ��� ���
CEO �Ʒ��� �λ�����(��) �߰��߽��ϴ�.
�λ��� �Ʒ��� IT������(��) �߰��߽��ϴ�.
�λ��� �Ʒ��� �����ú�����(��) �߰��߽��ϴ�.
IT���� �Ʒ��� ����������(��) �߰��߽��ϴ�.
IT���� �Ʒ��� �۰���������(��) �߰��߽��ϴ�.
�����ú��� �Ʒ��� ����������(��) �߰��߽��ϴ�.
�����ú��� �Ʒ��� ȫ��������(��) �߰��߽��ϴ�.
�λ��� �Ʒ��� �繫������(��) �߰��� �� �����ϴ�.
CEO, �λ���, IT����, ��������, �۰�������, �����ú���, ��������, ȫ������,
��������, IT����, �۰�������, �λ���, ��������, �����ú���, ȫ������, CEO,
��������, �۰�������, IT����, ��������, ȫ������, �����ú���, �λ���, CEO,
CEO,
�λ���,
IT����, �����ú���,
��������, �۰�������, ��������, ȫ������,
*/