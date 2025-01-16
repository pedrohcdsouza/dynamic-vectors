#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__
class linked_list {
private:
struct int_node {
int current;
int_node* next, * prev;
};
int_node* head, * tail;
unsigned int size_;
public:
linked_list() { // Construtor
    this->head = nullptr;
    this->tail = nullptr;
    this->size_ = 0;
}

~linked_list() { // Destrutor

}

unsigned int size() { // Retorna a quantidade de elementos armazenados
    return size_;
}

double percent_occupied() {  // Retorna um valor entre 0.0 a 1.0 com o percentual da memória usada.
    if (size_ > 0){
        return 1.0;
    }else{
        return 0.0;
    }
}

bool insert_at(unsigned int index, int value) { // Insere elemento no índice index
    if(index > size_){
        return false;
    }

    int_node *new_node = new int_node;
    new_node->current = value;

    if(index == 0){
        new_node->next = head;
        new_node->prev = nullptr;
        if(head){
            head->prev = new_node;
        }
        head = new_node;
        if(size_ == 0){
            tail = new_node;
        }
    }else if(index == size_){
        int_node* current = head;
        for(unsigned int i = 0; i < index -1; i++){
            current = current->next;
        }
        new_node->next = current ->next;
        new_node->prev = current;
        if(current->next){
            current->next = new_node;
        }
        size_ += 1;
        return true;   
    }
}

bool remove_at(unsigned int index) {} // Remove elemento do índice index
int get_at(unsigned int index) {} // Retorna elemento no 'índice' index, −1 se índice inválido

void clear() {} // Remove todos os elementos, deixando o vetor no estado inicial

void push_back(int value) { // Adiciona um elemento no ``final'' do vetor
    int_node *new_node = new int_node;
    new_node->current = value;
    if(size_ == 0){ // Se o tamanho do array é zero, o valor adicionado é o primeiro e último valor (head and tail)
        head = new_node;
        tail = new_node;
        new_node->next = nullptr;
        new_node->prev = nullptr;
    }else{
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    size_ += 1;
}

void push_front(int value) { // Adiciona um elemento no ``início'' do vetor
    int_node *new_node = new int_node;
    new_node->current = value;
    if(size_ == 0){ // Se o tamanho do array é zero {...}
        head = new_node;
        tail = new_node;
        new_node->next = nullptr;
        new_node->prev = nullptr;
    }else{
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    size_ += 1;
}

bool pop_back() { // Remove um elemento do ``final'' do vetor
    if(size_ == 0) {
        return false;
    }else if(tail == head){
        tail == nullptr;
        head == nullptr;
    }else{
        tail->prev = tail;
        tail->next = nullptr;
    }
    size_ -= 1;
    return true;
}

bool pop_front() { // Remove um elemento do ``início'' do vetor
    if(size_ == 0){
        return false;
    }else if(tail == head){
        tail = nullptr;
        head == nullptr;
    }else{
        head->next = head;
        head->prev = nullptr;
    }
    size_ -= 1;
    return true;
}

int back(){ // Retorna o elemento do ``final'' do vetor
    return tail->current;
}

int front(){ // Retorna o elemento do ``início'' do vetor
    return head->current;
}

bool remove(int value) {} // Remove value do vetor caso esteja presente
int find(int value) {} // Retorna o índice de value, −1 caso value não esteja presente
int count(int value) {} // Retorna quantas vezes value occorre no vetor
int sum() {} // Retorna a soma dos elementos do vetor
};
#endif // __LINKED_LIST_IFRN__