#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

int* my_realloc(int* buffer, int size){

int* ptr = mmap(NULL, 2*size, PROT_WRITE | PROT_READ, MAP_SHARED | MAP_ANON, -1, 0);
if(ptr == NULL){

perror("mapping failed");
exit(0);
}

for(int i = 0 ; i < size ; ++i){
    ptr[i] = buffer[i];
}

int check = munmap(buffer, 4096);
if(check == -1){

perror("MUNMAPPING failed");
exit(0);
}

return ptr;

}


int* create_buffer(){

int* ptr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);

if(ptr == NULL){

perror("mapping failed");
exit(0);

}

return ptr;


}

int* push_front(int* buffer, int* size, const int element){

if(*size == 1024){

buffer = my_realloc(buffer, *size);

}


for(int i = *size-1; i >= 0 ; --i){

buffer[i+1] = buffer[i];

}

buffer[0] = element;

*size += 1;
    
return buffer;

}



int* push_back(int * buffer, int * size, const int element){

if(*size == 1024){

buffer = my_realloc(buffer, *size);

}
   

buffer[*size] = element;

*size += 1;

return buffer;

}


int* remove_element(int* buffer, int* size, const int index){

if(index < 0 || index > *size){

perror("INVALID element");
exit(0);
}

for(int i = index ; i <= *size ; ++i){

buffer[i] = buffer[i+1];

}

*size += -1;

return buffer;

}

void current_state(int* buffer, const int size){

for(int i = 0 ; i < size ; ++i){

printf("%d", buffer[i]);

}


}

void destroy_buffer(int** buffer, int* size){

int check =  munmap(buffer, *size);
if(check == -1){
perror("munmapping failed");
exit(0);

}

*buffer = NULL;

}


/* int* insert_elem(int* buffer, int* size, const int index, const int elem){

if(*size == 1024){

    buffer = my_realloc(buffer, *size);

}

for(int i = *size-1 ; i >= index ; --i){

buffer[i+1] = buffer[i];

}

buffer[index] = elem;
*size += 1;
return buffer;

}
*/

