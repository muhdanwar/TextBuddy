#pragma once
class Storage {
private:
	static Storage *_storageInstance;

	Storage(void);
	~Storage(void);
public:
	static Storage *getInstance();
};

