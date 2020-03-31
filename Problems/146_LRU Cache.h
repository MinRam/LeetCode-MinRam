/**
 * @Problem https://leetcode.com/problems/lru-cache/
 * @Author  MinRam
 * @Date    03/31/2019
 * @Describe Achieved with a single list and a unordered hash map;
 */
 
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class LRUCache {
public:
	LRUCache(int capacity) {
		this->capacity = capacity > 0 ? capacity : 0;
		this->head = new ListNode(-1, -1);
		this->tail = this->head;
	}

	int get(int key) {
		auto preNode = map.find(key);
		if (preNode == map.end()) return -1;
		if (preNode->second->next != tail) {
			tail->next = preNode->second->next;
			preNode->second->next = preNode->second->next->next;

			auto updateNode = map.find(preNode->second->next->key);
			if (updateNode != map.end()) updateNode->second = preNode->second;

			preNode->second = tail;
			tail = tail->next;
			tail->next = nullptr;
		}

		return tail->value;
	}

	void put(int key, int value) {
		auto preNode = map.find(key);
		if (preNode == map.end()) {
			map.insert({ key,tail });
			tail->next = new ListNode(key, value);
			tail = tail->next;

			if (map.size() > capacity) {
				ListNode * tmp = head->next;
				head->next = head->next->next;
				if (head->next != nullptr) {
					auto updateNode = map.find(head->next->key);
					if (updateNode != map.end()) {
						updateNode->second = head;
					}
				}
				map.erase(tmp->key);
				delete tmp;
			}
		}
		else {
			preNode->second->next->value = value;

			if (preNode->second->next != tail) {
				tail->next = preNode->second->next;
				preNode->second->next = preNode->second->next->next;

				auto updateNode = map.find(preNode->second->next->key);
				if (updateNode != map.end()) updateNode->second = preNode->second;

				preNode->second = tail;
				tail = tail->next;
				tail->next = nullptr;
			}
		}
	}

private:
	struct ListNode {
		int key;
		int value;
		ListNode * next;
		ListNode(int iniKey, int iniValue) :key(iniKey), value(iniValue), next(nullptr) {};
	};
	unordered_map<int, ListNode *> map;
	int capacity;
	ListNode * head, *tail;
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/