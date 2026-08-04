class LRUCache {
public:
    struct Node {
        int key;
        int val;
        Node* left = NULL;
        Node* right = NULL;

        Node(int v, int k) {
            val = v;
            key = k;
            left = NULL;
            right = NULL;
        };
    };

    unordered_map<int, Node*> mp;
    int size;
    int max_size;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        size = 0;
        max_size = capacity;
        head = NULL;
        tail = NULL;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* tar = mp[key];

        if (tar == tail)
            return tar->val;

        if (tar == head) {
            head = head->right;
            if (head != NULL)
                head->left = NULL;
        } else {
            tar->left->right = tar->right;
            tar->right->left = tar->left;
        }

        tar->left = tail;
        tar->right = NULL;
        tail->right = tar;
        tail = tar;

        return mp[key]->val;
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {
            get(key);
            mp[key]->val = value;
            return;
        }
        if (size == max_size) {
            Node* temp = head;
            head = head->right;
            if (head != NULL)
                head->left = NULL;
            temp->right = NULL;
            mp.erase(temp->key);
            size--;
        }

        Node* newnode = new Node(value, key);
        mp[key] = newnode;

        if (size == 0) {
            head = newnode;
            tail = newnode;
        } else {
            newnode->left = tail;
            tail->right = newnode;
            tail = newnode;
        }
        size++;
    }
};
