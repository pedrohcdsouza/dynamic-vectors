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
    clear();
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

bool insert_at(unsigned int index, int value){

    if (index > size_ || index < 0){
        return false; 
    }

    int_node *new_node = new int_node;
    new_node->current = value;
    new_node->next = nullptr;
    new_node->prev = nullptr;

    if (index == 0){

        if (head == nullptr){
            head = tail = new_node;
        }else{
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }else if (index == size_){
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    else{
        int_node *current = head;
        for (unsigned int i = 0; i < index; i++){
            current = current->next;
        }

        new_node->prev = current->prev;
        new_node->next = current;
        current->prev->next = new_node;
        current->prev = new_node;
    }

    size_++;
    return true;
}


bool remove_at(unsigned int index) { // Remove elemento do índice index
    
        if (index >= size_ || index < 0)
        {
            return false; 
        }

        int_node *to_delete = nullptr;

        if (index == 0)
        {

            to_delete = head;
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            else
            {

                tail = nullptr;
            }
        }
        else if (index == size_ - 1)
        {

            to_delete = tail;
            tail = tail->prev;
            if (tail != nullptr)
            {
                tail->next = nullptr;
            }
            else
            {

                head = nullptr;
            }
        }
        else
        {
            int_node *current = head;
            for (unsigned int i = 0; i < index; i++)
            {
                current = current->next;
            }
            to_delete = current;
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete to_delete;

        size_--;
        return true;
    
}

int get_at(unsigned int index) { // Retorna elemento no 'índice' index, −1 se índice inválido
    int_node* node = head;
    if(size_ > index)
        return -1;
    for(int i = 0; i < size_; i++){
        node = node->next;
    }
    return node->current;
}

void clear() {
    int_node* del_node = head;
    while (head != nullptr) { // Remove todos os elementos, deixando o vetor no estado inicial
        head = head->next;
        delete del_node;
    }
    tail = nullptr;
    size_ = 0;
} 

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

bool remove(int value) { // Remove value do vetor caso esteja presente

    int_node* del_node = head;

    if(size_ == 0){
        return false;
    }

    if(size_ == 1 && del_node->current == value){
        tail = nullptr;
        head = nullptr;
        size_ = 0;
        delete del_node;
        return true;
    }

    for(int i = 0; i < size_ -1; i++){
        if(del_node->current == value){
            del_node->prev->next = del_node->next;
            del_node->next->prev = del_node->prev;
            size_ -= 1;            
        }
        del_node = del_node->next;
    }

    if(tail->next == nullptr){
        tail = tail->prev;
        tail->prev->next = nullptr;
    }

    delete del_node;
    return true;

} 
int find(int value) { // Retorna o índice de value, −1 caso value não esteja presente
    int pos = 0;
    int loop = size_ -1;
    int_node* node = head;
    while(loop > 0){
        if(node->current == value){
            return pos;
        }
        node = node->next;
        pos += 1;
        loop -= 1;
    }
    return -1;
}
int count(int value) { // Retorna quantas vezes value ocorre no vetor
    int count = 0;
    int_node* node = head;
    for(int i = 0; i < size_ -1; i++){
        if(node->current == value){
            count += 1;
        }
        node = node->next;   
    }
} 
int sum() { // Retorna a soma dos elementos do vetor
    int sum = 0;
    int_node* node = head;
    for(int i = 0; i < size_ -1; i++){
        sum += node->current;
        node = node->next;
    }
    return sum;
} 
};
#endif // __LINKED_LIST_IFRN__