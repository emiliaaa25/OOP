#pragma once
template<typename K, typename V>

class Map {
private:
	struct Pair {
		K key;
		V value;
		int index;
	};
	Pair* pairs;
	int Index;
	int elemente;
public:
	Map() {
		this-> Index = 0;
		this->elemente = 10;
		this->pairs = new Pair[this->elemente];
	}
	~Map() {
		elemente = 0;
		Index = 0;
		if (pairs != nullptr)
			delete[]pairs;
	}
	V& operator [](K cheie)
	{
		int i;
		for (i = 0;i < Index;i++)
			if (pairs[i].key == cheie)
				return pairs[i].value;
	
			Pair* element = new Pair[this->elemente];
			for (i = 0;i < Index;i++)
			{
				element[i].key = pairs[i].key;
				element[i].value = pairs[i].value;
				element[i].index = pairs[i].index;
			}
			element[Index].key = cheie;
			element[Index].value = 0;
			element[Index].index = Index;
			Index++;
			if(this->pairs!=nullptr)
				delete[] pairs;
			pairs = new Pair[Index];
			for (i = 0;i < Index;i++)
			{
				pairs[i].key = element[i].key;
				pairs[i].value = element[i].value;
				pairs[i].index = element[i].index;
			}

				delete[] element;
			return pairs[Index - 1].value;
	}
	void operator = (V valoare)
	{
		this->value = valoare;
	}
	class Iterator {
		Pair* p;
		Iterator operator !=(Iterator& m)
		{
			return p != m.p;
		}
		Iterator& operator++() { p++; return *this; }
		Iterator operator*() { return *p; }

	};
	Pair* begin() {
		return &pairs[0]; 
	}

	Pair* end() {
		return &pairs[Index]; 
	}

	void Set(K cheie,V valoare) {
		int i,ok=0;
		for(i=0;i<Index;i++)
			if(pairs[i].key==cheie)
			{
				ok = 1;
				pairs[i].value = valoare;

			}
		if(ok==0)
		{
			pairs[Index].key = cheie;
			pairs[Index].value = valoare;
			pairs[Index].index = Index;
			this->Index++;
		}

	}
	bool Get(const K& key, V& value)
	{
		int i;
		for (i = 0;i < Index;i++)
			if (pairs[i].key == key)
			{
				
				value=pairs[i].value;
				return true;

			}
		return false;
	}

	int Count()
	{
		return this->Index;
	}
	void Clear() {
		
		delete[]pairs;
		pairs = nullptr;
		Index = 0;

	}
	bool Delete(const K& key)
	{
		int i,j;
		for (i = 0;i <= Index;i++)
			if (pairs[i].key == key)
			{
				for (j = i+1;j < Index;j++)
				{
					pairs[j].index--;
					pairs[j - 1] = pairs[j];
				}
				Index--;
				return true;
			}
		return false;
	}
	bool Includes(const Map<K, V>& map) {
		int i,j;
		if (Index != map.Index)
			return false;
		for (i = 0;i < Index;i++)
			for (j = 0;j < map.Index;j++)
				if (pairs[i].key != map[j].key)
					return 0;
				else
					if (pairs[i].value != map[j].value)
						return false;
		return true;
			
	}
};
