#ifndef _KVLIST_H_
#define _KVLIST_H_

#include <iostream>

template <typename K, typename V, int N>
class KVList
{

	K k[N];
	V v[N];

	int count;
public:
	KVList() : count(0) {} // default constructor

	size_t size() const {
		return count; // returns number of entries in the key-value list
	}

	const K& key(int i) const {
		return k[i];
	}

	const V& value(int i) const {
		return v[i];
	}

	KVList& add(const K& newK, const V& newV) {
		if (count < N) {
			k[count] = newK;
			v[count] = newV;
			count++;
		}
		return *this;
	}

	int find(const K& newK) const {
		for (int i = 0; i < count; i++) {
			if (k[i] == newK) {
				return i;
			}

		}

		return 0;
	}

	KVList&	replace(int i, const K& newK, const V& newV) {
		k[i] = newK;
		v[i] = newV;

		return *this;
	}

};

#endif
