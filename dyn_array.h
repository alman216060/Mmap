int* create_buffer();

int* push_front(int* buffer, int* size, const int element);

int* push_back(int * buffer, int * size, const int element);

void current_state(int* buffer, const int size);

void destroy_buffer(int** buffer, int* size);

int* remove_element(int* buffer, int* size, const int index);

int* insert_elem(int* buffer, int* size, const int index, const int elem);


