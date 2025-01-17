#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__
class array_list {
private:
int* data;
unsigned int size_, capacity_;

void increase_capacity() {
    capacity_ *= 2;
    int *new_node = new int[capacity_];

    for (unsigned int i = 0; i < size_; ++i) {
        new_node[i] = data[i];
    }

    data = new_node;
}
public:
array_list() { // Construtor
    this-> size_ = 0;
    this-> capacity_ = 8;
    this-> data = new int[capacity_];
}

~array_list() { // Destrutor
    delete[] data;
    size_ = 0;
    capacity_ = 8;
    data = new int[capacity_];
}
unsigned int size() { // Retorna a quantidade de elementos armazenados
    return size_;
}

unsigned int capacity() { // Retorna o espaço reservado para armazenar os elementos
    return capacity_;
}

double percent_occupied() { // Retorna um valor entre 0.0 a 1.0 com o percentual da memória usada.
    return static_cast<double>(size_) / static_cast<double>(capacity_);
}

bool insert_at(unsigned int index, int value) { // Insere um valor no index desejado.
    if (index > size_ or index < 0){
        return false;
    }

    if (size_ == capacity_){
        increase_capacity();
    }

    for (unsigned int i = size_; i > index; i--)
    {
        data[i] = data[i - 1];
    }

    data[index] = value;

    size_++;

    return true;
}

bool remove_at(unsigned int index) { // Remove elemento do índice index
    if (index > size_ or index < 0){
        return false;
    }

    for (unsigned int i = size_; i > index; i--){
        data[i] = data[i + 1];
    }
    size_ --;
    return true;
}

int get_at(unsigned int index) { // Retorna elemento no índice index, −1 se índice inválido
    if(size_ > index){
        return -1;
    }
    return data[index];
}

void clear() { // Remove todos os elementos, deixando o vetor no estado inicial
    delete[] data;
    size_ = 0;
    capacity_ = 8;
}

void push_back(int value) { // Adiciona um elemento no ``final'' do vetor
    if(size_ +1 > capacity_){
        increase_capacity();
    }
    data[size_+1] = value;

}
void push_front(int value) { // Adiciona um elemento no ``início'' do vetor
    if(size_ +1 > capacity_){
        increase_capacity();
    }
    for(int i = 0; i < size_; i++){
        data[i+1] = data[i];
    }
    data[0] = value;
    size_ ++;
}
bool pop_back() { // Remove um elemento do ``final'' do vetor

}

bool pop_front() { // Remove um elemento do ``início'' do vetor

}

int back(){ // Retorna o elemento do ``final'' do vetor
    return data[size_ -1];
}

int front(){ // Retorna o elemento do ``início'' do vetor
    return data[0];
}

bool remove(int value) { // Remove value do vetor caso esteja presente

}

int find(int value) { // Retorna o índice de value, −1 caso value não esteja presente
    if(size_ = 0)
        return -1;
    for(int i = 0; i < size_; i++){
        if(data[i] == value)
            return i;
    }
    return -1;
}

int count(int value) { // Retorna quantas vezes value occorre no vetor
    int count = 0;
    for(int i = 0; i < size_; i++){
        if(data[i] == value)
            count ++;
    }
    return count;
}

int sum() { // Retorna a soma dos elementos do vetor
    int sum = 0;
    for(int i = 0; i < size_; i++){
        sum += data[i];
    }
    return sum;
}

};
#endif // __ARRAY_LIST_IFRN__