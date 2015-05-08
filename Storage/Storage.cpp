#include "Storage.h"


Storage::Storage(void) {
}


Storage::~Storage(void) {
}

Storage *Storage::_storageInstance = nullptr;

Storage *Storage::getInstance() {
	if (_storageInstance == nullptr) {
		_storageInstance = new Storage;
	}
	return _storageInstance;
}