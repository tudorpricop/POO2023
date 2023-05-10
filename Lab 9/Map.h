#pragma once

#define MAXIM 100

template < typename K, typename V >
class Map {

public:

	struct IndexItem {
		K key;
		V value;
		int index;
	};

	Map() {
		for (int i = 0; i < MAXIM; i++)
		{
			Array[i].value = V();
			Array[i].key = K();
			Array[i].index = 0;
		}
	}

	void add(K key, V value) {
		if (len < MAXIM)
		{
			Array[len].index = len;
			Array[len].key = key;
			Array[len].value = value;
			len++;
		}
		else {
			std::cout << "\nThe map is full! Can't add more elements \n";
			exit(1);
		}
	}

	V& operator[] (K key)
	{
		for (int i = 0; i < len; i++)
		{
			if (Array[i].key == key)
			{
				return Array[i].value;
			}
		}

		add(key, V());
		return Array[len - 1].value;
	}

	IndexItem* begin() {
		return &Array[0];
	}

	IndexItem* end() {
		return &Array[len];
	}

	void Set(const K& key, const V& value) {

		bool flag = false;

		for (int i = 0; i < len; i++)
		{
			if (Array[i].key == key)
			{
				Array[i].value = value;
				flag = true;
			}
		}

		if (flag == false)
			add(key, value);
	}

	bool Get(const K& key, V& value) {

		for (int i = 0; i < len; i++)
		{
			if (Array[i].key == key)
			{
				value = Array[i].value;
				return true;
			}
		}
		return false;
	}

	int Count() {
		return len;
	}

	void Clear() {

		for (int i = 0; i < len; i++)
		{
			Array[i].value = V();
			Array[i].key = K();
			Array[i].index = 0;
		}
		len = 0;
	}

	bool Delete(const K& key) {

		for (int i = 0; i < len; i++)
		{
			if (Array[i].key == key)
			{
				//We swap the last element with the one we want to delete

				Array[i].value = Array[len - 1].value;
				Array[i].key = Array[len - 1].key;
				//Array[i].index = Array[len - 1].index;

				// Delete the last element and decrease the total nr of elem

				Array[len - 1].value = V();
				Array[len - 1].key = K();
				Array[len - 1].index = 0;

				len--;

				return true;
			}
		}
		return false;
	}

	bool Includes(const Map<K, V>& map) {

		if (len <= map.len) {
			int nr = 0;
			for (int i = 0; i < len; i++) {
				for (int j = 0; j < map.len; j++) {
					if (Array[i].key == map.Array[j].key) {
						nr++;
					}
				}
			}
			if (nr == len) {
				std::cout << "\nAll keys from current map are included\n";
				return true;
			}
		}
		std::cout << "\nNot all keys from current map are included\n";
		return false;
	}


private:
	int len = 0;
	IndexItem Array[MAXIM];
};